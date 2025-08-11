#include<iostream>
#include<stdexcept>
using namespace std;

//Single interface for all shape (Voilates ISP)

class Shape{
    public:
     virtual double area()=0;
     virtual double volume()= 0; //2D shape dont have volume

};

class Square:public Shape{
    private:
    double side;

    public:
    Square( double s): side(s){}

    double area() override {
        return side * side;
    }

    double volume() override{
        throw logic_error("Volume not applicable for Square");
    }
};


class Rectangle:public Shape{
    private:
     double length,width;

    public:
     Rectangle(double l,double w):length(l),width(w){};
     double area() override{
        return length* width;
     }

      double volume() override{
        throw logic_error("Volume not applicable for Rectangle");
    }

};

class Cube: public Shape{
    private:
     double side;

    public:
     Cube(double s):side(s){}
     
    double area() override{
        return 6* side* side;
    }
    double volume() override{
        return side* side* side;
    }
};

int main(){
     Shape* square = new Square(5);
     Shape* rectangle = new Rectangle(4,6);
     Shape* cube = new Cube(3);

     cout<<"Shape Area:"<<square->area()<<endl;
     cout<<"Reactangle:"<<rectangle->area()<<endl;
     cout<<"Cube Area:"<<cube->area()<<endl;

     try{
        cout<<"Square Volume:"<<square->volume()<<endl;
     }catch(logic_error& e){
        cout<<"Exception"<<e.what()<<endl;
     }
}