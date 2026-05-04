int mySqrt(int x) {
    if (x < 2) return x;

    int left = 2;
    int right = x / 2;
    int mid;
    long num;

    while (left <= right) {
        mid = left + (right - left) / 2;
        num = (long)mid * mid;

        if (num > x) {
            right = mid - 1;
        } else if (num < x) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return right;
}