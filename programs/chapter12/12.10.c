#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ERROR -1
#define TRUE 1
#define OK 0
#define STACK_INIT_SIZE 30
#define STACKINCREMENT 50
struct stack {
    int *bottom;
    int *top;
    int stacksize;
};

int InitStack(stack &S) {
S.bottom = (int *) malloc(STACK_INIT_SIZE
                          * sizeof(char));
if (!S.bottom) exit(OVERFLOW);
S.
top = S.bottom;
S.
stacksize = STACK_INIT_SIZE;
return OK;
}

int push(stack &S, int ch) {
if (S.top - S.bottom >= S.stacksize) {
S.bottom = (int *) realloc(S.bottom, S.stacksize + STACKINCREMENT * sizeof(int));
if (!S.bottom) exit(OVERFLOW);
S.top = S.bottom + S.stacksize;
S.stacksize += STACKINCREMENT;
}
*S.top = ch;
S.top = S.top + 1;
return OK;
}

int pop(stack &S, int &ch) {
if (S.top == S.bottom) return ERROR;
ch = *(S.top - 1);
S.top--;
*(S.top) = 0;
return OK;
}

int GetTop(stack &S) {
int ch;
if (S.top == S.bottom) return ERROR;
ch = *(S.top - 1);
return ch;
}

int IsOptr(char ch) {
    int i = 0;
    char optr[] = {'+', '-', '*', '/', '(', ')', '#', '@'};
    while (optr[i] != '@') {
        if (ch == optr[i]) return TRUE;
        i++;
    }
    return OK;
}

char Precede(int sym1, int sym2) {
    if (sym1 == '#' && sym2 == '#') return '=';
    else if (sym1 == '#' && sym2 == ')') exit(ERROR);
    else if (sym1 == '#') return '<';
    else if (sym1 == '(' && sym2 == '#') exit(ERROR);
    else if (sym2 == '#') return '>';
    else if (sym1 == ')' && sym2 == '(') exit(ERROR);
    else if (sym1 == ')') return '>';
    else if (sym1 == '(' && sym2 == ')') return '=';
    else if (sym2 == ')') return '>';
    else if (sym1 == '(') return '<';
    else if (sym2 == '(') return '<';
    else if (sym1 == '*' || sym1 == '/' || sym2 == '+' || sym2 == '-') return '>';
    else return '<';
}

int Operate(int a, int theta, int b) {
    if (theta == '+') return a + b;
    else if (theta == '-') return a - b;
    else if (theta == '*') return a * b;
    else if (theta == '/') {
        if (b == 0) {
            printf("该行除数为0，出错！");
            return NULL;
        } else return a / b;
    } else exit(ERROR);
}

FILE *fp;

int main() {
    stack OPTR, OPND;
    char c = '0';
    int x, theta, a, b;
    fp = fopen("../in.txt", "r");
    while (c != EOF) {
        InitStack(OPTR);
        push(OPTR, '#');
        InitStack(OPND);
        c = fgetc(fp);
        while (c != '#' || GetTop(OPTR) != '#') {
            if (!IsOptr(c)) {
                push(OPND, c - 48);
                c = fgetc(fp);
                while (!IsOptr(c)) {
                    pop(OPND, x);
                    push(OPND, x * 10 + c - 48);
                    c = fgetc(fp);
                }
            } else
                switch (Precede(GetTop(OPTR), c)) {
                    case '<':
                        push(OPTR, c);
                        c = fgetc(fp);
                        break;
                    case '=':
                        pop(OPTR, x);
                        c = fgetc(fp);
                        break;
                    case '>':
                        pop(OPTR, theta);
                        pop(OPND, b);
                        pop(OPND, a);
                        push(OPND, Operate(a, theta, b));
                        break;
                }
        }
        printf("%d\n", GetTop(OPND));
        c = fgetc(fp);
    }
    fclose(fp);
    return 0;
}


