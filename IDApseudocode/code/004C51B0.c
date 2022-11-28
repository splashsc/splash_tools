int __fastcall sub_4C51B0(int a1, int a2, int a3, int a4, char *nptr)
{
  const char *v9; // $v0
  int v10; // $s3
  bool v11; // dc
  int result; // $v0
  int v13; // $a0
  char v14[8192]; // [sp+28h] [-401Ch] BYREF
  char v15[8192]; // [sp+2028h] [-201Ch] BYREF
  int v16[7]; // [sp+4028h] [-1Ch] BYREF

  v10 = atoi(nptr);
  v9 = (const char *)nvram_get("ipv6in4_all");
  if ( !v9 )
    v9 = "";
  snprintf(v15, 0x2000, "%s", v9);
  v14[0] = 0;
  nvparm_del_str(v15, 60, 0, a1, 124, 0, v14);
  v16[0] = (int)v14;
  v16[1] = 0x2000;
  v16[2] = strlen(v14);
  v16[3] = 0;
  v16[4] = 0;
  v11 = mcl_bytearray_printf(
          v16,
          "<%s|%s|%s|%s|%d",
          (const char *)a1,
          (const char *)a2,
          (const char *)a3,
          (const char *)a4,
          v10 != 0) <= 0;
  result = -1;
  if ( !v11 )
  {
    ipv6in4_stop(a1);
    if ( v10 )
      ipv6in4_start(a1, a2, a3, a4);
    nvram_set("ipv6in4_all", v16[0]);
    jhl_parm_commit(v13);
    result = 0;
  }
  return result;
}
// 4C531C: variable 'v13' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A850C: using guessed type int __fastcall ipv6in4_stop(_DWORD);
// 6A8510: using guessed type int __fastcall ipv6in4_start(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

