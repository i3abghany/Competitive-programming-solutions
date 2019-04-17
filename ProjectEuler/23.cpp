#include<iostream>
#include<unordered_set>

using namespace std;

const int LIMIT = 28123;

bool is_abundant(int N) {
	int sum = 1; int i; 
	for(i = 2; i*i <= (N); i++)
		if(N % i == 0) {
			sum += i;
			if(N / i != i)
				sum += N / i;
		}
	return (sum > N);
}

int main() {
	unordered_set<int> abundant_nums;	
	for(int i = 1; i < LIMIT + 1; i++) {
		if(is_abundant(i))
			abundant_nums.insert(i);
	}

	int result{0};
	for(int i = 1; i < LIMIT + 1; i++) {
		bool good = true;
		for(int j = i; j > 0; j--) {
			if(abundant_nums.find(j) != abundant_nums.end()
					&& abundant_nums.find(i - j) != abundant_nums.end()) {
				good = false;
				break;
			}		
	}
		if(good){
			result += i;
		}	
	}
	cout << result;
}
