#include <iostream>
using namespace std;

template<typename T>
class singleton {
    static inline singleton *instance = nullptr;
    T data;
    singleton() = default;                  // no one can create singleton, so, define default ctor in private section
    singleton(singleton& obj) = delete;     // singleton cannot be cloneable, so delete copy ctor
    void operator=(singleton&) = delete;    // cannot be assignable, delete
public:
    static singleton* getInstance();
    T getdata(){return data;}
    void setdata(T val){data = val;}
};

template<typename T>
singleton<T>* singleton<T>::getInstance()
{    
    return instance = (instance == nullptr)? new singleton: instance ;
}

int main()
{
    if(singleton<int>::getInstance() != nullptr)
    {
        auto mysingleton = singleton<int>::getInstance();
        mysingleton->setdata(10);
        cout<<"singleton created data is "<< mysingleton->getdata()<<endl;
    }

    //singleton<int> s;
}