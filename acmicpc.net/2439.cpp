//2017-06-28 13:21:30
#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		for (int s = 1; s <= input - i; s++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}
}