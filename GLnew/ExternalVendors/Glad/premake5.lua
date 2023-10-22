project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    files
    {
        "src/**.c",
        "include/**.h"
    }

    includedirs
    {
        "include"
    }