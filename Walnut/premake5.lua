workspace "Walnut"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

--outputdir =  Debug/Windows/X64 or x 32
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "Walnut/Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Walnut/Engine/vendor/Glad/include"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")
	
	pchheader "wlpch.h"
	pchsource "common/inc/wlpch.cpp"

	files
	{
		"%{prj.name}/platform/windows/**",
		"%{prj.name}/inc/**.h",
		"%{prj.name}/events/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)Engine/inc",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}
	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "on"
		defines
		{
			"WL_PLATFORM_WINDOWS",
			"WL_BUILD_DLL",
			"WL_DYNAMIC_LINK",
			"GLFW_INCLUDE_NONE"
		}		

	filter "configurations:Debug"
		defines "WL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "WL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "WL_DIST"
		runtime "Release"
		optimize "on"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-Obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/inc/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)Engine",
		"$(SolutionDir)Engine/inc",
		"$(SolutionDir)Logger/inc"
		"$(SolutionDir)Common/inc"
	}

	links
	{
		"Engine",
		("bin/" .. outputdir .."/Logger/Logger.lib" )
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"WL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "WL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "WL_DIST"
		runtime "Release"
		optimize "on"

project "Logger"
	location "Logger"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-Obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/inc/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)Logger/inc",
		"$(SolutionDir)Engine/inc"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"WL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "WL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "WL_DIST"
		runtime "Release"
		optimize "on"
