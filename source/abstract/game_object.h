#pragma once

class GameObject
{
public:
    GameObject();
    virtual void Draw() const = 0;
    virtual void Update() = 0;
};