#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int map[25][25];
int dirs[4][2] = { {-1, 0}, {1,0}, {0,-1}, {0,1} };
int N;
vector<int> sizes;
bool isInRange(int y, int x) {
	return !(y<0 || x<0 || x>=N || y>=N);
}
void dfs(int y, int x, int id) {
	if (map[y][x] != 1)return;
	int y2, x2;
	map[y][x] = id;
	sizes[id-2]++;
	for (int i = 0; i < 4; i++) {
		y2 = y + dirs[i][0];
		x2 = x + dirs[i][1];
		if (isInRange(y2, x2)) {
			dfs(y2, x2, id);
		}
	}
	return;
}
int main() {
	cin >> N;
	sizes.resize(N*N, 0);
	int id = 2;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			scanf("%1d", &input);
			map[i][j] = input;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) { 
				cnt++;
				dfs(i, j, id); 
				id++;
			}
		}
	}
	sort(sizes.begin(), sizes.end());
	cout << cnt << endl;
	for (int i = 0; i < N*N; i++) {
		if (sizes[i] == 0)continue;
		cout << sizes[i] << endl;
	}
}