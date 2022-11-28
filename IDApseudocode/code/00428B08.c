int __fastcall usb_httpd_send_login_html(int a1)
{
  char *v2; // $v0
  int v3; // $a2
  const char *v4; // $s0
  unsigned int v5; // $v0
  int v6; // $v0
  const char *v7; // $a3
  int v8; // $s0
  int v9; // $s1
  int v10; // $v0
  int v11; // $v0
  int result; // $v0
  const char *v13; // $v0
  unsigned int v14; // $v0
  char v15[1024]; // [sp+20h] [-804h] BYREF
  char v16[1028]; // [sp+420h] [-404h] BYREF

  memset(v16, 0, 0x400u);
  v2 = httpd_find_ext_name(*(const char **)(a1 + 44));
  if ( v2
    && ((v4 = v2, !strcmp(v2, "data"))
     || !strcmp(v4, "asp")
     || !strcmp(v4, (const char *)&off_4CFE60)
     || !strcmp(v4, "txt")
     || !strcmp(v4, (const char *)&off_641118)) )
  {
    v13 = (const char *)_GET_LANG_TEXT(2, *(unsigned __int8 *)(a1 + 210102), v3);
    v14 = snprintf(v16, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 5, v13);
    if ( v14 >= 0x400 )
      v14 = 1023;
    result = httpd_cgi_ret(a1, v16, v14, 4);
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    *(_DWORD *)(a1 + 36) = v5;
    memset(v15, 0, sizeof(v15));
    v6 = snprintf(v15, 1024, "%s%s?", *(const char **)(a1 + 205504), "/usb_login.htm");
    v7 = *(const char **)(a1 + 52);
    v8 = v6;
    if ( v7 )
    {
      v9 = a1 + 56;
      do
      {
        v9 += 4;
        v10 = snprintf(&v15[v8], 1024 - v8, "%s&", v7);
        v7 = *(const char **)(v9 - 4);
        v8 += v10;
      }
      while ( v7 );
    }
    v11 = jiffies_get();
    snprintf(&v15[v8], 1024 - v8, "_t=%lu", v11);
    result = httpd_send_redirect(a1, v15);
  }
  return result;
}
// 428D30: variable 'v3' is possibly undefined
// 4CFE60: using guessed type void *off_4CFE60;
// 641118: using guessed type void *off_641118;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

