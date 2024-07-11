#pragma once

#include <filesystem>

#include "../Core/Scene/Scene.h"
#include "../Entities/Triangle.h"
#include "../Core/Scene/Components.h"
#include "../Core/Math.h"
#include "../Core/Renderer/Renderer.h"
#include "../Core/Renderer/Texture.h"




class FirstScene : public Scene
{
public:
	FirstScene(const char* title) : Scene(title)
	{
		/*std::vector<Vertex> vertices1;
		vertices1.emplace_back(glm::vec3{ -0.5f, -0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 0.f, 1.f });
		vertices1.emplace_back(glm::vec3{ 0.5f, -0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 1.f, 1.f });
		vertices1.emplace_back(glm::vec3{ 0.0f,  0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 0.5f, 0.f });*/
		
		//auto triangle = new Entity("triangle");
		//triangle->addComponent<MeshComponent>(vertices1);
		//triangle->addComponent<ColorComponent>(0.f, 0.5f, 0.7f, 1.f);
		//triangle->addComponent<TransformationComponent>(glm::vec3{1.f}, glm::vec3{0, 45, 0}, glm::vec3{1.f});
		//
		////std::cout << std::filesystem::current_path() << std::endl;
		//addMesh(triangle);
		Entity e1 = createEntity();
		attachComponent<MeshComponent>(e1, { "monkey.obj" });
		//addComponent<ColorComponent>(e1, { 0.25f, 0.5f, 1.f, 1.f });
	}

	virtual ~FirstScene() {}
};