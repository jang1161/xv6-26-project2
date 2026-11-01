//
// User-space helpers for kernel threads.
//
// thread_create() and thread_join() are thin wrappers over the clone()
// and join() system calls.  They mirror the spirit of pthread_create()
// and pthread_join():

#include "kernel/types.h"
#include "kernel/riscv.h"
#include "user/user.h"
#include "user/uthread.h"

int
thread_create(void (*fn)(void *), void *arg, int n_pages)
{
  uint64 ustack = malloc(n_pages * PGSIZE);
  return clone(fn, arg, ustack, n_pages, CLONE_VM); // pid
}

int
thread_join(void)
{
  return -1;
}
