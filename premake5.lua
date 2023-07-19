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

-- Included directories relative to root folder
IncludeDir = {};
IncludeDir["GLFW"] = "Normal/vendor/glfw/include"

-- this code is include a premake5 file
include "Normal/vendor/glfw"

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
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:Windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest" -- If this version is not defined, automatically define a Windows 8 version.  


    defines
    {
        "NR_PLATFORM_WINDOWS",
        "NR_BUILD_DLL",
        "NR_ENABLE_ASSERTS"
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
        "NR_PLATFORM_WINDOWS",
        "NR_ENABLE_ASSERTS"
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