int __fastcall sub_4C5A3C(int a1, int a2, const char *a3)
{
  const char *v6; // $v0
  char v8[32]; // [sp+20h] [-20h] BYREF

  v6 = (const char *)lan_showname_guess(a2, a3, v8);
  return -(mcl_bytearray_printf(a1, "{\"iface\":\"%u\",\"ifname\":\"%s\",\"showname\":\"%s\"},", a2, a3, v6) < 1);
}
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A8954: using guessed type int __fastcall lan_showname_guess(_DWORD, _DWORD, _DWORD);

