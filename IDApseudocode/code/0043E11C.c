int __fastcall sub_43E11C(int a1)
{
  char *v2; // $s1
  const char *v3; // $v0
  int v4; // $s2
  unsigned int v5; // $v0
  char v7[1024]; // [sp+18h] [-804h] BYREF
  char v8[1028]; // [sp+418h] [-404h] BYREF

  memset(v8, 0, 0x400u);
  memset(v7, 0, sizeof(v7));
  f_read("/proc/modules", v7, 1024);
  v2 = strstr(v7, "wys_sfe");
  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v3 = (const char *)jhl_nv_get_def("sfe_enable");
  v4 = sprintf(&v8[29], "\"en\":\"%s\",\"state\":\"%d\"", v3, v2 != 0) + 29;
  v5 = snprintf(&v8[v4], 1024 - v4, "}}");
  if ( v5 >= 1024 - v4 )
    v5 = 1023 - v4;
  return httpd_cgi_ret(a1, v8, v5 + v4, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);

