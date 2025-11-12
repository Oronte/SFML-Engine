project "Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",
      "../ThirdParty/SFML-3.0.0/include",

	  -- Include Core
	  "../Engine/Source"
   }

   libdirs 
   {
      "../ThirdParty/SFML-3.0.0/lib"
   }

   links
   {
      "Engine"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       links { "sfml-graphics-d", "sfml-window-d", "sfml-system-d", "sfml-audio-d", "sfml-network-d" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       links { "sfml-graphics", "sfml-window", "sfml-system", "sfml-audio", "sfml-network" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"