<h1 align="center">
     MINISHELL
</h1>

**`/cantasar`**

<br>
<br>

### Contents

1. **[Shell Program Structures](#1-shell-program-structures)**
     1. **[Lexer](#11-lexer)**
     2. **[Parser](#12-parser)**
     3. **[Executor](#13-executor)**
     4. **[PIPE '|'](#14-pipe)**
     5. **[AND Operator (&&)](#15-and-operator)**
     6. **[OR Operator (||)](#16-or-operator)**
     7. **[Exit Status ($?)](#17-exit-status)**
     8. **[PID](#18-pid)**
     9. **[Environments (ENV)](#19-env)**
     10. **[Export](#110-export)**
     11. **[Declare](#111-declare)**
     12. **[Echo](#112-echo)**
     13. **[File Descriptors](#113-file-descriptors)**
2. **[Shell Program Functions](#2-shell-program-functions)**
     1. **[Fork()](#21-fork)**
     2. **[Pipe()](#22-pipe)**
     3. **[Dup()](#23-dup)**
     4. **[Dup2()](#24-dup2)**
4. **[Working Structure](#3-working-structure)**
     1. **[Flowchart](#31-flowchart)**
     2. **[Functions](#32-functions)**
5. **[Redirections](#4-redirections)**
     1. **[Standard Input '<'](#41-standard-input)**
     2. **[Standard Output '>'](#42-standard-output)**
     3. **[Appending Redirected Output ">>"](#43-appending-redirected-output)**
     4. **[Here Documents '<<'](#44-here-documents)**
<br>

## 1. Shell Program Structures

<br>

### 1.1 Lexer
- Lexer scans the input text and analyzes it based on specific grammatical rules.
- For Bash shell, the lexer splits the input text into parts and defines each part as a **"token"**.
- Tokens represent grammatical structures such as commands, arguments, variables, operators, etc.
- The lexer reads the characters in the text, groups them into meaningful chunks, and then creates a list of these tokens.

```
3 + 4 * 2
```
- In the example above, the lexer will analyze each character in sequence and identify "3", "+", "4", "*", and "2" as tokens.
- The lexer recognizes and creates tokens during character analysis.
- Integer: "3", "4", "2"
- Operator: "+", "*"
- The lexer outputs the identified tokens.

*INTEGER: "3"*

*OPERATOR: "+"*

*INTEGER: "4"*

*OPERATOR: "*"

*INTEGER: "2"*

<br>

### 1.2 Parser
- The parser takes the token list created by the lexer and checks if these tokens follow a specific grammatical structure.
- Using grammatical rules, the parser processes the tokens, arranges them syntactically, and creates a tree structure that conforms to the language's grammar.
- For the Bash shell, the parser ensures that commands are arranged correctly, arguments and options are placed properly, and markers (e.g., tokens indicating the end of statements or the start of loops) are used correctly.

<br>

### 1.3 Executor
- The executor takes the grammar tree created by the parser and generates operations for each command in the tree.
- For the Bash shell, the executor is responsible for executing commands and obtaining their results.
- The executor evaluates variables, performs file operations, runs other programs, and creates pipes to direct output from one command to the next as needed.
- The executor also evaluates conditional statements, checks loop conditions, and manages program flow.

<br>

### 1.4 Pipe
- Used to direct the output of one process directly into the input of another process.
- Enables efficient chaining of multiple processes.
- Represented by the vertical bar '|' symbol.

```
ls | grep ".txt"
```
- This command uses "grep" to filter files with the ".txt" extension from the output of the "ls" command.
- The "ls" command produces a list of files, and this output is passed to the "grep" command, resulting in only ".txt" files being printed to the screen.

<br>

### 1.5 AND Operator
- The **'&&'** operator on the command line starts executing from the left-hand side expression sequentially.
- If the left-hand side expression is successful, it executes the right-hand side expressions.

```
git add . && git commit -m "commit" && git push
```
- In the example above, if the "git commit -m" line fails, the commands to its right will not execute.

<br>

### 1.6 OR Operator
- The **'||'** operator on the command line executes the right-hand side expression only if the left-hand side expression fails.

```
make || make fclean
```
```
gcc deneme.c || echo "Failed."
```


<br>

### 1.7 Exit Status
- When each command is executed, the exit status is represented by an integer value.
- A value of 0 usually indicates success, while different values indicate errors.
- The "$?" variable contains the exit status of the last executed command.

```
echo a
$?
```
- Returns '0' for success.
```
cat abc.txt
$?
```
- Returns '1' for error because the file does not exist.
```
/bin/ech0
$?
```
- Returns '127' for error because the command was not found.

<br>

### 1.8 PID
- PID represents the **unique identifier** of a running process.
- Every process has a unique number assigned by the operating system, identified by its PID.
- PID can be used to track the identity of a process, communicate between processes, or control a process.

```
pid_t pid = getpid();
```
- You need the PID to terminate or stop a process. You can also use the PID to monitor or interact with a specific process.
- If a process has not started, the value of "pid" is set to "-1".

<br>

### 1.9 ENV
- Environment variables are values used by programs and processes on the system.
- These variables provide information to running programs and commands.
- Bash offers various methods to access these variables.
- Environment variables are **key-value** pairs.
- Keys are names used to access the variables, and values are the information the variables hold.
- For example, a "PATH" variable might contain a list of directories where system programs are located.
- To define a variable:

```
export MY_VARIABLE="Hello, World"
```
you need to specify the variable's name and assign it a value. The 'export' command is typically used in Bash to do this.
- To access a variable:

```
echo $MY_VARIABLE
```
you can call the variable name using the **'$'** sign.
- To delete a variable:
```
unset MY_VARIABLE
```
- Some environment variables are automatically defined by the system and can be used directly. For example:
     - **'PATH'**: List of directories where system programs are located
     - **'HOME'**: User's home directory
     - **'USER'**: User's name
- Bash provides several predefined environment variables. For example:
     - **'PWD'**: Current working directory
     - **'SHELL'**: Name of the shell program in use
     - **'LANG'**: Language setting

<br>

### 1.10 Export

```
export
```
- The **"export"** command is used to transfer a variable to the shell environment.
- When you **"export"** a variable, this variable and its value are passed to sub-shell processes and become accessible in those processes.
- The "export" command is generally used to make environment variables (e.g., PATH, HOME) or user-defined variables available in sub-shell processes.
- Variables transferred can be modified in sub-shell processes without affecting the parent shell process. Changes made in sub-shell processes only affect those processes.
```
my_var="Hello"
export my_var
```
- In the example above, a variable named "my_var" is created and then transferred to the shell environment using the "export" command. This makes the "my_var" variable accessible in sub-shell processes as well.

<br>

### 1.11 Declare
- The **"declare"** command is used to define variables, specify their types, and assign attributes.
```
declare [options] variable=value
```
- You can specify the type of variables. For example, using the **"-i"** option, you can define a variable as an integer.
- You can assign special attributes (readonly, local, etc.) to variables.
- The **"declare"** command allows you to create variables that are only valid within the shell session or script in which they are defined.
- These variables are not valid in sub-shell processes.
```
declare -i num=10
```
- The 'num' variable is defined as an integer.
```
declare -r readonly_var="Hello"
```
- The 'readonly_var' variable is defined as read-only.
```
declare -x exported_var="World"
```
- The 'exported_var' variable is defined as exported.
```
declare -a my_array=(1 2 3)
```
- 'my_array' değişkeni dizi olarak tanımlanır.
```
declare -f my_function
```
- 'my_function' isimli bir işlev tanımlanır.

<br>

### 1.12 Echo
- The **"echo"** command is used to print messages, variable values, or command results to the screen.
```
name="Yakup"
echo "My name is $name"
```
- In the example above, a variable named "name" is defined, and the "echo" command prints the value of the variable to the screen. The output will be "My name is Yakup".
```
echo -n "Hello, " && echo "World"
```
- In the example above, the **"-n"** option is used to disable the newline character in the first "echo" command. The second "echo" command runs with the newline character, resulting in the output "Hello, World!".
- The **'&&'** operator is a logical operator used in the Bash shell to combine sequential commands.

<br>

### 1.13 File Descriptors
- File descriptors used in the Bash shell are numerical values used to direct the input, output, and error streams of a process.
- The first 3 file descriptors are reserved for the OS, and the rest are filled by the user.

#### 0: Standard Input (stdin):
- Standard input is the mechanism that provides data to a process. It typically corresponds to input provided by the keyboard or another process.
- It is represented by file descriptor 0.

#### 1: Standard Output (stdout):
- Standard output is where a process directs its output. By default, standard output allows data to be printed to the shell window or a file.
- It is represented by file descriptor 1.

#### 2: Standard Error (stderr):
- Standard error is where a process directs its errors and error messages.
- It is usually kept separate from standard output and is used for debugging and error management.
- It is represented by file descriptor 2.

#### 1. Reading from Standard Input:
```
read line
```
- The command above reads a line of input from the user. The input provided by the user is taken from standard input (stdin).

#### 2. Writing to Standard Output:

```
echo "Hello, World" > file.txt
```
- The command above writes the text "Hello, World" to the file "file.txt". The standard output (stdout) is redirected to the file, writing the data.

#### 3. Redirecting Standard Error Output:

```
command_not_found 2> error.log
```
- The command above attempts to run a non-existent command and writes the resulting error message to the file "error.log". The standard error (stderr) is redirected to the file, logging the errors.

<br>


## 2. Shell Program Functions

<br>

### 2.1 Fork()
- The **"fork()"** system call is used to create a new process.
- A process created with "fork()" becomes a copy of the parent process.
- The newly created process is called the child process, while the original process is the parent process.
- "fork()" returns the PID of the newly created process.
- If "fork()" is successful, the PID of the child process is returned to the parent process, and the value **"0"** is returned to the child process.
- If "fork()" fails, the value **"-1"** is returned.
- The parent and child processes start executing from the point where "fork()" was called.
- "fork()" is used to run separate parts of a program in parallel.

![a](https://github.com/Yakupacs/Ecole42_Minishell/assets/73075252/29ba1dd6-d2c0-4631-a7c6-53efa91dd787)


```
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(int argc, char *argv[]){
     int id = fork();
     if (id == 0){
          printf("Hello from child process\n");
     } else {
          printf("Hello from the main process\n");
     }
     return 0;
}
```

```
output:
     Hello from child process
     Hello from the main process
```


<br>

### 2.2 Pipe()
- The **"pipe()"** system call is used to create a unidirectional communication channel.
- Data written to a pipe is sent to one end, and the data is read from the other end.
- Pipes are used to send data from one process to another.
- "pipe()" creates two file descriptors: one for reading and one for writing.
- If "pipe()" is successful, it returns **"0"**.
- If "pipe()" fails, the value **"-1"** is returned.
- Pipes are used to transfer the output of one process to the input of another process.

![pipe](https://github.com/Yakupacs/Ecole42_Minishell/assets/73075252/d2e1c274-ef21-4601-8daa-da16fc4767ec)

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd[2]; // fd[0] => Read, fd[1] => Write
    char buffer[20];

    if (pipe(fd) == -1) {
        perror("Pipe oluşturma hatası");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[0]); // Read kapattı.
        char message[] = "Merhaba Ebeveyn!";
        write(fd[1], message, sizeof(message)); // Write(fd[1]) içerisinde "Merhaba Ebeveyn!"
        close(fd[1]); // Write kapattı.
    } else {
        // Parent process
        close(fd[1]); // Yazma kapattı.
        read(fd[0], buffer, sizeof(buffer)); // Read(fd[0]) içerisinden "Merhaba Ebeveyn" okudu.
        printf("Ebeveyn: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
```

```
output:
     Ebeveyn: Merhaba Ebeveyn!
```
- The filedes[0] descriptor is used for reading, and the filedes[1] descriptor is used for writing.

<br>

### 2.3 Dup()
- The **"dup()"** system call duplicates an existing file descriptor.
- The duplicated file descriptor is a copy of the original file descriptor.
- "dup()" creates a new file descriptor with the same properties as the original file descriptor.


```
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
  
int main()
{
    int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
      
    if(file_desc < 0)
        printf("Error opening the file\n");

    int copy_desc = dup(file_desc);

    write(copy_desc,"This will be output to the file named dup.txt\n", 46);
          
    write(file_desc,"This will also be output to the file named dup.txt\n", 51);

}
```
- If "dup()" is successful, it returns the new file descriptor.
- If "dup()" fails, the value **"-1"** is returned.
- The new file descriptor can be used to access the same file or resource as the original file descriptor.

<br>

### 2.4 Dup2()
- The **"dup2()"** system call duplicates an existing file descriptor and assigns it to a specified file descriptor.

```
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int fd = open("tricky.txt", O_WRONLY | O_APPEND, 0777);

    dup2(fd, 1) ; 
          
    printf("I will be printed in the file tricky.txt\n");
}
```
- If "dup2()" is successful, it returns the new file descriptor.
- If "dup2()" fails, the value **"-1"** is returned.
- "dup2()" assigns the new file descriptor to the same file or resource as the original file descriptor.
- If the new file descriptor is already in use, it is closed and assigned to the new file descriptor.

<br>

## 3. Working Structure

<br>

### 3.1 Flowchart
- The flowchart of a Shell program typically involves the following steps:
     1. **Lexical Analysis**: The input is tokenized.
     2. **Parsing**: Tokens are analyzed and converted into a syntax tree.
     3. **Execution**: The commands are executed.
     4. **Input/Output Redirection**: Handles redirection of standard input/output.
     5. **Pipe Handling**: Manages the flow of data between commands through pipes.
     6. **Environment Variables**: Manages the environment variables.
     7. **Sub-shell Management**: Handles sub-shell processes.
     8. **Error Handling**: Manages errors and exit statuses.

<br>

### 3.2 Functions
- The functions of a Shell program typically include:

| Function  | Library | Description |
| ------------- | ------------- | ------------- |
| printf  | <stdio.h>  | Prints output to stdout. |
| malloc  | <stdlib.h>  | Allocates dynamic memory. |
| free  | <stdlib.h>  | Releases dynamic memory. |
| read  | <unistd.h>  | Reads data. |
| write  | <unistd.h>  | Writes data. |
| open  | <fcntl.h>  | Opens a file. |
| close  | <unistd.h>  | Closes a file. |
| fork  | <unistd.h>  | Creates a new child process. |
| wait  | <sys/wait.h>  | Waits for a child process to complete. |
| waitpid  | <sys/wait.h>  | Waits for a specific child process to complete. |
| wait3  | <sys/wait.h>  | Waits for a child process to complete. |
| wait4  | <sys/wait.h>  | Waits for a specific child process to complete. |
| signal  | <signal.h>  | Sets a signal handler. |
| kill  | <signal.h>  | Terminates a process and sends a signal. |
| exit  | <stdlib.h>  | Exits the program. |
| getcwd  | <unistd.h>  | Gets the current working directory. |
| chdir  | <unistd.h>  | Changes the working directory. |
| stat  | <sys/stat.h>  | Retrieves information about a file or directory. |
| lstat  | <sys/stat.h>  | Retrieves information about a symbolic link itself. |
| fstat  | <sys/stat.h>  | Retrieves information about a file associated with a file descriptor. |
| execve  | <unistd.h>  | Executes a new program. |
| dup  | <unistd.h>  | Duplicates a file descriptor. |
| dup2  | <unistd.h>  | Duplicates a file descriptor to a specified file descriptor. |
| pipe  | <unistd.h>  | Creates a two-way communication channel (pipe). |
| opendir  | <dirent.h>  | Opens a directory stream. |
| readdir  | <dirent.h>  | Reads the next directory entry. |
| closedir  | <dirent.h>  | Closes a directory stream. |
| strerror  | <string.h>  | Returns a string describing the error code. |
| errno  | <errno.h>  | Variable holding the error code. |
| termcap  | <term.h>  | Retrieves terminal capabilities. |

<br>

## 4. Redirections

<br>

### 4.1 Standard Input '<'
- The **"<"** operator redirects the standard input (stdin) of a command to a file.

```
command < input.txt
```
- The command reads its input from "input.txt" instead of the keyboard.

<br>

### 4.2 Standard Output '>'
- The **">"** operator redirects the standard output (stdout) of a command to a file.

```
command > output.txt
```
- The command writes its output to "output.txt" instead of the screen.

<br>

### 4.3 Appending Redirected Output ">>"
- The **">>"** operator appends the standard output (stdout) of a command to a file.

```
echo "hello" >> output.txt
```
- The command appends its output to "output.txt" instead of overwriting it.

<br>

### 4.4 Here Documents '<<'
- The **"<<"** operator reads input from the current source until a line containing only a specified word is seen.

```
cat << END
This is line 1.
This is line 2.
This is line 3.
END
```
- The command reads input from the current source until the line containing only "EOF" is seen.

<br>
