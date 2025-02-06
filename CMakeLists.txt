cmake_minimum_required(VERSION 3.10)

project (GLren VERSION 0.75)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GLren 
                src/Camera/camera.cpp 
                src/Camera/camera.h 
                
                src/Entities/cube.cpp 
                src/Entities/cube.h 
                src/Entities/entity.cpp 
                src/Entities/entity.h
                
                src/Lighting/DirectionalLight.cpp 
                src/Lighting/DirectionalLight.h 
                src/Lighting/Flashlight.cpp 
                src/Lighting/FlashLight.h 
                src/Lighting/PointLight.h
                src/Lighting/SkyLight.cpp
                src/Lighting/SkyLight.h 
                src/Lighting/SpotLight.h
                
                src/Materials/Material.cpp 
                src/Materials/Material.h 
                
                src/Renderer/Renderer.cpp 
                src/Renderer/Renderer.h 
                
                src/Shader/Shader.cpp 
                src/Shader/Shader.h 

                src/Texture/texture.cpp 
                src/Texture/texture.h
                
                src/Window/window.cpp 
                src/Window/window.h
                src/Window/Events.cpp 
                src/Window/Events.h
                
                src/Source.cpp)

target_include_directories(GLren PUBLIC 
                        "${PROJECT_SOURCE_DIR}/src"
                        "${PROJECT_SOURCE_DIR}/ExternalVendors/Glew/include"
                        "${PROJECT_SOURCE_DIR}/ExternalVendors")

target_link_directories(GLren PUBLIC
                        "${PROJECT_SOURCE_DIR}/ExternalDependencies/Glew/lib/Release/x64")

target_link_libraries(GLren PUBLIC  
                        glew32s
                        OpenGL32)