#include <iostream>

#define MAX 10

using namespace std;

int arr[MAX] = {2,1,3,5,9,8,6,7,0,4};

void swap(int l, int r){
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void display(){
    cout << "\n[";
    for (int i=0; i < MAX; ++i){
        cout << arr[i];
    }
    cout << "]";
}

int partition(int l, int r, int pivot){
    int numL(l), numR(r);
    while (1)
    {
        while(numL < numR && arr[numL] <= pivot)
        {
            ++numL;
        }

        while (numR > 0 && arr[numR] >= pivot)
        {
            --numR;
        }

        if (numL >= numR){
            break; 
        }else{
            swap(numL, numR);
        }
    }

    // swap pivot
    swap(numL, r);   
    return numL;
}

void quick_sort(int left, int right){
    if (left >= right){
        return;
    }else{
        int pivot = arr[right];
        int pos = partition(left, right, pivot);
        quick_sort(left, pos -1);
        quick_sort(pos + 1, right);
    }
}

int main(){
    display();
    quick_sort(0, MAX - 1);
    display();

    return 0;
}