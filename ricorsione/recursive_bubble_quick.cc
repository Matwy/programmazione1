#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{ 
    if (n == 1) 
        return; 
  
    int count = 0; 

    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]){ 
            swap(arr[i], arr[i+1]); 
            count++; 
        } 
  
      if (count==0) 
           return; 
  
    bubbleSort(arr, n-1); 
}
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void printArray(int arr[], int n) 
{ 
    for (int i=0; i < n; i++) 
        cout<<arr[i]<<" "; 
    cout<<"\n"; 
} 
int* generate_numbers(int N){
    int* random_array = new int[N];
    for(int i = 0; i < N; i++){
        random_array[i] = rand() % 100;
    }
    return random_array;
}
// Driver program to test above functions 
int main() 
{ 
    int* arr = generate_numbers(10); 
    int n = 10; 
    bubbleSort(arr, n);
    cout<<"Bubble array : \n"; 
    printArray(arr, n); 
    delete[] arr;

    arr = generate_numbers(10); 
    quickSort(arr, 0, n - 1);
    cout<<"Quick array : \n"; 
    printArray(arr, n);
    delete[] arr;

    return 0; 
} 
  