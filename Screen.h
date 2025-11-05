#pragma once
#include <vector>

class Settings;
class Mesh;
struct Vertex;

class Screen
{
    public:
    Screen(Settings const& settings);
    void Display() const;
    void Display(Mesh const& mesh);

    private:
    void _ProjectMesh(Mesh const& mesh);
    void _ProjectInCenterScreenSpace(Vertex& vertex);
    void _ProjectInTopLeftScreenSpace(Vertex& vertex);
    void _Display() const;

    private:
    int m_width;
    int m_height;
    char m_background;
    char m_meshProjection;
    float m_meshPosition;
    float m_viewerPosition;
    std::vector<char> m_pixels;
};