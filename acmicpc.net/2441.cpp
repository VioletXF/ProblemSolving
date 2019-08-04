//2017-06-29 13:13:59
#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;
	for (int i = input; i >= 0; i--) {
		for (int s = 1; s <= input - i; s++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}
}