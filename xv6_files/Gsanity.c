//
// Created by hossein on 1/17/17.
//


#include "user.h"
#define N  50

void
print_sth()
{
    int i;
    for (i = 0; i < N; ++i) {
        printf(1, "process %d is printing for the %d time.\n", getpid(), i);
    }

}

void
Gsanity(void)
{

    int pid;


    printf(1, "Father pid is %d", getpid());
    sleep(10);
    pid = fork();
    if(pid == 0){
        print_sth();
        exit();
    }


    print_sth();

}
int
main(void)
{
    Gsanity();
    exit();
}
