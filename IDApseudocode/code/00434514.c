int __fastcall sub_434514(int a1, int a2, int a3)
{
  int result; // $v0

  result = 1;
  if ( !gl_reset_timer )
  {
    dword_6A3A38 = a3;
    dword_6A3A34 = a2;
    dword_6A3A30 = a1 + jiffies_get();
    add_timer(&gl_reset_timer);
    result = 0;
  }
  return result;
}
// 6A3A28: using guessed type int gl_reset_timer;
// 6A3A30: using guessed type int dword_6A3A30;
// 6A3A34: using guessed type int dword_6A3A34;
// 6A3A38: using guessed type int dword_6A3A38;
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

