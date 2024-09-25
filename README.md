
---

# Philosophers

## Description

The `Philosophers` project is a classic concurrency problem that simulates a dining scenario with philosophers and forks. The goal is to implement a solution that avoids deadlock and ensures that each philosopher can eat without starving while sharing limited resources. This project is an excellent introduction to multithreading, synchronization, and resource management in C.

## Features

- **Philosopher Simulation**: Models a fixed number of philosophers sitting at a table, each trying to eat and think.
- **Fork Management**: Implements a system for philosophers to share forks (resources) safely, ensuring no deadlock occurs.
- **Thread Management**: Utilizes pthreads for concurrent execution, allowing philosophers to run simultaneously.
- **Time Management**: Each philosopher has a defined eating, sleeping, and thinking time, simulating realistic behavior.

## Key Technologies

- **C Programming Language**: The primary language used for implementing the simulation.
- **POSIX Threads (pthreads)**: Utilizes threads for concurrent execution of the philosophers.
- **Mutexes and Condition Variables**: Implements synchronization mechanisms to prevent race conditions and ensure proper access to shared resources.

## Learning Outcomes

- Gained experience in multithreading and concurrent programming concepts.
- Developed skills in using synchronization mechanisms like mutexes and condition variables.
- Learned to analyze and implement solutions to classic concurrency problems.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/Bidiche49/Philosophers
   cd Philosophers
   cd philo
   ```
2. Compile the project:
   ```bash
   make
   ```
3. Run the simulation:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```

   Replace the placeholders with the appropriate arguments.

## Example Usage

To run the simulation with 5 philosophers:
```bash
./philo 5 800 200 200
```

---
