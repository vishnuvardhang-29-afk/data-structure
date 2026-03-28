#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int peek() {
    return stack[top];
}

void nextGreaterElement(int arr[], int n) {

    push(arr[0]);

    for (int i = 1; i < n; i++) {
        int next = arr[i];

        while (!isEmpty() && peek() < next) {
            int element = pop();
            printf("%d → %d\n", element, next);
        }

        push(next);
    }

    while (!isEmpty()) {
        int element = pop();
        printf("%d → -1\n", element);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Next Greater Elements:\n");
    nextGreaterElement(arr, n);

    return 0;
}