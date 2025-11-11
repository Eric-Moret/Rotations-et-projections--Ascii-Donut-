#pragma once

class Settings
{
    public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    char GetScreenBackground() const { return m_screenBackground; }
    float GetScreenPosition() const { return m_screenPosition; }
    float GetViewerPosition() const { return m_viewerPosition; }
    char GetScreenMeshProjection() const { return m_screenMeshProjection; }
    int GetMeshResolution() const { return m_meshResolution; }
    float GetMeshRotationXPerFrame() const { return m_meshRotationXPerFrame; }
    int GetFrameDuration() const { return m_frameDuration; }
    
    private:
    void _ParseArguments(int argc, char** argv);

    private:
    int m_screenWidth;
    int m_screenHeight;
    char m_screenBackground;
    float m_screenPosition;
    float m_viewerPosition;
    char m_screenMeshProjection;
    int m_meshResolution;
    float m_meshRotationXPerFrame;
    int m_frameDuration;
};