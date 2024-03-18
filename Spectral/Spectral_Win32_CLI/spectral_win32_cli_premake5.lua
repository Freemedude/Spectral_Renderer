project "Spectral_Win32_CLI"
   kind "ConsoleApp"
   language "C++"
   targetdir "%{wks.location}/../Bin"
   architecture "x64"
   files { "Code/**.cpp", "Code/**.hpp" }

   links {"Spectral_Core"}

   includedirs {
      "../Spectral_Core/Code/include"
   }
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
