#include <iostream>

void bubbleSort(int arr[], int arrSize){
    int tmp;
    int swaps = 0;
    for(int i = 0; i < arrSize; i ++){
        for(int j = 0; j < arrSize - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swaps++;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    std::cout<<"Number of swaps:" << swaps <<std::endl;

    std::cout<<"Bubble Sorted Array: [";
    for(int k = 0; k < arrSize; k++) {
        std::cout << arr[k] <<",";
    }
    std::cout<<"]"<<std::endl;

}

void selectionSort(int arr[], int arrSize){
    for(int i = 0 ; i< arrSize-1; i++){
        int min = i;
        for(int j = i+1; j<arrSize; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        arr[i] = arr[min];

    }

    std::cout<<"Selection Sorted Array: [";
    for(int i = 0; i < arrSize; i++){
        std::cout<<arr[i]<<",";
    }
    std::cout<<"]"<<std::endl;
}

void insertionSort(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        int temp = arr[i];
        int j = i;

        while(j > 0 && temp < arr[j-1]){
            arr[j] = arr[j-1];
            j = j-1;
        }

        arr[j] = temp;
    }

    std::cout<<"Insertion Sorted Array: [";
    for(int i = 0; i < arrSize; i++){
        if(i == arrSize-1) {
            std::cout<<arr[i];
            break;
        }
        std::cout<<arr[i]<<",";
    }
    std::cout<<"]"<<std::endl;
}

int main() {
    int numArray[] = {2,4,19,20,1,5,3,50,55,12};
    int arraySize = sizeof(numArray)/sizeof(numArray[0]);
    std::cout << "Array Size: " <<arraySize<< std::endl;
    bubbleSort(numArray, arraySize);
    selectionSort(numArray, arraySize);
    insertionSort(numArray, arraySize);



    return 0;
}
