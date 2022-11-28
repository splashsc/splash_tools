int __fastcall jhl_gl_restart_jhttpd(char *src, int a2)
{
  int result; // $v0

  result = 1;
  if ( !gl_reset_timer )
  {
    strcpy(gl_exec_service_name, src);
    dword_6A3A38 = 0;
    dword_6A3A34 = (int)_restart_jhttpd_fun;
    dword_6A3A30 = a2 + jiffies_get();
    add_timer(&gl_reset_timer);
    result = 0;
  }
  return result;
}
// 4341F8: using guessed type int _restart_jhttpd_fun();
// 6A3A28: using guessed type int gl_reset_timer;
// 6A3A30: using guessed type int dword_6A3A30;
// 6A3A34: using guessed type int dword_6A3A34;
// 6A3A38: using guessed type int dword_6A3A38;
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

