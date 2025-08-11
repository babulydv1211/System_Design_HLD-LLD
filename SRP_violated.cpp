#include<iostream>
#include<vector>
using namespace std;


// prduct class responsibility any item of  any Ecommerce

class Product{
    public:
        string name;
        double price;

      Product(string name,double price){  //ye constructer bnya h
        this->name=name;
        this->price=price;
      }
};

//volitaing SRP:shoppingCart is handle multiple responsibility
class ShoppingCart{
private:
      vector<Product*>products;

public:
   void addProduct(Product* p){
    products.push_back(p);
   }

  const vector<Product*>&getProducts(){
    return products;
  }

  //1.calculate taotal price in cart.
  double calculateTotal(){
    double total =0;
    for(auto p:products){
        total+=p->price;
    }
    return total;
  }

 //2.voliting SRP -Prints invoice(should be in a seprate class)
 void printInvoice(){
    cout<<"Shopping Cart Invoice:\n";
    for(auto p:products){
        cout<<p->name<<":-$" <<p->price<<endl;
    }
    cout<<"Total :$"<<calculateTotal()<<endl;
 }

  //3.Voilating SRP -save to database(should be in seprate class
  void saveToDatabase(){
    cout<<"saving shopping cart to database..."<<endl;
  }

};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("Mouce",50));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}