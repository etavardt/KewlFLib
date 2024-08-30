#include "Kewl/OpenGL/Quad.hpp"

namespace Kewl
{
    namespace OpenGL
    {
        Quad QuadNs::createQuad(const float texID, const float mvpID)
        {
            Vertex v0;
            v0.position = {-0.5f, -0.5f, 0.0f};
            v0.color = {0.0f, 0.0f, 0.0f, 0.0f};
            v0.texCoords = {0.0f, 0.0f};
            v0.texID = texID;
            v0.mvpID = mvpID;

            Vertex v1;
            v1.position = {0.5f, -0.5f, 0.0f};
            v1.color = {0.0f, 0.0f, 0.0f, 0.0f};
            v1.texCoords = {1.0f, 0.0f};
            v1.texID = texID;
            v1.mvpID = mvpID;

            Vertex v2;
            v2.position = {0.5f, 0.5f, 0.0f};
            v2.color = {0.0f, 0.0f, 0.0f, 0.0f};
            v2.texCoords = {1.0f, 1.0f};
            v2.texID = texID;
            v2.mvpID = mvpID;

            Vertex v3;
            v3.position = {-0.5f, 0.5f, 0.0f};
            v3.color = {0.0f, 0.0f, 0.0f, 0.0f};
            v3.texCoords = {0.0f, 1.0f};
            v3.texID = texID;
            v3.mvpID = mvpID;

            return {v0, v1, v2, v3};
        }

        Quads QuadNs::createQuads(const unsigned int quantity, const float texID, const float mvpID)
        {
            Quads quads;

            for (unsigned int i = 0; i < quantity; i++)
            {
                quads.emplace_back(createQuad(texID, mvpID));
            }

            return quads;
        }

        VertexBuf QuadNs::GetVertexBuf(const Quad& quad, bool bColor, bool bTexCoords, bool bTexID, bool bMvpID)
        {
            std::vector<float> vBuf;
            vBuf.reserve(sizeof(quad) / sizeof(float));

            for (const Vertex& v : quad)
            {
                vBuf.insert(vBuf.end(), {v.position.x, v.position.y, v.position.x});
                if (bColor)     vBuf.insert(vBuf.end(), {v.color.r, v.color.g, v.color.b, v.color.a});
                if (bTexCoords) vBuf.insert(vBuf.end(), {v.texCoords.x, v.texCoords.y});
                if (bTexID)     vBuf.insert(vBuf.end(), v.texID);
                if (bMvpID)     vBuf.insert(vBuf.end(), v.mvpID);
            }

            vBuf.shrink_to_fit();

            return vBuf;
        }

        VertexBuf QuadNs::GetVertexBuf(const Quads& quads, bool bColor, bool bTexCoords, bool bTexID, bool bMvpID)
        {
            VertexBuf vBuf;

            vBuf.reserve(sizeof(quads) / sizeof(float));

            for (const Quad& quad : quads)
            {

                for (const Vertex& v : quad)
                {
                    vBuf.insert(vBuf.end(), {v.position.x, v.position.y, v.position.x});
                    if (bColor)     vBuf.insert(vBuf.end(), {v.color.r, v.color.g, v.color.b, v.color.a});
                    if (bTexCoords) vBuf.insert(vBuf.end(), {v.texCoords.x, v.texCoords.y});
                    if (bTexID)     vBuf.insert(vBuf.end(), v.texID);
                    if (bMvpID)     vBuf.insert(vBuf.end(), v.mvpID);
                }
            }
            vBuf.shrink_to_fit();
            return vBuf;
        }


        Indices QuadNs::GetIndices(const unsigned int quantity)
        {
            Indices indices(quantity * 6);

            for (unsigned int vInd = 0; vInd < quantity; vInd++)
            {
                unsigned int ind = vInd * 6;
                unsigned int vOffset = vInd * 4;
                indices[ind] = 0 + vOffset;
                indices[ind + 1] = 1 + vOffset;
                indices[ind + 2] = 2 + vOffset;
                indices[ind + 3] = 2 + vOffset;
                indices[ind + 4] = 3 + vOffset;
                indices[ind + 5] = 0 + vOffset;
            }

            return indices;
        }
    } // namespace OpenGL
} // namespace Kewl
