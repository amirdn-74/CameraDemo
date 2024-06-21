#pragma once

#include <memory>
#include <stdio.h>
#include <iostream>
#include <glad/glad.h>

#include "../Scene/Scene.h"
#include "../Scene/Entity.h"
#include "../Scene/Components.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Texture.h"




class Renderer
{
private:
	static std::shared_ptr<Scene> m_scene;

public:
	static void submitScene(std::shared_ptr<Scene> scene)
	{
		m_scene = scene;
	}

	static void DrawScene(std::shared_ptr<Scene> scene)
	{
		auto sceneEntities = scene->getMeshEntities();


		for (const auto* entity : sceneEntities)
		{
			auto meshes = entity->getComponent<MeshComponent>();
			auto color = entity->getComponent<ColorComponent>()[0];
			auto transform = entity->getComponent<TransformationComponent>()[0];

			for (auto mesh : meshes)
			{
				VertexArray va;
				VertexBuffer vb(mesh->vertices);
				vb.addLayout("position", 3);
				vb.addLayout("normal", 3);
				vb.addLayout("texCoord", 2);
				vb.applyLayouts();
				Shader shader("./Core/Renderer/Shaders/Default/Vertex.shader", "./Core/Renderer/Shaders/Default/Fragment.shader");
				shader.bind();

				shader.set4f("_color", color->color.r, color->color.g, color->color.b, color->color.a);

				glm::mat4 trans = glm::mat4(1.f);

				trans = glm::rotate(trans, glm::radians(45.f), glm::vec3{0.f, 0.f, 1.f});

				shader.setMat4("_transform", trans);

				//Texture texture("Textures\\1.jpg");

				DrawMesh(mesh);

				va.unBind();
			}
		}
	}

private:
	static void DrawMesh(const MeshComponent* mesh)
	{
		glDrawArrays(GL_TRIANGLES, 0, mesh->vertices.size());
	}
};