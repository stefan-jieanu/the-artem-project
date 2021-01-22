workspace "Artem"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ArtemEngine"
    location "ArtemEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/glfw/include",
        "%{prj.name}/vendor/glew/include",
        "%{prj.name}/vendor/sbt_image",
        "%{prj.name}/vendor/spdlog/include"
    }

    libdirs
    {
        "%{prj.name}/vendor/glfw/lib-vc2019",
        "%{prj.name}/vendor/glew/lib-vc2019/lib/Release/x64",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "AR_PLATFORM_WINDOWS",
            "AR_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Artem")
        }

    filter "configurations:Debug"
        defines "AR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "AR_DIST"
        optimize "On"

project "Artem"
    location "Artem"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "ArtemEngine/vendor/spdlog/include",
        "ArtemEngine/src"
    }

    links
    {
        "ArtemEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "AR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "AR_DIST"
        optimize "On"