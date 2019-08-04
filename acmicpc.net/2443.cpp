//2019-07-17 15:02:06
#include <iostream>
using namespace std;
int main() {
	int l;
	cin >> l;
	for (int i = l; i > 0; i--) {
		for (int j = 0; j < l - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}