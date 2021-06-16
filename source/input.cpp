#include "input.h"
#include "util/logger.h"

InputCtrl* InputCtrl::getInstance() {
    if(m_instance == nullptr)
        m_instance = new InputCtrl();
    return m_instance;
}
void InputCtrl::freeInstanceIfAny() {
    if(m_instance != nullptr)
        delete m_instance;
}
InputCtrl::InputCtrl() = default;
InputCtrl::~InputCtrl() = default;

InputCtrl* InputCtrl::m_instance = nullptr;