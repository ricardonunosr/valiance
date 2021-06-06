project "Valiance"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
 
    files 
    { 
        "src/*/**.h", 
        "src/*/**.cpp",
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl",
        "assets/**/*",
    }
 
    includedirs
    {
        "src", 
        "vendor/GLFW/include",
        "vendor/Glad/include",
        "vendor/glm",
        "vendor/imgui"
    }

    libdirs 
    {
        "vendor/GLFW/lib"
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