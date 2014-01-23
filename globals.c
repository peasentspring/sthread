#include "include/globals.h"

/* mvheap malloc base address*/
void *__privatebase;

/* __localtid == __selftid, except in main thread  __localtid == number of total threads*/
unsigned int __localtid;
unsigned int __selftid;

/* all info about created threads*/
sthread_t *__threadpool;

sthread_t *__threadlist;
