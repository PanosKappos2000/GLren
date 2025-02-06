#include "Window/window.h"
#include "Window/Events.h"
#include "Shader/Shader.h"
#include "Entities/cube.h"
#include "Renderer/Renderer.h"

#include <vector>

static uint8_t isRunning = 1;

static uint8_t GetRunningState() { return isRunning; }
static void SetRunningState(uint8_t set) { isRunning = set; }

int main()
{
	EventSystemState eventSystem;
	InputSystemState inputSystem;

	PlatformStartup("GLren", 100, 100, 1280, 768);
	CreateOpenglDrawContext();

	std::unique_ptr<Camera> camera = std::make_unique<Camera>(sizeof(Camera));

	Renderer* renderer = new Renderer();
	Shader::Init();

	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(0.0f, 0.0f, 0.0f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(1.0f, -2.2f, -6.3f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(2.2f, -2.1, -3.4f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-3.7f, -4.0f, -8.9f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-2.7f, -2.0f, -7.2f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-4.7f, 4.0f, -11.5f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(-1.7f, 2.4f, -6.9f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(2.2f, 2.5f, -13.1f)));
	renderer->Append(new RotatingCube("Assets/Textures/Container.png",
		"Assets/Textures/Container_specular.png",glm::vec3(0.7f, 3.9f, -6.3f)));

	renderer->AddLightCube(new LightCube());
	renderer->AddLightCube(new LightCube(glm::vec3(8.0f, 6.0f, -4.0f)));
	renderer->AddLightCube(new LightCube(glm::vec3(8.0f, 6.0f, -8.0f)));
	renderer->AddLightCube(new LightCube(glm::vec3(-8.0f, 6.0f, -4.0f)));
	renderer->AddLightCube(new LightCube(glm::vec3(-8.5f, 6.0f, -8.0f)));

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

	unsigned int shadowFramebufferTag;
	glGenFramebuffers(1, &shadowFramebufferTag);

	unsigned int depthMapTextureTag;
	glGenTextures(1, &depthMapTextureTag);
	glActiveTexture(GL_TEXTURE0 + 30);
	glBindTexture(GL_TEXTURE_2D, depthMapTextureTag);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 1024, 1024, 0,
		GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindFramebuffer(GL_FRAMEBUFFER, shadowFramebufferTag);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMapTextureTag, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	ClockSet();

	while (isRunning)
	{
		UpdateTime();

		glClearColor(0.f, 0.4f, 0.6f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, 1024, 1024);
		glBindFramebuffer(GL_FRAMEBUFFER, shadowFramebufferTag);
		glClear(GL_DEPTH_BUFFER_BIT);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glViewport(0, 0, 1280, 768);

		renderer->OnUpdate();
		renderer->Draw();
		OpenglSwapBuffers();
	}

	PlatformShutdown();
	delete renderer;
	Shader::DeInit();
}