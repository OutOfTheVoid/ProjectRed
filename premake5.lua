workspace "ProjectRed"
	
	configurations { "Debug", "Release" }
	
	includedirs { "include" }
	
	flags { "C++11" }
	
	filter "system:macosx"
		
		includedirs { "/opt/local/include", "/opt/local/include/freetype2", "include" }
		libdirs { "/opt/local/lib" }
		frameworkdirs { "/Library/Frameworks/**"}
		links { "OpenGL.framework", "SDL2.framework", "png", "freetype" }
		
	filter {}
	
project "AudioTest"
	
	kind "ConsoleApp"
	
	files { "src/Red/**.cpp", "src/RAUX/**.cpp", "src/Xenon/**.cpp", "src/SDLX/**.cpp", "src/AudioTestMain.cpp" }
	
	filter "configurations:Debug"
		
		defines { "RED_DEBUG" }
		
	filter {}
	
project "GFXTest"

	kind "ConsoleApp"
	
	files { "src/Red/**.cpp", "src/RAUX/**.cpp", "src/Xenon/**.cpp", "src/SDLX/**.cpp", "src/GFXTestMain.cpp" }
	
	filter "configurations:Debug"
		
		defines { "RED_DEBUG" }
		
	filter {}
	
	
	