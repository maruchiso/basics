#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    //copy to temporary arrays
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    //L + R
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy rest
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(std::vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    std::vector<int> arr = {103, 12, 11, 5, 6, 50, 68, 420};
    int n = arr.size();
    std::cout << "Przed\n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    MergeSort(arr, 0, n - 1);

    std::cout << "Po MergeSort\n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}