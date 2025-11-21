project "Engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",
      "../ThirdParty/SFML-3.0.0/include"
   }

   libdirs 
   {
      "../ThirdParty/SFML-3.0.0/lib"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       links { "sfml-graphics", "sfml-window", "sfml-system", "sfml-audio", "sfml-network" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       links { "sfml-graphics", "sfml-window", "sfml-system", "sfml-audio", "sfml-network" }
       runtime "Release"
       optimize "On"
       symbols "On"