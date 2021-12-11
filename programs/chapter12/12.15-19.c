#include <stdio.h>
#include <stdlib.h>

#define maxn 10000
struct node {
    int val;
    node *left, *right;
};

void preorder(node *root) {
    printf("%d ", root->val);
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
}

void inorder(node *root) {
    if (root->left != NULL) preorder(root->left);
    printf("%d ", root->val);
    if (root->right != NULL) preorder(root->right);
}

void postorder(node *root) {
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
    printf("%d ", root->val);
}

node *find(node *root, int val) {
    if (root->val == val) return root;
    if (root->left == NULL && root->right == NULL) return NULL;
    node *rtn = NULL;
    if (root->left != NULL) rtn = find(root->left, val);
    if (rtn != NULL) return rtn;
    if (root->right != NULL) rtn = find(root->right, val);
    return rtn;
}

int main() {
    int n;
    scanf("%d", &n);
    node *queue[maxn];
    int head = 0, tail = 0;
    node *root = (node *) malloc(sizeof(node));
    scanf("%d", &(root->val));
    queue[tail++] = root;
    n--;
    while (n > 0) {
        node *father = queue[head++];
        father->left = (node *) malloc(sizeof(node));
        scanf("%d", &(father->left->val));
        father->left->left = NULL;
        father->left->right = NULL;
        queue[tail++] = father->left;
        n--;
        if (n == 0) break;
        father->right = (node *) malloc(sizeof(node));
        scanf("%d", &(father->right->val));
        father->right->left = NULL;
        father->right->right = NULL;
        n--;
        if (n == 0) break;
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    int val;
    scanf("%d", &val);
    printf("0x%016x", find(root, val));
    return 0;
}