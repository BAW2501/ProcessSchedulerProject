# Process Scheduler Simulator
## Operating Systems (Module SE) Project - April 2020

### Overview
This project implements various CPU scheduling algorithms as part of the Operating Systems module (Systèmes d'Exploitation) at the Faculty of Exact Sciences and Informatics. It provides a practical demonstration of process management and scheduling concepts through an interactive console-based interface.

### Implemented Algorithms
- First In First Out (FIFO)
- Priority Scheduling (Non-preemptive)
- Priority Scheduling (Preemptive)
- Shortest Job First (SJF)
- Shortest Remaining Time First (SRTF)
- Round Robin (RR)

### Features
- Interactive console-based interface
- Visual representation of process execution
- Performance metrics calculation:
  - Average Waiting Time
  - Average Turnaround Time
  - CPU Utilization
- Support for process priorities and arrival times
- Step-by-step execution visualization

### Compilation & Usage
```bash
# Compile the project
gcc -o scheduler main.c algorithms.c File.c Utility.c

# Run the executable
./scheduler
```

### Project Structure
- `main.c`: Entry point and menu interface
- `algorithms.c`: Implementation of scheduling algorithms
- `File.c`: Queue data structure implementation
- `Utility.c`: Helper functions and utilities
- `Structs.h`: Data structure definitions
- Additional header files for function declarations

### Authors
- Student Name
- January 2021
- Faculty of Exact Sciences and Informatics

### Academic Context
This project was developed as part of the Operating Systems module curriculum, demonstrating practical implementation of process scheduling concepts in operating systems.