int __fastcall sub_4A5210(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int v5; // $s1
  int v6; // $s1
  int v7; // $v0
  int v8; // $a2
  int result; // $v0
  const char *v10; // $v0
  unsigned int v11; // $v0
  char v12[256]; // [sp+20h] [-11Ch] BYREF
  const char *v13[7]; // [sp+120h] [-1Ch] BYREF

  v13[0] = "dmz_enable";
  v13[1] = "dmz_ipaddr";
  v13[2] = "dmz_sip";
  v13[3] = "dmz_wan";
  v13[4] = "";
  v13[5] = "";
  _mem_malloc(10240, "dmz_data", 491);
  if ( v2 )
  {
    v3 = v2;
    asp_lipp(v12);
    strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v3, "{\"code\":0,\"error\":\"\"", 20);
    v4 = get_nvarms(v13, (int)(v3 + 29), 10211) + 29;
    v5 = v4 + sprintf(&v3[v4], "\"lipp\":\"%s\",\"wans\":", v12);
    v6 = v5 + get_wans_data(&v3[v5], 10240 - v5);
    v7 = snprintf(&v3[v6], 10240 - v6, "}}");
    if ( v7 >= 10240 - v6 )
      v8 = 10239 - v6;
    else
      v8 = v7;
    result = httpd_cgi_ret(a1, v3, v8 + v6, 8);
  }
  else
  {
    v10 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v11 = snprintf(v12, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x100 )
      v11 = 255;
    result = httpd_cgi_ret(a1, v12, v11, 4);
  }
  return result;
}
// 4A5298: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

