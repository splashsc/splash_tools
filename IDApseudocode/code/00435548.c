int __fastcall sub_435548(int *a1, char **a2)
{
  __pid_t v4; // $v0
  __pid_t v5; // $s0
  int v7; // [sp+18h] [-10h] BYREF
  int fd; // [sp+1Ch] [-Ch]
  int v9; // [sp+20h] [-8h] BYREF

  if ( pipe(&v7) < 0 )
    perror("myexec: open pipe fd1 error");
  v4 = fork();
  v5 = v4;
  if ( v4 < 0 )
  {
    perror("myexec: fork error");
  }
  else if ( !v4 )
  {
    close(v7);
    if ( dup2(fd, 1) != 1 )
      perror("myexec: dup fd[1] to stdout error in child process");
    if ( execvp(*a2, a2) < 0 )
    {
      perror("myexec: execvp error in child process");
      exit(1);
    }
  }
  close(fd);
  waitpid(v5, &v9, 0);
  *a1 = v7;
  return 0;
}

