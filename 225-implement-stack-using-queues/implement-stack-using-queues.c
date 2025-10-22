#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int q1[MAX], q2[MAX];
    int front1, rear1, front2, rear2;
} MyStack;

// Initialize the stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front1 = stack->rear1 = 0;
    stack->front2 = stack->rear2 = 0;
    return stack;
}

// Helper function to check if a queue is empty
bool isEmptyQueue(int front, int rear) {
    return front == rear;
}

// Push element x onto stack
void myStackPush(MyStack* stack, int x) {
    // Step 1: Enqueue x into q2
    stack->q2[stack->rear2++] = x;

    // Step 2: Move all elements from q1 -> q2
    while (!isEmptyQueue(stack->front1, stack->rear1)) {
        stack->q2[stack->rear2++] = stack->q1[stack->front1++];
    }

    // Step 3: Swap q1 and q2 pointers (by copying indices)
    int* tempArr = (int*)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) tempArr[i] = stack->q1[i];
    for (int i = 0; i < MAX; i++) stack->q1[i] = stack->q2[i];
    for (int i = 0; i < MAX; i++) stack->q2[i] = tempArr[i];
    free(tempArr);

    int tempFront = stack->front1;
    int tempRear = stack->rear1;
    stack->front1 = stack->front2;
    stack->rear1 = stack->rear2;
    stack->front2 = tempFront;
    stack->rear2 = tempRear;

    // Reset q2
    stack->front2 = stack->rear2 = 0;
}

// Removes the element on top of the stack and returns it
int myStackPop(MyStack* stack) {
    if (isEmptyQueue(stack->front1, stack->rear1)) return -1;
    return stack->q1[stack->front1++];
}

// Get the top element
int myStackTop(MyStack* stack) {
    if (isEmptyQueue(stack->front1, stack->rear1)) return -1;
    return stack->q1[stack->front1];
}

// Returns whether the stack is empty
bool myStackEmpty(MyStack* stack) {
    return isEmptyQueue(stack->front1, stack->rear1);
}

// Free memory
void myStackFree(MyStack* stack) {
    free(stack);
}

/*Demo
int main() {
    MyStack* myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("%d\n", myStackTop(myStack));   // Output: 2
    printf("%d\n", myStackPop(myStack));   // Output: 2
    printf("%s\n", myStackEmpty(myStack) ? "true" : "false"); // Output: false
    myStackFree(myStack);
    return 0;
}
*/