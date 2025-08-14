#include<iostream>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger() {}
};

class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Basic Burger with bun ,patty ,and ketchip!"<<endl;
    }
};

class StandardBurger:public Burger{
    public:
    void prepare() override {
        cout<<"Preapring Standrd urger with bun,patty,cheese,and lettuce!"<<endl;
    }
};

class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Premium Burger with bun,Preimum patty,cheese,lettuce,secret cheese"<<endl;
    }
};

class BasicWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with Bun,patty and ketchup!"<<endl;
    }
};

class StandardWheatBurger:public Burger{
    public:
    void prepare() override {
        cout<<"Preapring Standrd Wheat Burger with bun,patty,cheese,and lettuce!"<<endl;
    }
};

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Premium    Wheat Burger with Bun,patty and ketchup!"<<endl;
    }
};


//Factory and its conccretions

class Burgeractory{
   public:
    virtual Burger* createBurger(string & type)=0;
};

class SinghBurger :public Burgeractory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type =="standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
            return new PremiumBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
     }
};

class KingBurger :public Burgeractory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type =="standard"){
            return new StandardWheatBurger();
        }
        else if(type == "premium"){
            return new PremiumWheatBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
     }
};

//client side 
int main(){
    string type="basic";

    Burgeractory* myFactory = new KingBurger();
    Burger* burger = myFactory->createBurger(type);

    burger->prepare();
    
    return 0;
}