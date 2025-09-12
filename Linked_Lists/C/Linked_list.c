#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node *next;
};
typedef struct Node *Node;

// 1.Create new Node
Node createNode(int data)
{
    Node new_node;
    new_node = (Node)malloc(sizeof(*new_node));
    new_node->value = data;
    new_node->next = NULL;
    return new_node;
}

// 2.insert in the beginning
Node insert_beginning(Node head,int value)
{
    Node new_node = createNode(value);
    new_node->next = head;
    return new_node;
}

// 3.insert in the end
Node insert_end(Node head,int value)
{   
    Node current = head;
    Node new_node = createNode(value);
    if(head == NULL)
        return new_node;
    else
    {
        while(current->next != NULL)
            current = current->next;

        current->next = new_node;
        return head;
    }
}   

// 4.insert at position
Node insert_position(Node head,int value,int position)
{
    int counter = 0;
    Node current = head;
    Node new_node = createNode(value);
    if(position == 0)
    {
        return insert_beginning(head,value);
    } 
    while(current != NULL && counter < position - 1)
    {
        current = current->next;
        counter++;
    }      
    if(current == NULL)
    {
        printf("Position out of range !");
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;  
}

// 5.Delete at beginning;
Node delete_beginning(Node head)
{
    if(head == NULL)
    {
        printf("your list is empty !\n");
        return NULL;    
    }
    Node temp = head;
    head = head->next;
    free(temp);
    return head;
}

// 6.delete at end
Node delete_end(Node head)
{
    if(head == NULL)
    {
        printf("list is empty !\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node current = head;
    while(current->next->next != NULL)
        current = current->next;
    Node temp = current->next;
    current->next = NULL;
    free(temp);
    return head;
}

// 7.delete at position
Node delete_position(Node head,int position)
{
    if(head == NULL)
    {
        printf("list is empty !\n");
        return NULL;
    }
    if(position == 0)
    {
        return delete_beginning(head);
    }
    Node current = head;
    int counter = 0;
    while(current->next != NULL && counter < position - 1)
    {
        current = current->next;
        counter++;
    }
    Node temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// 8.search value in the list
int search_position(Node head,int value)
{
    int position = 0;
    if(head == NULL)
    {
        return 0;
    }
    while(head != NULL)
    {
        if(head->value == value)
        {
            return position;
        }
        position++;
        head = head->next;
    }
    return -1;
}

// 9.display list elements
void Display(Node head)
{
    if(head == NULL)
    {
        printf("your list is empty !\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ",head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// 10.reverse list elements
Node reverse_list(Node head)
{
    Node prev = NULL;
    Node current = head;
    Node next;

    if (head == NULL)
        return NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;

}

int main() {
    Node head = NULL;

    // 1. Insert at beginning
    head = insert_beginning(head, 10);
    head = insert_beginning(head, 20);
    head = insert_beginning(head, 30);
    printf("After insert at beginning: ");
    Display(head);   // 30 -> 20 -> 10 -> NULL

    // 2. Insert at end
    head = insert_end(head, 40);
    head = insert_end(head, 50);
    printf("After insert at end: ");
    Display(head);   // 30 -> 20 -> 10 -> 40 -> 50 -> NULL

    // 3. Insert at position
    head = insert_position(head, 99, 2);
    printf("After insert 99 at pos 2: ");
    Display(head);

    // 4. Delete beginning
    head = delete_beginning(head);
    printf("After delete beginning: ");
    Display(head);

    // 5. Delete end
    head = delete_end(head);
    printf("After delete end: ");
    Display(head);

    // 6. Delete at position
    head = delete_position(head, 2);
    printf("After delete at pos 2: ");
    Display(head);

    // 7. Search
    int pos = search_position(head, 40);
    if (pos != -1)
        printf("Value 40 found at position: %d\n", pos);
    else
        printf("Value 40 not found!\n");

    // 8. Reverse
    head = reverse_list(head);
    printf("After reverse: ");
    Display(head);

    return 0;
}
