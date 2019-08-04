//2019-08-04 20:17:08
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int found[9] = { 0 };//count 9 as 6
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		int idx = input[i] - '0';
		if (idx == 9)idx = 6;
		found[idx]++;
	}
	int maxCount = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			maxCount = max(maxCount, found[i] / 2 + (found[i] & 1));
		}
		else {
			maxCount = max(maxCount, found[i]);
		}
	}
	cout << maxCount;
}