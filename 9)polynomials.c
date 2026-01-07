#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int c,x,y,z;
    struct node *next;
};
typedef struct node* NODE;

NODE createNode(int c,int x,int y,int z){
    NODE n = malloc(sizeof(*n));
    n->c=c; n->x=x; n->y=y; n->z=z;
    n->next = NULL;
    return n;
}

NODE insertEnd(NODE head,int c,int x,int y,int z){
    NODE n=createNode(c,x,y,z), t=head;
    if(!head){ n->next=n; return n; }
    while(t->next!=head) t=t->next;
    t->next=n; n->next=head;
    return head;
}

NODE readPoly(){
    int n,c,x,y,z;
    NODE head=NULL;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Coef x y z: ");
        scanf("%d%d%d%d",&c,&x,&y,&z);
        head = insertEnd(head,c,x,y,z);
    }
    return head;
}

void display(NODE head){
    if(!head){ printf("Polynomial empty\n"); return; }
    NODE t=head;
    do{
        printf("%dx^%dy^%dz^%d",t->c,t->x,t->y,t->z);
        t=t->next;
        if(t!=head) printf(" + ");
    }while(t!=head);
    printf("\n");
}

int evaluate(NODE head){
    int xv,yv,zv,sum=0;
    printf("Enter x y z values: ");
    scanf("%d%d%d",&xv,&yv,&zv);
    NODE t=head;
    do{
        sum += t->c * pow(xv,t->x) * pow(yv,t->y) * pow(zv,t->z);
        t=t->next;
    }while(t!=head);
    return sum;
}

NODE polySum(NODE p1,NODE p2){
    NODE sum=NULL,t1=p1,t2=p2;
    do{
        sum = insertEnd(sum,t1->c,t1->x,t1->y,t1->z);
        t1=t1->next;
    }while(t1!=p1);
    do{
        sum = insertEnd(sum,t2->c,t2->x,t2->y,t2->z);
        t2=t2->next;
    }while(t2!=p2);
    return sum;
}

int main(){
    NODE p=NULL,p1=NULL,p2=NULL,psum=NULL;
    int ch,res;
    while(1){
        printf("\nMenu\n1.Evaluate Polynomial\n2.Add Polynomials\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                p=readPoly();
                printf("Polynomial:\n");
                display(p);
                res=evaluate(p);
                printf("Result = %d\n",res);
                break;
            case 2:
                printf("Enter POLY1:\n");
                p1=readPoly();
                printf("Enter POLY2:\n");
                p2=readPoly();
                psum=polySum(p1,p2);
                printf("Polynomial Sum:\n");
                display(psum);
                break;
            case 3:
                exit(0);
        }
    }
}
