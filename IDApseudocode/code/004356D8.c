int __fastcall sub_4356D8(int *a1, char **a2)
{
  __pid_t v4; // $v0
  int v5; // $s0
  int fd; // [sp+18h] [-8h] BYREF
  int v8; // [sp+1Ch] [-4h]

  if ( pipe(&fd) < 0 )
    perror("myexec: open pipe fd1 error");
  v4 = fork();
  v5 = v4;
  if ( v4 < 0 )
  {
    perror("myexec: fork error");
    v5 = -1;
    close(fd);
    close(v8);
  }
  else if ( v4 )
  {
    close(v8);
    *a1 = fd;
  }
  else
  {
    close(fd);
    if ( dup2(v8, 1) != 1 )
      perror("myexec: dup fd[1] to stdout error in child process");
    v5 = -1;
    if ( execvp(*a2, a2) < 0 )
    {
      perror("myexec: execvp error in child process");
      exit(1);
    }
  }
  return v5;
}

