int jhl_vpnclient_stop()
{
  MEMORY[0]();
  return vpn_user_del();
}
// 4CE190: using guessed type int vpn_user_del(void);

