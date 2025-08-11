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

//1.Shoping cart:only responsible for Cart realted business logic

class ShoppingCart{
    private:
    vector<Product*> products; //store heap-allocation products

    public:
    void addProduct(Product* p){
       products.push_back(p);
    }


  const vector<Product*>&getProducts(){
    return products;
  }

  //calculate total price in cart.
  double calculateTotal(){
    double total=0;
    for(auto p:products){
        total +=p->price;
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


//3. ShopingCartStorage:only response for saving cart to DB
class ShoppingCartStorage{
    private:
     ShoppingCart* cart;

    public:
     ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
     }

    void saveToSQLDatabase(){
        cout<<"Saving shoping cart to SQL DB ..."<<endl;
    }
    void saveToMongoDatabase(){
        cout<<"Saving shopping cart to mongo DB.."<<endl;

    }
    void saveToFile(){
        cout<<"Saving shoping cart to file..."<<endl;
    }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop",1550));
     cart->addProduct(new Product("mouse",550));

     ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
     printer->printInvoice();

     ShoppingCartStorage* db = new ShoppingCartStorage(cart);
     db->saveToSQLDatabase();
     return 0;

}