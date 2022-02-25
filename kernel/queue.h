//
// Created by Jack Nunley on 2/22/22.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"
#include "defs.h"

struct queue_t {
  struct proc* root[64];
  int size;
};

struct proc **queue_append(struct queue_t *, struct proc*);
struct proc *queue_pop_front(struct queue_t *);
struct proc* queue_pop(struct queue_t *q, int idx);
//struct proc &*queue_find(struct queue_t *q, struct proc pid);
struct proc *queue_remove(struct queue_t *q, int pid);
void queue_print(struct queue_t *);

#endif // QUEUE_H
