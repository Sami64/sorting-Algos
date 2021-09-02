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
            if(arr[j] < arr[min])
                min = j;
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

void shellShort(int arr[], int arrSize){
    //int pass = 0;
    for(int gap = arrSize/2; gap > 0; gap/=2){
        for(int j = gap; j < arrSize; j++){
            for(int i = j - gap; i >= 0; i = i-gap){
      //          pass++;
                if(arr[i+gap] > arr[i])
                    break;
                int tmp = arr[i+gap];
                arr[i+gap] = arr[i];
                arr[i] = tmp;
            }
        }
    }

    // Print
    std::cout<<"Shell Sorted Array: [";
    for(int i = 0; i< arrSize; i++){
        if(i == arrSize-1){
            std::cout<<arr[i];
            break;
        }
        std::cout<<arr[i]<<",";
    }
    std::cout<<"]"<<std::endl;
    //std::cout<<"Shell Passes: "<<pass<<std::endl;

}

int getMax(int arr[], int arrSize){
    int max = arr[0];
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int arrSize, int pos){
    int countArr[10] = {0};
    int outputArr[arrSize];
    for(int i = 0; i<arrSize; i++)
        countArr[(arr[i]/pos) % 10]++;// Set count array
    for(int i = 0; i < 10; i++)
        countArr[i] += countArr[i-1]; // Update count array
    for(int i = arrSize-1; i >= 0; i--) {
        outputArr[countArr[(arr[i] / pos) % 10] - 1] = arr[i]; // Fill output array
        countArr[(arr[i]/pos) % 10]--; // Reduce value in count array of the found number
    }

    for(int i = 0 ; i < arrSize; i++)
        arr[i] = outputArr[i];
}

void radixSort(int arr[], int arrSize){
    int maxNum = getMax(arr, arrSize);
    for(int pos = 1; maxNum / pos > 0; pos*=10){
        countSort(arr,arrSize,pos);
    }

    // Print
    std::cout<<"Radix Sorted Array: [";
    for(int i = 0; i < arrSize; i++){
        std::cout<<arr[i]<<",";
    }
    std::cout<<"]"<<std::endl;
}

int main() {
    //int numArray[] = {2,4,19,20,1,5,3,50,55,12};
    int numArray[] = {432,8,530,90,88,231,11,45,677,199};
    int arraySize = sizeof(numArray)/sizeof(numArray[0]);
    std::cout << "Array Size: " <<arraySize<< std::endl;
    bubbleSort(numArray, arraySize);
    selectionSort(numArray, arraySize);
    insertionSort(numArray, arraySize);
    shellShort(numArray, arraySize);
    radixSort(numArray, arraySize);



    return 0;
}
