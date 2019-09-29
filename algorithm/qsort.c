#include <stdio.h>

void swap(int arr[], int a, int b)
{
    if (a == b) return;
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void qsort(int arr[], int s, int e)
{
    if (s >= e) return;
    int x = arr[s];
    int j = s, i = s+1;
    for(; i <= e; i++) {
        if (arr[i] > x) {
            swap(arr, j+1, i);
            j++;
        }
    }
    swap(arr, s, j);
    qsort(arr, s, j-1);
    qsort(arr, j+1, e);
}
void qsort2(int arr[], int s, int e)
{
    if (s >= e) return;
    int p = (e+s)/2;
    swap(arr, p, s);
    int x = arr[s];
    int j = s, i = s+1;
    for(; i <= e; i++) {
        if (arr[i] > x) {
            swap(arr, j+1, i);
            j++;
        }
    }
    swap(arr, s, j);
    qsort(arr, s, j-1);
    qsort(arr, j+1, e);
}

int main()
{
    int arr[] = {5,4,8,1,3,9,2,11,0,23};
    qsort2(arr, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
