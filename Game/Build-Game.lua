project "Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs {
      "Source",
      RootDir .. "ThirdParty/SFML-3.0.0/include",
      RootDir .. "ThirdParty/imgui",
      RootDir .. "ThirdParty/rapidjson",
      RootDir .. "Engine/Source"
   }

   links { "Engine" }

   targetdir (RootDir .. "Bin/" .. OutputDir .. "/%{prj.name}")
   objdir (RootDir .. "Bin/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }


   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       postbuildcommands {
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-audio-d-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-graphics-d-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-network-d-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-system-d-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-window-d-3.dll %{cfg.targetdir}"
       }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
       postbuildcommands {
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-audio-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-graphics-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-network-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-system-3.dll %{cfg.targetdir}",
            "{COPY}" .. RootDir .. "ThirdParty/SFML-3.0.0/binaries/sfml-window-3.dll %{cfg.targetdir}"
       }

   filter {}