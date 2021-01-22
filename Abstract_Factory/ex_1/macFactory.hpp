#ifndef __MACFACTORY_HPP
#define __MACFACTORY_HPP
#include "Button_Interface.hpp"
#include "Checkbox_Interface.hpp"
#include "AbstractFactory_Interface.hpp"

class macButton :public Button {
public:
    void renderButton();
};

class macCheckbox :public Checkbox {
public:
    void renderCheckbox();
};

class macFactory : public GUIFactory {
    public:    
    Button* CreateButton();
    Checkbox* CreateCheckbox();
};

#endif //__MACFACTORY_HPP