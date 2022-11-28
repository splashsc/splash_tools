int _reboot_timer_fun()
{
  system("echo \"upgrade re_boot, System will reboot!\" >/dev/console");
  return re_boot();
}
// 6A86A0: using guessed type int re_boot(void);

