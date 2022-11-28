int __fastcall jhl_gl_net_restart_timer(int a1)
{
  int result; // $v0

  result = 1;
  if ( !net_restart_timer )
  {
    dword_6A3A24 = 0;
    dword_6A3A20 = (int)_net_restart_fun;
    dword_6A3A1C = a1 + jiffies_get();
    add_timer(&net_restart_timer);
    result = 0;
  }
  return result;
}
// 6A3A14: using guessed type int net_restart_timer;
// 6A3A1C: using guessed type int dword_6A3A1C;
// 6A3A20: using guessed type int dword_6A3A20;
// 6A3A24: using guessed type int dword_6A3A24;
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

