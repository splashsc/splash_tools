int ping_wan_gw_get_state()
{
  MEMORY[0]();
  return read_log_data();
}
// 4CCA90: using guessed type int read_log_data(void);

