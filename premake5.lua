workspace "GLnew"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release"
    }
    startproject "GLnew"
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "GLnew/ExternalVendors/GLFW"
    include "GLnew/ExternalVendors/Glad"

    project "GLnew"
        language "C++"
        kind "ConsoleApp"
        cppdialect "C++17"
        location "GLnew"

        files
        {
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/src/**.h"
        }

        targetdir ("%{prj.name}/"..outputdir.."/bin")
        objdir ("%{prj.name}/"..outputdir.."/bin-int")

        includedirs
        {
            "%{prj.name}/ExternalVendors/GLFW/include",
            "%{prj.name}/ExternalVendors/Glad/include",
            "%{prj.name}/ExternalVendors/glm",
            "%{prj.name}/ExternalVendors/assimp/include",
            "%{prj.name}/src",
            "%{prj.name}/res"
        }

        syslibdirs
        {
            "%{prj.name}/ExternalVendors/assimp/lib/Debug"
        }

        links
        {
            "GLFW",
            "Glad",
            "assimp-vc143-mtd"
        }
