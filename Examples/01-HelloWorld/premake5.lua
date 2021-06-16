project "01-HelloWorld"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
	{
		"src/**.h",
		"src/**.cpp",
        "assets/**/*",
        "%{wks.location}/Valiance/vendor/glm/glm/**.hpp",
        "%{wks.location}/Valiance/vendor/glm/glm/**.inl",
	}

    includedirs
	{
		"%{wks.location}/Valiance/src",
		"%{wks.location}/Valiance/vendor/Glad/include",
        "%{wks.location}/Valiance/vendor/imgui",
        "%{wks.location}/Valiance/vendor/glm",
        "%{wks.location}/Valiance/vendor/GLFW/include",
        
	}

    libdirs 
    {
        "%{wks.location}/Valiance/vendor/GLFW/lib"
    }

    links
	{
		"Valiance",
        "Glad",
        "ImGui",
        "glfw3",
	}

    filter "configurations:Debug"
       defines { "DEBUG" }
       symbols "On"
 
    filter "configurations:Release"
       defines { "NDEBUG" }
       optimize "On"