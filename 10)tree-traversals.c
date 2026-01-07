#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *l,*r;
};

struct node* newNode(int x){
    struct node *n = malloc(sizeof(*n));
    n->data = x;
    n->l = n->r = NULL;
    return n;
}

struct node* insert(struct node* t,int x){
    if(!t) return newNode(x);
    if(x < t->data) t->l = insert(t->l,x);
    else if(x > t->data) t->r = insert(t->r,x);
    return t;
}

void inorder(struct node* t){
    if(t){ inorder(t->l); printf("%d ",t->data); inorder(t->r); }
}

void preorder(struct node* t){
    if(t){ printf("%d ",t->data); preorder(t->l); preorder(t->r); }
}

void postorder(struct node* t){
    if(t){ postorder(t->l); postorder(t->r); printf("%d ",t->data); }
}

struct node* search(struct node* t,int key){
    if(!t || t->data==key) return t;
    return key < t->data ? search(t->l,key) : search(t->r,key);
}

int main(){
    struct node *root=NULL;
    int ch,key;
    int a[]={6,9,5,2,8,15,24,14,7,8,5,2};

    do{
        printf("\nMenu\n");
        printf("1.Create BST\n2.Traversals\n3.Search\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                root=NULL;
                for(int i=0;i<12;i++)
                    root=insert(root,a[i]);
                printf("BST created successfully\n");
                break;

            case 2:
                printf("Inorder   : "); inorder(root);
                printf("\nPreorder  : "); preorder(root);
                printf("\nPostorder : "); postorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d",&key);
                if(search(root,key))
                    printf("Element %d found in BST\n",key);
                else
                    printf("Element %d not found in BST\n",key);
                break;

            case 4:
                printf("Exiting program\n");
        }
    }while(ch!=4);

    return 0;
}
