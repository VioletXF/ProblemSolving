//2019-08-04 17:12:28
#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;
	int ten = input / 10;
	int one = input % 10;
	int count = 0;
	do {
		int nextTen = one;
		int nextOne = (ten + one) % 10;
		ten = nextTen;
		one = nextOne;
		count++;
	} while (ten * 10 + one != input);
	cout << count;
}