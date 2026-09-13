#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = -999999;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = -999999;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high) {

    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);

    return max(max(left, right), cross);
}

int main() {
    int a[] = {-2, 3, -1, 5, -6, 4};
    int n = sizeof(a) / sizeof(a[0]);

    int result = maxSubarray(a, 0, n - 1);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}