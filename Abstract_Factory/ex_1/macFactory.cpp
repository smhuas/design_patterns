#include <iostream>
#include "macFactory.hpp"
using namespace std;


void macButton::renderButton() {
    cout<<"mac Button rendered "<<endl;
}

void macCheckbox::renderCheckbox() {
        cout<<"mac checkbox rendered "<<endl;
}

Button* macFactory::CreateButton(){ 
    return new macButton; 
}
Checkbox* macFactory::CreateCheckbox(){
    return new macCheckbox;
}

