int switch_reboot_auto_timer_init()
{
  dword_6A7D60 = 0;
  dword_6A7D58 = jiffies_get() + 2000;
  dword_6A7D5C = (int)switch_reboot_auto_timeout;
  init_timer(&switch_reboot_timer);
  return add_timer(&switch_reboot_timer);
}
// 6A7D58: using guessed type int dword_6A7D58;
// 6A7D5C: using guessed type int dword_6A7D5C;
// 6A7D60: using guessed type int dword_6A7D60;
// 6A8368: using guessed type int __fastcall init_timer(_DWORD);
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

