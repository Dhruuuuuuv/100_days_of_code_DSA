#include <stdlib.h>
#include <limits.h>

typedef struct {
    int val;
    int min;
} Node;

typedef struct {
    Node* data;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10000;
    obj->data = (Node*)malloc(sizeof(Node) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    int currentMin;
    if (obj->top == 0) {
        currentMin = val;
    } else {
        int prevMin = obj->data[obj->top - 1].min;
        currentMin = (val < prevMin) ? val : prevMin;
    }
    obj->data[obj->top].val = val;
    obj->data[obj->top].min = currentMin;
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}