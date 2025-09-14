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

        //1. insert in the beginning of the list
        Linked_List insert_beginning(int v){
            Node *new_node = new Node(v);
            new_node->next = head;
            head = new_node;
            return *this;
        }

        //2. insert in the end of the list
        Linked_List insert_end(int v)
        {
            Node *current = head;
            Node *new_node = new Node(v);
            if(head == nullptr){
                insert_beginning(v);
                return *this;
            }

            while(current->next != nullptr)
                current = current->next;
            current->next = new_node;
        }

        //3. insert in position
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

        //4. delete last node
        Linked_List delete_last()
        {
            if(head == nullptr)
            {    
                cout<<"your list is empty!\n";
                return *this;
            }

            if(head->next == nullptr)
            {
                delete(head);
                head = nullptr;
                return *this;
            }
            
            Node *current = head;
            while(current->next->next != nullptr){
                current = current->next;
            }
            Node *temp = current->next;
            delete(temp);
            current->next = nullptr;
            return *this;
        }
        
        //5. delete beginning
        Linked_List delete_beginning(){
            if(head == nullptr){
                cout<<"Your list is empty!\n";
                return *this;
            }
            Node *temp = head;
            head = head->next;
            delete temp;
            return *this;
        }

        //6. delete position
        Linked_List delete_position(int pos){
            if(head == nullptr){
                cout<<"your list is empty\n";
                return *this;
            }
            if(pos == 0){
                delete_beginning();
                return *this;
            }
            Node *current = head;
            int counter = 0;
            while(current != nullptr && counter < pos - 1){
                current = current->next;
                counter++;
            }
            if(current == nullptr || current->next == nullptr){
                cout<<"position out of range !\n";
                return *this;
            }
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            return *this;
        }


        //7. Display list elements
        void display(){
            Node *current = head;
            if(current == nullptr)
                cout<<"List is empty!\n";
            while(current != nullptr)
            {
                cout<<current->value<<" -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }

        //8. search element in the list

        



        // ~Linked_List(){
        //     Node* current = head;
        //     while(current != nullptr){
        //         Node* temp = current;
        //         current = current->next;
        //         delete temp;
        //     }
        //     head = nullptr;
        //     cout << "Your list was destroyed !\n";
        // };
};

int main(){
    Linked_List list;
    list.insert_beginning(10);
    list.insert_beginning(20);
    list.insert_beginning(30);
    list.insert_end(69);
    list.insert_position(100,0);
    list.display();
    list.delete_position(1);
    list.display();
}