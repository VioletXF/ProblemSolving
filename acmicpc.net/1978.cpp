//2019-08-04 17:18:34
#include <iostream>
using namespace std;
int isPrime(int n) {
	if (n == 1)return false;
	if (n == 2)return true;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		if (isPrime(input))count++;
	}
	cout << count;
}
