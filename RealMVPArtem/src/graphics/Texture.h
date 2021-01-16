#pragma once

#include "../logging/log_gl.h"

namespace artem { namespace graphics {

    class Texture
    {
    public:
        Texture(const char* fileName);
        ~Texture();

        void Bind() const;
        void Unbind() const;

        inline int const GetHeight() const { return height_; }
        inline int const GetWidth() const { return width_; }
        inline int const GetChannelsCount() const { return channelsCount_; }
        inline unsigned char* const GetData() const { return data_; }

        inline const unsigned int GetID() const { return textureID_; }
    private:
        // General info 
        unsigned int height_, width_, channelsCount_;
        unsigned char* data_;

        // OpenGL stuff
        unsigned int textureID_;
    };

} }