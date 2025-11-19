#include <iostream>
#include <cmath>
#include "Screen.h"
#include "Settings.h"
#include "Mesh.h"

Screen::Screen(Settings const& settings)
: m_width(settings.GetScreenWidth())
, m_height(settings.GetScreenHeight())
, m_zPosition(settings.GetScreenPosition())
, m_background(settings.GetScreenBackground())
, m_meshProjection(settings.GetScreenMeshProjection())
, m_meshZPosition(settings.GetMeshPosition())
, m_pixels(m_width * m_height, '.')
{
}

void Screen::Display() const
{
    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width; j++)
        {
            std::cout << m_pixels[m_width * i + j];
        }
        std::cout << std::endl;
    }
}

void Screen::Display(Mesh const& mesh)
{
    std::fill(m_pixels.begin(), m_pixels.end(), m_background);
    _ProjectMesh(mesh);
    Display();
}

void Screen::_ProjectMesh(Mesh const& mesh)
{
    for(Vertex vertex : mesh.GetVertices())
    {
        _ProjectInCenterScreenSpace(vertex);
        _ProjectInTopLeftScreenSpace(vertex);
        int u = std::round(vertex.x);
        int v = std::round(vertex.y);
        if(u > 0 && u < m_width && v > 0 && v < m_height)
        {
            m_pixels[v * m_width + u] = m_meshProjection;
        }
    }
}

void Screen::_ProjectInCenterScreenSpace(Vertex& vertex)
{
    vertex.z += m_meshZPosition;
    vertex.x = m_zPosition * vertex.x / vertex.z;
    vertex.y = m_zPosition * vertex.y / vertex.z / 2.f;
}

void Screen::_ProjectInTopLeftScreenSpace(Vertex& vertex)
{
    vertex.x += m_width/2;
    vertex.y += m_height/2;
}