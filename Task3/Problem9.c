//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316088937

#include <stdio.h>
 
int main() {
    int n, i;
    scanf("%d", &n);
 
    int a[1000];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    int min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    int freq = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == min) {
            freq++;
        }
    }
 
    if (freq % 2 == 1) {
        printf("Lucky\n");
    } else {
        printf("Unlucky\n");
    }
 
    return 0;
}