int __fastcall jhl_gl_lan_restart_timer(int a1)
{
  int result; // $v0

  result = 1;
  if ( !lan_restart_timer )
  {
    dword_6A3910 = 0;
    dword_6A390C = (int)_lan_restart_fun;
    dword_6A3908 = a1 + jiffies_get();
    add_timer(&lan_restart_timer);
    result = 0;
  }
  return result;
}
// 6A3900: using guessed type int lan_restart_timer;
// 6A3908: using guessed type int dword_6A3908;
// 6A390C: using guessed type int dword_6A390C;
// 6A3910: using guessed type int dword_6A3910;
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

