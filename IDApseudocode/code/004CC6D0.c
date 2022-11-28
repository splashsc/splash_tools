void __noreturn exit(int status)
{
  MEMORY[0](status);
  jhl_stop_redial();
}
// 4CC6E0: using guessed type int jhl_stop_redial(void);

