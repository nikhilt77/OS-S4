#include <stdio.h>
#include <stdlib.h>

int main() {
    int initial, pos, tot_movements = 0, n, direction, size;
    printf("Enter Disk size: ");
    scanf("%d", &size);
    printf("Enter the requests size: ");
    scanf("%d", &n);
    int RQ[n + 1];
    printf("Enter initial disk position: ");
    scanf("%d", &initial);
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    printf("Enter direction (1-high, 0-low): ");
    scanf("%d", &direction);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (RQ[i] >= initial) {
            pos = i;
            break;
        }
    }

    if (direction == 1) {
        for (int i = pos; i < n; i++) {
            tot_movements += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        if (initial != size - 1) {
            tot_movements += abs(initial - (size - 1));
            initial = size - 1;
        }
        for (int i = pos - 1; i >= 0; i--) {
            tot_movements += abs(initial - RQ[i]);
            initial = RQ[i];
        }
    }
    else {
        for (int i = pos; i >= 0; i--) {
            tot_movements += abs(initial - RQ[i]);
            initial = RQ[i];
        }
        if (initial != 0) {
            tot_movements += abs(initial - 0);
            initial = 0;
        }
        for (int i = pos + 1; i < n; i++) {
            tot_movements += abs(initial - RQ[i]);
            initial = RQ[i];
        }
    }

    printf("Total disk arm movements: %d\n", tot_movements);
    return 0;
}
