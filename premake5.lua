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

-- Include Directories
IncludeDir = {}
IncludeDir["glfw"] = "ArtemEngine/vendor/glfw-3.3.5/include"

-- group "Dependencies"
-- 	include "./ArtemEngine/vendor/glfw-3.3.5"
-- group ""

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
        "%{prj.name}",
        "%{prj.name}/src",
        "%{IncludeDir.glfw}"
    }

    linkgroups "On"

    links 
    { 
        "GLFW",
        "Xrandr",
		"Xi",
		"GL",
		"X11"
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
        "ArtemEngine",
        "%{IncludeDir.glfw}",
    }

    linkgroups "On"

    linkoptions
    {
        "-ldl",
        "-lpthread",
        "-lX11",
        "-lXxf86vm",
        "-lXrandr",
        "-lXi"
    }

    links
    {
        "ArtemEngine",
        "GLFW",
        "Xrandr",
		"Xi",
		"GL",
		"X11",
        "dl",
        "pthread",
        "X11",
        "Xxf86vm",
        "Xrandr",
        "Xi"
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

project "GLFW"
    location "GLFW"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "ArtemEngine/vendor/glfw-3.3.5/include/GLFW/glfw3.h",
        "ArtemEngine/vendor/glfw-3.3.5/include/GLFW/glfw3native.h",
        "ArtemEngine/vendor/glfw-3.3.5/src/glfw_config.h",
        "ArtemEngine/vendor/glfw-3.3.5/src/context.c",
        "ArtemEngine/vendor/glfw-3.3.5/src/init.c",
        "ArtemEngine/vendor/glfw-3.3.5/src/input.c",
        "ArtemEngine/vendor/glfw-3.3.5/src/monitor.c",
        "ArtemEngine/vendor/glfw-3.3.5/src/vulkan.c",
        "ArtemEngine/vendor/glfw-3.3.5/src/window.c"
    }
    filter "system:linux"
        pic "On"

        systemversion "latest"
        staticruntime "On"

        files
        {
            "ArtemEngine/vendor/glfw-3.3.5/src/x11_init.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/x11_monitor.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/x11_window.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/xkb_unicode.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/posix_time.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/posix_thread.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/glx_context.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/egl_context.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/osmesa_context.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/linux_joystick.c"
        }

        defines
        {
            "_GLFW_X11"
        }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        files
        {
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_init.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_joystick.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_monitor.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_time.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_thread.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/win32_window.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/wgl_context.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/egl_context.c",
            "ArtemEngine/vendor/glfw-3.3.5/src/osmesa_context.c"
        }

        defines 
        { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
