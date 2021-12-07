#include <stdio.h>
#include <string.h>

#define maxn 1000
#define maxstr 100
struct timetable {
    char from[maxstr], to[maxstr];
    int distance, price, trainNo;
};

timetable timetable[maxn];

int main() {
    int n;
    for (int i = 0; i < n; i++)
        scanf("%s%s%d%d%d", timetable[i].from, timetable[i].to, &timetable[i].distance, &timetable[i].price,
              &timetable[i].trainNo);
    char from[maxstr], to[maxstr];
    scanf("%s%s", from, to);
    for (int i = 0; i < n; i++) {
        if (strcmp(from, timetable[i].from) == 0 && strcmp(to, timetable[i].to) == 0) {
            printf("yes\ndistance: %d price: %d train number: %d\n", timetable[i].distance, timetable[i].price,
                   timetable[i].trainNo);
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
