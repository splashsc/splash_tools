void __fastcall free(void *ptr)
{
  MEMORY[0](ptr);
  jhl_ddns_del();
}
// 4CCBC0: using guessed type int jhl_ddns_del(void);

