//2017-08-01 23:54:59
#include <cstdlib>
#include <cstdio>
int main() {
	char** a;
	int tc;
	scanf("%d", &tc);
	int* rp = (int*)malloc(sizeof(int) * (unsigned int)tc), k = 0;

	a = (char**)malloc(sizeof(char*) * (char)tc);
	for (int i = 0; i < tc; i++) {
		a[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%d %s", &rp[i], a[i]);
	}

	while (k < tc) {

		int len;
		for (len = 0; a[k][len] != 32 && a[k][len] != 0; len++);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < rp[k]; j++) {
				printf("%c", a[k][i]);
			}
		}
		printf("\n");
		k++;
	}
}