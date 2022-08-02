#include <iostream>
using namespace std;
#define COUT(x) cout<<x<<endl;


class HousePlanner {
public:
    virtual void setBasement(string basement)=0;
    virtual void setStructure(string structure)=0;
    virtual void setRoof(string roof)=0;
    virtual void setInterior(string interior)=0;
};

class House : public HousePlanner{
public:
    string basement;
    string structure;
    string roof;
    string interior;

    void setBasement(string b){basement=b;COUT(b)}
    void setStructure(string s){structure=s;COUT(s)}
    void setRoof(string r){roof=r;COUT(r)}
    void setInterior(string i){roof=i;COUT(i)}
};


class Builder{
public:
    virtual void BuildBasement()=0;
    virtual void BuildStructure()=0;
    virtual void BuildRoof()=0;
    virtual void BuildInterior()=0;
    virtual House* gethouse()=0;
};

class IglooBuilder : public Builder{
public:
    House *h;
    IglooBuilder(){h = new House;}
    ~IglooBuilder(){delete h;}
    void BuildBasement(){h->setBasement("Igloo Basement");}
    void BuildStructure(){h->setStructure("Igloo Structure");}
    void BuildRoof(){h->setRoof("Igloo Roof");}
    void BuildInterior(){h->setInterior("Igloo Interior");}
    House* gethouse(){return h;}
};

class ApartmentBuilder : public Builder{
public:
    House *h;
    ApartmentBuilder(){h = new House;}
    ~ApartmentBuilder(){delete h;}
    void BuildBasement(){h->setBasement("Apartment Basement");}
    void BuildStructure(){h->setStructure("Apartment Structure");}
    void BuildRoof(){h->setRoof("Apartment Roof");}
    void BuildInterior(){h->setInterior("Apartment Interior");}
    House* gethouse(){return h;}
};

class CivilEngineer {
public:
    Builder *build;
    CivilEngineer(Builder *b){build = b;}
    House* gethouse(){return build->gethouse();}
    void constructHouse(){
        build->BuildBasement();
        build->BuildStructure();
        build->BuildRoof();
        build->BuildInterior();
    }
};

int main(){

    Builder *builder = new ApartmentBuilder();
    CivilEngineer *ce = new CivilEngineer(builder);

    ce->constructHouse();
    House *h = ce->gethouse();

}
