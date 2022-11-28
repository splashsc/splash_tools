int ping_wan_gw_stop()
{
  MEMORY[0]();
  return kill_by_pid_name();
}
// 4CC700: using guessed type int kill_by_pid_name(void);

