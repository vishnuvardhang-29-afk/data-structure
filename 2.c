#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("stack underflow\n");
        return -1;  
    } else {
        return stack[top--];
    }
}

int balanced(char *exi){
    for(int i=0;i<strlen(exi);i++){
        char ch=exi[i];
        if(ch=='('||ch=='{'||ch=='['){
            push(ch);
        }else if(ch==')'||ch=='}'||ch==']'){
            if(top==-1){
                return 0;
            }char popped=pop();
            if(ch==')'&& popped!='('||ch=='}'&& popped!='{'||ch==']'&& popped!='['){
                return 0;
            }
        }
    }
    return (top==-1);
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (balanced(exp)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }
    return 0;
}