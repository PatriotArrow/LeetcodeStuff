#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int q1[100];
    int q2[100];

    int front1, rear1; // Front and rear pointers for q1
    int front2, rear2; // Front and rear pointers for q2
} MyStack;

int enq(int array[100], int* front, int* rear, int x) {
    if (*front == -1) {
        *front = *rear = 0;
        array[*front] = x;
        return 0;

    } else if (*rear < 100) {
        array[++(*rear)] = x;
        return 0;
    } else {
        return -1;
    }
}

int deq(int array[100], int* front, int* rear) {
    if (*front < *rear) {
        return array[(*front)++];

    } else if (*front == *rear) // reset queue
    {
        int ret = array[*front];
        *rear = *front = -1;
        return ret;

    } else {
        return -1;
    }
}

MyStack* myStackCreate() {

    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1;

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    while (obj->front1 != -1) {
        enq(obj->q2, &obj->front2, &obj->rear2,
            deq(obj->q1, &obj->front1, &obj->rear1));
    }

    enq(obj->q1, &obj->front1, &obj->rear1, x);

    while (obj->front2 != -1) {
        enq(obj->q1, &obj->front1, &obj->rear1,
            deq(obj->q2, &obj->front2, &obj->rear2));
    }
}

int myStackPop(MyStack* obj) { return deq(obj->q1, &obj->front1, &obj->rear1); }

int myStackTop(MyStack* obj) {
    if (obj->front1 == -1) { 
        return -1;           
    }
    return obj->q1[obj->front1]; 
}

bool myStackEmpty(MyStack* obj) { return obj->front1 == -1; }

void myStackFree(MyStack* obj) {
    if (obj == NULL) {
        free(obj);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/