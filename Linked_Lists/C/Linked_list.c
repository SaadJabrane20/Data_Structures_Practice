#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node *next;
};
typedef struct Node *Node;

Node createNode(int data)
{
    Node new_node;
    new_node = (Node)malloc(sizeof(*new_node));
    new_node->value = data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    Node node1 = createNode(10);
    Node node2 = createNode(20);
    Node node3 = createNode(30);
    node1->next = node2;
    node2->next = node3;
    Node cuurent = node1;
    while (cuurent != NULL){
        printf("%d -> ",cuurent->value);
        cuurent = cuurent->next;
    }
    printf("NULL");
}