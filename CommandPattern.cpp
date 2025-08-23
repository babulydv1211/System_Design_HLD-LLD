#include<iostream>
using namespace std;

//command interface
class Command{
    public:virtual void excute() = 0;
    virtual void undo()=0;
    virtual ~Command() {};
};

//Reciver
class Light{
    public:
     void on(){
        cout<<"Light is On"<<endl;
     }
     void off(){
        cout<<"Light is OFF"<<endl;
     }
};

class Fan{
    public:
     void on(){
        cout<<"fan is On"<<endl;
     }
     void off(){
        cout<<"Fan is Off"<<endl;
     }
};

//concrete Command for Light
class LightCommand:public Command{
    private:
     Light* light;
    public:
     LightCommand(Light* l){
        light=l;
     }
     void excute(){
        light->on();
     }
     void undo(){
        light->off();
     }
};

//concrete command for fan
class FanCommand:public Command{
  private:
  Fan* fan;
  public:
  FanCommand(Fan* f){
    fan=f;
  }
  void excute(){
    fan->on();
  }
  void undo(){
    fan->off();
  }
};

//Remoate controller
class RemoteController{
    private:
    static const int numButtons=4;
    Command* buttons[numButtons];
    bool buttonPressed[numButtons];

public:
 RemoteController(){
    for(int i=0;i<numButtons;i++){
        buttons[i]=nullptr;
        buttonPressed[i]=false;
    }
 }
   
void setCommand(int idx,Command* cmd){
    if(idx>=0 && idx<numButtons){
        if(buttons[idx]!=nullptr);
         delete buttons[idx];
         buttons[idx]=cmd;
         buttonPressed[idx]=false;
    }
}

void pressButton(int idx){
    if(idx>=0 && idx <numButtons && buttons[idx] !=nullptr){
        if(buttonPressed[idx]==false){
            buttons[idx]->excute();
        }else{
            buttons[idx]->undo();
        }
        buttonPressed[idx]=!buttonPressed[idx];

    } else{
        cout<<"No command assigned at button"<<idx<<endl;
    }
}

 ~RemoteController(){
    for(int i=0;i<numButtons;i++){
        if(buttons[i] !=NULL)
        delete buttons[i];
    }
 }

};

int main(){
    Light* livingRoomLight = new Light();
    Fan* ceilingFan = new Fan();

    RemoteController* remote = new RemoteController();
    remote->setCommand(0,new LightCommand(livingRoomLight));
    remote->setCommand(1,new  FanCommand(ceilingFan));

    // button press
    cout<<"---Toggling Light Button 0 --"<< endl;
    remote->pressButton(0); //on
    remote->pressButton(0);//off

    //press unassigned button to show default message
    cout<<"---Pressing Unassigned Button 1" <<endl;
    remote->pressButton(1); //on
    remote->pressButton(1);//off
    
    // Press unassigned button to show default message
    cout<< "----Pressing Unassigned Button 2 ----"<<endl;
    remote->pressButton(2);
   
    //clean up
    delete remote;
    delete livingRoomLight;
    delete ceilingFan;

    return 0;

}