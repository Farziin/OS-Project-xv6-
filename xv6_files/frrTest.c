//
// Created by hossein on 1/17/17.
//

//Test FIFO round robin policy

#include "user.h"
#define CHILD_NUMBER 10
#define N  1000

void
print_sth(int number)
{
    int i;
    for (i = 0; i < N; ++i) {
        printf(1, "%d, ", number);
    }

}

void
frrTest(void)
{

    int wTime[CHILD_NUMBER];
    int rTime[CHILD_NUMBER];
    int pid[CHILD_NUMBER];

    int i;
    for (i = 0; i < CHILD_NUMBER; i++) {
        pid[i] = fork();
        if(pid[i] == 0){
            print_sth(i);
            exit();
        }
    }

    int j;
    for (j = 0; j < CHILD_NUMBER; ++j) {
        wait2(&wTime[j], &rTime[j]);
    }

    int k;
    for (k = 0; k < CHILD_NUMBER; ++k) {
        printf(1, "The waittime of %d child is %d\n", k, wTime[k]);
        printf(1, "The runtime of %d child is %d\n", k, rTime[k]);
    }

}
int
main(void)
{
    frrTest();
    exit();
}
