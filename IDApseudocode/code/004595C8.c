int __fastcall sub_4595C8(int a1)
{
  const char *v2; // $s1
  const char *v3; // $v0
  const char *v4; // $v0
  int v5; // $s2
  unsigned int v6; // $s1
  char v8[512]; // [sp+18h] [-200h] BYREF

  v2 = (const char *)nvram_get("lan_ipaddr");
  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v3 = (const char *)nvram_get("http_lanport");
  if ( v3 && !strcmp(v3, "80") )
  {
    v5 = sprintf(&v8[29], "\"ip\":\"%s\"", v2) + 29;
  }
  else
  {
    v4 = (const char *)nvram_get("http_lanport");
    v5 = sprintf(&v8[29], "\"ip\":\"%s:%s\"", v2, v4) + 29;
  }
  v6 = snprintf(&v8[v5], 512 - v5, "}}");
  if ( v6 >= 512 - v5 )
    v6 = 511 - v5;
  jhl_gl_reboot_timer(3000);
  return httpd_cgi_ret(a1, v8, v6 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

