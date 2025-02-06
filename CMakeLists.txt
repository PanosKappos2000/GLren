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
                src/Lighting/PointLight.cpp
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
                        "${PROJECT_SOURCE_DIR}/ExternalVendors/Glew/lib/Release/x64")

target_link_libraries(GLren PUBLIC  
                        glew32s
                        OpenGL32)


# Copy the glsl shaders to the binary directory
add_custom_target(copy_glsl_shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/Shaders ${CMAKE_CURRENT_BINARY_DIR}/Shaders
)
add_dependencies(GLren copy_glsl_shaders)

# Copy assets like textures to the binary directory
add_custom_target(copy_assets 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/Assets ${CMAKE_CURRENT_BINARY_DIR}/Assets
)
add_dependencies(GLren copy_assets)   

# Copy the glsl shaders to the target directory
add_custom_command(TARGET GLren POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:GLren>/Shaders"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_BINARY_DIR}/Shaders" "$<TARGET_FILE_DIR:GLren>/Shaders"
)

# Copy the assets folder over to the target directory
add_custom_command(TARGET GLren POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:GLren/Assets"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_BINARY_DIR}/Assets" "<TARGET_FILE_DIR:GLren>/Assets"
)