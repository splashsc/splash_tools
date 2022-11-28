int __fastcall sub_4A0268(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s5
  const char *v5; // $s1
  const char *v6; // $s2
  const char *v7; // $s4
  const char *v8; // $v0
  int v9; // $s1
  int v10; // $s1
  int v11; // $v0
  int v12; // $a2
  int result; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[1024]; // [sp+28h] [-400h] BYREF

  memset(v16, 0, sizeof(v16));
  _mem_malloc(0x100000, "speed_test_data", 44);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = (const char *)nvram_get("speed_test_en");
    if ( !v4 )
      v4 = "";
    v5 = (const char *)nvram_get("speed_test_iface");
    if ( !v5 )
      v5 = "";
    v6 = (const char *)nvram_get("speed_test_time");
    if ( !v6 )
      v6 = "";
    v7 = (const char *)nvram_get("speed_test_result");
    if ( !v7 )
      v7 = "";
    v8 = (const char *)nvram_get("speed_test_state");
    if ( !v8 )
      v8 = "";
    v9 = sprintf(
           v3 + 29,
           "\"state\":\"%s\",\"iface\":\"%s\",\"time\":\"%s\",\"msg\":\"%s\",\"ret\":\"0\",\"real_state\":\"%s\",\"wans\":",
           v4,
           v5,
           v6,
           v7,
           v8)
       + 29;
    v10 = v9 + get_wans_data(&v3[v9], 0x100000 - v9);
    v11 = snprintf(&v3[v10], 0x100000 - v10, "}}");
    if ( v11 >= 0x100000 - v10 )
      v12 = 0xFFFFF - v10;
    else
      v12 = v11;
    result = httpd_cgi_ret(a1, v3, v12 + v10, 8);
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x100000);
    v15 = snprintf(v16, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v15 >= 0x400 )
      v15 = 1023;
    result = httpd_cgi_ret(a1, v16, v15, 4);
  }
  return result;
}
// 4A02DC: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

