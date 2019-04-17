#include<iostream>
#include<algorithm>

int main() {
	std::string num = "1234567890";
	std::sort(begin(num), end(num));
	int iter = 0;
	std::cout << num << std::endl;
	for(; iter < 1e6 - 1; iter++)
		std::next_permutation(begin(num), end(num));
	std::cout << num;


}
