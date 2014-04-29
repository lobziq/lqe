#include "model.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

model::model(GLFWwindow *window, camera *sceneCamera): oglObject3d(window, sceneCamera)
{
    loadShaderProgram();
}

void model::load(std::string fileName)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_GenSmoothNormals);

    for (unsigned int n=0; n<scene->mNumMeshes; n++)
    {
        aiMesh *mesh = scene->mMeshes[n];

        for(unsigned int i=0; i<mesh->mNumFaces; i++)
        {
            const aiFace& face = mesh->mFaces[i];

            for(int j=0; j<3; j++)
            {
                aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
                uvs.push_back(uv.x);
                uvs.push_back(uv.y);

                //aiVector3D normal = mesh->mNormals[face.mIndices[j]];
                //glm::vec3 normalVec(normal.x, normal.y, normal.z);
                //normals.push_back(normalVec);

                aiVector3D pos = mesh->mVertices[face.mIndices[j]];
                vertices.push_back(pos.x);
                vertices.push_back(pos.y);
                vertices.push_back(pos.z);
            }
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size()*sizeof(GLfloat), &uvs[0], GL_STATIC_DRAW);
}
