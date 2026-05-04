#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlaceBalls(int* position, int n, int m, int mid) {
    int count = 1;
    int lastPos = position[0];
    for (int i = 1; i < n; i++) {
        if (position[i] - lastPos >= mid) {
            count++;
            lastPos = position[i];
        }
        if (count >= m) return 1;
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);
    
    int low = 1;
    int high = (position[positionSize - 1] - position[0]) / (m - 1);
    int ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceBalls(position, positionSize, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}