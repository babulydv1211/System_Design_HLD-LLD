#include<iostream>
using namespace std;

class User{
public:
// Precondition:Password must be at least 8 charector long
virtual void setPassword(string password){
    if(password.length()<8){
      throw invalid_argument("Password must be at least 8 characters long!");

    }
    cout<<"Password set successfully"<<endl;
 }
};


class AdminUser:public User{
public:
  //Precondtion:Password must be at least 6 characters
  void setPassword(string password) override{
    if(password.length()<6){
        throw invalid_argument("password must be at least 6 character long!");
    }
    cout<<"Password set successfully"<<endl;
  }
  

};

int main(){
    User* user = new AdminUser();
    user->setPassword("Admin1");
    
    return 0;
}