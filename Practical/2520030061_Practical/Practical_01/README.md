
Linux Command Execution and OS Hardware Resource Investigation:

This practical demonstrates how a Linux operating system executes a command entered by a user using process creation and system calls.

The C program:

Accepts a Linux command as input from the user.
Creates a child process using fork().
Executes the entered command in the child process using an appropriate exec() system call.
Allows the parent process to wait for the child process using wait().
Displays the Process ID (PID) of both the parent and child processes.

The practical also investigates the relationship between hardware resources and operating system services using Linux terminal commands such as:

uname – Displays information about the Linux kernel and system.
lscpu – Displays CPU architecture and processor information.
lsblk – Displays available storage devices and partitions.
ps – Displays information about currently running processes.
top – Provides a real-time view of processes and CPU/memory usage.

Objective:

The main objective is to understand how the Linux operating system acts as an interface between applications and hardware. The OS abstracts hardware resources such as CPU, memory, storage, and I/O devices, allowing programs to use these resources through system calls and OS services without directly managing the hardware.
