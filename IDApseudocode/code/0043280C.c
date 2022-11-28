int __fastcall httpd_send_login_html(int a1)
{
  unsigned int v2; // $v0
  unsigned __int8 *v3; // $s0
  char *v4; // $v0
  int v5; // $s1
  const char *v6; // $a0
  int v7; // $a2
  const char *v8; // $s0
  const char *v9; // $v0
  unsigned int v10; // $v0
  int result; // $v0
  const char *v12; // $s0
  int v13; // $v0
  int v14; // $s0
  const char *v15; // $a3
  int i; // $s1
  int v17; // $v0
  int v18; // $v0
  char v19[1028]; // [sp+20h] [-404h] BYREF

  v2 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
  *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
  *(_DWORD *)(a1 + 36) = v2;
  memset(v19, 0, 0x400u);
  v3 = (unsigned __int8 *)(*(_DWORD *)(a1 + 44) + 1);
  v5 = get_name_hash(v3);
  v4 = httpd_find_ext_name(*(const char **)(a1 + 44));
  v6 = (const char *)v3;
  v8 = v4;
  if ( httpd_find_ext_file(v6, v5)
    || v8
    && (!strcmp(v8, "data")
     || !strcmp(v8, "asp")
     || !strcmp(v8, (const char *)&off_4CFE60)
     || !strcmp(v8, "txt")
     || !strcmp(v8, (const char *)&off_641118)) )
  {
    v9 = (const char *)_GET_LANG_TEXT(2, *(unsigned __int8 *)(a1 + 210102), v7);
    v10 = snprintf(v19, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 2, v9);
    if ( v10 >= 0x400 )
      v10 = 1023;
    result = httpd_cgi_ret(a1, v19, v10, 4);
  }
  else
  {
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v12 = *(const char **)(a1 + 205504);
      v13 = nvram_get_int("https_lanport");
      v14 = snprintf(v19, 1024, "https://%s:%d%s?", v12, v13, "/login.html");
    }
    else
    {
      v14 = snprintf(v19, 1024, "%s%s?", *(const char **)(a1 + 205504), "/login.html");
    }
    v15 = *(const char **)(a1 + 52);
    for ( i = a1 + 56; v15; v14 += v17 )
    {
      i += 4;
      v17 = snprintf(&v19[v14], 1024 - v14, "%s&", v15);
      v15 = *(const char **)(i - 4);
    }
    v18 = jiffies_get();
    snprintf(&v19[v14], 1024 - v14, "_t=%lu", v18);
    result = httpd_send_redirect(a1, v19);
  }
  return result;
}
// 4328DC: variable 'v7' is possibly undefined
// 4CFE60: using guessed type void *off_4CFE60;
// 641118: using guessed type void *off_641118;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

