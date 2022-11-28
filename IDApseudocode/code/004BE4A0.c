int __fastcall sub_4BE4A0(int a1)
{
  unsigned int v2; // $v0
  int v3; // $s0
  unsigned int v4; // $v0
  char v6[260]; // [sp+18h] [-104h] BYREF

  strcpy(v6, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = snprintf(&v6[29], 227, "\"total\":%u,\"all\":[]", 0);
  v3 = v2 + 29;
  if ( v2 >= 0xE3 )
    v3 = 255;
  v4 = snprintf(&v6[v3], 256 - v3, "}}");
  if ( v4 >= 256 - v3 )
    v4 = 255 - v3;
  return httpd_cgi_ret(a1, v6, v4 + v3, 4);
}
// 642164: using guessed type __int16 word_642164;

