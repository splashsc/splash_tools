const char *inet_ntop(int af, const void *cp, char *buf, socklen_t len)
{
  int v4; // $a0
  unsigned int v5; // $a1

  MEMORY[0](af, cp, buf, len);
  return (const char *)ioctl(v4, v5);
}
// 4CE079: variable 'v4' is possibly undefined
// 4CE079: variable 'v5' is possibly undefined

