#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int topIndex;
    int minTop;
} MinStack;

// Create stack
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->topIndex = -1;
    obj->minTop = -1;
    return obj;
}

// Push element
void minStackPush(MinStack* obj, int x) {
    obj->stack[++obj->topIndex] = x;
    if (obj->minTop == -1 || x <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = x;
    }
}

// Pop element
void minStackPop(MinStack* obj) {
    if (obj->topIndex == -1) return;

    int val = obj->stack[obj->topIndex--];
    if (val == obj->minStack[obj->minTop]) obj->minTop--;
}

// Top element
int minStackTop(MinStack* obj) {
    if (obj->topIndex == -1) return -1;
    return obj->stack[obj->topIndex];
}

// Get minimum
int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return -1;
    return obj->minStack[obj->minTop];
}

// Free memory
void minStackFree(MinStack* obj) {
    free(obj);
}
