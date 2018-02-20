#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
   int x = 4;
   int b[]={1,2*2,3*3};
   int *a = &b[0];
   int &c = x;
   //char *s ="abc";
   for(int i=0;i<3;i++){
   		cout<<a[i]<<endl;
   }
   cout<<c<<endl;
   //&c = b[0];
   cout<<x<<endl;

   x =11;
   cout<<c<<endl;
   return 0;
}