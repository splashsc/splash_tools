int __fastcall sub_4557F4(int a1)
{
  char *v1; // $v0
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $s0
  char *v5; // $s6
  char *v6; // $s7
  const char *v7; // $s2
  int v8; // $fp
  int v9; // $s1
  uint32_t v10; // $v0
  int v11; // $t1
  int v12; // $v0
  char *v13; // $a0
  unsigned int v14; // $s2
  unsigned int v15; // $v0
  int result; // $v0
  const char *v17; // $v0
  unsigned int v18; // $s1
  int v19; // $a2
  const char *v20; // $v0
  unsigned int v21; // $v0
  char v22[128]; // [sp+20h] [-88h] BYREF
  int v23; // [sp+A0h] [-8h]

  _mem_malloc(1024000, "shibie_app_data", 162);
  v4 = v3;
  _mem_malloc(1024000, "shibie_app_data", 163);
  v5 = v1;
  if ( !v4 || !v1 )
  {
    _mem_free(v4);
    _mem_free(v5);
    v20 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v21 = snprintf(v22, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
    if ( v21 >= 0x80 )
      result = httpd_cgi_ret(a1, v22, 127, 4);
    else
      result = httpd_cgi_ret(a1, v22, v21, 4);
    return result;
  }
  *(_DWORD *)v1 = 34;
  *((_DWORD *)v1 + 3) = 8;
  *((_DWORD *)v1 + 1) = 1024000;
  if ( !jianhl_order_opt_fun(v1, 1024000, v2) )
  {
    strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v4, "{\"code\":0,\"error", 16);
    v6 = v4 + 29;
    if ( *((int *)v5 + 5) <= 0 )
    {
      _mem_free(v5);
      v9 = 29;
      v12 = 28;
      v11 = 29;
    }
    else
    {
      v7 = v5 + 28;
      v8 = 0;
      v9 = 29;
      do
      {
        ++v8;
        v10 = ntohl(*((_DWORD *)v7 - 1));
        v9 += sprintf(v6, "{\"n\":\"%s\",\"id\":\"%08x\"},", v7, v10);
        v6 = &v4[v9];
        if ( v8 >= *((_DWORD *)v5 + 5) )
          break;
        v7 += 68;
      }
      while ( (unsigned int)(1024000 - v9) >= 0xC8 );
      v23 = v9;
      _mem_free(v5);
      v11 = v9;
      v12 = v9 - 1;
      if ( v9 <= 0 )
      {
        v13 = &v4[v9];
LABEL_12:
        v14 = 1024000 - v11;
        v23 = v11;
        *v13 = 0;
        v15 = snprintf(v13, 1024000 - v11, "]}");
        if ( v15 >= v14 )
          v15 = 1023999 - v23;
        return httpd_cgi_ret(a1, v4, v23 + v15, 8);
      }
    }
    if ( v4[v12] == 44 )
      v11 = v9 - 1;
    v13 = &v4[v11];
    goto LABEL_12;
  }
  v17 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
  v18 = snprintf(v22, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
  _mem_free(v5);
  v19 = v18;
  if ( v18 >= 0x80 )
    v19 = 127;
  return httpd_cgi_ret(a1, v4, v19, 8);
}
// 455868: variable 'v3' is possibly undefined
// 455874: variable 'v1' is possibly undefined
// 45589C: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

