struct hostent *StrToIp()
{
  const char *v0; // $a0

  MEMORY[0]();
  return gethostbyname(v0);
}
// 4CD4A9: variable 'v0' is possibly undefined

