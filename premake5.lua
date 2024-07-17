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
IncludeDir["GLM"] = "Normal/vendor/GLM"
IncludeDir["STB_IMAGE"] = "Normal/vendor/stb_image"

-- this code is include a premake5 file
include "Normal/vendor/GLFW"
include "Normal/vendor/Glad"
include "Normal/vendor/imgui"

project "Normal"
    location "Normal"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest" -- If this version is not defined, automatically define a Windows 8 version.  

    targetdir ("bin/"..outputDir.."/%{prj.name}")
    objdir ("bin-int/"..outputDir.."/%{prj.name}")

    pchheader "Nrpch.h"
    pchsource "Normal/src/Nrpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/stb_image.cpp",
        "%{prj.name}/vendor/stb_image/stb_image.h",
    }

    includedirs
    { -- The order of imports is important.
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.Imgui}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.STB_IMAGE}",
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


    defines
    {
        "NR_PLATFORM_WINDOWS",
        "NR_BUILD_DLL",
        "GLFW_INCLUDE_NONE", -- Does not include OpenGL header.
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .."/Workspace/\"" )
    }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "On"

project "Workspace"
    location "Workspace"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest"

    targetdir ("bin/"..outputDir.."/%{prj.name}")
    objdir ("bin-int/"..outputDir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src/",
        "Normal/src",
        "Normal/vendor/spdlog/include",
        "%{IncludeDir.Imgui}",
        "%{IncludeDir.GLM}",
    }

    links
    {
        "Normal"
    }
    
    defines
    {
        "NR_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "On"