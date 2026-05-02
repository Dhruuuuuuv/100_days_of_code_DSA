#include <math.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = 0, max_sum = nums[0];
    int currMin = 0, min_sum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        currMax += nums[i];
        if (currMax > max_sum) max_sum = currMax;
        if (currMax < 0) currMax = 0;

        currMin += nums[i];
        if (currMin < min_sum) min_sum = currMin;
        if (currMin > 0) currMin = 0;
    }

    if (max_sum < 0) {
        return max_sum;
    }

    int circular_sum = totalSum - min_sum;
    return (max_sum > circular_sum) ? max_sum : circular_sum;
}