#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
    auto algorithm = [&]( double x, double m, double b ) -> double
   {
       return m*x+b;
   };

    int a=algorithm(1,2,3), b=algorithm(4,5,6);

    return 0;
}