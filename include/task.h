#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include "heap.h"
#include <semaphore.h>
#include "barrier.h"
#include "mutex.h"
#include "cond.h"


struct counter_struct
{
	volatile int *val;
};

struct va_struct
{
	void *addr;
	void *shared;
	void *backup;
	size_t size;
};

struct sharedlist_struct
{
	int lock;
	int __vamsize;
	struct va_struct __vamap[MAPSIZE];
};

typedef struct sthread_t
{
	unsigned int tid;
	void *retval;
	int pid;
	struct heap_struct heap;
	int state;
	int lock1;
//	int lock2;
	int joinlock;
	struct mutex_struct *mutex;
	struct cond_struct *cond;
	struct barrier_struct *barrier;
	int leaved;
	int arrived;
	
} sthread_t;

typedef struct sthread_attr_t 
{
	unsigned int stack_size;
} sthread_attr_t;

struct __argwrapper 
{
	void *(*func)(void *);
	void *args;
};


unsigned int __alloc_tid();
void *__alloc_stack(unsigned int size);
void __init_localtid(void);
void __init_threadpool(void);
void *__start_routine(void *arw);
void __init_threadlist(void);
void __addtask(sthread_t *task);
sthread_t *__nexttask(sthread_t *task);
sthread_t *__pretask(sthread_t *task);
sthread_t *__currenttask(void);
sthread_t *__lasttask(void);


__attribute__((constructor)) void init();
__attribute__((constructor)) void cleanup();
int sthread_create(sthread_t *newthread, sthread_attr_t *attr, void *(*func)(void *), void *args);
sthread_t sthread_self(void);

void sthread_exit(void *value);
int sthread_join(sthread_t thread, void **thread_return);

void sthread_main_wait(int n);
#endif
