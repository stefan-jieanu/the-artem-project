#include "BatchRenderer.h"
#include "sprite.h"

namespace artem { namespace graphics {

    BatchRenderer::BatchRenderer()
    {
        // Initializing the actual rendering things
        InitRendetingStuff();

        // Initializing the transformation stack
        transformationStack_.push_back(maths::Matrix4::Identity());
        transformationBack_ = &transformationStack_.back();
    }

    BatchRenderer::~BatchRenderer()
    {
        delete vertexArray_;
        delete indexBuffer_;
        delete vertexBuffer_;
    }

    void BatchRenderer::InitRendetingStuff()
    {
        vertexBuffer_ = new VertexBuffer(NULL, RENDERER_BUFFER_SIZE, false);
        // Push the position of VertexData struct
        vertexBufferLayout_.Push<float>(3, false);
        // Push the texture coordinates
        vertexBufferLayout_.Push<float>(2, false);
        // Push the texture index
        vertexBufferLayout_.Push<float>(1, false);
        // Push the color of VertexData struct
        vertexBufferLayout_.Push<unsigned char>(4, true);

        vertexArray_ = new VertexArray();   
        vertexArray_->AddBuffer(*vertexBuffer_, vertexBufferLayout_);

        unsigned int* indices = new unsigned int[RENDERER_INDICES_SIZE];

        int offset = 0;
        for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
        {
            indices[i + 0] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 2;
            indices[i + 4] = offset + 3;
            indices[i + 5] = offset + 0;
            
            offset += 4;
        }

        indexBuffer_ = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
    }

    void BatchRenderer::Begin()
    {
        vertexBuffer_->Bind();
        vertexData_ = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    }

    void BatchRenderer::Submit(const Sprite* rend)
    {
        const maths::Vector3& position = rend->GetPosition();
        const maths::Vector2& size = rend->GetSize();
        const maths::Vector4& color = rend->GetColor();
        const std::vector<maths::Vector2>& uv = rend->GetUV();
        const unsigned int textureID = rend->GetTextureID();

        unsigned int c = 0;
        float ts = 0.0f;


        // Warning
        /*
            This method might not actually work with more than 32 textures
            didn't test it yet
        */
        if (textureID > 0)
        {
            bool found = false;
            for (int i = 0; i < textureSlots_.size(); i++)
            {
                if (textureSlots_[i] == textureID)
                {
                printf("fount text: %d\n", textureID);
                    ts = (float) (i + 1);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                if (textureSlots_.size() >= 32)
                {
                    End();
                    Flush();
                    Begin();
                }
                textureSlots_.push_back(textureID);
                ts = (float) (textureSlots_.size());
            }
        }
        else 
        {
            int r = color.x * 255.0f;
            int g = color.y * 255.0f;
            int b = color.z * 255.0f;
            int a = color.w * 255.0f;

            c = a << 24 | b << 16 | g << 8 | r;
        }


        vertexData_->position = *transformationBack_ * position;
        vertexData_->uv = uv[0];
        vertexData_->tid = ts;
        vertexData_->color = c;
        vertexData_++;

        vertexData_->position = *transformationBack_ * maths::Vector3(position.x, position.y + size.y, position.z);
        vertexData_->uv = uv[1];
        vertexData_->tid = ts;
        vertexData_->color = c;
        vertexData_++;

        vertexData_->position = *transformationBack_ * maths::Vector3(position.x + size.x, position.y + size.y, position.z);
        vertexData_->uv = uv[2];
        vertexData_->tid = ts;
        vertexData_->color = c;
        vertexData_++;

        vertexData_->position = *transformationBack_ * maths::Vector3(position.x + size.x, position.y, position.z);
        vertexData_->uv = uv[3];
        vertexData_->tid = ts;
        vertexData_->color = c;
        vertexData_++;

        indexCount_ += 6;
    }
    
    void BatchRenderer::Flush()
    {
        for (int i = 0; i < textureSlots_.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textureSlots_[i]);
        }

        vertexArray_->Bind();
        indexBuffer_->Bind();

        glDrawElements(GL_TRIANGLES, indexCount_, GL_UNSIGNED_INT, NULL);

        vertexArray_->Unbind();
        indexBuffer_->Unbind();

        indexCount_ = 0;
    }

    void BatchRenderer::End()
    {
        glUnmapBuffer(GL_ARRAY_BUFFER);
        vertexBuffer_->Unbind();
    }

    void BatchRenderer::PushMatrix(const maths::Matrix4& matrix, bool override)
    {
        // Override the current matrix (matrices?) in the stack and 
        // push a matrix relative to nothig(the identity matrix/transformation)
        if (override)
            transformationStack_.push_back(matrix);
        else
            transformationStack_.push_back(transformationStack_.back() * matrix);

        transformationBack_ = &transformationStack_.back();
    }

    void BatchRenderer::PopMatrix()
    {
        //TODO: Log if poping too many matrices

        if (transformationStack_.size() > 1) 
            transformationStack_.pop_back();
        else 
            std::cout << "Error: transformation stack is less than one!\n";

        transformationBack_ = &transformationStack_.back();
    }

} }