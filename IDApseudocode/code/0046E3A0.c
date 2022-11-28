int __fastcall sub_46E3A0(int a1)
{
  const char *v2; // $s0
  const char *v3; // $v0
  unsigned int v4; // $v0
  int v5; // $s0
  unsigned int v6; // $v0
  char v8[1028]; // [sp+20h] [-404h] BYREF

  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("billing_rid");
  v3 = (const char *)nvram_get("agent_host");
  if ( !v3 )
    v3 = "";
  v4 = snprintf(&v8[29], 995, "\"ret\":0,\"rid\":\"%s\",\"srv\":\"%s\"", v2, v3);
  v5 = v4 + 29;
  if ( v4 >= 0x3E3 )
    v5 = 1023;
  v6 = snprintf(&v8[v5], 1024 - v5, "}}");
  if ( v6 >= 1024 - v5 )
    v6 = 1023 - v5;
  return httpd_cgi_ret(a1, v8, v6 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

