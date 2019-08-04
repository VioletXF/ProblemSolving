//2017-08-01 23:25:52
#include <cstdio>
#include <cstdlib>
int main() {
	char* a = (char*)malloc(sizeof(char) * 101);
	scanf("%s", a);
	int res = -1;
	int i, j, length;
	for (length = 0; a[length] != 32 && a[length] != 0; length++);
	for (i = 97; i < 123; i++) {
		res = -1;
		for (j = 0; j < length; j++) {
			if (a[j] == i) {
				res = j;
				break;
			}
		}
		printf("%d ", res);
	}

}