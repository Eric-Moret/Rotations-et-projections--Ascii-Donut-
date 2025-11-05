#include <iostream>
#include "Mesh.h"
#include "Settings.h"

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = 2.f*i / (m_resolution - 1) - 1.f;
            m_vertices[m_resolution * i + j].y = 2.f*j / (m_resolution - 1) - 1.f;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}