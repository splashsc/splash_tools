int switch_reboot_auto_timeout()
{
  struct tm *v0; // $v0
  int *v1; // $v1
  struct tm *v2; // $t1
  int v3; // $t0
  int v4; // $a3
  int v5; // $a2
  int v6; // $a1
  int v7; // $a1
  int v8; // $a2
  int v9; // $v0
  int v11; // [sp+18h] [-34h] BYREF
  int v12; // [sp+1Ch] [-30h]
  time_t v13; // [sp+44h] [-8h] BYREF

  v13 = time(0);
  v0 = localtime(&v13);
  v1 = &v11;
  v2 = (struct tm *)&v0->tm_isdst;
  do
  {
    v3 = v0->tm_sec;
    v4 = v0->tm_min;
    v5 = v0->tm_hour;
    v6 = v0->tm_mday;
    v0 = (struct tm *)((char *)v0 + 16);
    *v1 = v3;
    v1[1] = v4;
    v1[2] = v5;
    v1[3] = v6;
    v1 += 4;
  }
  while ( v0 != v2 );
  v7 = v0->tm_hour;
  v8 = v0->tm_min;
  *v1 = v0->tm_sec;
  v1[1] = v8;
  v1[2] = v7;
  if ( v12 != dword_67A5D0 )
  {
    dword_67A5D0 = v12;
    switch_reboot_auto_runing(&v11);
  }
  v9 = jiffies_get();
  return mod_timer(&switch_reboot_timer, v9 + 5000);
}
// 67A5D0: using guessed type int dword_67A5D0;
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

