#include <iostream>
#include "quick_sort.h"

#define MAX 10

using namespace std;

int arr[MAX] = {2,4,5,7,3,1,9,8,0,6};

void display(){
    cout << "\n[";
    for(int i = 0; i < MAX; ++i){
        cout << arr[i];
    }
    cout << "]\n";
}

void swap(int l, int r){
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

// int partition(int numLeft, int numRight, int pivot){
//     int numPivot = numRight;
//     while (true)
//     {
//         while(arr[++numLeft] <= pivot){}
//         while(numRight > 0 && arr[--numRight] >= pivot){}

//         if(numLeft >= numRight){
//             break;
//         }else{
//             swap(numLeft, numRight);
//         }
//     }
//     swap(numLeft, numPivot);
//     return numLeft;
// }
// ham de chia mang thanh 2 phan, su dung phan tu chot (pivot)
int partition(int left, int right, int pivot){
    int leftPointer = left -1;
    int rightPointer = right;
 
    while(true){
 
        while(arr[++leftPointer] < pivot){
            //khong lam gi
        }
        while(rightPointer > 0 && arr[--rightPointer] > pivot){
            //khong lam gi
        }
 
        if(leftPointer >= rightPointer){
            break;
        }else{
            printf(" Phan tu duoc trao doi :%d,%d\n", 
            arr[leftPointer],arr[rightPointer]);
            swap(leftPointer,rightPointer);
        }
 
    }
 
    printf(" Phan tu chot duoc trao doi :%d, %d\n", arr[leftPointer],arr[right]);
    swap(leftPointer,right);
    printf("Mang sau moi lan trao doi: "); 
    display();
    return leftPointer;
}

void quick_sort(int left, int right){
    if (right <= left){
        return;
    }else{
        int pivot = arr[right];
        int pos = partition(left, right, pivot);
        quick_sort(left, pos - 1);
        quick_sort(pos + 1, right);
    }
}


int main(){
    display();
    quick_sort(0, MAX - 1);
    display();

    return 0;
}
