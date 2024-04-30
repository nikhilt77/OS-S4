#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 
#define MAX_PAGES 20 

int frames[MAX_FRAMES]; 
int rear = -1; 

void initialize() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; 
       }
}

void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

void FIFO(int pages[], int n) {
    int page_hits=0;
    int page_faults = 0;
    int front = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                printf("page %d already there\n",page);
                page_hits++;
                break;
            }
        }

        if (!found) {
            page_faults++;
           
            if (rear < MAX_FRAMES - 1) {
                rear++;
            } else {
                rear = 0;
            }
            frames[rear] = page;
            printf("page %d loaded in frame %d \n",page,rear);
        }

        printf("Page %d : ", page);
        displayFrames();
    }

    printf("Total Page Faults: %d\n", page_faults);
    float s=page_hits+page_faults;
    printf("Totall page hits:%d\n",page_hits);
    float fault_ratio=page_faults/s;
    printf("Fault Ratio:%f\n",fault_ratio);
    float hit_ratio=page_hits/s;
    printf("%f\n",s);
    printf("hit Ratio:%f\n",hit_ratio);
}

int main() {
    int pages[MAX_PAGES];
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize(); 
    FIFO(pages, n);
    return 0;
}
