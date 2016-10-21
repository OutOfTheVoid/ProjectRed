CXX=g++
LD=g++

LINK_FLAGS=-framework SDL2 -framework OpenGL -L/opt/local/lib -lpng -lgcc -lfreetype -march=nehalem -flto
CXX_FLAGS=$(LINK_FLAGS) -Iinclude -I/opt/local/include/freetype2 -std=c++11 -pedantic-errors -Wextra -Wall

all: build test

test: bin/Main
	./bin/Main
	
build: bin/Main
	
#MAINFILE=src/GFXTestMain.cpp
MAINFILE=src/AudioTestMain.cpp
	
OBJECTS=obj/SDLX/Lib.o \
		obj/SDLX/RefCounted.o \
		obj/SDLX/Window.o \
		obj/SDLX/Surface.o \
		obj/SDLX/Mutex.o \
		obj/SDLX/Timer.o \
		obj/SDLX/GLContext.o \
		obj/SDLX/UserEvent.o \
		obj/SDLX/Texture.o \
		obj/SDLX/Renderer.o \
		obj/SDLX/Keyboard.o \
		obj/SDLX/Mouse.o \
		obj/SDLX/AudioDevice.o \
		obj/Xenon/GPU/ShaderProgram.o \
		obj/Xenon/GPU/VertexShader.o \
		obj/Xenon/GPU/Context.o \
		obj/Xenon/GPU/FragmentShader.o \
		obj/Xenon/GPU/GeometryShader.o \
		obj/Xenon/GPU/VertexBuffer.o \
		obj/Xenon/GPU/VertexArray.o \
		obj/Xenon/GPU/IndexBuffer.o \
		obj/Xenon/GPU/Texture2D.o \
		obj/Xenon/GPU/UniformSet.o \
		obj/Xenon/GPU/FrameBuffer.o \
		obj/Xenon/Math/Transform3D.o \
		obj/Xenon/Math/RawFloatUniformSource.o \
		obj/Xenon/Math/RawVec2UniformSource.o \
		obj/Xenon/Math/RawVec4UniformSource.o \
		obj/Xenon/Math/RawVec3UniformSource.o \
		obj/Xenon/Math/Matrix3x3.o \
		obj/Xenon/Math/Vec2.o \
		obj/Xenon/Math/Transform2D.o \
		obj/Xenon/Math/Vec3.o \
		obj/Xenon/Math/Quaternion.o \
		obj/Xenon/Math/Matrix4x4.o \
		obj/Xenon/Math/Vec4.o \
		obj/Xenon/Math/RawMatrix4x4UniformSource.o \
		obj/Xenon/Math/RawMatrix3x3UniformSource.o \
		obj/Xenon/Math/ConstantUIntUniformSource.o \
		obj/Xenon/Math/ConstantIntUniformSource.o \
		obj/Xenon/Math/ConstantBoolUniformSource.o \
		obj/Xenon/Geometry/Mesh.o \
		obj/Xenon/Geometry/MeshAttributeData.o \
		obj/Xenon/Geometry/MeshAttribute.o \
		obj/Xenon/Geometry/Primitives.o \
		obj/RAUX/File.o \
		obj/RAUX/PNGFile.o \
		obj/RAUX/TextFile.o \
		obj/RAUX/ObjFile.o \
		obj/RAUX/MtlFile.o \
		obj/RAUX/StlFile.o \
		obj/RAUX/VertexShaderFile.o \
		obj/RAUX/FragmentShaderFile.o \
		obj/RAUX/WAVFile.o \
		obj/RAUX/FLACFile.o \
		obj/Red/Events/BasicEvent.o \
		obj/Red/Events/EventDispatcher.o \
		obj/Red/Threading/Thread.o \
		obj/Red/Threading/ThreadEvent.o \
		obj/Red/Threading/Time.o \
		obj/Red/Threading/Mutex.o \
		obj/Red/Text/Rendering/RawFontTextureAtlas.o \
		obj/Red/Text/Rendering/FreeType/FTLibrary.o \
		obj/Red/Text/Rendering/FreeType/FontFace.o \
		obj/Red/Text/Rendering/FontRenderData.o \
		obj/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.o \
		obj/Red/Text/Rendering/ShadedRenderer.o \
		obj/Red/Graphics/DeferredModelRenderer.o \
		obj/Red/Audio/AudioBuffer.o \
		obj/Red/Audio/EmptyAudioBufferPool.o \
		obj/Red/Math/FFT.o \
		obj/Xenon/GPU/RenderBuffer.o
	
bin/Main: obj/Main.o include/Red/Util/Endian.h
	$(LD) $(LINK_FLAGS) $(OBJECTS) obj/Main.o -o bin/Main

obj/Main.o: $(MAINFILE) $(OBJECTS)
	$(CXX) -c $(CXX_FLAGS) $(MAINFILE) -o obj/Main.o
	
# ======================== SDLX ======================== #
	
obj/SDLX/Lib.o: src/SDLX/Lib.cpp include/SDLX/Lib.h include/SDLX/SDLX.h include/SDLX/Keyboard.h include/SDLX/Mouse.h include/SDLX/UserEvent.h include/SDLX/Window.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Lib.cpp -o obj/SDLX/Lib.o
	
obj/SDLX/UserEvent.o: src/SDLX/UserEvent.cpp include/SDLX/UserEvent.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/UserEvent.cpp -o obj/SDLX/UserEvent.o
	
obj/SDLX/RefCounted.o: src/SDLX/RefCounted.cpp include/SDLX/RefCounted.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/RefCounted.cpp -o obj/SDLX/RefCounted.o
	
obj/SDLX/Window.o: src/SDLX/Window.cpp include/SDLX/Window.h include/SDLX/RefCounted.h include/SDLX/Surface.h include/SDLX/GLContext.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Window.cpp -o obj/SDLX/Window.o
	
obj/SDLX/Surface.o: src/SDLX/Surface.cpp include/SDLX/Surface.h include/SDLX/Window.h include/SDLX/RefCounted.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Surface.cpp -o obj/SDLX/Surface.o
	
obj/SDLX/Mutex.o: src/SDLX/Mutex.cpp include/SDLX/Mutex.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Mutex.cpp -o obj/SDLX/Mutex.o
	
obj/SDLX/Timer.o: src/SDLX/Timer.cpp include/SDLX/Timer.h include/SDLX/Mutex.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Timer.cpp -o obj/SDLX/Timer.o
	
obj/SDLX/Texture.o: src/SDLX/Texture.cpp include/SDLX/Texture.h include/SDLX/Surface.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Texture.cpp -o obj/SDLX/Texture.o
	
obj/SDLX/Renderer.o: src/SDLX/Renderer.cpp include/SDLX/Renderer.h include/SDLX/Window.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Renderer.cpp -o obj/SDLX/Renderer.o
	
obj/SDLX/GLContext.o: src/SDLX/GLContext.cpp include/SDLX/GLContext.h include/SDLX/Window.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/GLContext.cpp -o obj/SDLX/GLContext.o
	
obj/SDLX/Keyboard.o: src/SDLX/Keyboard.cpp include/SDLX/Keyboard.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Keyboard.cpp -o obj/SDLX/Keyboard.o
	
obj/SDLX/Mouse.o: src/SDLX/Mouse.cpp include/SDLX/Mouse.h include/SDLX/SDLX.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/Mouse.cpp -o obj/SDLX/Mouse.o
	
obj/SDLX/AudioDevice.o: src/SDLX/AudioDevice.cpp include/SDLX/AudioDevice.h include/SDLX/SDLX.h include/Red/Audio/Audio.h include/Red/Audio/IAudioOutputDevice.h
	$(CXX) -c $(CXX_FLAGS) src/SDLX/AudioDevice.cpp -o obj/SDLX/AudioDevice.o
	
# ======================== XENON ======================= #
	
obj/Xenon/GPU/ShaderProgram.o: src/Xenon/GPU/ShaderProgram.cpp include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/ShaderProgram.cpp -o obj/Xenon/GPU/ShaderProgram.o
	
obj/Xenon/GPU/VertexShader.o: src/Xenon/GPU/VertexShader.cpp include/Xenon/GPU/VertexShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexShader.cpp -o obj/Xenon/GPU/VertexShader.o
	
obj/Xenon/GPU/FragmentShader.o: src/Xenon/GPU/FragmentShader.cpp include/Xenon/GPU/FragmentShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/FragmentShader.cpp -o obj/Xenon/GPU/FragmentShader.o
	
obj/Xenon/GPU/GeometryShader.o: src/Xenon/GPU/GeometryShader.cpp include/Xenon/GPU/GeometryShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/GeometryShader.cpp -o obj/Xenon/GPU/GeometryShader.o

obj/Xenon/GPU/VertexBuffer.o: src/Xenon/GPU/VertexBuffer.cpp include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexBuffer.cpp -o obj/Xenon/GPU/VertexBuffer.o
	
obj/Xenon/GPU/IndexBuffer.o: src/Xenon/GPU/IndexBuffer.cpp include/Xenon/GPU/IndexBuffer.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/IndexBuffer.cpp -o obj/Xenon/GPU/IndexBuffer.o
	
obj/Xenon/GPU/VertexArray.o: src/Xenon/GPU/VertexArray.cpp include/Xenon/GPU/VertexArray.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/IGPUResourceUser.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexArray.cpp -o obj/Xenon/GPU/VertexArray.o
	
obj/Xenon/GPU/Context.o: src/Xenon/GPU/Context.cpp include/Xenon/GPU/Context.h include/Xenon/GPU/IGLContext.h include/Xenon/Xenon.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/FrameBuffer.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/Context.cpp -o obj/Xenon/GPU/Context.o
	
obj/Xenon/GPU/Texture2D.o: include/Xenon/GPU/Texture2D.h src/Xenon/GPU/Texture2D.cpp include/Xenon/Xenon.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/ITexture.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/Texture2D.cpp -o obj/Xenon/GPU/Texture2D.o
	
obj/Xenon/GPU/FrameBuffer.o: include/Xenon/GPU/FrameBuffer.h src/Xenon/GPU/FrameBuffer.cpp include/Xenon/Xenon.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLInclude.h include/Red/Util/RefCounted.h include/Xenon/GPU/Context.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/FrameBuffer.cpp -o obj/Xenon/GPU/FrameBuffer.o
	
obj/Xenon/GPU/UniformSet.o: include/Xenon/GPU/UniformSet.h src/Xenon/GPU/UniformSet.cpp include/Xenon/Xenon.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/IMatrix3x3UniformSource.h include/Xenon/GPU/IMatrix4x4UniformSource.h include/Xenon/GPU/IFloatUniformSource.h include/Xenon/GPU/IFloatVec2UniformSource.h include/Xenon/GPU/IFloatVec3UniformSource.h include/Xenon/GPU/IFloatVec4UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/UniformSet.cpp -o obj/Xenon/GPU/UniformSet.o
	
obj/Xenon/GPU/RenderBuffer.o: include/Xenon/GPU/RenderBuffer.h src/Xenon/GPU/RenderBuffer.cpp include/Xenon/Xenon.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLInclude.h include/Red/Util/RefCounted.h include/Xenon/GPU/Context.h include/Xenon/GPU/Texture2D.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/RenderBuffer.cpp -o obj/Xenon/GPU/RenderBuffer.o
	
obj/Xenon/Math/Vec2.o: include/Xenon/Math/Vec2.h src/Xenon/Math/Vec2.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec2.cpp -o obj/Xenon/Math/Vec2.o
	
obj/Xenon/Math/Vec3.o: include/Xenon/Math/Vec3.h src/Xenon/Math/Vec3.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec3.cpp -o obj/Xenon/Math/Vec3.o
	
obj/Xenon/Math/Vec4.o: include/Xenon/Math/Vec4.h src/Xenon/Math/Vec4.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h include/Xenon/SSE.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec4.cpp -o obj/Xenon/Math/Vec4.o

obj/Xenon/Math/RawFloatUniformSource.o: include/Xenon/Math/RawFloatUniformSource.h src/Xenon/Math/RawFloatUniformSource.cpp include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatUniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawFloatUniformSource.cpp -o obj/Xenon/Math/RawFloatUniformSource.o
	
obj/Xenon/Math/RawVec2UniformSource.o: include/Xenon/Math/RawVec2UniformSource.h src/Xenon/Math/RawVec2UniformSource.cpp include/Xenon/Math/Vec2.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec2UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec2UniformSource.cpp -o obj/Xenon/Math/RawVec2UniformSource.o
	
obj/Xenon/Math/RawVec4UniformSource.o: include/Xenon/Math/RawVec4UniformSource.h src/Xenon/Math/RawVec4UniformSource.cpp include/Xenon/Math/Vec4.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec4UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec4UniformSource.cpp -o obj/Xenon/Math/RawVec4UniformSource.o
	
obj/Xenon/Math/RawVec3UniformSource.o: include/Xenon/Math/RawVec3UniformSource.h src/Xenon/Math/RawVec3UniformSource.cpp include/Xenon/Math/Vec3.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec3UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec3UniformSource.cpp -o obj/Xenon/Math/RawVec3UniformSource.o
	
obj/Xenon/Math/Transform3D.o: include/Xenon/Math/Transform3D.h src/Xenon/Math/Transform3D.cpp include/Xenon/Math/Quaternion.h include/Xenon/Math/Vec3.h include/Xenon/Math/Matrix4x4.h include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/GPU/IMatrix4x4UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Transform3D.cpp -o obj/Xenon/Math/Transform3D.o
	
obj/Xenon/Math/Quaternion.o: include/Xenon/Math/Quaternion.h src/Xenon/Math/Quaternion.cpp include/Xenon/Math/Vec3.h include/Xenon/Xenon.h include/Xenon/SSE.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Quaternion.cpp -o obj/Xenon/Math/Quaternion.o
	
obj/Xenon/Math/Matrix4x4.o: include/Xenon/Math/Matrix4x4.h src/Xenon/Math/Matrix4x4.cpp include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/Math/Vec4.h include/Xenon/Math/Vec3.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Matrix4x4.cpp -o obj/Xenon/Math/Matrix4x4.o
	
obj/Xenon/Math/Matrix3x3.o: include/Xenon/Math/Matrix3x3.h src/Xenon/Math/Matrix3x3.cpp include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/Math/Vec3.h include/Xenon/Math/Vec2.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Matrix3x3.cpp -o obj/Xenon/Math/Matrix3x3.o
	
obj/Xenon/Math/Transform2D.o: include/Xenon/Math/Transform2D.h src/Xenon/Math/Transform2D.cpp include/Xenon/Math/Vec3.h include/Xenon/Math/Matrix3x3.h include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/GPU/IMatrix3x3UniformSource.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Transform2D.cpp -o obj/Xenon/Math/Transform2D.o
	
obj/Xenon/Math/RawMatrix4x4UniformSource.o: include/Xenon/Math/RawMatrix4x4UniformSource.h src/Xenon/Math/RawMatrix4x4UniformSource.cpp include/Xenon/GPU/IMatrix4x4UniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLinclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawMatrix4x4UniformSource.cpp -o obj/Xenon/Math/RawMatrix4x4UniformSource.o
	
obj/Xenon/Geometry/Mesh.o: include/Xenon/Geometry/Mesh.h src/Xenon/Geometry/Mesh.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/IndexBuffer.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLinclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/Mesh.cpp -o obj/Xenon/Geometry/Mesh.o

obj/Xenon/Geometry/MeshAttribute.o: include/Xenon/Geometry/MeshAttribute.h src/Xenon/Geometry/MeshAttribute.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/VertexArray.h include/Xenon/GPU/GLinclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/MeshAttribute.cpp -o obj/Xenon/Geometry/MeshAttribute.o
	
obj/Xenon/Geometry/MeshAttributeData.o: include/Xenon/Geometry/MeshAttributeData.h src/Xenon/Geometry/MeshAttributeData.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/GLinclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/MeshAttributeData.cpp -o obj/Xenon/Geometry/MeshAttributeData.o
	
obj/Xenon/Geometry/Primitives.o: include/Xenon/Geometry/Primitives.h src/Xenon/Geometry/Primitives.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/GLinclude.h include/Xenon/Geometry/Mesh.h include/Xenon/Geometry/MeshAttribute.h include/Xenon/Geometry/MeshAttributeData.h include/Xenon/Math/Quaternion.h include/Xenon/Math/Vec3.h include/Xenon/Math/Vec2.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/Primitives.cpp -o obj/Xenon/Geometry/Primitives.o
	
obj/Xenon/Math/RawMatrix3x3UniformSource.o: include/Xenon/Math/RawMatrix3x3UniformSource.h src/Xenon/Math/RawMatrix3x3UniformSource.cpp include/Xenon/GPU/IMatrix3x3UniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLinclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawMatrix3x3UniformSource.cpp -o obj/Xenon/Math/RawMatrix3x3UniformSource.o
	
obj/Xenon/Math/ConstantUIntUniformSource.o: include/Xenon/Math/ConstantUIntUniformSource.h src/Xenon/Math/ConstantUIntUniformSource.cpp include/Xenon/GPU/IUIntUniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLInclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/ConstantUIntUniformSource.cpp -o obj/Xenon/Math/ConstantUIntUniformSource.o
	
obj/Xenon/Math/ConstantIntUniformSource.o: include/Xenon/Math/ConstantIntUniformSource.h src/Xenon/Math/ConstantIntUniformSource.cpp include/Xenon/GPU/IIntUniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLInclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/ConstantIntUniformSource.cpp -o obj/Xenon/Math/ConstantIntUniformSource.o
	
obj/Xenon/Math/ConstantBoolUniformSource.o: include/Xenon/Math/ConstantBoolUniformSource.h src/Xenon/Math/ConstantBoolUniformSource.cpp include/Xenon/GPU/IBoolUniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLInclude.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/ConstantBoolUniformSource.cpp -o obj/Xenon/Math/ConstantBoolUniformSource.o
	
# ======================== RAUX ======================== #
	
obj/RAUX/File.o: include/RAUX/File.h src/RAUX/File.cpp include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/File.cpp -o obj/RAUX/File.o
	
obj/RAUX/PNGFile.o: include/RAUX/PNGFile.h src/RAUX/PNGFile.cpp include/RAUX/RAUX.h include/RAUX/File.h 
	$(CXX) -c $(CXX_FLAGS) src/RAUX/PNGFile.cpp -o obj/RAUX/PNGFile.o
	
obj/RAUX/TextFile.o: include/RAUX/TextFile.h src/RAUX/TextFile.cpp include/RAUX/File.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/TextFile.cpp -o obj/RAUX/TextFile.o
	
obj/RAUX/ObjFile.o: include/RAUX/ObjFile.h src/RAUX/ObjFile.cpp include/RAUX/MtlFile.h include/RAUX/TextFile.h include/RAUX/RAUX.h include/Xenon/Math/Vec3.h include/Xenon/Geometry/Mesh.h include/Xenon/Geometry/MeshAttribute.h include/Xenon/Geometry/MeshAttributeData.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/ObjFile.cpp -o obj/RAUX/ObjFile.o
	
obj/RAUX/MtlFile.o: include/RAUX/MtlFile.h src/RAUX/MtlFile.cpp include/RAUX/TextFile.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/MtlFile.cpp -o obj/RAUX/MtlFile.o
	
obj/RAUX/StlFile.o: include/RAUX/StlFile.h src/RAUX/StlFile.cpp include/RAUX/File.h include/RAUX/RAUX.h include/Xenon/Math/Vec3.h include/Xenon/Geometry/Mesh.h include/Xenon/Geometry/MeshAttribute.h include/Xenon/Geometry/MeshAttributeData.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/StlFile.cpp -o obj/RAUX/StlFile.o
	
obj/RAUX/VertexShaderFile.o: include/RAUX/VertexShaderFile.h src/RAUX/VertexShaderFile.cpp include/RAUX/TextFile.h include/RAUX/RAUX.h include/Xenon/GPU/VertexShader.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/VertexShaderFile.cpp -o obj/RAUX/VertexShaderFile.o
	
obj/RAUX/FragmentShaderFile.o: include/RAUX/FragmentShaderFile.h src/RAUX/FragmentShaderFile.cpp include/RAUX/TextFile.h include/RAUX/RAUX.h include/Xenon/GPU/FragmentShader.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/FragmentShaderFile.cpp -o obj/RAUX/FragmentShaderFile.o
	
obj/RAUX/WAVFile.o: include/RAUX/File.h include/RAUX/WAVFile.h src/RAUX/WAVFile.cpp include/Red/Audio/Audio.h include/RAUX/RAUX.h include/Red/Util/Endian.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/WAVFile.cpp -o obj/RAUX/WAVFile.o
	
obj/RAUX/FLACFile.o: include/RAUX/File.h include/RAUX/FLACFile.h src/RAUX/FLACFile.cpp include/Red/Audio/Audio.h include/Red/Util/Endian.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/FLACFile.cpp -o obj/RAUX/FLACFile.o
	
# ========================= Red ======================== #

obj/Red/Events/BasicEvent.o: include/Red/Red.h include/Red/Events/Events.h include/Red/Events/IEvent.h include/Red/Events/BasicEvent.h src/Red/Events/BasicEvent.cpp
	$(CXX) -c $(CXX_FLAGS) src/Red/Events/BasicEvent.cpp -o obj/Red/Events/BasicEvent.o
	
obj/Red/Events/EventDispatcher.o: include/Red/Red.h include/Red/Events/Events.h include/Red/Events/IEvent.h include/Red/Events/IEventDispatcher.h include/Red/Events/EventDispatcher.h src/Red/Events/EventDispatcher.cpp
	$(CXX) -c $(CXX_FLAGS) src/Red/Events/EventDispatcher.cpp -o obj/Red/Events/EventDispatcher.o
	
obj/Red/Threading/Thread.o: include/Red/Threading/Thread.h src/Red/Threading/Thread.cpp include/Red/Threading/ThreadEvent.h include/Red/Threading/Threading.h include/Red/Events/IEvent.h include/Red/Events/IEventDispatcher.h include/Red/Events/EventDispatcher.h include/Red/Util/Function.h include/Red/Red.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Threading/Thread.cpp -o obj/Red/Threading/Thread.o
	
obj/Red/Threading/Mutex.o: include/Red/Threading/Mutex.h src/Red/Threading/Mutex.cpp include/Red/Threading/Threading.h include/Red/Red.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Threading/Mutex.cpp -o obj/Red/Threading/Mutex.o
	
obj/Red/Threading/ThreadEvent.o: include/Red/Threading/ThreadEvent.h src/Red/Threading/ThreadEvent.cpp include/Red/Threading/Thread.h include/Red/Threading/Threading.h include/Red/Events/IEvent.h include/Red/Events/BasicEvent.h include/Red/Red.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Threading/ThreadEvent.cpp -o obj/Red/Threading/ThreadEvent.o
	
obj/Red/Threading/Time.o: include/Red/Threading/Time.h src/Red/Threading/Time.cpp include/Red/Threading/Threading.h include/Red/Red.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Threading/Time.cpp -o obj/Red/Threading/Time.o
	
obj/Red/Text/Rendering/RawFontTextureAtlas.o: include/Red/Text/Rendering/RawFontTextureAtlas.h src/Red/Text/Rendering/RawFontTextureAtlas.cpp  include/Red/Text/Rendering/Rendering.h include/Red/Text/Text.h include/Red/Red.h include/Red/Options.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/RawFontTextureAtlas.cpp -o obj/Red/Text/Rendering/RawFontTextureAtlas.o
	
obj/Red/Text/Rendering/FreeType/FTLibrary.o: include/Red/Text/Rendering/FreeType/FTLibrary.h src/Red/Text/Rendering/FreeType/FTLibrary.cpp include/Red/Text/Rendering/FreeType/FreeType.h include/Red/Text/Rendering/Rendering.h include/Red/Text/Text.h include/Red/Red.h include/Red/Options.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/FreeType/FTLibrary.cpp -o obj/Red/Text/Rendering/FreeType/FTLibrary.o
	
obj/Red/Text/Rendering/FreeType/FontFace.o: include/Red/Text/Rendering/FreeType/FTLibrary.h include/Red/Text/Rendering/FreeType/FontFace.h include/Red/Text/Rendering/FreeType/FreeType.h include/Red/Text/Rendering/Rendering.h include/Red/Text/Text.h include/Red/Red.h include/Red/Options.h include/Red/Util/RCMem.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/FreeType/FontFace.cpp -o obj/Red/Text/Rendering/FreeType/FontFace.o
	
obj/Red/Text/Rendering/FontRenderData.o: include/Red/Text/Rendering/FontRenderData.h src/Red/Text/Rendering/FontRenderData.cpp include/Red/Text/Rendering/Rendering.h include/Red/Text/Text.h include/Red/Red.h include/Red/Util/RefCounted.h include/Red/Text/Rendering/IFontLayoutSource.h include/Red/Text/Rendering/IFontReference.h include/Red/Text/Rendering/IFontTextureAtlasFactory.h include/Red/Text/Rendering/RawFontTextureAtlas.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/FontRenderData.cpp -o obj/Red/Text/Rendering/FontRenderData.o
	
obj/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.o: include/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.h src/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.cpp include/Red/Text/Rendering/FontRenderData.h include/Red/Text/Rendering/FreeType/FreeType.h include/Red/Text/Rendering/FreeType/FontFace.h include/Red/Text/Rendering/Rendering.h include/Red/Text/Text.h include/Red/Red.h include/Red/Util/RefCounted.h include/Red/Text/Rendering/IFontLayoutSource.h include/Red/Text/Rendering/IFontReference.h include/Red/Text/Rendering/IFontTextureAtlasFactory.h include/Red/Text/Rendering/RawFontTextureAtlas.h include/Red/Options.h include/Red/Util/RCMem.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.cpp -o obj/Red/Text/Rendering/FreeType/FreeTypeFontRenderData.o
	
obj/Red/Text/Rendering/ShadedRenderer.o: include/Red/Text/Rendering/ShadedRenderer.h src/Red/Text/Rendering/ShadedRenderer.cpp include/Red/Text/Rendering/Rendering.h include/Red/Text/Rendering/FontRenderData.h include/Xenon/Geometry/Mesh.h include/Xenon/Geometry/Primitives.h include/Xenon/Math/Matrix3x3.h include/Xenon/Math/Vec4.h include/Xenon/Math/Vec2.h include/Xenon/Math/RawVec4UniformSource.h include/Xenon/Math/RawFloatUniformSource.h include/Xenon/Math/RawMatrix3x3UniformSource.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/VertexShader.h include/Xenon/GPU/FragmentShader.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/UniformSet.h include/Xenon/GPU/FrameBuffer.h include/Xenon/GPU/VertexArray.h include/Xenon/GPU/Texture2D.h include/Red/Util/RefCounted.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Text/Rendering/ShadedRenderer.cpp -o obj/Red/Text/Rendering/ShadedRenderer.o

obj/Red/Graphics/DeferredModelRenderer.o: include/Red/Graphics/DeferredModelRenderer.h src/Red/Graphics/DeferredModelRenderer.cpp include/Xenon/GPU/Context.h include/Xenon/Math/Vec2.h include/Xenon/GPU/RenderBuffer.h include/Xenon/GPU/VertexArray.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/FrameBuffer.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/UniformSet.h include/Xenon/GPU/VertexShader.h include/Xenon/GPU/FragmentShader.h include/Xenon/GPU/Texture2D.h include/Xenon/Geometry/Mesh.h include/Red/Graphics/Graphics.h include/Red/Red.h include/Xenon/Math/RawMatrix4x4UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Graphics/DeferredModelRenderer.cpp -o obj/Red/Graphics/DeferredModelRenderer.o
	
obj/Red/Audio/AudioBuffer.o: include/Red/Audio/Audio.h include/Red/Audio/AudioBuffer.h src/Red/Audio/AudioBuffer.cpp include/Red/Util/RefCounted.h include/Red/Util/Function.h include/Red/Util/SSE.h
	$(CXX) -c $(CXX_FLAGS) src/Red/Audio/AudioBuffer.cpp -o obj/Red/Audio/AudioBuffer.o
	
obj/Red/Audio/EmptyAudioBufferPool.o: include/Red/Audio/Audio.h include/Red/Audio/EmptyAudioBufferPool.h src/Red/Audio/EmptyAudioBufferPool.cpp include/Red/Util/RefCounted.h include/Red/Util/MethodObjectClosure.h 
	$(CXX) -c $(CXX_FLAGS) src/Red/Audio/EmptyAudioBufferPool.cpp -o obj/Red/Audio/EmptyAudioBufferPool.o
	
obj/Red/Math/FFT.o: include/Red/Math/Math.h include/Red/Math/FFT.h src/Red/Math/FFT.cpp
	$(CXX) -c $(CXX_FLAGS) src/Red/Math/FFT.cpp -o obj/Red/Math/FFT.o
	
clean:
	-@rm -r obj/*
	-@rm bin/main
	-@mkdir obj/SDLX
	-@mkdir obj/Xenon
	-@mkdir obj/Xenon/Math
	-@mkdir obj/Xenon/GPU
	-@mkdir obj/Xenon/Geometry
	-@mkdir obj/Xenon/Rendering
	-@mkdir obj/RAUX
	-@mkdir obj/Red
	-@mkdir obj/Red/Events
	-@mkdir obj/Red/Audio
	-@mkdir obj/Red/Graphics
	-@mkdir obj/Red/Threading
	-@mkdir obj/Red/Math
	-@mkdir obj/Red/Text
	-@mkdir obj/Red/Text/Rendering
	-@mkdir obj/Red/Text/Rendering/FreeType
	