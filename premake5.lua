workspace "Artem"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (soulution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ArtemEngine/vendor/GLFW/include"

include "ArtemEngine/vendor/GLFW"

project "ArtemEngine"
    location "ArtemEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "aepch.h"
    pchsource "ArtemEngine/src/aepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "AR_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "AR_DIST"
        buildoptions "/MD"
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