workspace "OpenGlEngine"

	architecture "x64"
	configurations {
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg-%{cfg.system}-%{cfg.architecture}"


project "OpenGlEngine"
	location "OpenGlEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include {
		"%{prj.name}/vendor/spdlog"
	}


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"