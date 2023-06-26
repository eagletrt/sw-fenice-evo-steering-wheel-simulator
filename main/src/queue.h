#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

#include "can.h"
#ifndef DIM_queue
#define DIM_queue 200
#endif

typedef struct queue_element_t {
  int can_network;
  struct can_frame frame;
  uint64_t timestamp;
} queue_element_t;

typedef struct queue_t {
  queue_element_t data[DIM_queue];
  int tail;
  int head;
} queue_t;

void queue_init(queue_t *q);
/*
**
**  @brief  Enqueue element in queue
**  @param  e: element to be enqueued
**  @param  q: queue in which e is enqueued
**
*/
void enqueue(queue_element_t e, queue_t *q);

/*
** @brief  Get first element from queue
** @param  q: queue from which the head is to be taken
** @param  element: pointer to element to be returned
** @return 1 if queue is not empty, 0 otherwise
*/
int queue_first(const queue_t *, queue_element_t *element);

/*
** @brief  Dequeue element from queue
** @param  q: queue from which the head is to be removed
*/
void dequeue(queue_t *q);

/*
** @brief  Check if queue is empty
** @param  q: queue to be checked
*/
int emptyp(const queue_t *q);

#endif
