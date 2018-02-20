#include <iostream>
#include <bitset>

int main() {
	//int num=-15;
	int num = -2147483648;
	int ones_complement = ~num;
	int twos_complement = ones_complement+1;
	
	std::cout<<num<<std::endl;
	std::bitset<32> number(num);
	std::cout<<number<<std::endl;

	std::cout<<ones_complement<<std::endl;
	std::bitset<32> number_ones_complement(ones_complement);
	std::cout<<number_ones_complement<<std::endl;

	std::cout<<twos_complement<<std::endl;
	std::bitset<32> number_twos_complement(twos_complement);
	std::cout<<number_twos_complement<<std::endl;

	// for(int i=0;i<32;i++){
	// 	std::cout<<i<<"	"<<~i+1<<std::endl;
	// }
	return 0;
}