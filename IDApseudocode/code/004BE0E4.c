int __fastcall sub_4BE0E4(int a1)
{
  int v2; // $fp
  int v3; // $s7
  int v4; // $v0
  unsigned int v5; // $v0
  unsigned int v6; // $v0
  unsigned int v7; // $s7
  unsigned int v8; // $v0
  char v10[4096]; // [sp+18h] [-1000h] BYREF

  memset(v10, 0, sizeof(v10));
  v2 = 0;
  strcpy(v10, "{\"code\":0,\"error\":\"\",\"data\":{\"limit\":[");
  v3 = 38;
  do
  {
    v4 = get_rule_num_limit(v2);
    v5 = snprintf(&v10[v3], 4096 - v3, "%u,", v4);
    ++v2;
    if ( v5 >= 4096 - v3 )
      v5 = 4095 - v3;
    v3 += v5;
  }
  while ( v2 != 42 );
  if ( v3 > 0 && v10[v3 - 1] == 44 )
    --v3;
  v10[v3] = 0;
  v6 = snprintf(&v10[v3], 4096 - v3, &byte_6445A0);
  if ( v6 >= 4096 - v3 )
    v6 = 4095 - v3;
  v7 = v6 + v3;
  v8 = snprintf(&v10[v7], 4096 - v7, "}}");
  if ( v8 >= 4096 - v7 )
    v8 = 4095 - v7;
  return httpd_cgi_ret(a1, v10, v8 + v7, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;

