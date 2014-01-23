#ifndef GLOABALS_H
#define GLOABALS_H

#include "types.h"


extern void *__privatebase;
extern unsigned int __localtid;
extern unsigned int __selftid;
extern void *__mutexbase;

extern sthread_t *__threadpool;

#endif
