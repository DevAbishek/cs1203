#include<stdio.h> 

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 


void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) { 
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 

void buildHeap(int arr[], int n) { 
    int startIdx = (n / 2) - 1; 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 


void selectionSort(int arr[], int n)  { 
    buildHeap(arr, n); 
    for (int i = n - 1; i >= 0; i--) { 
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
  
int main() 
{ 
    int arr[] = {67,  87, 98, 345, 1, 23}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    selectionSort(arr, n); 
  
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}