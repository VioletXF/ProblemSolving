//2019-07-19 23:09:36
#include <iostream>
using namespace std;
int main() {
	int T;
	int n;
	cin >> T;
	int* z = new int[41];
	int* o = new int[41];
	z[0] = 1, o[0] = 0;
	z[1] = 0, o[1] = 1;

	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 2; j <= n; j++) {
			z[j] = z[j - 2] + z[j - 1];
			o[j] = o[j - 2] + o[j - 1];
		}
		cout << z[n] << " " << o[n] << "\n";
	}
	delete[] z;
	delete[] o;
}