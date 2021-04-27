# Clock System Driver

To assert processing times, the system only needs to keep track, upon process start, the value of the system clock ticks and compare it to the current system clock ticks.

To schedule processes, the systems generally use pre-emptive scheduling. For that, tasks are time-sliced and prioritized, and the needed time for a running process is set and allocated. At the end of each time slice (clock interrupt) or after an I/O interrupt, the scheduler decides whose turn it is to execute again, by basis os urgency.