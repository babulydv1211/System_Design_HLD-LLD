#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//Abstract Observer interface: subscribers must implement update()

class ISubscriber{
    public:
     virtual void update()=0;
     virtual ~ISubscriber() {} //virtual destructor for interface
};

//Abstract Observable interface: a youtube channel interface

class IChannel{
    public:
    virtual void subscribe(ISubscriber* subscribe)= 0;
    virtual void unsubscribe(ISubscriber* subscriber)= 0;
    virtual void notifySubscribers()=0;
    virtual ~IChannel() {} //distructor ye interface h
};

//Concrete Subject :a Youtube channel

class Channel :public IChannel {
    private:
     vector<ISubscriber*>subscribers;
     string name;
     string latestVideo;
    public:
    Channel(const string& name){
        this->name=name;
    }

    //Add a subscriber
    void subscribe(ISubscriber* subscriber) override{
        if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }

    //Remove a subscriber if present
    void unsubscribe(ISubscriber* subscriber) override{
        auto it = find(subscribers.begin(),subscribers.end(),subscriber);
        if(it!=subscribers.end()){
            subscribers.erase(it);
        }
    }

    //notify all subscriber of the latest video
    void notifySubscribers() override{
        for(ISubscriber* sub : subscribers){
            sub->update();
        }
    }

    //Upload a new video and notify all subscribers
    void uploadVideo(const string& title){
        latestVideo=title;
        cout<<"\n["<<name<<"uploaded \""<<title<<"\"]\n";
        notifySubscribers();
    }

    //Read video data
    string gteVideoData(){
        return "\nCheckout our new Video:"+latestVideo+"\n";
    }
};

//concrete Observer:repersent a subscriber

class Subscriber:public ISubscriber{
    private:
    string name;
    Channel* channel;
    public:
    Subscriber(const string& name,Channel* channel){
        this->name=name;
        this->channel=channel;
    }

    //called by channel:prints notification message
    void update() override{
        cout<<"Hey"<<name<<","<<this->channel->gteVideoData();
    }

};

int main(){
    //create a channel and subscribers

    Channel* channel = new Channel("CodeKiller");
    Subscriber* sub1 = new Subscriber("Varun",channel);
    Subscriber* sub2 = new Subscriber("Tarun",channel);

    //Varun and tarun subscribe to codekiller
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    //uplaod a video:both varun and tarun are notified
    channel->uploadVideo("Observer pattern Tuotorial");

    //varun unsubscribe:Tarun remains subscribe
    channel->unsubscribe(sub1);

    channel->uploadVideo("Decorator Pattern Tutorial");
    
    return 0;

}