//
// Created by sai madan mohan reddy  patlolla on 4/5/18.
//


//An abstract class is a class that is designed to be specifically
//used as a base class. An abstract class contains at least one pure
// virtual function. You declare a pure virtual function by using a
// pure specifier (= 0) in the declaration of a virtual member function
// in the class declaration.
//https://stackoverflow.com/questions/9756893/how-to-implement-interfaces-in-c
//abstract class constructor should not be virtual
//to facilitate the initialization of the private members of the abstract class
// destructor can be virtual
#include <iostream>
#include <unordered_map>
using namespace std;

class IKeyValueInterface
{
private:
    int enc_key;
public:
    IKeyValueInterface(int enc_key){
        this->enc_key = enc_key;
    }
    virtual ~IKeyValueInterface(){}
    virtual int get(int k) = 0;
    virtual void put(int k,int v) = 0;
    void who_am_i(){
        cout<<"i am an interface "<<this->enc_key<<endl;
    }
};

class KeyValueStore:public IKeyValueInterface{
private:
    unordered_map<int,int> hash;
public:
public:
    KeyValueStore(int enc_key):IKeyValueInterface(enc_key){}
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
//    void who_am_i(){
//
//    }
};

int main(){
    KeyValueStore *ks = new KeyValueStore(10);
    ks->who_am_i();
    ks->put(10,5);
    cout<<ks->get(10);

}