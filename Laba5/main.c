#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <unistd.h>

#define SEC_NSEC 1000000000LL // 1 sekynda billion nanosekynd

void *long_thread(void *notused)
{
    printf("Etot potok vipolnaetsa bolee 10 sekynd \n");
    sleep(20);
}

int main(void)
{
    uint64_t timeout;
    struct sigevent event;
    int rval;
    pthread_t thread_id;

    printf("Kalmykov Vladimir I993\nProg timer \n");
    event.sigev_notify = SIGEV_UNBLOCK;
    pthread_create(&thread_id, NULL, long_thread, NULL);
    timeout = 10LL * SEC_NSEC;
    TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
    rval = pthread_join(thread_id, NULL);
    if (rval == ETIMEDOUT)
    {
        printf("istekli 10 sekynd, potok %d vipolniaetsia!\n", thread_id);
    }
    sleep(5);
    TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
    rval = pthread_join(thread_id, NULL);
    if (rval == ETIMEDOUT)
    {
        printf("potok %d >25 sek!", thread_id);
    }
    else
    {
        printf("Potok %d zavershon kak nado \n", thread_id);
    }
    return (1);
}