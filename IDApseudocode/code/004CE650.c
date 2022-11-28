int nvram_get_int()
{
  MEMORY[0]();
  return get_dhcp_left_num();
}
// 4CE660: using guessed type int get_dhcp_left_num(void);

