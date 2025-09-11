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
    if(!isfull(*top))
    {
        (*top)++;
        stack[*top] = val;
    }
    else
        printf("Stack Overflow!\n");
}
void pop(int stack[],int *top)
{
    if(!isempty(*top))
    {
        printf("popped: %d\n",stack[*top]);
        (*top)--;
    }
    else
        printf("Stack Underflow!\n");
}
void peek(int stack[], int top){
    if(!isempty(top))
        printf("Top element: %d\n", stack[top]);
    else
        printf("Stack is empty!\n");
}
void display(int stack[], int top){
    if(isempty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
int main(){
    int pile[max];
    int top = -1;
    int choice, val;
    do{
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter a value to push : ");
            scanf("%d",&val);
            push(pile,&top,val);
            printf("%d pushed onto stack\n", val);
            break;
        case 2:
            pop(pile,&top);
            break;
        case 3:
            peek(pile,top);
            break;
        case 4:
            display(pile,top);
            break;
        case 5 :
            printf("Exiting....");
            break;
        default:
            printf("invalid choice !");
            break;
        }
    }while(choice != 5);

    return 0;
}
    