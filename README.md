Project Red
===========
An open-source experimental game engine in C++
----------------------------------------------

I love making games, and I love programming, but I don't love working with existing 3D engines. I thought I might try and build my own, just for some fun.

This engine is (currently) an OpenGL based game engine that supports 2D and 3D graphics, and will eventually be a fully featured game engine with extensive tooling and utility code to manage content creation and game development. I chose C++11 as the development language because I feel most at home with it, and it will still allow considerable performance.

It is broken up into several discrete parts, which include:

  * Red: The master library, containing everything that doesn't (or shouldn't) fit into sublibraries, as well as further utility and abstractions on sublibraries.
  * SDLX: An OOP wrapper for the SDL2 multimedia library
  * Xenon: An OOP OpenGL abstraction library with 3D management and generation utilities
  * RAUX: A OOP Resource management and aquisition library.
	
You can see what i'm working on, as well as get and Idea of a typical game loop, by looking at src/Main.cpp

Dependancies
============
SDLX
----
	* SDL2
	* Xenon ( Optional )
Xenon
-----
	* OpenGL 3.2
	* Red
	* Autodesk FBX ( Eventually ) ( Optional )
RAUX
----
	* LibPNG
	* Red ( Eventually )
	* Xenon ( Optional )
RED
---
	* LibFreeType 2 ( Optional )
