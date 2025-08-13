#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class DocumentEditor {
    private:
     vector<string>documentElements;
     string renderedDocument;

   public:
   //Add text as a plain string
   void addText(string text){
    documentElements.push_back(text);
   }

   void addImage(string imagePath){
     documentElements.push_back(imagePath);
   }

   //Renders the documnet by checking the type of each element at runtime
   //ye business logic h
   string renderDocument() {
     if(renderedDocument.empty()){
        string result;

        for( auto element:documentElements){ //image pata lgne ka logic
            if(element.size()>4 &&(element.substr(element.size()-4)==".jpg"|| 
            element.substr(element.size() -4 ) == ".png")){
                result+="[Image:"+element+"]"+"\n";
            }else{
                result+=element+"\n";
            }
        }
        renderedDocument=result;
     }
     return renderedDocument;
   }
    
   //file save logic
   void saveToFile(){
    ofstream file("document.txt");
    if(file.is_open()){
        file<<renderDocument();
        file.close();
        cout<<"Document saved to document.txt"<<endl;
    }else{
        cout<<"Error:unable to open file for writing."<<endl;
    }
   }
};


//this client code
int main(){
    DocumentEditor editor;
    editor.addText("Hello,World");
    editor.addImage("picture.jpg");
    editor.addText("This is a document editior.");
    cout<<editor.renderDocument()<<endl;
    editor.saveToFile();

    return 0;
}