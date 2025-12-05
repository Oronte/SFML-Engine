project "Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs {
      "Source",
      "../ThirdParty/SFML-3.0.0/include",
      "../ThirdParty/imgui",
      "../ThirdParty/rapidjson",
      "../Engine/Source"
   }

   links { "Engine" }

   targetdir ("Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("Bin/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }


   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       postbuildcommands {
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-audio-d.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-graphics-d.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-network-d.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-system-d.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-window-d.lib %{cfg.targetdir}",

            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-audio-d-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-graphics-d-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-network-d-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-system-d-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-window-d-3.dll %{cfg.targetdir}"
       }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
       postbuildcommands {
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-audio.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-graphics.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-network.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-system.lib %{cfg.targetdir}",
            --"{COPY} ../ThirdParty/SFML-3.0.0/lib/sfml-window.lib %{cfg.targetdir}",

            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-audio-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-graphics-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-network-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-system-3.dll %{cfg.targetdir}",
            "{COPY} ../ThirdParty/SFML-3.0.0/binaries/sfml-window-3.dll %{cfg.targetdir}"
       }

   filter {}