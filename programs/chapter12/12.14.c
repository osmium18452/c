
#include <stdio.h>
#include <string.h>

#define maxn 1000
int map[maxn][maxn];
int visited[maxn][maxn];
int queuex[maxn * 10], queuey[maxn * 10];
int prev[maxn * 10];
int path[maxn * 10];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int h = 0, t = 0;
    queuex[t] = x1;
    queuey[t++] = y1;
    visited[x1][y1] = true;
    bool found = false;
    while (h != t) {
        int x = queuex[h], y = queuey[h++];
        if (x == x2 && y == y2) {
            int cnt = 0;
            int i = h - 1;
            path[cnt++] = i;
            while (i != 0) {
                i = prev[i];
                path[cnt++] = i;
            }
            found = true;
            while (cnt--) {
                printf("(%d, %d) ", queuex[path[cnt]], queuey[path[cnt]]);
            }
            break;
        }
        if (x + 1 < n && !visited[x + 1][y] && map[x + 1][y] == 0) {
            queuex[t] = x + 1;
            queuey[t] = y;
            prev[t++] = h - 1;
            visited[x + 1][y] = true;
        }
        if (x - 1 >= 0 && !visited[x - 1][y] && map[x - 1][y] == 0) {
            queuex[t] = x - 1;
            queuey[t] = y;
            prev[t++] = h - 1;
            visited[x - 1][y] = true;
        }
        if (y + 1 < m && !visited[x][y + 1] && map[x][y + 1] == 0) {
            queuex[t] = x;
            queuey[t] = y + 1;
            prev[t++] = h - 1;
            visited[x][y + 1] = true;
        }
        if (y - 1 >= 0 && !visited[x][y - 1] && map[x][y - 1] == 0) {
            queuex[t] = x;
            queuey[t] = y - 1;
            prev[t++] = h - 1;
            visited[x][y - 1] = true;
        }
    }
    if (!found) printf("path not found");
    return 0;
}

/*
3 3
0 0 0
1 1 0
1 1 0
0 0 2 2
 */
