#include<iostream>
#include<string>

using namespace std;

//component Interface :define a common interface for Mario and all power-up decoration
class Character{
   public:
   virtual string getAbilities() const =0;
   virtual ~Character() {} //virtual destructor
};

//Concrete componenet :Basic Mario character with no power-ups
class Mario: public Character{
    public:
    string getAbilities() const override{
        return "Mario";
    }
};

//Abstract decorator

class CharacterDecorator : public Character {
    protected:
     Character* character; //refrace Wrapped componet(has a realation)
     public:
     CharacterDecorator(Character* c){
        this->character = c;
     }
};

//concret decorartor Height-Increasing

class HeightUp : public CharacterDecorator {
    public:
    HeightUp(Character* c):CharacterDecorator(c){}
    string getAbilities() const override{
       return character->getAbilities()+"with HeightUp";
    }
};


//Concrete Decorator:Gun shooting powe-Up
class GunPowerUp: public CharacterDecorator{
    public:
    GunPowerUp(Character* c):CharacterDecorator(c){}
      string getAbilities() const override{
        return character -> getAbilities()+"with Gun";
      
    }
};

//concret star powerdecorator

class StarPowerUp: public CharacterDecorator{
    public:
    StarPowerUp(Character* c):CharacterDecorator(c){}
      string getAbilities() const override{
        return character -> getAbilities()+"with Star Power (Limited Time)";
      
    }
    ~StarPowerUp(){
        cout<<"Destroying StarPowerUp decorator" <<endl;
    }
};

int main(){
    // create a basic mario character.
    Character* mario = new Mario();
    cout<<"Basic Character:"<<mario->getAbilities() <<endl;

    //Decorate mario with a Helping power-up
    mario = new HeightUp(mario);
    cout<<"After Heightup:" << mario->getAbilities()<<endl;

    //decorate Mario further with a GunPowerup.
    mario = new GunPowerUp(mario);
    cout<<"After GunPowerUp:" <<mario->getAbilities()<<endl;

    //Finally add a starPowerUp decoration
    mario = new StarPowerUp(mario);
    cout<<"After StarPowerUp:" <<mario->getAbilities() <<endl;

    delete mario;
    return 0;
}