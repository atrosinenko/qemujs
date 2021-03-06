#include <pthread.h>

#ifndef __EMSCRIPTEN__
#include <signal.h>
#endif

// For ./configure script
// Execute new thread function just now in this thread
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg)
{
	// typedef unsigned long pthread_t;
	*thread = start_routine(arg);
	return 0;
}

int pthread_join(pthread_t thread, void **retval)
{
	*retval = thread;
	return 0;
}

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void))
{
	return 0;
}

int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset)
{
    return 0;
}

