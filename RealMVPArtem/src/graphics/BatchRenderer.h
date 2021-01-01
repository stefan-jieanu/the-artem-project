#pragma once

#include "buffers/buffers.h"
#include "../maths/maths.h"
#include "../graphics/Renderable2d.h"

namespace artem { namespace graphics {

#define RENDERER_MAX_SPRITES  40000
#define RENDERER_VERTEX_SIZE  sizeof(VertexData)
#define RENDERER_SPRITE_SIZE  RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE  RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6

    class Sprite;

    class BatchRenderer
    {
    private:
        // Data needed for the actual rendering
        VertexArray* vertexArray_;
        IndexBuffer* indexBuffer_;
        VertexBuffer* vertexBuffer_;
        VertexBufferLayout vertexBufferLayout_;
        unsigned int indexCount_;
        VertexData* vertexData_;

        // The matrix tranformation stack
        std::vector<maths::Matrix4> transformationStack_;
        const maths::Matrix4* transformationBack_;

        void InitRendetingStuff();
    public:
        BatchRenderer();
        ~BatchRenderer();

        // Functions used for the actual rendering
        void Begin();
        void Submit(const Sprite* rend);
        void Flush();
        void End();

        // Functions used for the tranformation stack
        void PushMatrix(const maths::Matrix4& matrix, bool override = false);
        void PopMatrix();
    };

} }