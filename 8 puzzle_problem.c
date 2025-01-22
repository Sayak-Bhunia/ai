// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
#define n 3

struct Node {
    struct Node* parent;
    int mat[n][n], x, y, cost, level;
};

struct Node* newNode(struct Node* parent, int mat[n][n], int x, int y, int nx, int ny, int level) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->parent = parent;
    memcpy(node->mat, mat, sizeof(node->mat));
    int tmp = node->mat[x][y];
    node->mat[x][y] = node->mat[nx][ny];
    node->mat[nx][ny] = tmp;
    node->level = level;
    node->cost = INT_MAX;
    node->x = nx;
    node->y = ny;
    return node;
}

void printMatrix(int mat[n][n]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

int calc(int a[n][n], int b[n][n]) {
    int c = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j] && a[i][j] != b[i][j]) c++;
        }
    }
    return c;
}

bool isSafe(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void printPath(struct Node* root) {
    if(root == NULL) return;
    printPath(root->parent);
    printMatrix(root->mat);
    printf("\n");
}

int cmp(const void *lhs, const void *rhs) {
    struct Node* l = *(struct Node**)lhs;
    struct Node* r = *(struct Node**)rhs;
    return (l->cost + l->level) - (r->cost + r->level);
}

void helper(int x, int y, int a[n][n], int b[n][n]) {
    struct Node* pq[100000];
    int sz = 0;
    struct Node* root = newNode(NULL, a, x, y, x, y, 0);
    root->cost = calc(a, b);
    pq[sz++] = root;
    while(sz>0) {
        qsort(pq, sz, sizeof(struct Node*), cmp);
        struct Node* mn = pq[0];
        for(int i=1;i<sz;i++) pq[i-1] = pq[i];
        sz--;
        if(mn->cost == 0) {
            printPath(mn);
            return;
        }
        for(int i=0;i<4;i++) {
            if(isSafe(mn->x + row[i], mn->y + col[i])) {
                struct Node* child = newNode(
                    mn, mn->mat, mn->x, mn->y,
                    mn->x + row[i], mn->y + col[i],
                    mn->level + 1);
                child->cost = calc(child->mat, b);
                pq[sz++] = child;
            }
        }
    }
}

int main() {
    int a[n][n] = {{1, 2, 3}, {5, 6, 0}, {7, 8, 4}};
    int b[n][n] = {{1, 2, 3}, {5, 8, 6}, {0, 7, 4}};
    int x = 1, y = 2;
    helper(x, y, a, b);
}
