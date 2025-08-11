#include<iostream>
#include<string>

using namespace std;


// encapsulation h ek class ke under car ka char or behavior h
class SportsCar{
private:
    //characters it meant varibale declear
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;


public:
   SportsCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
        currentGear=0;
        tyre="MRF";
    }
     
    //getter and setter

    int getCurrentSpeed(){
        return this->currentSpeed;
    }
    
    string getTyre(){
        return this->tyre;
    }

    void setTyre(string tyre){
        this->tyre=tyre;
    }

    //behaviours ->>methods
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
};

};


//main method
int main(){
  
  SportsCar* mySportsCar = new SportsCar("ford","musting");
   mySportsCar->startEngine();
   mySportsCar->shiftGear(1);
   mySportsCar->accelerate();
   mySportsCar->shiftGear(2);
   mySportsCar->accelerate();
   mySportsCar->brake();
   mySportsCar->stopEngine();
   
  //setting arbitrary value to speed
//   mySportsCar->currentSpeed = 500;

//   cout<<"Current Speed of my Sports car is set to :" <<mySportsCar->currentSpeed<<endl;
  
  cout<< mySportsCar ->getCurrentSpeed();
   delete mySportsCar;
   return 0;
}