int __fastcall jhl_link_uptime(char *a1, int a2, int a3)
{
  int v4; // $v0
  const char *v6; // $s1
  int result; // $v0
  int v8; // $v0
  struct sysinfo v9[4]; // [sp+18h] [-138h] BYREF

  v4 = jhl_nvget("wan_uptime", a2);
  v6 = (const char *)nvram_get(v4);
  result = 45;
  *a1 = 45;
  a1[1] = 0;
  if ( a3 )
  {
    if ( v6 )
    {
      sysinfo(v9);
      v8 = atol(v6);
      result = (int)reltime(a1, v9[0].uptime - v8);
    }
  }
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

