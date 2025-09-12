#include <iostream>
using namespace std;

class Linked_List{
    private:
        class Node{
            public:
                int value;
                Node *next;
                Node(int v){
                    value = v;
                    next = nullptr;
                }
            };
            Node *head;
    public:
        Linked_List(){
            head = nullptr;
        }

        //insert in the beginning of the list
        Linked_List insert_beginning(int v){
            Node *new_node = new Node(v);
            new_node->next = head;
            head = new_node;
        }

        //insert in the end of the list
        Linked_List insert_end(int v)
        {
            Node *current = head;
            Node *new_node = new Node(v);
            if(head == nullptr)
                insert_beginning(v);
            while(current->next != nullptr)
                current = current->next;
            current->next = new_node;
        }

        //insert in position
        Linked_List insert_position(int v, int position)
        {
            Node *current = head;
            Node *new_node = new Node(v);
            int counter = 0;
            if(position == 0)
            {
                insert_beginning(v);
                return *this;
            }
            while(current != NULL && counter < position - 1)
            {
                current = current->next;
                counter++;
            }
            if(current == nullptr)
            {
                printf("Position out of range !\n");
                delete new_node;
                return *this;
            }
            new_node->next = current->next;
            current->next = new_node;
            return *this;
        }

        //Display list elements
        void display(){
            if(head == nullptr)
                cout<<"List is empty!\n";
            while(head != nullptr)
            {
                cout<<head->value<<" -> ";
                head = head->next;
            }
            cout << "NULL\n";
        }
};

int main(){
    Linked_List list;
    list.insert_beginning(10);
    list.insert_beginning(20);
    list.insert_beginning(30);
    list.insert_end(69);
    list.insert_position(100,0);
    list.display();
}