#ifndef __WINFACTORY_HPP
#define __WINFACTORY_HPP
#include "Button_Interface.hpp"
#include "Checkbox_Interface.hpp"
#include "AbstractFactory_Interface.hpp"


class winButton :public Button {
public:
    void renderButton() ;
};

class winCheckbox :public Checkbox {
public:
    void renderCheckbox();
};

class winFactory : public GUIFactory {
    public:    
    Button* CreateButton();
    Checkbox* CreateCheckbox();
};

#endif //__WINFACTORY_HPP