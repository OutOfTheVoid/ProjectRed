CXX=g++-mp-4.9
LD=g++-mp-4.9

LINK_FLAGS=-framework SDL2 -framework OpenGL -L/opt/local/lib -lpng -lgcc -march=nehalem -flto
CXX_FLAGS=$(LINK_FLAGS) -Iinclude -std=c++11

all: build test

test: bin/main
	./bin/main
	
build: bin/main
	
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
		obj/Xenon/Geometry/Mesh.o \
		obj/Xenon/Geometry/MeshAttributeData.o \
		obj/Xenon/Geometry/MeshAttribute.o \
		obj/Xenon/Geometry/Primitives.o \
		obj/RAUX/File.o \
		obj/RAUX/PNGFile.o \
		obj/RAUX/TextFile.o \
		obj/RAUX/ObjFile.o \
		obj/RAUX/MtlFile.o
	
bin/main: obj/Main.o
	$(LD) $(LINK_FLAGS) $(OBJECTS) obj/Main.o -o bin/Main

obj/Main.o: src/Main.cpp $(OBJECTS)
	$(CXX) -c $(CXX_FLAGS) src/Main.cpp -o obj/Main.o
	
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
	
# ======================== XENON ======================= #
	
obj/Xenon/GPU/ShaderProgram.o: src/Xenon/GPU/ShaderProgram.cpp include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/ShaderProgram.cpp -o obj/Xenon/GPU/ShaderProgram.o
	
obj/Xenon/GPU/VertexShader.o: src/Xenon/GPU/VertexShader.cpp include/Xenon/GPU/VertexShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexShader.cpp -o obj/Xenon/GPU/VertexShader.o
	
obj/Xenon/GPU/FragmentShader.o: src/Xenon/GPU/FragmentShader.cpp include/Xenon/GPU/FragmentShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/FragmentShader.cpp -o obj/Xenon/GPU/FragmentShader.o
	
obj/Xenon/GPU/GeometryShader.o: src/Xenon/GPU/GeometryShader.cpp include/Xenon/GPU/GeometryShader.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/IShader.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/GeometryShader.cpp -o obj/Xenon/GPU/GeometryShader.o

obj/Xenon/GPU/VertexBuffer.o: src/Xenon/GPU/VertexBuffer.cpp include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexBuffer.cpp -o obj/Xenon/GPU/VertexBuffer.o
	
obj/Xenon/GPU/IndexBuffer.o: src/Xenon/GPU/IndexBuffer.cpp include/Xenon/GPU/IndexBuffer.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/IndexBuffer.cpp -o obj/Xenon/GPU/IndexBuffer.o
	
obj/Xenon/GPU/VertexArray.o: src/Xenon/GPU/VertexArray.cpp include/Xenon/GPU/VertexArray.h include/Xenon/GPU/GLInclude.h include/Xenon/Xenon.h include/Xenon/GPU/Context.h include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/IGPUResourceUser.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/VertexArray.cpp -o obj/Xenon/GPU/VertexArray.o
	
obj/Xenon/GPU/Context.o: src/Xenon/GPU/Context.cpp include/Xenon/GPU/Context.h include/Xenon/GPU/IGLContext.h include/Xenon/Xenon.h include/Xenon/GPU/ShaderProgram.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/FrameBuffer.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/Context.cpp -o obj/Xenon/GPU/Context.o
	
obj/Xenon/GPU/Texture2D.o: include/Xenon/GPU/Texture2D.h src/Xenon/GPU/Texture2D.cpp include/Xenon/Xenon.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/ITexture.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/Texture2D.cpp -o obj/Xenon/GPU/Texture2D.o
	
obj/Xenon/GPU/FrameBuffer.o: include/Xenon/GPU/FrameBuffer.h src/Xenon/GPU/FrameBuffer.cpp include/Xenon/Xenon.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLInclude.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/FrameBuffer.cpp -o obj/Xenon/GPU/FrameBuffer.o
	
obj/Xenon/GPU/UniformSet.o: include/Xenon/GPU/UniformSet.h src/Xenon/GPU/UniformSet.cpp include/Xenon/Xenon.h include/Xenon/GPU/GLInclude.h include/Xenon/GPU/IMatrix3x3UniformSource.h include/Xenon/GPU/IMatrix4x4UniformSource.h include/Xenon/GPU/IFloatUniformSource.h include/Xenon/GPU/IFloatVec2UniformSource.h include/Xenon/GPU/IFloatVec3UniformSource.h include/Xenon/GPU/IFloatVec4UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/GPU/UniformSet.cpp -o obj/Xenon/GPU/UniformSet.o
	
obj/Xenon/Math/Vec2.o: include/Xenon/Math/Vec2.h src/Xenon/Math/Vec2.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec2.cpp -o obj/Xenon/Math/Vec2.o
	
obj/Xenon/Math/Vec3.o: include/Xenon/Math/Vec3.h src/Xenon/Math/Vec3.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h 
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec3.cpp -o obj/Xenon/Math/Vec3.o
	
obj/Xenon/Math/Vec4.o: include/Xenon/Math/Vec4.h src/Xenon/Math/Vec4.cpp include/Xenon/Math/Quaternion.h include/Xenon/Xenon.h include/Xenon/SSE.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Vec4.cpp -o obj/Xenon/Math/Vec4.o

obj/Xenon/Math/RawFloatUniformSource.o: include/Xenon/Math/RawFloatUniformSource.h src/Xenon/Math/RawFloatUniformSource.cpp include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatUniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawFloatUniformSource.cpp -o obj/Xenon/Math/RawFloatUniformSource.o
	
obj/Xenon/Math/RawVec2UniformSource.o: include/Xenon/Math/RawVec2UniformSource.h src/Xenon/Math/RawVec2UniformSource.cpp include/Xenon/Math/Vec2.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec2UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec2UniformSource.cpp -o obj/Xenon/Math/RawVec2UniformSource.o
	
obj/Xenon/Math/RawVec4UniformSource.o: include/Xenon/Math/RawVec4UniformSource.h src/Xenon/Math/RawVec4UniformSource.cpp include/Xenon/Math/Vec4.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec4UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec4UniformSource.cpp -o obj/Xenon/Math/RawVec4UniformSource.o
	
obj/Xenon/Math/RawVec3UniformSource.o: include/Xenon/Math/RawVec3UniformSource.h src/Xenon/Math/RawVec3UniformSource.cpp include/Xenon/Math/Vec3.h include/Xenon/Xenon.h include/Xenon/GPU/GLinclude.h include/Xenon/Math/Math.h include/Xenon/GPU/IFloatVec3UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawVec3UniformSource.cpp -o obj/Xenon/Math/RawVec3UniformSource.o
	
obj/Xenon/Math/Transform3D.o: include/Xenon/Math/Transform3D.h src/Xenon/Math/Transform3D.cpp include/Xenon/Math/Quaternion.h include/Xenon/Math/Vec3.h include/Xenon/Math/Matrix4x4.h include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/GPU/IMatrix4x4UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Transform3D.cpp -o obj/Xenon/Math/Transform3D.o
	
obj/Xenon/Math/Quaternion.o: include/Xenon/Math/Quaternion.h src/Xenon/Math/Quaternion.cpp include/Xenon/Math/Vec3.h include/Xenon/Xenon.h include/Xenon/SSE.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Quaternion.cpp -o obj/Xenon/Math/Quaternion.o
	
obj/Xenon/Math/Matrix4x4.o: include/Xenon/Math/Matrix4x4.h src/Xenon/Math/Matrix4x4.cpp include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/Math/Vec4.h include/Xenon/Math/Vec3.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Matrix4x4.cpp -o obj/Xenon/Math/Matrix4x4.o
	
obj/Xenon/Math/Matrix3x3.o: include/Xenon/Math/Matrix3x3.h src/Xenon/Math/Matrix3x3.cpp include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/Math/Vec3.h include/Xenon/Math/Vec2.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Matrix3x3.cpp -o obj/Xenon/Math/Matrix3x3.o
	
obj/Xenon/Math/Transform2D.o: include/Xenon/Math/Transform2D.h src/Xenon/Math/Transform2D.cpp include/Xenon/Math/Vec3.h include/Xenon/Math/Matrix3x3.h include/Xenon/Xenon.h include/Xenon/SSE.h include/Xenon/GPU/IMatrix3x3UniformSource.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/Transform2D.cpp -o obj/Xenon/Math/Transform2D.o
	
obj/Xenon/Math/RawMatrix4x4UniformSource.o: include/Xenon/Math/RawMatrix4x4UniformSource.h src/Xenon/Math/RawMatrix4x4UniformSource.cpp include/Xenon/GPU/IMatrix4x4UniformSource.h include/Xenon/Math/Math.h include/Xenon/GPU/GLinclude.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Math/RawMatrix4x4UniformSource.cpp -o obj/Xenon/Math/RawMatrix4x4UniformSource.o
	
obj/Xenon/Geometry/Mesh.o: include/Xenon/Geometry/Mesh.h src/Xenon/Geometry/Mesh.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/IndexBuffer.h include/Xenon/GPU/IGPUResourceUser.h include/Xenon/GPU/GLinclude.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/Mesh.cpp -o obj/Xenon/Geometry/Mesh.o

obj/Xenon/Geometry/MeshAttribute.o: include/Xenon/Geometry/MeshAttribute.h src/Xenon/Geometry/MeshAttribute.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/VertexArray.h include/Xenon/GPU/GLinclude.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/MeshAttribute.cpp -o obj/Xenon/Geometry/MeshAttribute.o
	
obj/Xenon/Geometry/MeshAttributeData.o: include/Xenon/Geometry/MeshAttributeData.h src/Xenon/Geometry/MeshAttributeData.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/VertexBuffer.h include/Xenon/GPU/GLinclude.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/MeshAttributeData.cpp -o obj/Xenon/Geometry/MeshAttributeData.o
	
obj/Xenon/Geometry/Primitives.o: include/Xenon/Geometry/Primitives.h src/Xenon/Geometry/Primitives.cpp include/Xenon/Xenon.h include/Xenon/Geometry/Geometry.h include/Xenon/GPU/GLinclude.h include/Xenon/Geometry/Mesh.h include/Xenon/Geometry/MeshAttribute.h include/Xenon/Geometry/MeshAttributeData.h include/Xenon/Math/Quaternion.h include/Xenon/Math/Vec3.h include/Xenon/Math/Vec2.h
	$(CXX) -c $(CXX_FLAGS) src/Xenon/Geometry/Primitives.cpp -o obj/Xenon/Geometry/Primitives.o
	
# ======================== RAUX ======================== #
	
obj/RAUX/File.o: include/RAUX/File.h src/RAUX/File.cpp include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/File.cpp -o obj/RAUX/File.o
	
obj/RAUX/PNGFile.o: include/RAUX/PNGFile.h src/RAUX/PNGFile.cpp include/RAUX/RAUX.h include/RAUX/File.h 
	$(CXX) -c $(CXX_FLAGS) src/RAUX/PNGFile.cpp -o obj/RAUX/PNGFile.o
	
obj/RAUX/TextFile.o: include/RAUX/TextFile.h src/RAUX/TextFile.cpp include/RAUX/File.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/TextFile.cpp -o obj/RAUX/TextFile.o
	
obj/RAUX/ObjFile.o: include/RAUX/ObjFile.h src/RAUX/ObjFile.cpp include/RAUX/MtlFile.h include/RAUX/TextFile.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/ObjFile.cpp -o obj/RAUX/ObjFile.o
	
obj/RAUX/MtlFile.o: include/RAUX/MtlFile.h src/RAUX/MtlFile.cpp include/RAUX/TextFile.h include/RAUX/RAUX.h
	$(CXX) -c $(CXX_FLAGS) src/RAUX/MtlFile.cpp -o obj/RAUX/MtlFile.o
	
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
	