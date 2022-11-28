int __fastcall sub_45C810(int a1)
{
  const char *v2; // $v0
  unsigned int v3; // $v0
  int v4; // $s0
  unsigned int v5; // $v0
  char v7[1028]; // [sp+18h] [-404h] BYREF

  memset(v7, 0, 0x400u);
  strcpy(v7, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)nvram_get("http_hadmin");
  if ( !v2 )
    v2 = "";
  v3 = snprintf(&v7[29], 995, "\"http_username\":\"%s\"", v2);
  v4 = v3 + 29;
  if ( v3 >= 0x3E3 )
    v4 = 1023;
  v5 = snprintf(&v7[v4], 1024 - v4, "}}");
  if ( v5 >= 1024 - v4 )
    v5 = 1023 - v4;
  return httpd_cgi_ret(a1, v7, v5 + v4, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

