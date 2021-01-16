#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../vendor/stb_image/stb_image.h"

namespace artem { namespace graphics {

    Texture::Texture(const char* filename)
    {
        // Load the image data using stb_image
        int w, h, c;
        data_ = stbi_load(filename, &w, &h, &c, 0);
        if (data_) {
            width_ = w;
            height_ = h;
            channelsCount_ = c;
        } 
        else 
        {
            printf("Could not load texture!\n");
        }

        // Sending the data to OpenGL
        glGenTextures(1, &textureID_);
        glBindTexture(GL_TEXTURE_2D, textureID_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        if (channelsCount_ == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, (const void*)data_);
        else if (channelsCount_ == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, (const void*)data_);
        glBindTexture(GL_TEXTURE_2D, 0);
        
    }

    Texture::~Texture()
    {
        stbi_image_free(data_);
    }

    void Texture::Bind() const
    {
        glBindTexture(GL_TEXTURE_2D, textureID_);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

} }