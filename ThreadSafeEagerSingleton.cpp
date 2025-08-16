#include<iostream>
#include<mutex>

using namespace std;

class Singleton{
    private:
    static Singleton* instance;

    Singleton(){
        cout<<"Singleton Constructor called"<<endl;
    }

    public:
    static Singleton* getInstance(){
        return instance;
    }
};

//initialize static members
//isko initlize ke time per hi ek naya object de diye h
Singleton* Singleton::instance = new Singleton();

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<(s1==s2)<<endl;
}