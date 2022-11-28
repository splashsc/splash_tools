int __fastcall jhl_gl_poweroff_timer(int a1)
{
  int result; // $v0

  result = 1;
  if ( !gl_reset_timer )
  {
    dword_6A3A38 = 0;
    dword_6A3A34 = (int)_poweroff_timer_fun;
    dword_6A3A30 = a1 + jiffies_get();
    killall("wys_billing", 17);
    killall("wys_billing_new", 17);
    killall("mqtt_ai", 17);
    killall("mqtt_ai_new", 17);
    add_timer(&gl_reset_timer);
    result = 0;
  }
  return result;
}
// 6A3A28: using guessed type int gl_reset_timer;
// 6A3A30: using guessed type int dword_6A3A30;
// 6A3A34: using guessed type int dword_6A3A34;
// 6A3A38: using guessed type int dword_6A3A38;
// 6A8178: using guessed type int __fastcall killall(_DWORD, _DWORD);
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

