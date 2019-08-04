//2019-08-04 20:45:50
#include <iostream>
#include <vector>
using namespace std;
vector<int> count;
int cuts(int n) {
	if (n == 1)return 0;
	if (n == 2)return 1;
	int f = n / 2;
	int l = n - n / 2;
	int fcuts, lcuts;
	if (count[f] != -1)fcuts = count[f]; else count[f] = fcuts = cuts(f);
	if (count[l] != -1)lcuts = count[l]; else count[l] = lcuts = cuts(l);
	return fcuts + lcuts + 1;
}
int main() {
	int n, m, size;
	cin >> n >> m;
	size = n * m;
	count.resize(size, -1);
	cout << cuts(size);
}
