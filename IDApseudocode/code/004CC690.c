int printf(char *format, ...)
{
  MEMORY[0](format);
  return start_qos_iface();
}
// 4CC6A0: using guessed type int start_qos_iface(void);

