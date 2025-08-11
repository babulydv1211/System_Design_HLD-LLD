#include<iostream>

using namespace std;

//Method Argumant Rule:
//subtype method argumant can be identical or wider than supertype

class Parent{
    public:
    virtual void print(string msg){
        cout<<"Parent:"<<msg<<endl;
    }
};

class Child: public Parent{
    public:
    void print(string msg) override {
        cout<<"Child"<<msg<<endl;
    }
};

class Client {
    private:
     Parent* p;

    public:
     Client(Parent* p){
        this->p=p;
     }

     void printMsg(){
        p->print("Hello");
     }
};

int main(){
    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client = new Client(child);

    client->printMsg();
}