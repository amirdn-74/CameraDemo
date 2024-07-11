
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
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "../Providers/ResourceProvider.h"




class Renderer
{
private:
	static std::shared_ptr<Scene> m_scene;

public:
	static void submitScene(std::shared_ptr<Scene> scene);

	static void DrawScene(std::shared_ptr<Scene> scene);

private:
	static void DrawTriangles(const RenderComponent& obj);
};
