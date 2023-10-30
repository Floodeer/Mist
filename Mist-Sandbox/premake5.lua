project "Mist-Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"../Mist-Core/vendor/spdlog/include",
		"../Mist-Core/src",
		"../Mist-Core/vendor",
		"../Mist-Core/%{IncludeDir.glm}",
		"../Mist-Core/%{IncludeDir.Glad}",
		"../Mist-Core/%{IncludeDir.ImGui}",
		"../Mist-Core/%{IncludeDir.curl}",
		"../Mist-Core/%{IncludeDir.jsoncpp}"
	}

	links
	{
		"Mist-Core"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MCORE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MCORE_RELEASE"
		runtime "Release"
        optimize "on"
