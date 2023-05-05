#include <stdio.h>

#define MAX 10

int arr[MAX] = {7,9,3,6,2,1,0,5,8,4};
int b[MAX];

void display(){
    printf("[");
    for(int i=0; i< MAX; i++){
        printf("%d", arr[i]);
    }
    printf("]");
}

void merging(int low, int mid, int high){
    int i,l = low, r = mid + 1;
    for(i = low; l <= mid && r <= high; i++){
        if(arr[l] <= arr[r]){
            b[i] = arr[l++];
        }else{
            b[i] = arr[r++];
        }
    }
    while (l <= mid)
    {
        b[i++] = arr[l++];
    }
    while (r <= high)
    {
        b[i++] = arr[r++];
    }
    
    printf("\n[");
    for(i=0; i< MAX; i++){
        printf("%d", b[i]);
    }
    printf("]");
    for(i = low; i<= high; i++){
        arr[i] = b[i];
    }
}

void sort(int low, int high){
    int mid;
    if(low >= high){
        return;
    }else{
        mid = (low + high)/2;
        sort(low,mid);
        sort(mid +1,high);
        merging(low, mid, high);
    }
}
int main(){

    printf("Mang nhap vao:\n");
    display();
    sort(0, MAX-1);
    printf("Mang da merge sort: \n");
    display();
}