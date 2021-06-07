This method can work efficiently if both of the processes always run mutually.
The problem resides in the following example

- Process 1 leaves region
- Process 0 is not interested right now, so it neither enters or leaves
- Process 1 can't enter again
