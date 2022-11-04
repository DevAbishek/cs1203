
#include <stdio.h>
#include <stdlib.h>
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int pivotFn(int a[], int l, int h) {
    int p = a[h];
    int i = l - 1;
    for(int j = l; j < h; j++)
    {
        if(a[j] < p)
        {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i+1, h);
    return i+1;
}

void quickSort(int a[], int l, int h) {
    if(l < h)
    {
        int pi = pivotFn(a, l, h);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, h);
    }
}
int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Elements in array: \n");
    for(int i=0; i<n; i++) {
        printf("%d \t", arr[i]);
    }

    quickSort(arr, 0, n-1);

    printf("\nElements in sorted array: \n");
    for(int i=0; i<n; i++) {
        printf("%d \t", arr[i]);
    }
    
    return 0;
}