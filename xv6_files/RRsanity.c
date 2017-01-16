//
// Created by hossein on 1/16/17.
//

// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "user.h"
#define CHILD_NUMBER 10
#define N  1000

void
print_sth()
{
    for (int i = 0; i < N; ++i) {
        printf(1, "Child %d prints for the %d time.\n", getpid(), i);
    }

}

void
RRsanity(void)
{
    int wTime[CHILD_NUMBER];
    int rTime[CHILD_NUMBER];
    int pid[CHILD_NUMBER];

    for (int i = 0; i < CHILD_NUMBER; i++) {
        pid[i] = fork();
        if(pid[i] == 0){
            print_sth();
            exit();
        }
    }

    for (int j = 0; j < CHILD_NUMBER; ++j) {
        wait2(&wTime[j], &rTime[j]);
    }

    for (int k = 0; k < CHILD_NUMBER; ++k) {
        printf(1, "The waittime of %d child is %d\n", k, wTime[k]);
        printf(1, "The runtime of %d child is %d\n", k, rTime[k]);
    }

}
int
main(void)
{
    RRsanity();
    exit();
}
