#include <stdio.h>
#include <string.h>

enum fruit {
    apple, orange, banana, grape, pear
};
bool visited[5];
int cnt;

void dfs(int curr,int n) {
    if (n == 3) {
        for (int i = 0; i < 5; i++) {
            if (visited[i]) printf("%s ",
                                   i == apple ? "apple" : (i == orange ? "orange" : (i == banana ? "banana" : (i ==
                                                                                                               grape
                                                                                                               ? "grape"
                                                                                                               : "pear"))));
        }
        putchar('\n');
        cnt++;
        return;
    }
    for (int i = curr; i < 5; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i,n + 1);
            visited[i] = false;
        }
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    cnt=0;
    dfs(0,0);
    printf("%d",cnt);
    return 0;
}
