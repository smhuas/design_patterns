#include <iostream>
using namespace std;
#define COUT cout<<__FUNCTION__<<endl;

class Light{
public:
    void LightOn(){COUT}
    void LightOff(){COUT}
};

class Engine{
public:
    void EngineOn(){COUT}
    void EngineOff(){COUT}
};

class command{
public:
    virtual void execute() = 0;
};

class LightOnCommand : public command{
public:
    Light *lgt;
    LightOnCommand(Light *l):lgt(l){COUT}
    
    void execute(){
        lgt->LightOn();
    }    

    ~LightOnCommand(){delete lgt;}
};

class LightOffCommand : public command{
public:
    Light *lgt;
    LightOffCommand(Light *l):lgt(l){COUT}
    
    void execute(){
        lgt->LightOff();
    }  

    ~LightOffCommand(){delete lgt;}
};

class EngineOnCommand : public command{
public:
    Engine *lgt;
    EngineOnCommand(Engine *l):lgt(l){COUT}
    
    void execute(){
        lgt->EngineOn();
    }    

    ~EngineOnCommand(){delete lgt;}
};

class EngineOffCommand : public command{
public:
    Engine *lgt;
    EngineOffCommand(Engine *l):lgt(l){COUT}
    
    void execute(){
        lgt->EngineOff();
    }    

    ~EngineOffCommand(){delete lgt;}
};


void processcommands(command *c)
{
    c->execute();
    delete c;
}

int main()
{
    LightOnCommand *lOnCommand = new LightOnCommand(new Light); 
    processcommands(lOnCommand);

    LightOffCommand *lOffCommand = new LightOffCommand(new Light); 
    processcommands(lOffCommand);

    EngineOnCommand *eOnCommand = new EngineOnCommand(new Engine); 
    processcommands(eOnCommand);

    EngineOffCommand *eOffCommand = new EngineOffCommand(new Engine); 
    processcommands(eOffCommand);
}
