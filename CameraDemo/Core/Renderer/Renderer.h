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
		
	}

	static void DrawScene(std::shared_ptr<Scene> scene)
	{		
		auto entities = scene->getEntities();
		auto components = scene->getComponents<MeshComponent>();

		for (auto ent : entities)
		{
			if (!scene->hasComponent<MeshComponent>(ent)) continue;

			auto meshComponents = scene->getComponents<MeshComponent>(ent);

			for (auto mesh : meshComponents)
			{
				VertexArray va;
				VertexBuffer vb(mesh.vertices);
				vb.addLayout("position", 3);
				vb.addLayout("normal", 3);
				vb.addLayout("texCoord", 2);
				vb.applyLayouts();
				/*Shader shader("./Core/Renderer/Shaders/Default/Vertex.shader", "./Core/Renderer/Shaders/Default/Fragment.shader");
				shader.bind();

				shader.set4f("_color", color->color.r, color->color.g, color->color.b, color->color.a);

				glm::mat4 trans = glm::mat4(1.f);

				trans = glm::rotate(trans, glm::radians(45.f), glm::vec3{ 0.f, 0.f, 1.f });

				shader.setMat4("_transform", trans);*/

				//scene->attachComponent<RenderComponent>(ent, { va });
				//ent.AddComponent<MaterialComponent>(shader);
				DrawMesh(mesh);

				va.unBind();
			}
		}
	}

private:
	static void DrawMesh(const MeshComponent& mesh)
	{
		glDrawArrays(GL_TRIANGLES, 0, mesh.vertices.size());
	}
};