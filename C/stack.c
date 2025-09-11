#include <stdio.h>
#include <stdbool.h>
#define max 100
bool isfull(int top){
    return(top == max - 1);
}
bool isempty(int top)
{
    return(top == -1);
}
void push(int stack[],int *top,int val)
{
    if(!isfull(top))
    {
        (*top)++;
        stack[*top] = val;
    }
}
void pop(int stack[],int *top)
{
    if(!isempty(top))
    {
        *(top)--;
    }
}
int main(){
    int pile[max];
    int *top;
}
    