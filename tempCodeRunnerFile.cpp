#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//ek abstract for document class
class DocumentElement{
    public:
    virtual string render()=0;
};


//concrete implementation for text elements
class TextElement:public DocumentElement{
    private:
     string text;
    public:
     TextElement(string text){
        this->text=text;
     }
    string render()override{
        return text;
    }
};

//Concrete implement for image elements
class ImageElement: public DocumentElement {
    private:
    string imagepath;

    public:
     ImageElement(string imagePath){
        this->imagepath=imagePath;
     }
     string render()override{
        return "[Image:"+imagepath+"]";
     }
};

//new line element repersent a line break in the document.
class NewLineElement:public DocumentElement{
    public:
    string render()override{
        return "\n";
    }
};

//newtabspaceElement repersent a tab space in the document.
class TabSpaceElement : public DocumentElement{
    public:
     string render()override{
        return "\t";
     }
};

//Document class responsible for holding a collection of elements

class Document{
    private:
     vector<DocumentElement*>DocumentElements;

    public:
    void addElement(DocumentElement* element){
        DocumentElements.push_back(element);
    }

    string render(){
        string result;
        for(auto element:DocumentElements){
            result+=element->render();
        }
        return result;
    }
};

//persistence class interface
class Persistence {
    public:
    virtual void save(string data) =0;
};

//fileStorage implementation of Persistence

class FileStorage:public Persistence{
    public:
    void save(string data) override{
        ofstream outFile("document.txt");
        if(outFile){
            outFile<<data;
            outFile.close();
            cout<<"Document save to document.txt"<<endl;

        }
        else{
            cout<<"Error:unable to open  file for writing."<<endl;
        }
    }
};


//DocumnetEditor class managing client interactiopns

class DocumentEditor {
    private:
    Document* document;
    Persistence* storage;
    string renderedDocument;
    public:
    DocumentEditor(Document* document,Persistence* storage){
     this->document=document;
     this->storage=storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    //add space tab to the document
    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }
    void saveDocument(){
        storage->save(renderDocument());
    }

};

//client usage example
int main(){
    Document* document = new Document();
    Persistence* persistence = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(document,persistence);

    //simulate a client using the editor with common text forwading features
    editor->addText("Hello,World!");
    editor->addNewLine();
    editor->addText("This is real-world document editor exmple.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout<<editor->renderDocument()<<endl;
    editor->saveDocument();
    return 0;
}
