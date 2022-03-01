//
// Created by Jack Nunley on 2/22/22.
//

#include "queue.h"
#include "defs.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "types.h"

struct proc **queue_append(struct queue_t *q, struct proc *x) {
  q->root[q->size] = x;
  struct proc **ptr = &q->root[q->size];
  q->size++;
  return ptr;
}

struct proc *queue_pop_front(struct queue_t *q) {
  if (q->size == 0) {
    return NULL;
  }
  struct proc *front = q->root[0];
  int i;
  for (i = 1; i < q->size; i++) {
    q->root[i - 1] = q->root[i];
  }
  q->size--;
  return front;
}

struct proc *queue_pop(struct queue_t *q, int idx) {
  struct proc *item = q->root[idx];
  for (int i = idx + 1; i < q->size; i++) {
    q->root[i - 1] = q->root[i];
  }
  q->size--;
  return item;
}

struct proc *queue_remove(struct queue_t *q, int pid) {
  for (int i = 0; i < q->size; i++) {
    if (q->root[i]->pid == pid) {
      return queue_pop(q, i);
    }
  }
  return NULL;
}

struct proc *queue_find(struct queue_t *q, int pid) {
  for (int i = 0; i < q->size; i++) {
    if (q->root[i]->pid == pid) {
      return q->root[i];
    }
  }
  return NULL;
}

void queue_print(struct queue_t *q) {
  for (int i = 0; i < q->size; i++)
    cprintf("%d ", q->root[i]->pid);
  cprintf("\n");
}
