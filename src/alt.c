/* Lab 2, core B -- THE ALTERNATIVE named in BRIEF.md.
 *
 * The two-turnstile barrier, out of counting semaphores: arrive, count, and
 * when the last one arrives open the first turnstile for everybody; then
 * leave, count down, and when the last one leaves open the second.
 * (Downey, "The Little Book of Semaphores", 3.6-3.7, and class 6.)
 *
 * TWO turnstiles, not one. Work out for yourself what a fast thread does to a
 * single-turnstile version before you decide the second one is decoration --
 * and say so in S2.3, because it is the same lesson as your fix.
 *
 * my_sem_init / my_sem_wait / my_sem_post / my_sem_destroy are declared in
 * include/mysem.h and implemented, correctly, in src/mysem_ref.c. A
 * pthread_mutex_t is fine for the counter.
 *
 * It is correct, and it is not expected to be fast. Do not tune it: it is
 * evidence, not a submission.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <mysem.h>
#include "barrier.h"

/* TODO: the barrier's state. What has to be shared between the threads, and
 *       what does each thread have to remember for itself? */
typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t  cv;
    int             n;   
} bar_t;
   

my_sem_t *s1;
my_sem_t *s2;    



static void *create(int nthreads)
{




        bar_t *b = malloc(sizeof *b);
    if (b == NULL) {
        return NULL;
    }
    if (pthread_mutex_init(&b->lock, NULL) != 0 ||
        pthread_cond_init(&b->cv, NULL) != 0) {
        fprintf(stderr, "barrier init failed\n");
        free(b);
        return NULL;
    }
    b->n     = nthreads;
    my_sem_init(&s1,nthreads);
    my_sem_init(&s2,0);
    return b;
}

static void wait_(void *p)
{
    /* TODO: the barrier. Write the invariant you are keeping in a comment
     *       above it, in one line, before you write the code -- your report
     *       and your oral both ask you to state it. */
    bar_t *b = (bar_t *)p;
    
    my_sem_wait(&s1);

    


    (void)p;
}

static void destroy(void *p)
{
    my_sem_destroy(&s1);
    my_sem_destroy(&s2);
    

    
}

const bar_ops_t bar_alt = { "alt", create, wait_, destroy };
