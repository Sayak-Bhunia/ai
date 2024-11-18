#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

struct Node {
    struct Node* parent;
    int mat[N][N];
    int x, y;
    int cost;
    int level;
};

void printMatrix(int mat[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

struct Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, struct Node* parent) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->parent = parent;
    memcpy(node->mat, mat, sizeof(node->mat));
    int temp = node->mat[x][y];
    node->mat[x][y] = node->mat[newX][newY];
    node->mat[newX][newY] = temp;
    node->cost = INT_MAX;
    node->level = level;
    node->x = newX;
    node->y = newY;
    return node;
}

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

int calculateCost(int initial[N][N], int final[N][N]) {
    int c = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(initial[i][j] && initial[i][j] != final[i][j]) c++;
    return c;
}

int isSafe(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<N);
}

void printPath(struct Node* root) {
    if(root == NULL) return;
    printPath(root->parent);
    printMatrix(root->mat);
    printf("\n");
}

int comp(const void* lhs, const void* rhs) {
    struct Node* l = *(struct Node**)lhs;
    struct Node* r = *(struct Node**)rhs;
    return (l->cost + l->level) - (r->cost + r->level);
}

void solve(int initial[N][N], int x, int y, int final[N][N]) {
    struct Node* pq[100000];
    int n = 0;
    struct Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);
    pq[n++] = root;
    while(n>0) {
        qsort(pq, n, sizeof(struct Node*), comp);
        struct Node* min = pq[0];
        for(int i=1;i<n;i++) pq[i-1] = pq[i];
        n--;
        if(min->cost == 0) {
            printPath(min);
            return;
        }
        for(int i=0;i<4;i++) {
            if(isSafe(min->x + row[i], min->y + col[i])) {
                struct Node* child = newNode(
                    min->mat, min->x, min->y,
                    min->x + row[i], min->y + col[i],
                    min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq[n++] = child;
            }
        }
    }
}

int main() {
    int initial[N][N] = {{1, 2, 3}, {5, 6, 0}, {7, 8, 4}};
    int final[N][N] = {{1, 2, 3}, {5, 8, 6}, {0, 7, 4}};
    int x = 1, y = 2;
    solve(initial, x, y, final);
    return 0;
}
