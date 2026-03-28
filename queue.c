#include <stdio.h>
#include <stdlib.h>

// Queue node structure
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Creates a new queue node with the given data value.
// Parameters:
//   data - The integer value to store in the node
// Returns:
//   Pointer to newly allocated QueueNode, or NULL if allocation fails
QueueNode* createQueueNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Creates and initializes a new empty queue.
// Parameters:
//   None
// Returns:
//   Pointer to newly allocated Queue with front and rear set to NULL
Queue* createQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Adds an element to the rear of the queue (enqueue operation).
// Parameters:
//   queue - Pointer to the queue
//   data - The integer value to enqueue
// Returns:
//   1 if successful, 0 if queue is NULL or memory allocation fails
int enqueue(Queue* queue, int data) {
    if (queue == NULL) {
        printf("Queue is NULL!\n");
        return 0;
    }

    QueueNode* newNode = createQueueNode(data);
    if (newNode == NULL) {
        return 0;
    }

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return 1;
}

// Removes and returns the element from the front of the queue (dequeue).
// Parameters:
//   queue - Pointer to the queue
//   value - Pointer to store the dequeued value
// Returns:
//   1 if successful, 0 if queue is NULL or empty
int dequeue(Queue* queue, int* value) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty or NULL!\n");
        return 0;
    }

    QueueNode* temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return 1;
}

// Returns the value at the front of the queue without removing it.
// Parameters:
//   queue - Pointer to the queue
//   value - Pointer to store the front value
// Returns:
//   1 if successful, 0 if queue is NULL or empty
int peekQueue(Queue* queue, int* value) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty or NULL!\n");
        return 0;
    }
    *value = queue->front->data;
    return 1;
}

// Checks if the queue is empty.
// Parameters:
//   queue - Pointer to the queue
// Returns:
//   1 if queue is empty or NULL, 0 otherwise
int isEmpty(Queue* queue) {
    if (queue == NULL || queue->front == NULL) {
        return 1;
    }
    return 0;
}

// Displays all elements in the queue from front to rear.
// Parameters:
//   queue - Pointer to the queue
// Returns:
//   void
void displayQueue(Queue* queue) {
    if (queue == NULL) {
        printf("Queue is NULL!\n");
        return;
    }

    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Frees all memory allocated for the queue and its nodes.
// Parameters:
//   queue - Pointer to the queue
// Returns:
//   void
void destroyQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }

    QueueNode* current = queue->front;
    while (current != NULL) {
        QueueNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

// Main function demonstrating queue operations
int main(void) {
    printf("=== Queue Operations Test ===\n\n");

    // Test 1: Create queue and enqueue elements
    printf("Test 1: Create queue and enqueue elements\n");
    Queue* queue = createQueue();
    if (queue == NULL) {
        printf("Failed to create queue\n");
        return 1;
    }

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    displayQueue(queue);
    printf("\n");

    // Test 2: Peek at front element
    printf("Test 2: Peek at front element\n");
    int value;
    if (peekQueue(queue, &value)) {
        printf("Front element: %d\n", value);
    }
    printf("\n");

    // Test 3: Dequeue elements
    printf("Test 3: Dequeue elements\n");
    while (dequeue(queue, &value)) {
        printf("Dequeued: %d\n", value);
        displayQueue(queue);
    }
    printf("\n");

    // Test 4: Check isEmpty on empty queue
    printf("Test 4: Check isEmpty on empty queue\n");
    if (isEmpty(queue)) {
        printf("Queue is empty: Yes\n");
    } else {
        printf("Queue is empty: No\n");
    }
    printf("\n");

    // Test 5: Dequeue from empty queue
    printf("Test 5: Attempt to dequeue from empty queue\n");
    dequeue(queue, &value);
    printf("\n");

    // Test 6: Enqueue after empty, then dequeue
    printf("Test 6: Enqueue after empty, then dequeue\n");
    enqueue(queue, 100);
    displayQueue(queue);
    dequeue(queue, &value);
    printf("Dequeued: %d\n", value);
    printf("\n");

    // Test 7: Multiple enqueues and dequeues
    printf("Test 7: Multiple enqueues and dequeues\n");
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i * 10);
    }
    displayQueue(queue);
    for (int i = 0; i < 3; i++) {
        dequeue(queue, &value);
        printf("Dequeued: %d\n", value);
    }
    displayQueue(queue);
    printf("\n");

    // Cleanup
    printf("Cleaning up...\n");
    destroyQueue(queue);
    printf("Queue destroyed\n");

    return 0;
}
