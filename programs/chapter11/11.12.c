#include <stdio.h>
#include <stdlib.h>
#define maxn 200

void InitTable(int *table, int table_rank) {
    for (int i = 0; i < table_rank; ++i) {
        for (int j = 0; j < table_rank; ++j)
            *(table + i * table_rank + j) = 0;
    }
    for (int i = 0; i < table_rank; ++i) {
        *(table + i * table_rank + 0) = i + 1;
    }
}

void GSchedule(int *table, int table_rank,
               int r1, int c1, int r2, int c2, int n) {
    if (n >= 2) {
        for (int i = 0; i < n; ++i) {
            if (*(table + (r2 - i) * table_rank + c2) == 0)
                *(table + (r2 - i) * table_rank + c2)
                        = *(table + (r1 + i) * table_rank + c1);
            else
                *(table + (r1 + i) * table_rank + c1)
                        = *(table + (r2 - i) * table_rank + c2);
        }
        int mr = (r2 - r1) / 2;
        int mc = (c2 - c1) / 2;
        n /= 2;
        GSchedule(table, table_rank, r1, c1, r1 + mr, c1 + mc, n);
        GSchedule(table, table_rank, r1, c1 + mc + 1, r1 + mr, c2, n);
        GSchedule(table, table_rank, r1 + mr + 1, c1, r2, c1 + mc, n);
        GSchedule(table, table_rank, r1 + mr + 1, c1 + mc + 1, r2, c2, n);
    }
}

void GameSchedule(int *table, int table_rank) {
    InitTable(table, table_rank);
    GSchedule(table, table_rank,
              0, 0, table_rank - 1, table_rank - 1, table_rank);
}


void PrintTable(int *table, int table_rank) {
    for (int i = 0; i < table_rank; ++i) {
        for (int j = 0; j < table_rank; ++j)
            printf("%d ",*(table + i * table_rank + j));
        printf("\n");
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *table = (int*) malloc(sizeof (int)*n*n);
    GameSchedule(table, n);
    PrintTable(table, n);
    free(table);
    return 0;
}

