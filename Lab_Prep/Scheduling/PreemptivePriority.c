#include<stdio.h>
#define max 20

struct priority {
    int pid;
    int BT;
    int AT;
    int priority;
    int WT;
    int TAT;
    int RBT;
};

struct priority p[max];

int main() {
    int time = 0, totWT = 0, totTAT = 0, completed = 0, shortest, n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i);
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time of P%d: ", i);
        scanf("%d", &p[i].BT);
        printf("Enter Priority of P%d: ", i);
        scanf("%d", &p[i].priority);
        p[i].pid = i;
        p[i].RBT = p[i].BT;
    }

    while (completed != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].RBT > 0) {
                if (shortest == -1 || p[i].priority < p[shortest].priority) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        p[shortest].RBT--;
        time++;

        if (p[shortest].RBT == 0) {
            p[shortest].TAT = time - p[shortest].AT;
            p[shortest].WT = p[shortest].TAT - p[shortest].BT;
            completed++;
            totTAT += p[shortest].TAT;
            totWT += p[shortest].WT;
        }
    }

    float avgWT = (float)totWT / n;
    float avgTAT = (float)totTAT / n;
    printf("Process\tAT\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].priority, p[i].WT, p[i].TAT);
    }
    printf("Average Waiting time: %.2f\n", avgWT);
    printf("Average TAT: %.2f\n", avgTAT);

    return 0;
}
