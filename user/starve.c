#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"
int
main(int argc, char *argv[])
{
    int i;

    // process heavy
    if(argc > 1){

        while(1){

            for(i = 0; i < 10000000; i++);

            printf("HEAVY PID %d running\n", getpid());

            sleep(10);
        }
    }

    // process normal
    else {

        while(1){

            printf("NORMAL PID %d running\n", getpid());

            sleep(30);
        }
    }

    exit(0);
}
