#include <iostream>
using namespace std;

// These are the libraries given to client to include in their code
class Button {
public:
    virtual void renderButton() = 0;
};

class Checkbox {
public:
    virtual void renderCheckbox() = 0;
};

class winButton :public Button {
public:
    void renderButton() {cout<<"windows Button rendered "<<endl;}
};

class winCheckbox :public Checkbox {
public:
    void renderCheckbox() {cout<<"windows checkbox rendered "<<endl;}
};

class macButton :public Button {
public:
    void renderButton() {cout<<"mac Button rendered "<<endl;}
};

class macCheckbox :public Checkbox {
public:
    void renderCheckbox() {cout<<"mac checkbox rendered "<<endl;}
};

class GUIFactory {
public:
    virtual Button* CreateButton() = 0;
    virtual Checkbox* CreateCheckbox() = 0;
};

class winFactory : public GUIFactory {
    public:    
    Button* CreateButton(){ return new winButton; }
    Checkbox* CreateCheckbox(){return new winCheckbox;}
};

class macFactory : public GUIFactory {
    public:    
    Button* CreateButton(){ return new macButton; }
    Checkbox* CreateCheckbox(){return new macCheckbox;}
};

//This is client Application class
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
        cout<<"choose factory: "<<endl<<"1) Windows Factory "<<endl<<"2) mac factory "<<endl <<"Enter any other value to exit "<<endl;
        cin>> cin_val;    
        if(cin_val == 1){        
            Application app(new winFactory);
            app.createGUI();
        }else if(cin_val == 2){
            Application app(new macFactory);
            app.createGUI();
        } else
        {
            break;
        }
    }
}