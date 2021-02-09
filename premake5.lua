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
IncludeDir["Glad"] = "ArtemEngine/vendor/Glad/include"
IncludeDir["glm"] = "ArtemEngine/vendor/glm"
IncludeDir["stb"] = "ArtemEngine/vendor/stb"

include "ArtemEngine/vendor/GLFW"
include "ArtemEngine/vendor/Glad"

project "ArtemEngine"
    location "ArtemEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "aepch.h"
    pchsource "ArtemEngine/src/aepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
        "%{prj.name}/vendor/stb/**.h",
        "%{prj.name}/vendor/stb/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "AR_PLATFORM_WINDOWS",
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
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "ArtemEngine/vendor/spdlog/include",
        "ArtemEngine/vendor/glm",
        "ArtemEngine/src"
    }

    links
    {
        "ArtemEngine"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "AR_PLATFORM_WINDOWS"
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