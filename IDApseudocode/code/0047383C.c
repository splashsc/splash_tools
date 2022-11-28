int __fastcall sub_47383C(int a1)
{
  signed int v2; // $s2
  char *v3; // $v0
  char *v4; // $s3
  char *v5; // $v0
  int v6; // $a2
  const char *v7; // $v0
  unsigned int v8; // $v0
  const char *v10; // $v0
  int v11; // $v0
  char v12[1024]; // [sp+20h] [-484h] BYREF
  char v13[132]; // [sp+420h] [-84h] BYREF

  strcpy(v13, "Error reading file");
  memset(&v13[19], 0, 0x6Du);
  v2 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  v4 = v3;
  if ( v3 )
  {
    v2 = *(_DWORD *)(a1 + 205564) + v2 - (_DWORD)v3;
    v5 = find_file_end(a1, v3, v2);
    if ( v5 )
    {
      v2 = v5 - v4;
      if ( v5 - v4 < 10241 )
      {
        *v5 = 0;
        jhl_parm_set("ddate_htm", v4);
        nvram_commit();
        v13[0] = 0;
        goto LABEL_5;
      }
      v11 = _GET_LANG_TEXT(137, *(unsigned __int8 *)(a1 + 210102), 10);
      strlcpy(v13, v11, 128);
    }
    else
    {
      v6 = 5015;
      if ( debug_level > 0 )
        printf("%s:%d find_file_end err \n", "ddatefile_cgi", 5015);
    }
  }
  else
  {
    v6 = 5008;
    if ( debug_level > 0 )
      printf("%s:%d find_file_head err  \n", "ddatefile_cgi", 5008);
  }
  if ( v13[0] )
  {
    if ( write_tg_html_to_usb(v4, v2, "ddatefile") )
    {
      if ( v13[0] )
      {
        v10 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v13);
        v8 = snprintf(v12, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
        if ( v8 < 0x400 )
          return httpd_cgi_ret(a1, v12, v8, 4);
LABEL_13:
        v8 = 1023;
        return httpd_cgi_ret(a1, v12, v8, 4);
      }
    }
    else
    {
      jhl_parm_set("ddate_htm", &off_4CFA50);
      v13[0] = 0;
    }
  }
LABEL_5:
  v7 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v6);
  v8 = snprintf(v12, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v7);
  if ( v8 >= 0x400 )
    goto LABEL_13;
  return httpd_cgi_ret(a1, v12, v8, 4);
}
// 4738E0: variable 'v3' is possibly undefined
// 473964: variable 'v6' is possibly undefined
// 4CFA50: using guessed type void *off_4CFA50;
// 67D0BC: using guessed type int debug_level;
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8338: using guessed type int __fastcall write_tg_html_to_usb(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A87C4: using guessed type int nvram_commit(void);

