#ifndef STRACE_H
#define STRACE_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>
#include "syscalls.h"
/* strace_0 */
void _trace_child(char **argv, char **env);
void _trace_parent(pid_t child_pid);
int _await_syscall(pid_t child_pid);

#endif
