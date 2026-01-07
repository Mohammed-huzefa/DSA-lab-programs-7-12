#include<stdio.h>
#define MAX 20

int g[MAX][MAX], v[MAX], n;

void DFS(int s){
    printf("%d ", s);
    v[s] = 1;
    for(int i=1;i<=n;i++)
        if(g[s][i] && !v[i])
            DFS(i);
}

void BFS(int s){
    int q[MAX], f=0, r=0;
    for(int i=1;i<=n;i++) v[i]=0;

    printf("%d ", s);
    v[s]=1; q[r++]=s;

    while(f<r){
        int u=q[f++];
        for(int i=1;i<=n;i++){
            if(g[u][i] && !v[i]){
                printf("%d ", i);
                v[i]=1;
                q[r++]=i;
            }
        }
    }
}

int main(){
    int start;
    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);

    printf("Enter starting city: ");
    scanf("%d",&start);

    printf("\nDFS Traversal:\n");
    for(int i=1;i<=n;i++) v[i]=0;
    DFS(start);

    printf("\n\nBFS Traversal:\n");
    BFS(start);

    return 0;
}
