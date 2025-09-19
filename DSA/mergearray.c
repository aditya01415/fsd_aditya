//Wap to merge two sorted arrays into a single sorted array.
#include <stdio.h>
void merge(int arr1[], int m, int arr2[], int n, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < m) {
        merged[k++] = arr1[i++];    
    }
    while (j < n) {
        merged[k++] = arr2[j++];
    }
}
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int merged[m+ n];
    merge(arr1, m, arr2, n, merged);
    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}    

