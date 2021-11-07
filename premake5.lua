workspace "Artem"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    platforms
    {
        "Win64",
        "Linux"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ArtemEngine"
    location "ArtemEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ArtemEngine/src/pch.hpp"
    pchsource "ArtemEngine/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}"
    }

    filter "system:linux"
        staticruntime "On"

        defines 
        {
            "AR_PLATFORM_LINUX",
            "AR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }


    filter "configurations:Debug"
        defines "AR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AR_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AR_DIST"
        runtime "Release"
        optimize "on"


project "Artem"
    location "Artem"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "ArtemEngine"
    }

    links
    {
        "ArtemEngine"
    }

    filter "system:linux"
        staticruntime "On"

        defines 
        {
            "AR_PLATFORM_LINUX"
        }

        filter "configurations:Debug"
            defines "AR_DEBUG"
            symbols "on"

        filter "configurations:Release"
            defines "AR_RELEASE"
            optimize "on"

        filter "configurations:Dist"
            defines "AR_DIST"
            optimize "on"
