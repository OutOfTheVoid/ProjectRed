workspace "ProjectRed"
	
	configurations { "Debug", "Release" }
	
	flags { "C++11" }

	includedirs "include"
	
	filter "system:macosx"
	
		buildoptions "-std=c++11 -F/Library/Frameworks"
		
		includedirs { "/opt/local/include", "/opt/local/include/freetype2", "include" }
		libdirs "/opt/local/lib"
		frameworkdirs "/Library/Frameworks/**"
		links { "OpenGL.framework", "SDL2", "png", "freetype" }
		
	filter "action:xcode*"
		
		linkoptions "-stdlib=libc++"
		
	filter "system:linux"
		
		buildoptions "-std=c++11"
		includedirs "/usr/include/freetype2/"
		libdirs "/usr/lib"
		links { "GL", "SDL2", "png", "freetype" }

	filter "system:windows"

		includedirs "%HOMEPATH%/include"

		filter "configurations:Debug"

			buildoptions "/MDd /wd4250 /wd4244"

		filter "configurations:Release"

			buildoptions "/MD /wd4250 /wd4244"
		
	filter {}
	
project "AudioTest"
	
	kind "ConsoleApp"
	
	files { "src/Red/**.cpp", "src/RAUX/**.cpp", "src/Xenon/**.cpp", "src/SDLX/**.cpp", "src/AudioTestMain.cpp", "include/**.h" }
	
	filter "configurations:Debug"
		
		defines { "RED_DEBUG" }
		
	filter {}
	
project "GFXTest"

	kind "ConsoleApp"
	
	files { "src/Red/**.cpp", "src/RAUX/**.cpp", "src/Xenon/**.cpp", "src/SDLX/**.cpp", "src/GFXTestMain.cpp", "include/**.h" }
	
	filter "configurations:Debug"
		
		defines { "RED_DEBUG" }
		
	filter {}
	
	
	