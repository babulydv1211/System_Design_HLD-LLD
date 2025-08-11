#include<iostream>
#include <string>
using namespace std;

//Reallife car
// yha ek class bna h car jiske car chlti h wah ek method class ke under declear h,yah ek interface h car se intract krne ka,yah ek car ka behavior h
class Car{
    public:
    virtual void startEngine()=0; // yaha virtual jo h method ko declear kiya h
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine() =0;
    virtual ~Car() {};

};

//uper min  jo abstract class  h usko excess ke liye chlid class bnate h
class SportsCar: public Car{
public:
   string brand;
   string model;
   bool isEngineOn;
   int currentSpeed;
   int currentGear;

   SportsCar(string b,string m){
     this->brand=b;
     this->model=m;
     isEngineOn=false;
     currentSpeed=0;
     currentGear=0;//netural

 }

 void startEngine(){
    isEngineOn=true;
    cout<<brand<<" "<<model<<":Engine starts with a roar!"<<endl;

 }

 void shiftGear(int gear){
    if(!isEngineOn){
        cout<<brand<<" "<<model<<":Engine is off! canot shift Gear."<<endl;
         
        return;
    }
    currentGear=gear;
    cout<<brand<<""<<model<<":Shift to gear"<<currentGear<<endl;
 }

void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<":Engine is off! Cannot accelerate."<<endl;
            return;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<":Accelerating to"<<currentSpeed<<"km/h"<<endl;
    
}

void brake(){
    currentSpeed-=20;
    if(currentSpeed<0) currentSpeed=0;
    cout<<brand<<" "<<model<<":Breaking! Speed is Now" <<currentSpeed<<"km/h"<<endl;
}

void stopEngine(){
    isEngineOn:false;
    currentGear=0;
    currentSpeed=0;
    cout<<brand<<" " <<model<<":Engine turn off."<<endl;
}

};

//mian method ke under call
int main(){
   Car* myCar= new SportsCar("ford","Mustang");

   myCar->startEngine();
   myCar->shiftGear(1);
   myCar->accelerate();
   myCar->shiftGear(2);
   myCar->accelerate();
   myCar->brake();
   myCar->stopEngine();

   delete myCar;
   return 0;



}