#pragma once
#include <vector>
#include "abstract/game-object.h"

class ObjectStore
{
public:
    void RunBatchUpdate() const;
    void RunBatchDraw() const;
    void RegisterObject(GameObject* ptr);
public:
    static ObjectStore& getInstance();
    static void freeInstanceIfAny();
private:
    ObjectStore() = default;
    ~ObjectStore();
private:
    static ObjectStore* m_instance;
    std::vector<GameObject*> m_objects = {};
};