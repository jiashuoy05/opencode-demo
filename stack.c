#include <stdio.h>
#include <stdlib.h>

// Stack node structure
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Creates a new stack node with the given data value.
// Parameters:
//   data - The integer value to store in the node
// Returns:
//   Pointer to newly allocated StackNode, or NULL if allocation fails
StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Pushes an element onto the top of the stack.
// Parameters:
//   top - Pointer to the current top of the stack
//   data - The integer value to push onto the stack
// Returns:
//   Pointer to the new top of the stack, or the unchanged top if push fails
StackNode* push(StackNode* top, int data) {
    StackNode* newNode = createStackNode(data);
    if (newNode == NULL) {
        return top;
    }
    newNode->next = top;
    return newNode;
}

// Pops an element from the top of the stack.
// Parameters:
//   top - Pointer to the current top of the stack
//   value - Pointer to store the popped value
// Returns:
//   Pointer to the new top of the stack, or NULL if stack is empty
StackNode* pop(StackNode* top, int* value) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return NULL;
    }
    StackNode* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Returns the value at the top of the stack without removing it.
// Parameters:
//   top - Pointer to the current top of the stack
//   value - Pointer to store the top value
// Returns:
//   1 if successful, 0 if stack is empty
int peek(StackNode* top, int* value) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return 0;
    }
    *value = top->data;
    return 1;
}

// Checks if the stack is empty.
// Parameters:
//   top - Pointer to the current top of the stack
// Returns:
//   1 if stack is empty, 0 otherwise
int isStackEmpty(StackNode* top) {
    return (top == NULL);
}

// Displays all elements in the stack from top to bottom.
// Parameters:
//   top - Pointer to the current top of the stack
// Returns:
//   void
void displayStack(StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (top to bottom): ");
    StackNode* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Frees all memory allocated for the stack nodes.
// Parameters:
//   top - Pointer to the current top of the stack
// Returns:
//   void
void destroyStack(StackNode* top) {
    while (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        free(temp);
    }
}

// Main function demonstrating stack operations
int main(void) {
    printf("=== Stack Operations Test ===\n\n");

    StackNode* stack = NULL;
    int value;

    // Test 1: Push elements onto stack
    printf("Test 1: Push elements onto stack\n");
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    stack = push(stack, 40);
    displayStack(stack);
    printf("\n");

    // Test 2: Peek at top element
    printf("Test 2: Peek at top element\n");
    if (peek(stack, &value)) {
        printf("Top element: %d\n", value);
    }
    printf("\n");

    // Test 3: Pop elements from stack
    printf("Test 3: Pop elements from stack\n");
    while (!isStackEmpty(stack)) {
        stack = pop(stack, &value);
        printf("Popped: %d\n", value);
        displayStack(stack);
    }
    printf("\n");

    // Test 4: Check isEmpty on empty stack
    printf("Test 4: Check isEmpty on empty stack\n");
    if (isStackEmpty(stack)) {
        printf("Stack is empty: Yes\n");
    } else {
        printf("Stack is empty: No\n");
    }
    printf("\n");

    // Test 5: Pop from empty stack
    printf("Test 5: Attempt to pop from empty stack\n");
    stack = pop(stack, &value);
    printf("\n");

    // Test 6: Push after empty, then pop
    printf("Test 6: Push after empty, then pop\n");
    stack = push(stack, 100);
    displayStack(stack);
    stack = pop(stack, &value);
    printf("Popped: %d\n", value);
    printf("\n");

    // Test 7: Multiple pushes and pops
    printf("Test 7: Multiple pushes and pops\n");
    for (int i = 1; i <= 5; i++) {
        stack = push(stack, i * 10);
    }
    displayStack(stack);
    for (int i = 0; i < 3; i++) {
        stack = pop(stack, &value);
        printf("Popped: %d\n", value);
    }
    displayStack(stack);
    printf("\n");

    // Cleanup
    printf("Cleaning up...\n");
    destroyStack(stack);
    printf("Stack destroyed\n");

    return 0;
}
