#include<iostream>
using namespace std;

//Abstract (interface)
class Database{
  public:
   virtual void save(string data )=0;
};

//MySQL implimentation(low-levevl module)

class MySQLDatabase:public Database{
    public:
      void save(string data) override{
        cout<< "Excuting SQL Query:INSERT INTO   users Value(' "<<data<<" ');"<<endl;
      }
};

//MongoDb implementation

class MongoDBDatabase:public Database {
    public:
    void save(string data) override{
         cout<<"Executiing MongoDb function:db.users.insert({name:' "<<data<<" '})"<<endl;
    }
};

//Heigh-level module(Now loosely coupled)

class UserService{
    private:
    Database*db; //Dependency injection

    public:
    UserService(Database* database){
        db=database;
    }
    void storeUser(string user){
        db->save(user);
    }
};

int main(){
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("C++");


    UserService service2(&mongodb);
    service2.storeUser("c");
}