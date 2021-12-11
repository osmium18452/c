#include <stdio.h>
#include <stdlib.h>

#define maxn 10000

struct node {
    int val;
    node *left, *right;
};
node *queue[maxn];

void preorder(node *root) {
    printf("%d ", root->val);
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        queue[i] = (node *) malloc(sizeof(node));
        scanf("%d", &(queue[i]->val));
        queue[i]->left = NULL;
        queue[i]->right = NULL;
    }
    for (int i = 1; i < n; i++) {
        int min1 = 0x3fffffff, min2 = 0x3fffffff;
        int p1 = -1, p2 = -1;
        for (int j = 0; j < n; j++) {
            if (queue[j] != NULL) {
                if (p1 == -1) {
                    min1 = queue[j]->val;
                    p1 = j;
                    continue;
                }
                if (queue[j]->val <= min1) {
                    min2 = min1;
                    min1 = queue[j]->val;
                    p2 = p1;
                    p1 = j;
                } else if (queue[j]->val <= min2) {
                    min2 = queue[j]->val;
                    p2 = j;
                }
            }
        }
        node *p = (node *) malloc(sizeof(node));
        p->left = queue[p1];
        p->right = queue[p2];
        p->val = p->left->val + p->right->val;
        queue[p1] = p;
        queue[p2] = NULL;
    }
    node *root;
    for (int i = 0; i < n; i++) {
        if (queue[i] != NULL) root = queue[i];
    }
    preorder(root);
    return 0;
}
