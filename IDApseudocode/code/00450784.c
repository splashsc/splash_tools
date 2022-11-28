int __fastcall jhl_link_uptime_s(int a1, int a2)
{
  int v3; // $v0
  int v4; // $v0
  const char *v5; // $s0
  int v6; // $v0
  struct sysinfo v8[4]; // [sp+18h] [-13Ch] BYREF

  v3 = jhl_nvget("wan_uptime", a1);
  v4 = nvram_get(v3);
  if ( !a2 )
    return 0;
  v5 = (const char *)v4;
  if ( !v4 )
    return 0;
  sysinfo(v8);
  v6 = atol(v5);
  return v8[0].uptime - v6;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

