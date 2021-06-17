#include "game-object.h"
#include "../object-store.h"

GameObject::GameObject() {
    ObjectStore::getInstance().RegisterObject(this);
}