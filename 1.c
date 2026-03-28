#include<stdio.h>
#include<string.h>
#define max 100
int top=-1;
char stack[max];
void push(char x){
    if(top==max-1){
        printf("underflow\n");
    }else{
        stack[++top]=x;
    }
}
char pop(){
    if(top==-1){
        printf("underflow\n");
        return -1;
    }else{
        return stack[top--];
    }
} 
int main(){
    char str[max];
    int i,len;
    printf("enter the string\n");
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++){
        push(str[i]);
    }
    printf("reverse string\n");
     for(i=0;i<len;i++){
        printf("%c",pop());
     }
     return 0;
}