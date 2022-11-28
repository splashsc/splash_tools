ssize_t __fastcall sub_435310(void *a1, size_t a2, char **a3)
{
  __pid_t v6; // $v0
  __pid_t v7; // $s0
  ssize_t v9; // $s1
  int fd; // [sp+18h] [-14h] BYREF
  int v11; // [sp+1Ch] [-10h]
  int v12[3]; // [sp+20h] [-Ch] BYREF

  if ( pipe(&fd) < 0 )
    perror("myexec: open pipe fd1 error");
  v6 = fork();
  v7 = v6;
  if ( v6 < 0 )
  {
    perror("myexec: fork error");
    return 0;
  }
  if ( v6 )
  {
    close(v11);
    if ( a1 )
    {
      v9 = read(fd, a1, a2);
      if ( v9 < 0 )
        perror("myexec: read from fd[0] error");
    }
    else
    {
      v9 = 0;
    }
    close(fd);
    waitpid(v7, v12, 0);
    return v9;
  }
  close(fd);
  if ( dup2(v11, 1) != 1 )
    perror("myexec: dup fd[1] to stdout error in child process");
  if ( execvp(*a3, a3) < 0 )
  {
    close(v11);
    perror("myexec: execvp error in child process");
    exit(1);
  }
  close(v11);
  return 0;
}

