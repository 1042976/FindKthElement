#include <stdio.h>
#include <stdbool.h>
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool less(const int a, const int b){
    return a < b;
}
bool greater(const int a, const int b){
    return a > b;
}
void heapify(int arr[], int k, int i, bool (*compare)(const int, const int)){
    int nextI = i, left = 2*i+1, right = 2*i+2;
    if(left < k && compare(arr[nextI], arr[left])) {
        nextI = left;
    }
    if(right < k && compare(arr[nextI], arr[right])){
        nextI = right;
    }
    if(nextI != i){
        swap(&arr[nextI], &arr[i]);
        heapify(arr, k, nextI, compare);
    }
}
int* getKth(int arr[], int n, int k, bool (*compare)(const int, const int)){
    for(int i = k/2-1; i >= 0; --i){
        heapify(arr, k, i, compare);
    }
    for(int i = k; i < n ; ++i){
        if(compare(arr[i], arr[0])){
            swap(&arr[0], &arr[i]);
            heapify(arr, k, 0, compare);
        }
    }
    return arr;
}
int* getKthLargest(int arr[], int n, int k){
    //should use min heap
    return getKth(arr, n, k, greater);
}
int* getKthSmallest(int arr[], int n, int k){
    //should use max heap
    return getKth(arr, n, k, less);
}
//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}
