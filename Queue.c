//// Code from: https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

// C program for array implementation of queue


// function to create a queue of given capacity.
// It initializes size of queue as 0
#include "Queue.h"

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

//code for sorting from https://en.wikiversity.org/wiki/C_Source_Code/Sorting_array_in_ascending_and_descending_order
void sortByArrival (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j].arrivalTime > array[i].arrivalTime)
			{
				struct PCB temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
      else if (array[j].arrivalTime == array[i].arrivalTime) {
        lexigraphicalTieBreaker (array, i, j);
      }
		}
	}
}

void sortByBurst (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (array[j].burstTime > array[i].burstTime)
      {
        struct PCB temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void sortByPriority (struct PCB array[], int size) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (array[j].priority > array[i].priority)
      {
        struct PCB temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void lexigraphicalTieBreaker (struct PCB array[], int i, int j) {
    int comparison = strcmp (array[j].name, array[i].name);
    if (comparison < 0) {

    }
}

// Driver program to test above functions./
// int main()
// {
//     struct Queue* queue = createQueue(1000);

//     enqueue(queue, 10);
//     enqueue(queue, 20);
//     enqueue(queue, 30);
//     enqueue(queue, 40);

//     printf("%d dequeued from queue\n\n", dequeue(queue));

//     printf("Front item is %d\n", front(queue));
//     printf("Rear item is %d\n", rear(queue));

//     return 0;
// }
