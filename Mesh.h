#pragma once
#include <cstdio>
#include <vector>

struct Vertex
{
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z); }
    float x;
    float y;
    float z;
};

class Mesh
{
    public:
    Mesh();
    void Debug() const;

    private:
    std::vector<Vertex> m_vertices;
};