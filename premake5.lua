workspace "NormalEngine"
    startproject "SandBox"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
includeDir = {}
includeDir["GLFW"] = "Normal/vendor/GLFW/include"

include "Normal/vendor/GLFW"

project "Normal"
    location "Normal"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputDir.."/%{prj.name}")
    objdir ("bin-int/"..outputDir.."/%{prj.name}")

    pchheader "Nrpch.h"
    pchsource "Normal/src/Nrpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{includeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "$(VULKAN_SDK)/lib/vulkan-1.lib"
    }

    filter "system:Windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest" -- If this version is not defined, automatically define a Windows 8 version.  


    defines
    {
        "NR_PLATFORM_WINDOWS",
        "NR_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .."/SandBox/" )
    }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        optimize "On"



project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputDir.."/%{prj.name}")
    objdir ("bin-int/"..outputDir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Normal/vendor/spdlog/include",
        "Normal/src"
    }

    links
    {
        "Normal"
    }

    filter "system:Windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest" -- If this version is not defined, automatically define a Windows 8 version.  

    defines
    {
        "NR_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        optimize "On"