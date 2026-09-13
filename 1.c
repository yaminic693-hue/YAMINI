#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int a[], int low, int high) {
    struct Result result, left, right;

    // Only one element
    if (low == high) {
        result.max = a[low];
        result.min = a[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (a[low] > a[high]) {
            result.max = a[low];
            result.min = a[high];
        } else {
            result.max = a[high];
            result.min = a[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = findMaxMin(a, low, mid);
    right = findMaxMin(a, mid + 1, high);

    // Combine
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int a[] = {10, 5, 20, 8, 15, 2};
    int n = sizeof(a) / sizeof(a[0]);

    struct Result result = findMaxMin(a, 0, n - 1);

    printf("Maximum = %d\n", result.max);
    printf("Minimum = %d\n", result.min);

    return 0;
}