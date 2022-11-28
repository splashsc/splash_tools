int __fastcall upnp_data_send(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  int v5; // $s1
  char *v6; // $v1
  int v7; // $s1
  int v8; // $v0
  int v9; // $a2
  int result; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(1024000, "upnp_data_send", 546);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"upnnp_data\":[");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = format_upnp_state_data(v2 + 42, 1023958);
    v5 = v4 + 42;
    v6 = &v3[v4 + 42];
    if ( v4 + 42 > 0 && *(v6 - 1) == 44 )
    {
      v5 = v4 + 41;
      v6 = &v3[v4 + 41];
    }
    v7 = v5 + 1;
    *(_WORD *)v6 = 93;
    v8 = snprintf(&v3[v7], 1024000 - v7, "}}");
    if ( v8 >= 1024000 - v7 )
      v9 = 1023999 - v7;
    else
      v9 = v8;
    result = httpd_cgi_ret(a1, v3, v9 + v7, 8);
  }
  else
  {
    v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v12 = snprintf(v13, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x100 )
      v12 = 255;
    result = httpd_cgi_ret(a1, v13, v12, 4);
  }
  return result;
}
// 4A5650: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

