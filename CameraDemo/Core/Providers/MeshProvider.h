#pragma once

#include <string>
#include <vector>

#include <Assimp/Importer.hpp>
#include <Assimp/scene.h>
#include <Assimp/postprocess.h>

#include "../Renderer/VertexBuffer.h"





struct Mesh
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	Mesh(const std::vector<Vertex>& vrtx, const std::vector<unsigned int>& indx) 
		: vertices(vrtx), indices(indx)
	{}
};


class MeshProvider
{
private:
	std::string m_modelsBasePath = "assets/models/";
	std::vector<Mesh> m_meshes;

public:
	MeshProvider(const std::string& path);
	~MeshProvider() {  };

	inline const std::vector<Mesh>& getMeshes() const { return m_meshes; };

private:
	void processNode(aiNode* node, const aiScene* scene);
	void processMesh(aiMesh* mesh, const aiScene* scene);
};