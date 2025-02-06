#include "Camera/camera.h"
#include "Window/Events.h"
#include "Shader/Shader.h"
#include "Entities/cube.h"
#include "Renderer/Renderer.h"

#include <vector>

int main()
{
	// Start the event and input systems (ported from BlitzenEngine0, constructor does all the work)
	EventSystemState eventSystem;
	InputSystemState inputSystem;

	// Create the window and the opengl draw context
	PlatformStartup("GLren", 100, 100, 1280, 768);
	CreateOpenglDrawContext();

	// Register default event like window closing and camera movement
	RegisterDefaultEvents();

	// Allocate the camera with a unique pointer
	std::unique_ptr<Camera> camera = std::make_unique<Camera>(sizeof(Camera));

	// Allocate the renderer with a unique pointer and compile the required shaders
	std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
	Shader::Init();

	// Reserve space for the entities that will be allocated
	renderer->ReserveEntities(15);

	// Add rotating cubes
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(0.0f, 0.0f, 0.0f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(1.0f, -2.2f, -6.3f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(2.2f, -2.1, -3.4f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-3.7f, -4.0f, -8.9f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-2.7f, -2.0f, -7.2f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-4.7f, 4.0f, -11.5f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-1.7f, 2.4f, -6.9f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(2.2f, 2.5f, -13.1f));
	renderer->AddRotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(0.7f, 3.9f, -6.3f));

	// Add light cubes
	renderer->AddLightCube();
	renderer->AddLightCube(glm::vec3(8.0f, 6.0f, -4.0f));
	renderer->AddLightCube(glm::vec3(8.0f, 6.0f, -8.0f));
	renderer->AddLightCube(glm::vec3(-8.0f, 6.0f, -4.0f));
	renderer->AddLightCube(glm::vec3(-8.5f, 6.0f, -8.0f));

	// Give materials to the rotating cubes
	Material mat1(MaterialType::MT_BlackPlastic);
	renderer->GetRotatingCube(2)->SetMaterial(mat1);
	Material mat2(MaterialType::MT_Ruby);
	renderer->GetRotatingCube(3)->SetMaterial(mat2);
	Material mat3(MaterialType::MT_Obsidian);
	renderer->GetRotatingCube(4)->SetMaterial(mat3);
	Material mat4(MaterialType::MT_Silver);
	renderer->GetRotatingCube(5)->SetMaterial(mat4);
	Material mat5(MaterialType::MT_Gold);
	renderer->GetRotatingCube(6)->SetMaterial(mat5);
	Material mat6(MaterialType::MT_Emerald);
	renderer->GetRotatingCube(7)->SetMaterial(mat6);
	Material mat7(MaterialType::MT_CyanRubber);
	renderer->GetRotatingCube(8)->SetMaterial(mat7);
	Material mat8(MaterialType::MT_Brass);
	renderer->GetRotatingCube(9)->SetMaterial(mat8);
	Material mat9(MaterialType::MT_Pearl);
	renderer->GetRotatingCube(10)->SetMaterial(mat9);

	// Set the viewport and enable depth testing
	glViewport(0, 0, GetWindowWidth(), GetWindowHeight());
	glEnable(GL_DEPTH_TEST);

	// Set the clock to use delta time
	ClockSet();

	// Start the game loop
	while (GetRunningState())
	{
		// Checking for events
		if(!PlatformPumpMessages())
			SetRunningState(0);

		// Update delta time
		UpdateTime();

		// Update the camera
		camera->Update();

		// Clear the color and depth buffers
		glClearColor(0.f, 0.4f, 0.8f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw
		renderer->OnUpdate();
		renderer->Draw();

		// Swap buffers
		OpenglSwapBuffers();
	}

	PlatformShutdown();
	Shader::DeInit();
}