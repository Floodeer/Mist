workspace "Mist-Sandbox"
	architecture "x64"
	startproject "Mist-Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"
IncludeDir["curl"] = "vendor/curl/include/curl"
IncludeDir["jsoncpp"] = "vendor/jsoncpp/include/json"

group "Dependencies"
	include "Mist-Core/vendor/GLFW"
	include "Mist-Core/vendor/Glad"
	include "Mist-Core/vendor/imgui"
group ""

include "Mist-Core"
include "Mist-Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"
IncludeDir["curl"] = "vendor/curl/include"
IncludeDir["jsoncpp"] = "vendor/jsoncpp/include"

group "Dependencies"
    includeexternal "Mist-Core/vendor/GLFW"
    includeexternal "Mist-Core/vendor/Glad"
    includeexternal "Mist-Core/vendor/imgui"
group ""

includeexternal "Mist-Core"
include "Mist-Sandbox"