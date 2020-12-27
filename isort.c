#include <stdio.h>
#define ARR_SIZE 50


void shift_element(int *arr, int i){
    while(i){
        *(arr+i) = *(arr + i-1);
        i--;
    }
}


void insertion_sort(int *arr, int len){
    for (int i = 1; i < len; ++i) {
        int key = *(arr+i);
        int j = i-1;
        while(j >= 0 && *(arr+j) > key){
            *(arr+j +1) = *(arr+j);
            j--;
        }
        *(arr +j +1) = key;
    }
}

void print_arr(int *arr, size_t len){
    for (int i = 0; i < len; ++i) {
        printf("%d",*(arr+i));
        if(i<len-1){
            printf(",");
        }
    }
    printf("\n");
}




int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i) {
//        printf("insert to arr[%d] ", i);
        if(scanf(" %d",(arr+i)) == -1){
            printf("wrong input\n");
            return -1;
        }
    }
    insertion_sort(arr,ARR_SIZE);
    print_arr(arr, ARR_SIZE);
    return 0;
}
