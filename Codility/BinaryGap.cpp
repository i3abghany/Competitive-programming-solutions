#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

using std::cin;
using std::cout; 

int solution(int N) {
	std::bitset<32> rep(N);
	std::string num(rep.to_string());
	const auto first_digit = num.find('1');
	if (first_digit != std::string::npos)
		num = num.substr(first_digit);
	int mx{}, curr_mx{};
	std::string::size_type pos = num.find('0', 0);
	const size_t sz = num.length();
	while(pos != std::string::npos) {
		size_t i = pos;
		curr_mx = 1;
		while (num[++i] == '0')
			curr_mx++;
		if (i != sz) {
			mx = std::max(mx, curr_mx);
		}
		pos = num.find('0', pos + curr_mx);
	}
	return mx;
}
