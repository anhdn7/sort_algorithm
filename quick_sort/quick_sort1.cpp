#include <iostream>
#define MAX 10

using namespace std;
int arr[MAX] = {4,3,6,7,1,9,0,2,5,8};

void swap(int& l, int& r){
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void display(){
    cout << "[";
    for(int i=0; i< MAX; ++i){
        cout << arr[i];
    }
    cout << "]";
}

int partition(int left, int right, int pivot){
    int numLeft = left-1;
    int numRight = right;

    while (true)
    {
        while (arr[++numLeft] < pivot)
        {
            /* nothing */
        }
        while (numRight > 0 && arr[--numRight] > pivot)
        {
            /* nothing */
        }
        if(numLeft >= numRight){
            break;
        }else{
            swap(numLeft, numRight);
        }
    }
    // swap pivot
    swap(numLeft, right);
    
    return numLeft;
}
void quick_sort(int left, int right){
    if(left >= right)
    {    
        return;
    }else{
        int pivot = arr[right];
        int pos = partition(left, right, pivot);
        quick_sort(left, pos -1);
        quick_sort(pos+1, right);
    }
}
int main(){
    display();
    quick_sort(0, MAX -1);
    display();
    
    return 0;
}