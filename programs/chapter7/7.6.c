#include<conio.h>
#include<stdio.h>
#include<string.h>

void fun(char *str) {
    char s[100];
    int j = 0, n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] % 2 != 0) {
            s[j] = str[i];
            j++;
        }
    }
    s[j] = '\0';
    for (int i = 0; s[i] != 0; i++) {
        str[i] = s[i];
        str[i+1]='\0';
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    fun(str);
    printf("%s\n", str);
return 0;
}
