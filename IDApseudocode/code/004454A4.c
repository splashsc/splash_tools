int __fastcall sub_4454A4(int a1)
{
  int v2; // $s1
  unsigned int v3; // $v0
  char v5[508]; // [sp+18h] [-1FCh] BYREF

  memset(v5, 0, 0x1F4u);
  strcpy(v5, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = get_lan_vlan_data(&v5[29], 471) + 29;
  v3 = snprintf(&v5[v2], 500 - v2, "}}");
  if ( v3 >= 500 - v2 )
    v3 = 499 - v2;
  return httpd_cgi_ret(a1, v5, v3 + v2, 4);
}
// 642164: using guessed type __int16 word_642164;

