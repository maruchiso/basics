#include <iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//O(N^2)
void BubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}
//O(N * log(n))
void MergeSort(int arr[], int n){


}


void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array\n";
    printArr(arr, n);
    std::cout << "sorted array\n";
    BubbleSort(arr, n);
    printArr(arr, n);

    return 0;
        
}