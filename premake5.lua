workspace "Valiance"
    architecture "x86_64"
    configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Valiance/vendor/Glad"
	include "Valiance/vendor/imgui"
group ""

project "Valiance"
    location "Valiance"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
 
    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }
 
    includedirs
    {
        "%{prj.name}/vendor/GLFW/include",
        "%{prj.name}/vendor/Glad/include",
        "%{prj.name}/vendor/glm",
        "%{prj.name}/vendor/imgui"
    }

    libdirs 
    {
        "%{prj.name}/vendor/GLFW/lib"
    }

    links 
    {
        "glfw3",
        "Glad",
        "ImGui"
    }

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
       defines { "DEBUG" }
       symbols "On"
 
    filter "configurations:Release"
       defines { "NDEBUG" }
       optimize "On"

