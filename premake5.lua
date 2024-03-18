workspace "Spectral"
   configurations { "Debug", "Release" }
   platforms {"X64"}
   location "_Out/%{wks.name}"
   cppdialect "C++20"

   startproject "Spectral_Win32_CLI"


include "Spectral/Spectral_Win32_CLI/spectral_win32_cli_premake5.lua"
include "Spectral/Spectral_Core/spectral_core_premake5.lua"
