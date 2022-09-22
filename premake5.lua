workspace "GameEngine"
	architecture "x64"
	startproject "SandBox"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "GameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "GameEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "GameEngine/vendor/imgui"
IncludeDir["glm"] = "GameEngine/vendor/glm"

include "GameEngine/vendor/GLFW"
include "GameEngine/vendor/Glad"
include "GameEngine/vendor/imgui"

project "GameEngine"
	location "GameEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nepch.h"
	pchsource "GameEngine/src/nepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"

		systemversion "latest"

		defines
		{
			"NE_PLATFORM_WINDOWS",
			"NE_BUILD_DLL",
			"_WINDLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "NE_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NE_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "On"

project "SandBox"
	location "SandBox"
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
		"GameEngine/vendor/spdlog/include",
		"%{IncludeDir.glm}",
		"GameEngine/src",
		"GameEngine/vendor"
	}

	links
	{
		"GameEngine"
	}

	filter "system:windows"

		systemversion "latest"

		defines
		{
			"NE_PLATFORM_WINDOWS"	
		}

	filter "configurations:Debug"
		defines "NE_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NE_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "On"