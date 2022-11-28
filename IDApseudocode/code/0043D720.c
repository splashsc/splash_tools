int __fastcall sub_43D720(int a1)
{
  int v2; // $v0
  int v3; // $s1
  bool v4; // dc
  int v5; // $v0
  unsigned int v6; // $v0
  char v8[1028]; // [sp+18h] [-404h] BYREF

  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = get_nvarms((const char **)base_network_nvarms_dns, (int)&v8[29], 995);
  v3 = v2 + 29;
  v4 = v2 + 29 <= 0;
  v5 = v2 + 28;
  if ( !v4 && v8[v5] == 44 )
    v3 = v5;
  v8[v3] = 0;
  v6 = snprintf(&v8[v3], 1024 - v3, "}}");
  if ( v6 >= 1024 - v3 )
    v6 = 1023 - v3;
  return httpd_cgi_ret(a1, v8, v6 + v3, 4);
}
// 642164: using guessed type __int16 word_642164;
// 66E2E0: using guessed type char *base_network_nvarms_dns[4];

