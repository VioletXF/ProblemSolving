//2017-06-29 13:25:02
#include <iostream>
using namespace std;
int main() {
	int in;
	int st = 0;
	cin >> in;
	for (int i = 0; i < in; i++) {
		st = i * 2 + 1;
		for (int j = 1; j <= (in * 2 + 1) / 2 - (i + 1); j++) {
			cout << ' ';
		}
		for (int k = 1; k <= st; k++) {
			cout << '*';
		}
		cout << endl;
	}
}