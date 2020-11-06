#include <cstdio>
#include <queue>
using namespace std;
int N, M;
struct State
{
    int y, x;
    int broke; //1 on broke
};
int map[1000][1000];
int visit[1000][1000][2];
int dir[4][2] = { //y,x
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
bool is_available(int y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}
int bfs()
{
    queue<State> q;
    State start_point;
    start_point.y = 0;
    start_point.x = 0;
    start_point.broke = 0;
    q.push(start_point);
    visit[0][0][0] = 1;
    while (!q.empty())
    {
        State front = q.front();
        int y = front.y;
        int x = front.x;
        int broke = front.broke;
        q.pop();
        if (y == N - 1 && x == M - 1)
        {
            return visit[y][x][broke];
        }
        int i;

        for (i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (is_available(ny, nx))
            {
                if (map[ny][nx] == 1)
                { //wall
                    if (broke == 0)
                    {
                        State next;
                        next.y = ny;
                        next.x = nx;
                        next.broke = 1;
                        visit[ny][nx][1] = visit[y][x][broke] + 1;
                        q.push(next);
                    }
                }
                else if (visit[ny][nx][broke] == 0)
                {
                    visit[ny][nx][broke] = visit[y][x][broke] + 1;
                    State next;
                    next.y = ny;
                    next.x = nx;
                    next.broke = broke;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}
int main()
{
    int i, k;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < M; k++)
        {
            int num;
            scanf("%1d", &num);
            map[i][k] = num;
        }
    }
    printf("%d",bfs());
}
