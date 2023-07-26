workspace "NormalEngine"
    startproject "Workspace"
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
IncludeDir["GLFW"] = "Normal/vendor/GLFW/include"
IncludeDir["Glad"] = "Normal/vendor/Glad/include"
IncludeDir["Imgui"] = "Normal/vendor/imgui"

-- this code is include a premake5 file
include "Normal/vendor/GLFW"
include "Normal/vendor/Glad"
include "Normal/vendor/imgui"

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
    { -- The order of imports is important.
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.Imgui}",
        "Normal/vendor/spdlog/include",
        "Normal/src"
    }

    links
    {
        "GLFW",
        "Glad",
        "Imgui",
        "opengl32.lib"
    }

    filter "system:Windows"
        cppdialect "C++20"
        staticruntime "Off"
        systemversion "latest" -- If this version is not defined, automatically define a Windows 8 version.  


    defines
    {
        "NR_PLATFORM_WINDOWS",
        "NR_BUILD_DLL",
        "NR_ENABLE_ASSERTS",
        "GLFW_INCLUDE_NONE" -- Does not include OpenGL header.
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .."/Workspace/" )
    }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "NR_RELEASE"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "NR_DIST"
        optimize "On"
        buildoptions "/MD"


project "Workspace"
    location "Workspace"
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
        runtime "release"
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