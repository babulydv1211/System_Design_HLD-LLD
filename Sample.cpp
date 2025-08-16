#include<iostream>
#include <mutex>
using namespace std;

class Singleton{   //note->constuctor jo h wah new object jo banat h usko value assign krta h 
    private:
    static Singleton* instance;
    static  mutex mtx;
    Singleton(){
        cout<<"Singleton Constructor called. New Object create"<<endl;
    }
    public:
    static Singleton* getInstance(){
        if(instance == nullptr){
          lock_guard<mutex> lock(mtx); //yaha lock introdcue ho gya to pure area min ek thread enter krega
           if(instance == nullptr){
             instance = new Singleton();
           }
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;  //class ke under jo instance bna wah ek varible h usko declear kiya h outside the class
mutex Singleton::mtx;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<(s1==s2)<<endl;
}