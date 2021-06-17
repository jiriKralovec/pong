#include "game_object.h"
#include "../object_store.h"

GameObject::GameObject() {
    ObjectStore::getInstance().RegisterObject(this);
}