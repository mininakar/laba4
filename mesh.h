#pragma once
#define MESH_H
#include <glm/glm.hpp>	//#include "math_3d.h" - vector 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <map>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>	//#include "math_3d.h" - vector
#include "util.h"
#include "texture.h"

struct Vertex
{
    glm::vec3 m_pos;
    glm::vec3 m_tex;
    glm::vec3 m_normal;

    Vertex() {}

    Vertex(const glm::vec3& pos, const glm::vec3& tex, const glm::vec3& normal)
    {
        m_pos = pos;
        m_tex = tex;
        m_normal = normal;
    }
};

class Mesh
{
public:
    Mesh() {};
    ~Mesh() {
        Clear();
    };
    bool LoadMesh(const std::string& Filename);
    void Render();

private:
    bool InitFromScene(const aiScene* pScene, const std::string& Filename);
    void InitMesh(unsigned int Index, const aiMesh* paiMesh);
    bool InitMaterials(const aiScene* pScene, const std::string& Filename);
    void Clear();

#define INVALID_MATERIAL 0xFFFFFFFF

    struct MeshEntry {
        MeshEntry();
        ~MeshEntry();

        bool Init(const std::vector<Vertex>& Vertices,
            const std::vector<unsigned int>& Indices);

        GLuint VB;
        GLuint IB;

        unsigned int NumIndices;
        unsigned int MaterialIndex;
    };

    std::vector<MeshEntry> m_Entries;
    std::vector<Texture*> m_Textures;
};