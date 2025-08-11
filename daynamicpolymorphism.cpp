#include<iostream>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
public:
   Car(string brand,string model){
    this->brand=brand;
    this->model=model;
    this->isEngineOn=false;
    this->currentSpeed=0;
   }

   //commomn method for All cars;
   void startEngine(){
    isEngineOn= true;
    cout<<brand<<" "<< model <<":Engine started"<<endl;
   }

   void stopEngine(){
    isEngineOn= false;
    currentSpeed=0;
    cout<<brand<<" "<<model<<":Engine turned off"<<endl;
   }

   virtual void accelerate()=0; //abstract method for daynamic polymorphism
   virtual void brake()=0;   ////abstract method for daynamic polymorphism
   virtual ~Car(){}  //Viratual destuctor

};

class ManualCar:public Car{
private:
int currentGear;
public:
    ManualCar(string brand,string model):Car(brand,model){
       this->currentGear=0;
 }
//Specialized method for manual Car

void shiftGear(int gear){
    currentGear=gear;
    cout<<brand<<" "<<model <<":shifted to gear"<<currentGear<<endl;
}

//overriding accelerate-daynamic polymorphism
void accelerate(){
    if(!isEngineOn){
        cout<<brand <<" "<< model<<"Cannot accelerate! Engine is off."<<endl;
        return;
    }
    currentSpeed+=20;
    cout<<brand<<" "<<model<<":Braking !speed is now "<<currentSpeed<<"km/h"<<endl;
}
//overriding brake -daynamic polymorphism

  void brake(){
    currentSpeed-=20;
    if(currentSpeed<0) currentSpeed =0;
    cout<<brand<<" "<<model<<" :Braking !speed is now "<<currentSpeed<<"km/h"<<endl;
  }
};


class ElectricCar:public Car{
    private:int batteryLevel;

public:
ElectricCar(string brand,string model):Car(brand,model){
      
      this->batteryLevel=100;
      cout<<brand<<" " <<model<<"Battery fully charged"<<endl;
}

//overriding accelerate-daynamic polymorphism
void accelerate(){
    if(!isEngineOn){
        cout<<brand <<" "<< model<<"Cannot accelerate! Engine is off."<<endl;
        return;
    }
    if(batteryLevel<=0){
        cout<<brand<<""<<model<<":Battery dead! Cannot accelerate."<<endl;
        return;
    }
    batteryLevel-=10;
    currentSpeed+=15;
    cout<<brand<<" "<<model<<":Accelerating to "<<currentSpeed<<"km/h.Battery at"<<batteryLevel<<"%"<<endl;

}
//overriding brake -daynamic polymorphism

  void brake() {
    currentSpeed -=15;
    if(currentSpeed < 0) currentSpeed = 0;
    cout << brand <<" " << model << " :Regenrating braking !speed is now "<<currentSpeed<<"km/h.Battery at"<<batteryLevel<<"%"<<endl;
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
   
    ElectricCar* myElectricCar = new ElectricCar("Tesla","model s");
    
     myElectricCar->startEngine();
     myElectricCar->accelerate();
     myElectricCar->brake();
     myElectricCar->startEngine();
     delete myElectricCar;

     return 0;
}