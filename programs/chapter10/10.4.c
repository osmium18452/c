#include <stdio.h>
#include <string>
#include <stdlib.h>

using std::string;
using std::to_string;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string name = "data";
        if (i < 10) {
            name = name + "0" + to_string(i) + ".txt";
        } else {
            name = name + to_string(i) + ".txt";
        }
        freopen(name.c_str(), "r", stdin);
        int cnt = 0;
        int line = 0;
        char a;
        while ((a = getchar()) != EOF) {
            if (a == '\n') line++;
            cnt++;
        }
        printf("doc: %s, line: %d, letter: %d\n", name.c_str(), line, cnt);
    }
    return 0;
}

