#include <stdbool.h>

bool canSplit(int* nums, int numsSize, int k, int maxSum) {
    int currentSum = 0;
    int subarrays = 1;

    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] > maxSum) {
            subarrays++;
            currentSum = nums[i];
            if (subarrays > k) return false;
        } else {
            currentSum += nums[i];
        }
    }
    return true;
}

int splitArray(int* nums, int numsSize, int k) {
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left) left = nums[i];
        right += nums[i];
    }

    int ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (int)ans;
}