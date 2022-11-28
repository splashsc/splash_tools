int unlink(const char *name)
{
  MEMORY[0](name);
  return radius_server_start();
}
// 4CCD20: using guessed type int radius_server_start(void);

