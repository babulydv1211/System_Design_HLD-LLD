#include<iostream>
#include<vector>
using namespace std;

class Product{
   public:
    string name;
    double price;

   Product(string name,double price){
    this->name=name;
    this->price=price;
   }
   
};


//1.shoppingCart:Only responsibility for Cart realted business logic
class ShoppingCart{
    private:
     vector<Product*> products;// store heap-allocated product

    public:
      void addProduct(Product* p){
        products.push_back(p);
      }

    const vector<Product*>& getProducts(){
        return products;
    }

    //calculate total price in cart
    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};


//2.ShoppingCartPrinter:only resopnsible for printing invoice
class ShoppingCartPrinter{
    private:
     ShoppingCart* cart; //refrance pass kiya shoping cart ka

    public:
     ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;

     }

    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";
        for(auto p:cart->getProducts()){
            cout<<p->name<<"₹"<<p->price<<endl;
        }
        cout<<"total:₹"<<cart->calculateTotal()<<endl;

    }

};

//3. ShoppingCArtStorage:only responsible for saving cart to database
class ShoppingCartStorage{
    private:
     ShoppingCart *cart;

    public:
      ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
      }

    void saveToDatabase(){
        cout<<"saving shopping cart to database..."<<endl;
    }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;
}