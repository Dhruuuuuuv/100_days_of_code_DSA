int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low) low = weights[i];
        high += weights[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        int currentWeight = 0;
        int daysNeeded = 1;

        for (int i = 0; i < weightsSize; i++) {
            if (currentWeight + weights[i] > mid) {
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += weights[i];
        }

        if (daysNeeded > days) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}