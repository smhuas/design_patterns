#ifndef _ABSTRACTFACTORY_GUI_HPP
#define _ABSTRACTFACTORY_GUI_HPP

#include "Button_Interface.hpp"
#include "Checkbox_Interface.hpp"

class GUIFactory {
public:
    virtual Button* CreateButton() = 0;
    virtual Checkbox* CreateCheckbox() = 0;
};

#endif  //_ABSTRACTFACTORY_GUI_HPP