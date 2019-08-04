//2019-07-30 23:11:52
#include <iostream>
int main() {
	unsigned long long in;
	std::cin >> in;
	int diff = in % 10 - (in / 10) % 10;
	in /= 10;
	while (in > 9) {
		int now = in % 10;
		int noww = (in / 10) % 10;
		int ndiff = now - noww;
		if (diff != ndiff) { std::cout << "흥칫뿡!! <(￣ ﹌ ￣)>"; return 0; };
		in /= 10;
	}
	std::cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}