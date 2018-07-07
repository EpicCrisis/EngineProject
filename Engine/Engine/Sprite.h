#pragma once
class Sprite
{
private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_textureID;

public:
    Sprite();
    ~Sprite();

    void Draw(float x, float y);
};

