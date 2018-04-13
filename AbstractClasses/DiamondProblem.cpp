//
// Created by sai madan mohan reddy  patlolla on 4/6/18.
//


#include <iostream>
using namespace std;
class A
{
public:
    void  display(){
        cout<<"in Base class A"<<endl;
    }
};

class B:virtual public A{

};
class C:virtual public A{

};

class D:public B,public C{

};
int main(){
    D d;
    d.display();
    return 0;
}