#include<stdio.h>
#include<stdlib.h>

struct Student{
    char usn[20], name[30], prog[20];
    int sem;
    long long ph;
    struct Student *next;
};

struct Student* create(){
    struct Student *n = malloc(sizeof(*n));
    printf("Enter USN: ");        scanf("%s", n->usn);
    printf("Enter Name: ");       scanf("%s", n->name);
    printf("Enter Programme: ");  scanf("%s", n->prog);
    printf("Enter Semester: ");   scanf("%d", &n->sem);
    printf("Enter Phone No: ");   scanf("%lld", &n->ph);
    n->next = NULL;
    return n;
}

void insertFront(struct Student **h){
    struct Student *n = create();
    n->next = *h;
    *h = n;
}

void insertEnd(struct Student **h){
    struct Student *n = create(), *t = *h;
    if(!*h){ *h = n; return; }
    while(t->next) t = t->next;
    t->next = n;
}

void deleteFront(struct Student **h){
    if(!*h){ printf("List is empty\n"); return; }
    struct Student *t = *h;
    *h = (*h)->next;
    free(t);
    printf("Node deleted from front\n");
}

void deleteEnd(struct Student **h){
    if(!*h){ printf("List is empty\n"); return; }
    if(!(*h)->next){ free(*h); *h = NULL; }
    else{
        struct Student *t = *h;
        while(t->next->next) t = t->next;
        free(t->next); t->next = NULL;
    }
    printf("Node deleted from end\n");
}

void display(struct Student *h){
    int c = 0;
    printf("\nStudent Data:\n");
    while(h){
        printf("USN:%s Name:%s Prog:%s Sem:%d Ph:%lld\n",
               h->usn,h->name,h->prog,h->sem,h->ph);
        h = h->next; c++;
    }
    printf("Number of nodes = %d\n", c);
}

int main(){
    struct Student *head = NULL;
    int ch;
    do{
        printf("\nMenu\n");
        printf("1.Create (Front Insertion)\n");
        printf("2.Display & Count\n");
        printf("3.Insert at End\n");
        printf("4.Delete at End\n");
        printf("5.Insert at Front (Stack Push)\n");
        printf("6.Delete at Front (Stack Pop)\n");
        printf("7.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: insertFront(&head); break;
            case 2: display(head); break;
            case 3: insertEnd(&head); break;
            case 4: deleteEnd(&head); break;
            case 5: insertFront(&head); break;
            case 6: deleteFront(&head); break;
            case 7: printf("Exiting program\n");
        }
    }while(ch != 7);
    return 0;
}
