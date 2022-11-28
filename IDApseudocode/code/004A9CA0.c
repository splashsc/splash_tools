int __fastcall jhl_nat_more_add_iface(int a1, int a2)
{
  char *v4; // $s1
  char v6[256]; // [sp+18h] [-124h] BYREF
  int v7[9]; // [sp+118h] [-24h] BYREF

  memset(v6, 0, sizeof(v6));
  v4 = (char *)nvram_get("lan_ifname");
  if ( !v4 )
    v4 = "";
  ip_get_duolan(a1, a2, v6);
  v7[0] = (int)"ip";
  v7[3] = (int)v6;
  v7[1] = (int)"addr";
  v7[5] = (int)v4;
  v7[2] = (int)&off_646D8C;
  v7[4] = (int)"dev";
  v7[6] = 0;
  return eval(v7, 0, 0, 0);
}
// 646D8C: using guessed type char *off_646D8C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A881C: using guessed type int __fastcall ip_get_duolan(_DWORD, _DWORD, _DWORD);

