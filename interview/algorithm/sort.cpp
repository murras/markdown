#include <algorithm>
#include <iostream>
#define SIZE 300
using namespace std;
void Print_ary(int a[], int length);
void Bubble_sort(int ary[], int length);
void Bubble_sort_improved(int ary[], int length);
void Selection_sort(int ary[], int length);
void Insertion_sort(int ary[], int length);
void Quick_sort(int ary[], int, int);
int Partition(int ary[], int, int);
void Merge_sort(int ary[], int left, int right);
void Merge(int ary[], int left, int mid, int right);
int main() {
    int a[] = {1, 32, 3, 24, 15};
    Print_ary(a, 5);
    Merge_sort(a, 0, 4);
    Print_ary(a, 5);
}

void Print_ary(int a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
void Bubble_sort(int ary[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (ary[j] > ary[j + 1])
                swap(ary[j], ary[j + 1]);
        }
    }
}
void Bubble_sort_improved(int ary[], int length) {
    bool sorted = false;
    for (int i = 0; i < length; i++) {
        // 정렬된 상태
        if (sorted)
            break;
        sorted = true;
        for (int j = 0; j < length - 1 - i; j++) {
            if (ary[j] > ary[j + 1]) {
                // 정렬되지 않았으니 False 처리.
                sorted = false;
                swap(ary[j], ary[j + 1]);
            }
        }
    }
}
void Selection_sort(int ary[], int length) {
    int min_index;
    for (int i = 0; i < length - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (ary[min_index] > ary[j]) {
                min_index = j;
            }
        }
        swap(ary[i], ary[min_index]);
    }
}
void Insertion_sort(int ary[], int length) {
    int i, j, current;
    for (i = 1; i < length; i++) {
        current = ary[i];
        for (j = i - 1; j >= 0 && ary[j] > current; j--) {
            ary[j + 1] = ary[j];
        }
        ary[j + 1] = current;
    }
}
void Quick_sort(int ary[], int low, int high) {
    if (low < high) {
        int pivot = Partition(ary, low, high);
        Quick_sort(ary, low, pivot - 1);
        Quick_sort(ary, pivot + 1, high);
    }
}
int Partition(int ary[], int low, int high) {
    int left = low, right = high;
    int pivot = ary[left];  // pivot을 가장 왼쪽으로 선택하기로 한다.
    while (left < right) {
        // pivot보다 큰 원소가 나올 때까지 left를 증가시킨다.
        while (ary[left] <= pivot)
            left++;
        // pivot보다 작은 원소가 나올 때까지 right를 감소시킨다.
        while (ary[right] > pivot)
            right--;
        if (left < right)
            swap(ary[left], ary[right]);
    }
    swap(ary[right], ary[low]);
    return right;
}
void Merge_sort(int ary[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        Merge_sort(ary, left, mid);
        Merge_sort(ary, mid + 1, right);
        Merge(ary, left, mid, right);
    }
}
void Merge(int ary[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int temp[SIZE];
    while (i <= mid && j <= right) {
        if (ary[i] <= ary[j])
            temp[k++] = ary[i++];
        else
            temp[k++] = ary[j++];
    }
    if (i > mid) {
        for (int l = j; l <= right; l++)
            temp[k++] = ary[l];
    } else {
        for (int l = i; l <= mid; l++)
            temp[k++] = ary[l];
    }
    for (int l = left; l <= right; l++)
        ary[l] = temp[l];
}