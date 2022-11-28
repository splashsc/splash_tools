int __fastcall sub_448510(int a1)
{
  int v2; // $s1
  unsigned int v3; // $v0
  char v5[1028]; // [sp+18h] [-404h] BYREF

  strcpy(v5, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = get_vlan_name_data(&v5[29]) + 29;
  v3 = snprintf(&v5[v2], 1024 - v2, "}}");
  if ( v3 >= 1024 - v2 )
    v3 = 1023 - v2;
  return httpd_cgi_ret(a1, v5, v3 + v2, 4);
}
// 642164: using guessed type __int16 word_642164;

