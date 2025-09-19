//wap to find intersection of sorted array
#include<stdio.h>
void intersectionOfArrays(int a[], int m, int b[], int n, int c[],
                            int *size) {
        int i = 0, j = 0, k = 0;
    
        while (i < m && j < n) {
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                c[k++] = a[i++];
                j++;
            }
        }
    
        *size = k; 
    }

int main() {
    int m, n;

    printf("Enter the size of 1st Array: ");
    scanf("%d", &m);
    int a[m];
    printf("Enter the elements of 1st Array in sorted manner:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of 2nd Array: ");
    scanf("%d", &n);
    int b[n];
    printf("Enter the elements of 2nd Array in sorted manner:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int c[m < n ? m : n]; 
    int size = 0;
    intersectionOfArrays(a, m, b, n, c, &size);

    printf("Intersection Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}