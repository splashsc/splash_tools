int __fastcall dhcp_detect_list_data_send(int a1)
{
  char *v1; // $v0
  char *v2; // $s1
  int v3; // $a2
  int v4; // $s0
  int *v5; // $fp
  int v6; // $s3
  int v7; // $s7
  const char *v8; // $v0
  int v9; // $v0
  int v10; // $a0
  int v11; // $v0
  char *v12; // $a0
  int v13; // $v0
  int v14; // $a2
  const char *v15; // $v0
  const char *v17; // $v0
  unsigned int v18; // $a2
  int v19[2560]; // [sp+20h] [-2848h] BYREF
  char v20[32]; // [sp+2820h] [-48h] BYREF
  char v21[32]; // [sp+2840h] [-28h] BYREF
  const char *v22; // [sp+2860h] [-8h]

  _mem_malloc(20240, "dhcp_detect_list_data_send", 1575);
  if ( v1 )
  {
    v2 = v1;
    memset(v19, 0, sizeof(v19));
    v19[0] = 5;
    v19[3] = 11;
    v19[1] = 10240;
    if ( jianhl_order_opt_fun(v19, 10240, v3) )
    {
      v15 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
      v14 = snprintf(v2, 20240, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
      if ( v14 >= 20240 )
        v14 = 20239;
      return httpd_cgi_ret(a1, v2, v14, 8);
    }
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = 20211;
    if ( v19[5] <= 0 )
    {
      v11 = 28;
      v10 = 29;
      v7 = 29;
    }
    else
    {
      v5 = &v19[7];
      v6 = 0;
      v7 = 29;
      do
      {
        v22 = (const char *)IpToStr(v21, *(v5 - 1));
        v8 = (const char *)MacToStr(v20, v5);
        v9 = snprintf(&v2[v7], v4, "{\"i\":\"%s\",\"m\":\"%s\"},", v22, v8);
        if ( v9 >= v4 )
          v9 = 20239 - v7;
        v7 += v9;
        ++v6;
        v4 = 20240 - v7;
        if ( v6 >= v19[5] )
          break;
        v5 += 3;
      }
      while ( 20240 - v7 >= 100 );
      v10 = v7;
      if ( v7 <= 0 )
        goto LABEL_13;
      v11 = v7 - 1;
    }
    if ( v2[v11] == 44 )
      v10 = --v7;
LABEL_13:
    v12 = &v2[v10];
    *v12 = 0;
    v13 = snprintf(v12, 20240 - v7, "]}");
    if ( v13 >= 20240 - v7 )
      v13 = 20239 - v7;
    v14 = v7 + v13;
    return httpd_cgi_ret(a1, v2, v14, 8);
  }
  v17 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 20240);
  v18 = snprintf((char *)v19, 10240, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
  if ( v18 >= 0x2800 )
    v18 = 10239;
  return httpd_cgi_ret(a1, (char *)v19, v18, 4);
}
// 4A29B4: variable 'v1' is possibly undefined
// 4A29F8: variable 'v3' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

