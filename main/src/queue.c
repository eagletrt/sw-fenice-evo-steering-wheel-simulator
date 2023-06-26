#include "queue.h"

int emptyp(const queue_t *q) { return (q->head == q->tail); }

void queue_init(queue_t *q) {
  q->tail = 0;
  q->head = 0;
}

void enqueue(queue_element_t e, queue_t *q) {
  q->data[q->tail] = e;
  q->tail = (q->tail + 1) % (DIM_queue);
}

int queue_first(const queue_t *q, queue_element_t *element) {
  int res = !emptyp(q);
  if (res) {
    *element = q->data[q->head];
  }
  return res;
}

void dequeue(queue_t *q) {
  if (!emptyp(q)) {
    q->head = (q->head + 1) % (DIM_queue);
  }
}
