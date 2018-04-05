//
// Created by sai madan mohan reddy  patlolla on 4/5/18.
//


//An abstract class is a class that is designed to be specifically
//used as a base class. An abstract class contains at least one pure
// virtual function. You declare a pure virtual function by using a
// pure specifier (= 0) in the declaration of a virtual member function
// in the class declaration.
//https://stackoverflow.com/questions/9756893/how-to-implement-interfaces-in-c

#include <iostream>
#include <unordered_map>
using namespace std;

class IKeyValueInterface
{
public:
    IKeyValueInterface(){}
    virtual ~IKeyValueInterface(){}
    virtual int get(int k) = 0;
    virtual void put(int k,int v) = 0;
    void who_am_i(){
        cout<<"i am an interface"<<endl;
    }
};

class KeyValueStore:public IKeyValueInterface{
private:
    unordered_map<int,int> hash;
public:
public:
    KeyValueStore(){}
    ~KeyValueStore(){}
    int get(int key){
        if(this->hash.find(key) == this->hash.end()){
            return -1;
        } else{
            return hash[key];
        }
    }
    void put(int key,int value){
        hash[key] = value;
    }
    void who_am_i(){

    }
};

int main(){
    KeyValueStore *ks = new KeyValueStore();
    ks->who_am_i();
    ks->put(10,5);
    cout<<ks->get(10);
}