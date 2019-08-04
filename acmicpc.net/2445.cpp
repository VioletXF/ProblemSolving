//2019-07-17 15:12:45
#include <iostream>
using namespace std;
int main() {
	int l;
	cin >> l;
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < i; j++)cout << "*";
		for (int j = 0; j < l * 2 - i * 2; j++)cout << " ";
		for (int j = 0; j < i; j++)cout << "*";
		cout << "\n";
	}
	for (int i = l - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)cout << "*";
		for (int j = 0; j < l * 2 - i * 2; j++)cout << " ";
		for (int j = 0; j < i; j++)cout << "*";
		cout << "\n";
	}
}