#include<stdio.h>
#define MAX 20

int ht[MAX], flag[MAX];

int hash(int key,int m){
    return key % m;
}

void insert(int key,int m){
    int i = hash(key,m);
    while(flag[i])
        i = (i+1) % m;   // linear probing
    ht[i] = key;
    flag[i] = 1;
}

void display(int m){
    for(int i=0;i<m;i++){
        if(flag[i])
            printf("Memory Location %d : Key %d\n", i, ht[i]);
        else
            printf("Memory Location %d : Empty\n", i);
    }
}

int main(){
    int m,n,key;
    for(int i=0;i<MAX;i++) flag[i]=0;

    printf("Enter number of memory locations (m): ");
    scanf("%d",&m);
    printf("Enter number of employees (n): ");
    scanf("%d",&n);

    printf("Enter %d four digit employee keys:\n", n);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key,m);
    }

    printf("\nHash Table:\n");
    display(m);

    return 0;
}
