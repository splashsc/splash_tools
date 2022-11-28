int __fastcall sub_45C3BC(int a1)
{
  int v2; // $v0
  char *v3; // $v1
  int v4; // $s0
  const char *v5; // $v0
  int v6; // $s0
  unsigned int v7; // $v0
  char v9[1028]; // [sp+18h] [-404h] BYREF

  strcpy(v9, "{\"code\":0,\"error\":\"\",\"data\":{\"rtime\":\"");
  v2 = asp_time(&v9[38]);
  v3 = &v9[v2 + 38];
  *v3 = 34;
  v3[1] = 44;
  v3[2] = 0;
  v4 = v2 + 40 + get_nvarms((const char **)base_time_nvarms, (int)&v9[v2 + 40], 1024 - (v2 + 40));
  v5 = (const char *)nvram_get("time_type");
  v6 = v4 + sprintf(&v9[v4], "\"time_type\":\"%s\"", v5);
  v7 = snprintf(&v9[v6], 1024 - v6, "}}");
  if ( v7 >= 1024 - v6 )
    v7 = 1023 - v6;
  return httpd_cgi_ret(a1, v9, v7 + v6, 4);
}
// 642164: using guessed type __int16 word_642164;
// 66FD30: using guessed type char *base_time_nvarms[8];
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

