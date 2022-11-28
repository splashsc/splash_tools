int __fastcall execvp(char *file, char *argv[])
{
  MEMORY[0](file, argv);
  return SSL_read();
}
// 4CD320: using guessed type int SSL_read(void);

