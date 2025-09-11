#include <iostream>
using namespace std;
#define Max 100
class Stack{
    private:
        int arr[Max];
        int top;
    public:
        Stack(){
            top = -1;
        }
        bool isempty(){
            return(top == -1);
        }
        bool isfull(){
            return(top == Max - 1);
        }
        void peek() {
            if(!isempty())
                cout << "Top element: " << arr[top] << endl;
            else
                cout << "Stack is empty\n";
        }

        void display() {
            if(!isempty()) {
                cout << "Stack elements: ";
                for(int i = 0; i <= top; i++)
                    cout << arr[i] << " ";
                cout << endl;
            } else {
                cout << "Stack is empty\n";
            }
        }
        void push(int val){
            if(!isfull()){
                top++;
                arr[top] = val;
            }
            else{
                cout<<"stack overflow !\n";
            }
        }

        void pop(){
            if(!isempty())
            {
                top--;
            }
            else
                cout<<"stack underflow\n";
        }

};

int main(){
    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.peek();
    s1.display();
    s1.pop();
    s1.display();
}