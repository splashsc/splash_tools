int __fastcall sub_4C4F78(int a1, int a2, const char *a3)
{
  int v5; // $v0
  const char *v7; // $v0
  const char *v8; // $s0
  char v10[36]; // [sp+20h] [-24h] BYREF

  v5 = lan_name_get2("wan", a2, "proto", 0);
  v7 = (const char *)nvram_get(v5);
  if ( v7 && ((v8 = v7, !strcmp(v7, "3G")) || !strcmp(v8, "4G")) )
    strcpy(v10, "4G");
  else
    snprintf(v10, 32, "WAN%u", a2 + 1);
  return -(mcl_bytearray_printf(a1, "{\"iface\":\"%u\",\"ifname\":\"%s\",\"showname\":\"%s\"},", a2, a3, v10) < 1);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A84C4: using guessed type int __fastcall lan_name_get2(_DWORD, _DWORD, _DWORD, _DWORD);

