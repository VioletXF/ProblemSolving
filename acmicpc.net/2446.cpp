//2019-07-17 15:15:23
#include <iostream>
using namespace std;
int main() {
	int l;
	cin >> l;

	for (int i = l; i > 1; i--) {
		for (int j = 0; j < l - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < l - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}