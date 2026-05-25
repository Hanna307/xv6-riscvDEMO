#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void worker(int id, int prio)
{
    set_priority(prio);

    volatile long x = 0;

    for(int i = 0; i < 8; i++) {

        for(long j = 0; j < 20000000; j++) {
            x++;
        }

        printf("\n=== PROCESS %d | PID %d ===\n",
               id, getpid());

        print_pinfo();
    }

    printf("\nProcess %d finished\n", id);
    exit(0);
}

int
main(void)
{
    printf("\n========== AGING SCHEDULER DEMO ==========\n");

    if(fork() == 0)
        worker(1, 8);

    if(fork() == 0)
        worker(2, 6);

    if(fork() == 0)
        worker(3, 4);

    if(fork() == 0)
        worker(4, 1);

    for(int i = 0; i < 4; i++)
        wait(0);

    printf("\n========== DEMO FINISHED ==========\n");

    exit(0);
}
