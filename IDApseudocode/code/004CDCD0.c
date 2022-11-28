int access(const char *name, int type)
{
  MEMORY[0](name, type);
  return SSL_CTX_use_PrivateKey_file();
}
// 4CDCE0: using guessed type int SSL_CTX_use_PrivateKey_file(void);

