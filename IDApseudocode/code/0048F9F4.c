char *__fastcall jhl_vpn_link_uptime(char *a1, int a2)
{
  int v4; // $v0
  char *result; // $v0
  struct sysinfo v6[4]; // [sp+18h] [-144h] BYREF
  int v7[3]; // [sp+150h] [-Ch] BYREF

  *a1 = 45;
  a1[1] = 0;
  sysinfo(v6);
  v4 = jhl_vpndtime(a2);
  result = (char *)f_read(v4, v7, 4);
  if ( result == (char *)4 )
    result = reltime(a1, v6[0].uptime - v7[0]);
  return result;
}
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A87F4: using guessed type int __fastcall jhl_vpndtime(_DWORD);

