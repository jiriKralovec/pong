#include "object-store.h"

void ObjectStore::RunBatchUpdate() const
{
    for(GameObject* ptr : m_objects)
        ptr->Update();
}
void ObjectStore::RunBatchDraw() const
{
    for(GameObject* ptr : m_objects)
        ptr->Draw();
}
void ObjectStore::RegisterObject(GameObject* ptr)
{
    m_objects.emplace_back(ptr);
}
ObjectStore& ObjectStore::getInstance() {
    if(m_instance == nullptr)
        m_instance = new ObjectStore();
    return *m_instance;
}
void ObjectStore::freeInstanceIfAny() {
    if(m_instance != nullptr)
        delete m_instance;
    m_instance = nullptr;
}
ObjectStore::~ObjectStore()
{
    for(GameObject* ptr : m_objects)
        delete &ptr;
}

ObjectStore* ObjectStore::m_instance = nullptr;