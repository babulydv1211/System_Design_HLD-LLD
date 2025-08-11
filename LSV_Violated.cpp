#include<iostream>
#include<vector>
using namespace std;

class Account{

    public:
     virtual void deposit(double amount)= 0;
     virtual void withdraw(double amount)=0;
};

class SavingAccount:public Account{
    private:
    double balance;

    public:
      SavingAccount(){
        balance=0;
      }

    void deposit(double amount){
        balance += amount;
        cout<<"Deposited"<<amount<<"in saving Account.New balance"<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >=amount){
            balance-=amount;
            cout<<"Withdraw:"<<amount<<"from saving Account.New Balance"<<balance<<endl;
        }
        else{
            cout<<"Insuuicient funds in saving account!\n";
        }
    }
};

class CurrentAccount:public Account{
    private:
    double balance;

    public:
      CurrentAccount(){
        balance=0;
      }

    void deposit(double amount){
        balance += amount;
        cout<<"Deposited"<<amount<<"in saving Account.New balance"<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >=amount){
            balance-=amount;
            cout<<"Withdraw:"<<amount<<"from current Account.New Balance"<<balance<<endl;
        }
        else{
            cout<<"Insuuicient funds in current account!\n";
        }
    }
};



class FixedTermAccount:public Account{
private:
double balance;
public:
FixedTermAccount(){
    balance=0;
}

 void deposit(double amount){
    balance+= amount;
    cout<<"Deposited"<<amount<<"in fixed Term account.New balance:"<<balance<<endl;

 }

 void withdraw(double amount){
    throw logic_error("Withdraw not allow in fixed term account");
 }

};

class BankClient{
    private:
     vector<Account*>accounts;

    public:
    BankClient(vector<Account*>accounts){
        this->accounts=accounts;

    }

    void processTransactions(){
        for(Account* acc : accounts){
            acc->deposit(1000);  //all account allow deposits
        

        try{
            acc->withdraw(500);
        }
        catch(const logic_error& e){
           cout<<"Exceptioin:"<<e.what()<<endl;
        }
    }
    }

};

int main(){
    vector<Account*>accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();
    
    return 0;
}