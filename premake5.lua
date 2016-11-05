workspace "ProjectRed"
	
	configurations { "Debug", "Release" }
	
	includedirs { "include" }
	
	flags { "C++11" }
	
	filter "system:macosx"
	
		buildoptions "-std=c++11 -stdlib=libc++ -F/Library/Frameworks"
		linkoptions "-stdlib=libc++"
		
		includedirs { "/opt/local/include", "/opt/local/include/freetype2", "include" }
		libdirs "/opt/local/lib"
		frameworkdirs "/Library/Frameworks/**"
		links { "OpenGL.framework", "SDL2", "png", "freetype" }
		
	filter "system:linux"
		
		buildoptions "-std=c++11"
		includedirs "/usr/include/freetype2/"
		libdirs "/usr/lib"
		links { "GL", "SDL2", "png", "freetype" }
		
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
	
	
	