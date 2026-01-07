#include<stdio.h>
#include<stdlib.h>

struct Emp{
    char ssn[15], name[20], dept[15], desig[20];
    float sal;
    long long ph;
    struct Emp *prev, *next;
};

struct Emp* create(){
    struct Emp *n = malloc(sizeof(*n));
    printf("Enter SSN: "); scanf("%s", n->ssn);
    printf("Enter Name: "); scanf("%s", n->name);
    printf("Enter Dept: "); scanf("%s", n->dept);
    printf("Enter Designation: "); scanf("%s", n->desig);
    printf("Enter Salary: "); scanf("%f", &n->sal);
    printf("Enter Phone No: "); scanf("%lld", &n->ph);
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(struct Emp **h){
    struct Emp *n = create(), *t = *h;
    if(!*h){ *h = n; return; }
    while(t->next) t = t->next;
    t->next = n; n->prev = t;
}

void insertFront(struct Emp **h){
    struct Emp *n = create();
    n->next = *h;
    if(*h) (*h)->prev = n;
    *h = n;
}

void deleteEnd(struct Emp **h){
    if(!*h){ printf("List empty\n"); return; }
    struct Emp *t = *h;
    if(!t->next){ free(*h); *h = NULL; }
    else{
        while(t->next) t = t->next;
        t->prev->next = NULL;
        free(t);
    }
    printf("Node deleted from end\n");
}

void deleteFront(struct Emp **h){
    if(!*h){ printf("List empty\n"); return; }
    struct Emp *t = *h;
    *h = t->next;
    if(*h) (*h)->prev = NULL;
    free(t);
    printf("Node deleted from front\n");
}

void display(struct Emp *h){
    int c = 0;
    printf("\nEmployee Data:\n");
    while(h){
        printf("SSN:%s Name:%s Dept:%s Desig:%s Sal:%.2f Ph:%lld\n",
               h->ssn,h->name,h->dept,h->desig,h->sal,h->ph);
        h = h->next; c++;
    }
    printf("Number of nodes = %d\n", c);
}

int main(){
    struct Emp *head = NULL;
    int ch;
    do{
        printf("\nMenu\n");
        printf("1.Create (End Insert)\n2.Display\n3.Insert End\n4.Insert Front\n");
        printf("5.Delete End\n6.Delete Front\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: insertEnd(&head); break;
            case 2: display(head); break;
            case 3: insertEnd(&head); break;
            case 4: insertFront(&head); break;
            case 5: deleteEnd(&head); break;
            case 6: deleteFront(&head); break;
            case 7: printf("Exiting program\n");
        }
    }while(ch != 7);
    return 0;
}
