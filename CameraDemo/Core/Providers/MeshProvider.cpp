#include "MeshProvider.h"




MeshProvider::MeshProvider(const std::string& path)
{
	/*std::vector<Vertex> vertices;
	vertices.emplace_back(glm::vec3{ -0.5f, -0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 0.f, 1.f });
	vertices.emplace_back(glm::vec3{ 0.5f, -0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 1.f, 1.f });
	vertices.emplace_back(glm::vec3{ 0.0f,  0.5f, 0.f, }, glm::vec3{ 0.f }, glm::vec2{ 0.5f, 0.f });

	m_vertices = vertices;*/



	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(m_modelsBasePath + path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
		!scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	processNode(scene->mRootNode, scene);
}

void MeshProvider::processNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		processMesh(mesh, scene);
	}
	// then do the same for each of its children
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

void MeshProvider::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;

		glm::vec3 vector;

		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;

		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		vertex.TextureCoordinate = glm::vec2(0.f);

		vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	std::cout << vertices.size() << " , " << indices.size() << std::endl;

	m_meshes.emplace_back(vertices, indices);
}
