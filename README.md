# Spectral

This project is a ray tracer!

I application structure like this:


 * Core: The actual ray tracer as a dynamic library
 * Win32_App: An interactive application rendering the output of Core to a window. This application would allow you to edit scenes and set configuration etc.
 * Win32_CLI: A console application rendering the output of Core to a file.

Misc resources:
* spectral_scene files, probably json files?
* Model files for models, referenced in the spectral_scene files
* 