//2019-07-17 14:54:50
#include <iostream>
using namespace std;
int main() {
	int SIZE;
	cin >> SIZE;
	int min = 1000000;
	int max = -1000000;
	for (int i = 0; i < SIZE; i++) {
		int input;
		cin >> input;
		if (input > max)max = input;
		if (input < min)min = input;
	}
	cout << min << " " << max;
}