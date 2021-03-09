Pipes are basically an IPC mechanism used for message passing between processes in a system. They signify information flow between sender and receiver processes.
The major differences between named and unnamed pipes are:

1. As suggested by their names, a named type has a specific name which can be given to it by the user. Named pipes are referred by name only by the reader and writer. All instances of a named pipe share the same pipe name.
On the other hand, unnamed pipes are not given a name. It is accessible through two file descriptors that are created through the function pipe(fd[2]), where fd[1] signifies the write file descriptor, and fd[0] describes the read file descriptor.

2. An unnamed pipe is only used for communication between a child and it’s parent process, while a named pipe can be used for communication between two unnamed processes as well. Processes of different ancestry can share data through a named pipe.

3. A named pipe exists in the file system. After input-output has been performed by the sharing processes, the pipe still exists in the file system independently of the process, and can be used for communcation between some other processes.
On the other hand, an unnamed pipe vanishes as soon as it is closed, or one of the process (parent or child) completes execution.

4. Named pipes can be used to provide communication between processes on the same computer or between processes on different computers across a network, as in case of a distributed system.  Unnamed pipes are always local; they cannot be used for communication over a network.

5. A Named pipe can have multiple processes communicating through it, like multiple clients connected to one server. On the other hand, an unnamed pipe is a one-way pipe that typically transfers data between a parent process and a child process.

Then there are differences in their usage and syntax. An unnamed type is simple to use and incurs less overheads, whereas a named pipe provides us with greater functionalities.

[Source](https://atrystwithprogramming.wordpress.com/2015/10/15/difference-between-pipes-and-named-pipes/)