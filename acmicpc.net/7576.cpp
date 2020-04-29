#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int N, M;
int zerosCnt = 0;
int todayTaskNum = 0;
int map[1000][1000] = { 0 };
int dirs[4][2] = {
	{-1,0}, {0,-1}, {1,0}, {0,1}
};
queue<pair<int, int>> q;
bool checkRange(int y, int x) {
	return !(y < 0 || x < 0 || x >= M || y >= N);
}
int bfs() {
	int day = 0;
	int temp = 0;
	int madeToOne = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dirs[i][0];
			int nx = x + dirs[i][1];
			if (checkRange(ny, nx) && map[ny][nx] == 0) {
				madeToOne++;
				map[ny][nx] = 1;
				q.push(pair<int, int>(ny, nx));
				temp++;
			}
		}
		todayTaskNum--;
		if (todayTaskNum == 0) {
			todayTaskNum = temp;
			temp = 0;
			day++;
		}
	}
	if (madeToOne == zerosCnt)
		return day - 1;
	else
		return -1;
}
int main() {
	bool modu = true;

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			if (input == 0) {
				modu = false;
				zerosCnt++;
			}
			else if (input == 1) {
				q.push(pair<int, int>(i, j));
			}
			map[i][j] = input;
			
		}
	}
	if (modu) {
		cout << 0;
	}
	else {
		todayTaskNum = q.size();
		cout<<bfs();
	}
}