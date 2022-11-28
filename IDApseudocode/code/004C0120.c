int __fastcall sub_4C0120(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  int v5; // $s2
  int v6; // $s4
  int v7; // $v0
  int v8; // $a2
  int result; // $v0
  const char *v10; // $v0
  unsigned int v11; // $v0
  char v12[256]; // [sp+28h] [-100h] BYREF

  _mem_malloc(1024000, "mr_list_data", 1163);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = cgi_signal_to_kernel(10, 23, 1024000);
    v5 = 1023971 - v4;
    v6 = v4 + 29;
    v7 = snprintf(&v3[v4 + 29], 1023971 - v4, "]}");
    if ( v7 >= v5 )
      v8 = 1023999 - v6;
    else
      v8 = v7;
    result = httpd_cgi_ret(a1, v3, v8 + v6, 8);
  }
  else
  {
    v10 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v11 = snprintf(v12, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x100 )
      v11 = 255;
    result = httpd_cgi_ret(a1, v12, v11, 4);
  }
  return result;
}
// 4C0174: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8764: using guessed type int __fastcall cgi_signal_to_kernel(_DWORD, _DWORD, _DWORD);

