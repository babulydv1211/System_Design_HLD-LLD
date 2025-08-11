#include<iostream>

using namespace std;

// A postcondtion must be statisfied after the method is excute.

class Car{
    protected:
      int speed;

    public:
    Car(){
        speed=0;
    }
    void accelerate(){
        cout<<"Accelerating"<<endl;
        speed+=20;
    }

    //post condtion:Speed must reduce after brake
    virtual void brake(){
        cout<<"Applying brakes"<<endl;
        speed-=20;
    }
};

//subclass can strenthen postcondition - Does not valid Lsp

class HybridCar:public Car{
    private:
    int charge;
    public:
    HybridCar():Car(){
        charge=0;
    }
    //post condtion:speed must reeduce after brake
   // postCondition:charge must increase

   void brake(){
    cout<<"Applying brake:speed reduce of car"<<endl;
    speed-=20;
    charge+=10;
   }
};

int main(){
    Car* hybridCar = new HybridCar();
    hybridCar->brake(); //any car clent use kre brake dabane per speed reduce hoga
    
    return 0;
}