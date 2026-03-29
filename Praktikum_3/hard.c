#include <stdio.h>
#include <stdlib.h>

int countDig(int x){
    int count = 0;
    while (x > 0){
        count++;
        x /= 10;
    }
    return count;
}


int main(){
    int N;
    scanf("%d", &N);
    int arr[N];

    for (int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);
        arr[i] = A;
    }

    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N - i - 1; j++){
            int left = countDig(arr[j]);
            int right = countDig(arr[j+1]);
            if (left < right || (left == right && arr[j] > arr[j+1])){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    
    for(int i = 0; i < N-1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[N-1]);
    printf("\n");







    return 0;
}