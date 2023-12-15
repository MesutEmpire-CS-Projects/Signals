# SHELL SCRIPTING

## BASICS

### Question 1.

#### a) Print Process Information

Write a C program (`print_process_info.c`) that prints the process ID, priorities, and parent ID of all programs currently in RAM.

#### b) Kill Shell Script

Create a Shell Script named "NYONGA" that, while the Shell is open, executes a C program (`kill_shell_script.c`) to terminate the open Shell Script.

#### c) Fork() API Demonstration

Write a C program (`fork_example.c`) that uses the `fork()` API to create a child process.

#### d) Understanding waitpid() and wait()

Describe in prose how `waitpid()` and `wait()` work. Provide a C program (`wait_example.c`) demonstrating the use of both APIs to get the termination status of a child process in the parent.

#### e) CPU Usage Monitoring with GUI

Develop a C program (`cpu_monitor_gui.c`) with a Graphical User Interface (GUI) that graphs CPU usage in real time. Utilize Linux tools like sysstat, sar, or Nmon to capture CPU usage. To install sysstat in Debian, run the command: `sudo apt-get install sysstat`.

#### f) User Defined Signals

Explain user-defined signals and provide two working examples in C (`user_defined_signals.c`) that you've created.

#### g) Create and Delete File with Signal

Write a program (`create_and_delete_file.c`) that creates a text file named "JUJU" in the specified drive and implements a signal (using SIGALRM) to delete the file 5 seconds after creation. Display a prompt indicating the file deletion.

**Hint**: Knowledge of SIGALRM will be handy.

Feel free to refer to the respective C files in this repository for detailed implementations and explanations.
