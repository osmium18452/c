#include <stdio.h>
struct node{
    bool visited;
    node* next;
};
node* createList();
bool findLoop(node* head){
    node* p=head;
    while (p!=NULL){
        if (p->visited) {
            return true;
        } else {
            p->visited= true;
            p=p->next;
        }
    }
    return false;
}
int main(){
    node* head=createList();
    if (findLoop(head)) printf("yes\n");
    else printf("no\n");
    return 0;
}

