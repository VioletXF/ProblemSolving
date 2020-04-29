#include <iostream>
using namespace std;
int dirs[4][2] = {
	{-1,0}, {0,-1}, {0,1}, {1,0} 
};
int map[50][50] = { 0 };
int M, N, K;
int cnt;
bool checkRange(int y, int x) {
	return !(y < 0 || x < 0 || y >= N || x >= M);
}
void dfs(int y, int x) {
	if (!checkRange(y, x)) return;
	map[y][x] = 2;
	int y1, x1;
	for (int i = 0; i < 4; i++) {
		y1 = y + dirs[i][0];
		x1 = x + dirs[i][1];
		if (map[y1][x1] == 1)dfs(y1, x1);
	}
}
int main() {
	
	int T;
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> M >> N >> K;
		while (K--) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

	}
}