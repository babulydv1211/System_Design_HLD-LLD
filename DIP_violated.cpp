#include<iostream>
using namespace std;

//database bnaya
class MySQLDatabase {  //low elevel module
    public:
      void saveToSQL(string data){
        cout << "Excuting SQL Query:INSERT INTO   users Value(' "<<data<<" ');"<<endl;

    }
};

//data base bnaya
class MongoDBDatabase{  //low lvevl module
public:
 void saveToMongo(string data){
  cout<<"Executiing MongoDb function:db.users.insert({name:' "<<data<<" '})"<<endl;
 }
};

class UserService{  // heigh level module )tightly coupled
    private:
    MySQLDatabase sqlDb; //direct dependecy on MySQl
    MongoDBDatabase mongoDb; //Direct dependency on MongoDb


public:
    void storeUserToSQL(string user){
        sqlDb.saveToSQL(user);
    }
    void storeUserToMongo(string user){
        mongoDb.saveToMongo(user);
    }
};

int main(){
    UserService service;
    service.storeUserToSQL("Java language");
    service.storeUserToMongo("Raj");

}