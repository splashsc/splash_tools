int flash_get_sec_status()
{
  MEMORY[0]();
  return f_read_string();
}
// 4CDDF0: using guessed type int f_read_string(void);

