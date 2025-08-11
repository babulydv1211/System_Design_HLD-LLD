#include<iostream>
#include<vector>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class DepositOnlyAccount{
    public:
    virtual void deposit(double amount)= 0;
};

class WithdrawableAccount: public DepositOnlyAccount{  //yaha inheritance withdraW ke sath depositer bhi aa gya
    public:
    virtual void withdraw(double amount) =0;
};
class SavingAccount : public WithdrawableAccount {
private:
    double balance;
public:
    SavingAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited " << amount << " in saving Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdraw: " << amount << " from saving Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in saving Account!\n";
        }
    }
};


class CurrentAccount:public WithdrawableAccount{
    private:
     double balance;

    public:
    CurrentAccount(){
       balance=0;
    }
    void deposit(double amount){
          balance +=amount;
        cout<<"Deposited"<<amount<<"in current Account.New balance"<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdraw:"<<amount<<"from Current Accout.New balance"<<balance<<endl;
        }else{
        cout<<"Insufficient funds in Current Account \n";
    }
        
    }

};

class FixedTermAccount:public DepositOnlyAccount{
    private:
     double balance;

    public:
      FixedTermAccount(){
        balance=0;
      }

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited"<<amount<<"in fixed Term Account> New Balance:"<<balance<<endl;
    }

};

class BankClient{
    private:
    vector<WithdrawableAccount*>withdrawableAccounts;
    vector<DepositOnlyAccount*>depositOnlyAccounts;

    public:
    BankClient(vector<WithdrawableAccount*>withdrawableAccounts,
     vector<DepositOnlyAccount*>depositOnlyAccounts){
        this->withdrawableAccounts=withdrawableAccounts;
         this->depositOnlyAccounts=depositOnlyAccounts;
     }
    
    void processTransactions(){
        for(WithdrawableAccount* acc: withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
   for(DepositOnlyAccount* acc: depositOnlyAccounts){
    acc->deposit(5000);
   }

}    
    
};


int main(){
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*>depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient( withdrawableAccounts,depositOnlyAccounts);
    client->processTransactions();
}