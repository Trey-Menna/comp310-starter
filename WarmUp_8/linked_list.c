#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to add a new node at the beginning of the linked list
void push(struct LinkedList* list, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Set the data of the new node
    new_node->data = new_data;

    // Set the next pointer of the new node to the current head
    new_node->next = list->head;

    // Update the head to point to the new node
    list->head = new_node;
}

// Function to delete a node with a specific key from the linked list
void deleteNode(struct LinkedList* list, int key) {
    struct Node* temp = list->head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not present in the linked list
    if (temp == NULL)
        return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free the memory of the deleted node
    free(temp);
}

// Function to print the linked list
void printList(struct LinkedList* list) {
    struct Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Initialize an empty linked list
    struct LinkedList myLinkedList;
    myLinkedList.head = NULL;

    // Add elements to the linked list
    push(&myLinkedList, 2);
    push(&myLinkedList, 3);
    push(&myLinkedList, 1);
    push(&myLinkedList, 7);

    // Print the original linked list
    printf("Created Linked list is:\n");
    printList(&myLinkedList);

    // Delete a node with the key 1
    deleteNode(&myLinkedList, 1);

    // Print the linked list after deletion
    printf("\nLinked List after Deletion of 1:\n");
    printList(&myLinkedList);

    return 0;
}
