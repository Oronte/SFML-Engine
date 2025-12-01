project "Engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",
      "../ThirdParty/SFML-3.0.0/include",
      "../ThirdParty/imgui"
   }

   libdirs 
   {
      "../ThirdParty/SFML-3.0.0/lib"
   }

   targetdir ("../Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Bin/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

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