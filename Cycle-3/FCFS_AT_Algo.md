1. Start

2. Declare and initialize variables:
   - `bt[10]`: An array to store burst times of processes.
   - `at[10]`: An array to store arrival times of processes.
   - `tat[10]`: An array to store turnaround times of processes.
   - `wt[10]`: An array to store waiting times of processes.
   - `ct[10]`: An array to store completion times of processes.
   - `n`: Number of processes.
   - `sum`: A variable to keep track of the sum of burst times for calculating completion times.
   - `totalTAT`, `totalWT`: Variables to store the total turnaround time and total waiting time, respectively.

3. Read the number of processes `n` from the user.

4. Read the arrival time and burst time for each process in a loop from `0` to `n-1`:
   - Prompt the user to enter the arrival time and burst time for process `i+1`.
   - Store the entered values in the corresponding arrays `at[i]` and `bt[i]`.

5. Calculate the completion time of processes:
   - Initialize `sum` to 0.
   - For each process `j` from `0` to `n-1`:
     - Add the burst time of process `j` to `sum`.
     - Store the current value of `sum` in `ct[j]`, which represents the completion time of process `j`.

6. Calculate the turnaround time for each process and the total turnaround time (`totalTAT`):
   - For each process `k` from `0` to `n-1`:
     - Calculate `tat[k] = ct[k] - at[k]`, which represents the turnaround time of process `k`.
     - Add `tat[k]` to `totalTAT` to accumulate the total turnaround time.

7. Calculate the waiting time for each process and the total waiting time (`totalWT`):
   - For each process `k` from `0` to `n-1`:
     - Calculate `wt[k] = tat[k] - bt[k]`, which represents the waiting time of process `k`.
     - Add `wt[k]` to `totalWT` to accumulate the total waiting time.

8. Print the solution in a tabular format:
   - Print the headings for the table: "P#", "AT", "BT", "CT", "TAT", "WT".
   - For each process `i` from `0` to `n-1`, print the process number `i+1`, arrival time `at[i]`, burst time `bt[i]`, completion time `ct[i]`, turnaround time `tat[i]`, and waiting time `wt[i]`.

9. Calculate and print the average turnaround time and average waiting time:
   - Calculate `averageTAT = totalTAT / n`.
   - Calculate `averageWT = totalWT / n`.
   - Print "Average Turnaround Time = averageTAT" and "Average WT = averageWT".

10. stop
