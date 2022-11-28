int __fastcall ai_wait_upgrade(unsigned int a1)
{
  int v1; // $s0
  _BOOL4 v2; // $s4
  int v3; // $v0
  int result; // $v0

  v1 = 600;
  v2 = a1 < time(0);
  while ( 1 )
  {
    sleep(1u);
    --v1;
    v3 = nvram_get_int("fw_upgrade_state");
    if ( v3 == 2 )
    {
      nvram_set("fw_upgrade_state", "0");
      return 0;
    }
    if ( v3 == 1 )
      break;
    if ( v3 == 3 && v2 )
    {
      system("echo \" upgrade timeout\" >/dev/console");
      system("killall fw_upgrade");
      nvram_set("fw_upgrade_state", "0");
      return 148;
    }
    result = 150;
    if ( !v1 )
      return result;
  }
  system("echo \" upgrade err\" >/dev/console");
  nvram_set("fw_upgrade_state", "0");
  return 149;
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

