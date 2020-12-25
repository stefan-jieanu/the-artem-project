#include "SimpleRenderer.h"
#include "../maths/maths.h"

namespace artem { namespace graphics {

    void SimpleRenderer::submit(const Renderable2d* rend)
    {
        renderQueue_.push_back(rend);
    }

    void SimpleRenderer::flush()
    {
        while (!renderQueue_.empty())
        {
            const Renderable2d* rend = renderQueue_.front();
            GLCall(rend->GetVAO()->Bind());
            GLCall(rend->GetIBO()->Bind());

            maths::Matrix4 pos = maths::Matrix4::Translate(rend->GetPosition());
            maths::Matrix4 scale = maths::Matrix4::Scale(rend->GetSize());
            rend->GetShader().SetUniformMat4f("u_Model", scale * pos);
        	rend->GetShader().SetUniform4f("u_Color", rend->GetColor());
            GLCall(glDrawElements(GL_TRIANGLES, rend->GetIBO()->GetCount(), GL_UNSIGNED_INT, nullptr));

            GLCall(rend->GetVAO()->Unbind());
            GLCall(rend->GetIBO()->Unbind());

            renderQueue_.pop_front();
        }
    }

} }