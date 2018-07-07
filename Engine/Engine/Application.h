#pragma once
class Application
{
public:
    Application();
    ~Application();

    bool bVSync = true;

    void Start();
    void Update(float DeltaTime);
    void Draw();
};

