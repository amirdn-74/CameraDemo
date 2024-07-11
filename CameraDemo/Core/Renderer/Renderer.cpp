#include "Renderer.h"




void Renderer::submitScene(std::shared_ptr<Scene> scene)
{
	auto entities = scene->getEntities();

	for (auto ent : entities)
	{
		if (!scene->hasComponent<MeshComponent>(ent)) continue;

		auto meshComponents = scene->getComponents<MeshComponent>(ent);
		auto model = ResourceProvider::Load<MeshProvider>("monkey-high.fbx");

		for (auto mesh : model->getMeshes())
		{
			VertexArray va;
			IndexBuffer ib(mesh.indices);
			VertexBuffer vb(mesh.vertices);
			vb.addLayout("position", 3);
			vb.addLayout("normal", 3);
			vb.addLayout("texCoord", 2);
			vb.applyLayouts();

			Shader shader("./Core/Renderer/Shaders/Default/Vertex.shader", "./Core/Renderer/Shaders/Default/Fragment.shader");
			shader.bind();

			shader.set4f("_color", 0.2f, 0.f, 1.0f, 1.f);

			glm::mat4 trans = glm::mat4(1.f);

			trans = glm::scale(trans, glm::vec3{ 0.5f, 0.5f, 0.5f });

			trans = glm::rotate(trans, glm::radians(-90.f), glm::vec3(1.0f, 0.f, 0.f));

			shader.setMat4("_transform", trans);

			scene->attachComponent<RenderComponent>(ent, { va, vb, ib, mesh.vertices.size(), mesh.indices.size()});

			va.unBind();
		}
	}
}

void Renderer::DrawScene(std::shared_ptr<Scene> scene)
{
	auto entities = scene->getEntities();

	for (auto ent : entities)
	{
		if (!scene->hasComponent<RenderComponent>(ent)) continue;

		auto renderComponents = scene->getComponents<RenderComponent>(ent);

		for (auto obj : renderComponents)
			DrawTriangles(obj);
	}
}

void Renderer::DrawTriangles(const RenderComponent& obj)
{
	obj.va.bind();
	glDrawElements(GL_TRIANGLES, obj.indexCount, GL_UNSIGNED_INT, 0);
	obj.va.unBind();
}
