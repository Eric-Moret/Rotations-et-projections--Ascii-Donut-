#include <iostream>
#include "Mesh.h"

Mesh::Mesh()
: m_vertices({ {-1.f, -1.f, 0.f}, {-1.f, 1.f, 0.f}, {1.f, -1.f, 0.f}, {1.f, 1.f, 0.f}})
{
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}