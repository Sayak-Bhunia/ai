#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int helper(int m, int n, int d) {
    if(d>(m>n?m:n)) return -1; 
    int q[10000][3], f=0,r=0;
    bool vis[m+1][n+1];
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) vis[i][j] = false;
    }
    q[r][0] = 0;
    q[r][1] = 0;
    q[r][2] = 0;
    r++;
    vis[0][0] = true;
    while (f != r) {
        int jug1 = q[f][0];
        int jug2 = q[f][1];
        int steps = q[f][2];
        f++;
        if(jug1 == d || jug2 == d) return steps;
        if(!vis[m][jug2]) {
            vis[m][jug2] = true;
            q[r][0] = m;
            q[r][1] = jug2;
            q[r][2] = steps + 1;
            r++;
        }
        if(!vis[jug1][n]) {
            vis[jug1][n] = true;
            q[r][0] = jug1;
            q[r][1] = n;
            q[r][2] = steps + 1;
            r++;
        }
        if(!vis[0][jug2]) {
            vis[0][jug2] = true;
            q[r][0] = 0;
            q[r][1] = jug2;
            q[r][2] = steps + 1;
            r++;
        }
        if(!vis[jug1][0]) {
            vis[jug1][0] = true;
            q[r][0] = jug1;
            q[r][1] = 0;
            q[r][2] = steps + 1;
            r++;
        }
        int pour1to2 = jug1 < (n - jug2) ? jug1 : (n - jug2);
        if (!vis[jug1 - pour1to2][jug2 + pour1to2]) {
            vis[jug1 - pour1to2][jug2 + pour1to2] = true;
            q[r][0] = jug1 - pour1to2;
            q[r][1] = jug2 + pour1to2;
            q[r][2] = steps + 1;
            r++;
        }
        int pour2to1 = jug2 < (m - jug1) ? jug2 : (m - jug1);
        if (!vis[jug1 + pour2to1][jug2 - pour2to1]) {
            vis[jug1 + pour2to1][jug2 - pour2to1] = true;
            q[r][0] = jug1 + pour2to1;
            q[r][1] = jug2 - pour2to1;
            q[r][2] = steps + 1;
            r++;
        }
    }
    return -1;
}

int main() {
    int m = 4, n = 3, d = 2;
    printf("%d\n", helper(m, n, d));
    return 0;
}
