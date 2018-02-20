#include <iostream>
#include <bitset>
#include <math.h>


//reference for math library functions
int main() {

	double log_int_max = log(INT_MAX);
	double log_3 =log(3);

	log_int_max /= log_3;
	int power_val = floor(log_int_max);

	std::cout<<power_val<<std::endl;
	//highest power of three that fits in integer
	int highest_three_power = pow(3,power_val);
	std::cout<<highest_three_power<<std::endl;
	int n = 2187;
	n = 2188;
	n = -2188;
	n = 2188;
	if(n>0 && highest_three_power%n == 0)
		std::cout<<"divisible"<<std::endl;
	else
		std::cout<<"not divisible"<<std::endl;
	return 0;
}