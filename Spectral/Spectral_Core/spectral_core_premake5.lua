project "Spectral_Core"
   kind "SharedLib"
   language "C++"
   targetdir "%{wks.location}/../Bin"
   architecture "x64"
   files { "Code/**.cpp", "Code/**.hpp", "../Vendor/glm/include/**" }

   includedirs {
      "Code/include",
      "../Vendor/glm/include"
   }

   defines { "SPECTRAL_SHARED_LIB_EXPORT" }
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      symbols "Off"
