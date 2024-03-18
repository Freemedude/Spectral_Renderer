project "Spectral_Core"
   kind "SharedLib"
   language "C++"
   targetdir "%{wks.location}/../Bin"
   architecture "x64"
   files { "Code/**.cpp", "Code/**.hpp" }

   includedirs {
      "Code/include"
   }

   defines { "WIN_EXPORT" }
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      symbols "Off"
