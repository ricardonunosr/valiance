workspace "Valiance"
    architecture "x86_64"
    startproject "01-HelloWorld"
    configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Engine"
	include "Valiance"

group "Engine/Dependencies"
	include "Valiance/vendor/Glad"
	include "Valiance/vendor/imgui"
group ""

group "Examples"
    include "Examples/00-Sandbox"
	include "Examples/01-HelloWorld"
    include "Examples/02-Instancing"
group ""



