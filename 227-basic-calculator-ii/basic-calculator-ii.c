int calculate(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;

    long *stack = (long *)malloc(len * sizeof(long));
    int top = -1;
    long currentNumber = 0;
    char operation = '+';

    for (int i = 0; i < len; i++) {
        char curr = s[i];

        if (isdigit(curr)) {
            currentNumber = (currentNumber * 10) + (curr - '0');
        }

        if ((!isdigit(curr) && curr != ' ') || i == len - 1) {
            if (operation == '+') {
                stack[++top] = currentNumber;
            } else if (operation == '-') {
                stack[++top] = -currentNumber;
            } else if (operation == '*') {
                stack[top] = stack[top] * currentNumber;
            } else if (operation == '/') {
                stack[top] = stack[top] / currentNumber;
            }
            operation = curr;
            currentNumber = 0;
        }
    }

    long result = 0;
    while (top != -1) {
        result += stack[top--];
    }

    free(stack);
    return (int)result;
}