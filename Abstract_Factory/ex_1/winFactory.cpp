#include <iostream>
#include "winFactory.hpp"
using namespace std;

void winButton::renderButton() {
    cout<<"windows Button rendered "<<endl;
}
void winCheckbox::renderCheckbox() {
    cout<<"windows checkbox rendered "<<endl;
}
 
Button* winFactory::CreateButton(){ 
    return new winButton; 
}
Checkbox* winFactory::CreateCheckbox(){
    return new winCheckbox;
}
