//2017-06-28 13:24:13
#include <iostream>
using namespace std;
int main() {
	int in;
	cin >> in;
	for (int i = in; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}
}