#include<iostream>
#include<string>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
   Car(string b,string m){
    this->brand=b;
    this->model=m;
    isEngineOn:false;
    currentSpeed=0;
   }
//common method for all cars
void startEngine(){
    cout<<brand <<" "<<model<<":Engine started."<<endl;
}

void stopEngine(){
    isEngineOn= false;
    currentSpeed=0;
    cout<<brand<<" " <<model << ":Engine trun off."<<endl;

}

void accelerate(){
    if(!isEngineOn){
        cout<<brand<<" "<<model<<"cannot accelerate Engine is off"<<endl;
        return;
    }
    currentSpeed+=20;
    cout<<brand<<" "<<model<<" :Acceletrating to"<<currentSpeed<<"km/h"<<endl;
}

void brake(){
    currentSpeed-=20;
    if(currentSpeed<0) currentSpeed=0;
    cout<<brand<<" "<< model <<" Braking ! Speed is now"<<currentSpeed <<"km/h"<<endl;
}

virtual ~Car(){}

};

class ManualCar :public Car {  //inharite from car
    private:
    int currentGear;  //spcific to manual Car

public:
  ManualCar(string b,string m):Car(b,m){
    currentGear=0;
  }
  //Specialized method for manual car
  void shiftGear(int gear){
    currentGear=gear;
    cout<<brand<<" "<<model<<":Shifted to gear" <<currentGear<<endl;
  }

};

class ElectricCar:public Car{
private:
int batteryLevel;

public:
    ElectricCar(string b,string m):Car(b,m){
        batteryLevel=100;
    }
   //specialized method for electric car
   void chargeBattery(){
    batteryLevel=100;
    cout<<brand<<" "<< model <<":Battery fully charged"<<endl;
   }

};

int main(){
    ManualCar* myManualCar = new ManualCar("suzuki","WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"............."<<endl;


}