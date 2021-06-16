#pragma once
class InputCtrl
{
public:
    static InputCtrl* getInstance();
    static void freeInstanceIfAny();
private:
    static InputCtrl* m_instance;
    InputCtrl();
    ~InputCtrl();
};