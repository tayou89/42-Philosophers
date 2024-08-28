# Philosophers

![Philosophers Problem Image](https://github.com/user-attachments/assets/4506de72-18c8-4736-88ee-db90a079c62c)

This project is an implementation of the classic Dining Philosophers problem, demonstrating concepts of multi-threading and process synchronization.

## Getting Started

### Prerequisites

- GCC compiler
- Make
- Git

### Cloning the Repository

To clone the repository and create the executable, follow these steps:

```bash
# Clone the repository
git clone https://github.com/your-username/philosophers.git
cd philosophers

# Compile the mandatory part
make

# Compile the bonus part (optional)
make bonus
```

## Compilation

The project includes a Makefile with the following rules:

- `make`: Compiles the mandatory part
- `make bonus`: Compiles the bonus part
- `make clean`: Removes object files
- `make fclean`: Removes object files and executables
- `make re`: Recompiles the project

## Norminette

This project follows the Norm, a programming standard defined in [norminette.pdf](requirements/norminette.pdf). The Norm covers aspects such as function length, variable naming, header structure, etc.

## Usage

### Mandatory Part

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Bonus Part

```
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Examples

### Philosophers dying

```
./philo 4 310 200 100
```

This will likely result in a philosopher dying due to insufficient time between meals.

### Philosophers surviving

```
./philo 5 800 200 200
```

This configuration should allow all philosophers to eat, sleep, and think without dying.

## Required Knowledge

To successfully implement this project, the following concepts and skills are necessary:

1. **Multi-threading**: Understanding of how to create, manage, and synchronize threads.
2. **Mutex (Mutual Exclusion)**: Knowledge of how to use mutexes to prevent race conditions in shared resources.
3. **Process Management**: For the bonus part, understanding of how to create and manage processes.
4. **Semaphores**: Used in the bonus part for inter-process synchronization.
5. **Concurrency Issues**: Familiarity with common concurrency problems like deadlocks and race conditions.
6. **Time Management**: Ability to work with system time and implement delays.
7. **Memory Management**: Proper allocation and deallocation of resources.
8. **C Programming**: Proficiency in C, including pointer manipulation and structure handling.

## Mandatory vs Bonus Implementation

The main differences between the mandatory and bonus parts are:

### Mandatory Part
- Uses threads to represent philosophers
- Employs mutexes for fork management
- Each philosopher is a thread within the same process

### Bonus Part
- Uses processes to represent philosophers
- Employs semaphores for fork management
- Each philosopher is a separate process
- The main process is not a philosopher but manages the simulation

The bonus part is generally considered more complex due to the challenges of inter-process communication and synchronization. It requires a deeper understanding of operating system concepts and provides a different approach to solving the same problem.

## Project Details

For more information about the project requirements and specifications, please refer to the [subject.pdf](requirements/subject.pdf) file.