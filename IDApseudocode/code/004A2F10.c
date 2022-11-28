int __fastcall sub_4A2F10(int a1)
{
  const char *v2; // $v0
  const char *v3; // $s0
  unsigned int v4; // $v0
  int v5; // $s0
  unsigned int v6; // $v0
  char v8[4100]; // [sp+18h] [-1004h] BYREF

  v2 = (const char *)nvram_get("vue_customeze_menus");
  if ( !v2 || (v3 = v2, strlen(v2) < 2) )
    v3 = "[]";
  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v4 = snprintf(&v8[29], 4067, "\"menus\":%s", v3);
  v5 = v4 + 29;
  if ( v4 >= 0xFE3 )
    v5 = 4095;
  v6 = snprintf(&v8[v5], 4096 - v5, "}}");
  if ( v6 >= 4096 - v5 )
    v6 = 4095 - v5;
  return httpd_cgi_ret(a1, v8, v6 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

