//
// Created by hossein on 1/17/17.
//

// test MLQ policy

#include "user.h"
#define CHILD_NUMBER 30
#define N  500

void
print_sth(int number)
{
    int i;
    for (i = 0; i < N; ++i) {
        printf(1, "%d\n", number);
    }

}

void
sanity(void)
{

    int wTime[CHILD_NUMBER];
    int rTime[CHILD_NUMBER];
    int pid[CHILD_NUMBER];

    int cid;
    for (cid = 0; cid < CHILD_NUMBER; i++) {
        pid[cid] = fork();
        if(pid[cid] == 0){
            if(cid % 3 == 0)
                nice();
            else if (cid % 3 == 1){
                nice();
                nice();
            }
            print_sth(cid);
            exit();
        }
    }

    int j;
    for (j = 0; j < CHILD_NUMBER; ++j) {
        wait2(&wTime[j], &rTime[j]);
    }

    int i;
    int avg_runtime;
    int avg_wtime;
    int w_temp = 0, r_temp;
    for (i = 0; i < CHILD_NUMBER; ++i) {
        w_temp += wTime[i];
        r_temp += rTime[i];
    }
    avg_runtime = r_temp/CHILD_NUMBER;
    avg_wtime = w_temp/CHILD_NUMBER;
    printf(1, "the total average run time is: %d\n", avg_runtime);
    printf(1, "the total average wait time is: %d\n", avg_wtime);


    int w_temp0 = 0, w_temp1 = 0, w_temp2 = 0;
    int r_temp0 = 0, r_temp1 = 0, r_temp2 = 0;
    int l;
    for(l = 0; l < CHILD_NUMBER; l++){
        if(l % 3 == 0){
            w_temp2 += wTime[l];
            r_temp2 += rTime[l];
        }
        else if(l % 3 == 1){
            w_temp1 += wTime[l];
            r_temp1 += rTime[l];
        }
        else if(l % 3 == 2){
            w_temp0 += wTime[l];
            r_temp0 += rTime[l];
        }
    }

    int avgq_wtime[3];
    int avgq_rtime[3];

    avgq_rtime[0] = r_temp0/CHILD_NUMBER;
    avgq_rtime[1] = r_temp1/CHILD_NUMBER;
    avgq_rtime[2] = r_temp2/CHILD_NUMBER;

    avgq_wtime[0] = w_temp0/CHILD_NUMBER;
    avgq_wtime[1] = w_temp1/CHILD_NUMBER;
    avgq_wtime[2] = w_temp2/CHILD_NUMBER;

    int m;
    for (m = 0; m < 3; ++m) {
        printf("The average run time of queue #%d is: %d\n", m, avgq_rtime[m]);
        printf("The average wait time of queue #%d is: %d\n", m, avgq_wtime[m]);
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
    sanity();
    exit();
}

