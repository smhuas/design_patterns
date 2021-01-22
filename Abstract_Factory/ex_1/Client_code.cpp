#include <iostream>
#include "AbstractFactory_Interface.hpp"
#include "winFactory.hpp"
#include "macFactory.hpp"
using namespace std;

// client helper class
class Application {
    GUIFactory *factory;
public:
    Application(GUIFactory *fact):factory(fact){};    
    void createGUI(){
        factory->CreateButton()->renderButton(); 
        factory->CreateCheckbox()->renderCheckbox();
    }
};

int main()
{
    int cin_val = 0;
    while(1){
        cout<<"choose factory: "<<endl<<"1) Windows Factory "<<endl<<"2) mac factory "<<endl <<"3) exit "<<endl;
        cin>> cin_val;
        cout<<endl;    
        if(cin_val == 1){        
            Application app(new winFactory);
            app.createGUI();
            cout<<endl;
        }else if(cin_val == 2){
            Application app(new macFactory);
            app.createGUI();
            cout<<endl;
        } else if(cin_val == 3) {
            break;
        } else {
            cout<<"give valid input !!!! "<<endl;
            cout<<endl;
        }
    }
}