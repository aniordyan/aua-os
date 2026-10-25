#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} Process;

void print_process(int pid, int start, int end) {
    int duration = end - start;

    for (int j = 0; j < duration; j++)
        printf("-");

    if (pid == 0)
        printf("Idle");
    else
        printf("P%d", pid);

    for (int j = 0; j < duration; j++)
        printf("-");

    printf("|");
   
}


void sort_by_arrival(Process *p, int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time ||
                (p[j].arrival_time == p[j + 1].arrival_time && p[j].pid > p[j + 1].pid)) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}


void display_results(Process *p, int n) {
    double total_wt = 0, total_tat = 0, total_rt = 0;

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Response Time: %.2f\n", total_rt / n);
}

void fcfs(Process *p, int n){ 
    sort_by_arrival(p, n);

    int current = 0;

    printf("\n=== First Come First Served (FCFS) ===\n");
    printf("Gantt Chart: |");

    for(int i = 0; i < n; i++){
        if (current < p[i].arrival_time) {
            print_process(0, current, p[i].arrival_time);
            current = p[i].arrival_time;
        }
        
        int start = current;

        p[i].waiting_time = current - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        p[i].response_time = p[i].waiting_time;
        current += p[i].burst_time;

        print_process(p[i].pid, start, current);
    }
    printf("\n");
    display_results(p, n);

}

void sjf(Process *p, int n) {
    sort_by_arrival(p, n);

    int current = 0;
    int completed = 0;
    int done[n];
    for(int i=0; i<n; i++) done[i] = 0;

    printf("\n=== Shortest Job First (SJF) ===\n");
    printf("Gantt Chart: |");

    while(completed < n){
        int index = -1;
        for(int i=0; i<n; i++){
            if(!done[i] && p[i].arrival_time <= current){
                if(index == -1 || p[i].burst_time < p[index].burst_time || 
                (p[i].burst_time == p[index].burst_time && p[i].arrival_time < p[index].arrival_time) ||
                (p[i].burst_time == p[index].burst_time && p[i].arrival_time == p[index].arrival_time && p[i].pid < p[index].pid)){
                    index = i;
                }
            }
        }

        if (index == -1) {
            int next_arrival = -1;

            for (int i = 0; i < n; i++) {
                if (!done[i] &&
                    (next_arrival == -1 ||
                    p[i].arrival_time < next_arrival)) {

                    next_arrival = p[i].arrival_time;
                }
            }

            print_process(0, current, next_arrival);
            current = next_arrival;
            continue;
}

        int start = current;

        done[index] = 1;
        completed++;

        p[index].waiting_time = current - p[index].arrival_time;
        p[index].turnaround_time = p[index].waiting_time + p[index].burst_time;
        p[index].response_time = p[index].waiting_time;

        current += p[index].burst_time;

        print_process(p[index].pid, start, current);
    }
    printf("\n");
    display_results(p, n);
}


int main() {
    int n;

    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    Process *processes = malloc(n * sizeof(Process));
    Process *fcfs_processes = malloc(n * sizeof(Process));
    Process *sjf_processes = malloc(n * sizeof(Process));

    if (processes == NULL ||
        fcfs_processes == NULL || sjf_processes == NULL) {
        printf("Memory allocation failed.\n");
        free(processes);
        free(fcfs_processes);
        free(sjf_processes);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;

        printf("Enter the arrival time and burst time "
               "for process %d: ", i + 1);

        if (scanf("%d %d",
                  &processes[i].arrival_time,
                  &processes[i].burst_time) != 2 ||
            processes[i].arrival_time < 0 ||
            processes[i].burst_time <= 0) {

            printf("Invalid input. Arrival must be >= 0 "
                   "and burst must be > 0.\n");

            free(processes);
            free(fcfs_processes);
            free(sjf_processes);
            return 1;
        }

        fcfs_processes[i] = processes[i];
        sjf_processes[i] = processes[i];
    }

    fcfs(fcfs_processes, n);
    sjf(sjf_processes, n);

    free(processes);
    free(fcfs_processes);
    free(sjf_processes);

    return 0;
}


