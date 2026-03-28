#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node with a specific value
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    // If head node itself holds the data to be deleted
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If data was not present in the list
    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return head;
    }

    // Unlink the node from the list and free memory
    prev->next = current->next;
    free(current);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    printf("--- Inserting elements ---\n");
    head = insertAtBeginning(head, 10);
    displayList(head); // Expected: 10 -> NULL

    head = insertAtEnd(head, 20);
    displayList(head); // Expected: 10 -> 20 -> NULL

    head = insertAtBeginning(head, 5);
    displayList(head); // Expected: 5 -> 10 -> 20 -> NULL

    head = insertAtEnd(head, 30);
    displayList(head); // Expected: 5 -> 10 -> 20 -> 30 -> NULL

    printf("\n--- Deleting elements ---\n");
    head = deleteNode(head, 20);
    displayList(head); // Expected: 5 -> 10 -> 30 -> NULL

    head = deleteNode(head, 5);
    displayList(head); // Expected: 10 -> 30 -> NULL

    head = deleteNode(head, 100); // Node not found
    displayList(head); // Expected: 10 -> 30 -> NULL (and "Node not found" message)

    head = deleteNode(head, 30);
    displayList(head); // Expected: 10 -> NULL

    head = deleteNode(head, 10);
    displayList(head); // Expected: Linked List is empty.

    // Free all remaining nodes to prevent memory leaks (though in this example, it's empty after deletes)
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    // head = NULL; // No need to set head to NULL again as it's already handled by deleteNode for the last node

    return 0;
}
