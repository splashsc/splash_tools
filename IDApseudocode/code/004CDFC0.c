int remove(const char *filename)
{
  MEMORY[0](filename);
  return auth_write_usblog();
}
// 4CDFD0: using guessed type int auth_write_usblog(void);

