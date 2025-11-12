#include<stdio.h>
    void TowerOfHanoi(int n, char a, char b, char c){
        if(n==1){
            printf("Move disk 1 from rod %c to rod %c\n", a, c);
            return;
        }
        TowerOfHanoi(n-1, a, c, b);
        printf("Move disk %d from rod %c to rod %c\n", n, a, c);
        TowerOfHanoi(n-1, b, a, c);
    }
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TowerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}