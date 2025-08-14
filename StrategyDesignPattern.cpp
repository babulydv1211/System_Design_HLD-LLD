#include<iostream>
using namespace std;

//--Strategy interface for walk
class WalkableRobot{
    public:
    virtual void walk()=0;
    virtual ~WalkableRobot(){}
};

//--concrete Strategies for walk--
class NormalWalk:public WalkableRobot{
    public:
    void walk() override{
        cout<<"Walking normal..."<<endl;
    }
};

class NoWalk:public WalkableRobot{
    public:
    void walk() override{
        cout<<"Cannot walk.."<<endl;
    }
};

//strategis for talkable--
class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){}
};


//concrete Strategies for Talk--

class NormalTalk:public TalkableRobot{
    public:
    void talk() override{
        cout<<"Talking normaly..."<<endl;
    }
};

class NoTalk:public TalkableRobot{
    public:
    void talk() override{
        cout<<"Cannot talk."<<endl;
    }
};


// strategy  interface flyable robot
class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual ~FlyableRobot() {}

};

class NormalyFly:public FlyableRobot{
    public:
    void fly()override{
        cout<<"Flying normaly"<<endl;
    }
};

class NoFly:public FlyableRobot{
    public:
    void fly() override{
        cout<<"Cannot fly."<<endl;
    }
};

//--Robot Base class


class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
Robot(WalkableRobot* w,TalkableRobot* t, FlyableRobot* f){ //ye constructor min pass kiya 
      this->walkBehavior=w;
      this->talkBehavior=t;
      this->flyBehavior=f;
   }
    
   void walk(){
    walkBehavior->walk();
   }
   void talk(){
    talkBehavior->talk();
   }
   void fly(){
    flyBehavior->fly();
   }

   virtual void projection()=0;  //abstract method for subclasses


};

//--Concrete Robot Types--

class CompanionRobot:public Robot{
    public:
    CompanionRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){}

    void projection() override{
        cout<<"Displaying  friendly companion features...."<<endl;
    }
};

class WorkerRobot:public Robot{
    public:
    WorkerRobot(WalkableRobot* w,TalkableRobot* t, FlyableRobot* f):Robot(w,t,f){}

    void projection() override{
        cout<<"Displaying  worker efficiency stats...."<<endl;
    }
};

int main(){
    Robot *robot1 = new CompanionRobot(new NormalWalk(),new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"------------"<<endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(),new NoTalk(),new NormalyFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

}