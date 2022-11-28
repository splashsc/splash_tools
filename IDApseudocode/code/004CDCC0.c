int fcntl(int fd, int cmd, ...)
{
  const char *v2; // $a0
  int v3; // $a1

  MEMORY[0](fd, cmd);
  return access(v2, v3);
}
// 4CDCC9: variable 'v2' is possibly undefined
// 4CDCC9: variable 'v3' is possibly undefined

