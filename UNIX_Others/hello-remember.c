#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* name;
    struct node* next;
};

struct node* add(struct node* head, char* name) {
    struct node* n;
    struct node* p;

    n = (struct node*)malloc(sizeof(struct node));
    n->name = (char*)malloc(strlen(name) + 1);
    strcpy(n->name, name);    n->next = NULL;

    if(head == NULL) {
        return n;
    }
    p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = n;
    return head;
}

int known(struct node* head, char* name) {
    if(head == NULL)
        return 0;
    struct node* p = head;
    while(p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }
    return (p != NULL);
}

void clear(struct node* head) {
    if(head == NULL)
        return;
    struct node* p = head; // p is the current node
    while(p != NULL) {
        struct node* n = p->next; // n is the next node
        free(p->name); // free the name
        free(p); // free the node
        p = n; // move to the next node
    }
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv) {
    char name[64];
    printf("Enter x to exit the program.");
    struct node* head = NULL;
    while(scanf("%s", name) == 1) {
        if(strcmp(name, "x") == 0)
            break;
        else if(known(head, name)) {
            printf("Still around %s, eh?\n", name);
        }
        else {
            head = add(head, name);
            printf("Hello %s\n", name);
        }
    }
    clear(head);
    return 0;
}
