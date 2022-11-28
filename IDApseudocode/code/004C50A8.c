int __fastcall sub_4C50A8(int a1)
{
  const char *v2; // $v0
  int v3; // $a0
  char v5[8192]; // [sp+28h] [-4000h] BYREF
  char v6[8192]; // [sp+2028h] [-2000h] BYREF

  v5[0] = 0;
  v2 = (const char *)nvram_get("ipv6in4_all");
  if ( !v2 )
    v2 = "";
  snprintf(v6, 0x2000, "%s", v2);
  nvparm_del_str(v6, 60, 0, a1, 124, 0, v5);
  ipv6in4_stop(a1);
  nvram_set("ipv6in4_all", v5);
  jhl_parm_commit(v3);
  return 0;
}
// 4C5180: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A850C: using guessed type int __fastcall ipv6in4_stop(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

