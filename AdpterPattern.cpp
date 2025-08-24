#include<iostream>
#include<string>

using namespace std;

//Target interface expected by client
class IReports{
    public:
     virtual string getJsonData(const string data)=0;
     virtual ~IReports(){}
};

//2.Adaptee:provider Xml data from raw input
class XmlDataProvider{
    public:
     string getXmlData(const string& data){
        size_t sep = data.find(":");
        string name = data.substr(0,sep);
        string id = data.substr(sep+1);
     //Build and xml repersentaion
     return "<user>"
             "<name>"+name+"</name>"
             "<id>" +id + "</id>"
             "<user>";
     }
};


//3.build an adapter
class XmlDataProviderAdapter:public IReports{
    private:
     XmlDataProvider* xmlDataProvider; //adapter has a provider 3rd party app
     public:
     XmlDataProviderAdapter(XmlDataProvider* provider){
        this->xmlDataProvider=provider;
     }

     string getJsonData(const string data) override{
        string xml = xmlDataProvider->getXmlData(data); //xml data call adapter
        //xml convert into json data
        size_t startName= xml.find("<name>")+6;
        size_t endName= xml.find("</name>");
        string name = xml.substr(startName,endName-startName);

        size_t startId = xml.find("<id>")+4;
        size_t endId = xml.find("</id>");
        string id = xml.substr(startId,endId-startId);

        //#.bulid and return Json
        return "{\"name\":\""+name+ "\",\"id\":"+id+"}";
     }

};

class Client{
    public:
    void getReport(IReports* report, string rawData){
        cout<<"Processed Json:"
        <<report ->getJsonData(rawData)<<endl;
    }
};

int main(){
    //create the aadpter

    XmlDataProvider* xmlProv = new XmlDataProvider();
    //make our adaptor
    
    IReports* adapter = new XmlDataProviderAdapter(xmlProv);

    string rawData="Alice:42";
    //client print the json
    Client* client = new Client();
    client->getReport(adapter,rawData);

    delete adapter;
    delete xmlProv;
    return 0;
}

