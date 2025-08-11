#include<iostream>

using namespace std;


//sub class method should not be allowd state change 
//base class nver allowed

class BankAccount{
    protected:
     double balance;
    
    public:
      BankAccount(double b) {
        if(b<0) throw invalid_argument("Balance can't be negative");
        balance = b;
      }

      //history Constrain:withdraw should be allowed
      virtual void withdraw(double amount){
        if(balance-amount<0) throw runtime_error("Insufficient funds");
        balance-= amount;
        cout<<"Amount withdraw.Reamaing balace is"<< balance<<endl;
      }

};

class FixedDepositAccount:public BankAccount{
    public:
     FixedDepositAccount(double b):BankAccount(b) {};
     //Lsp beark! histroy constraint broke!
     //Parent class behavior change:Now withdraw is not allow.
     //this class will brake client code that relis on withdraw.
     void withdraw (double amount) override{
        throw runtime_error("withdraw not allowed in fixed Deposite");
     }
};

int main(){
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
}