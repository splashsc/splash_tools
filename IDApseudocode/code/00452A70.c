int init_diagnosis_timer()
{
  init_timer(&gl_auto_diagnosis_timer);
  dword_6A3C44 = jiffies_get() + 1000;
  dword_6A3C4C = 0;
  dword_6A3C48 = (int)auto_diagnosis_timer_fun;
  return add_timer(&gl_auto_diagnosis_timer);
}
// 6A3C44: using guessed type int dword_6A3C44;
// 6A3C48: using guessed type int dword_6A3C48;
// 6A3C4C: using guessed type int dword_6A3C4C;
// 6A8368: using guessed type int __fastcall init_timer(_DWORD);
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

