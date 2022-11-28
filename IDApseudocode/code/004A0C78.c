int __fastcall ping_data(int a1)
{
  char *v2; // $v0
  char *v3; // $fp
  const char *v4; // $s2
  int v5; // $s1
  int v6; // $v0
  char *v7; // $v0
  __pid_t v8; // $s6
  void *v9; // $v0
  int v10; // $v0
  int v11; // $s0
  void *v12; // $s5
  int v13; // $v0
  const char *v14; // $v0
  int v15; // $s1
  size_t v16; // $v0
  size_t v17; // $s1
  int v18; // $v0
  int v19; // $s1
  int result; // $v0
  int v21; // $s2
  unsigned int v22; // $v0
  int v23; // $v0
  const char *v24; // $v0
  int v25; // $v0
  const char *v26; // $v0
  const char *v27; // $v0
  unsigned int v28; // $v0
  char v29[1024]; // [sp+20h] [-480h] BYREF
  char v30[128]; // [sp+420h] [-80h] BYREF

  memset(v30, 0, sizeof(v30));
  v3 = httpd_get_parm(a1, (char *)&off_64CC40);
  v2 = httpd_get_parm(a1, "iface");
  if ( !v2 )
  {
    v5 = 0;
    if ( v3 )
    {
      v8 = J_atoi(v3);
      sprintf(v30, "/tmp/ping/ping_%d", v8);
      v5 = 0;
      v4 = "1";
      if ( v8 > 0 )
      {
LABEL_8:
        _mem_malloc(0x200000, "ping_data", 258);
        v11 = v10;
        _mem_malloc(0x200000, "ping_data", 259);
        v12 = v9;
        if ( v11 && v9 )
        {
          strcpy((char *)v11, "{\"code\":0,\"error\":\"\",\"data\":{");
          qmemcpy((void *)v11, "{\"code\":0,\"error\":\"\"", 20);
          *(_DWORD *)(v11 + 24) = 975331700;
          *((_BYTE *)v9 + f_read(v30, v9, 2097142)) = 0;
          if ( kill(v8, 0) )
          {
            v13 = jhl_nvget("wan_pinggw", v5);
            v14 = (const char *)nvram_get(v13);
            if ( !v14 )
              v14 = (const char *)jhl_get_wangw(v5);
            v15 = sprintf((char *)(v11 + 29), "\"iface\":\"%s\",\"gw\":\"%s\",\"msg\":\"", v4, v14) + 29;
            if ( v3 )
              unlink(v30);
          }
          else
          {
            v25 = jhl_nvget("wan_pinggw", v5);
            v26 = (const char *)nvram_get(v25);
            if ( !v26 )
              v26 = (const char *)jhl_get_wangw(v5);
            v15 = sprintf((char *)(v11 + 29), "\"iface\":\"%s\",\"gw\":\"%s\",\"msg\":\"", v4, v26) + 29;
          }
          get_json_data_safe2(v12, v11 + v15);
          v16 = strlen((const char *)v11);
          v17 = v16 + 1;
          *(_WORD *)(v11 + v16) = 34;
          v18 = snprintf((char *)(v11 + v16 + 1), 0x200000 - (v16 + 1), "}}");
          if ( v18 >= (int)(0x200000 - v17) )
            v18 = 0x1FFFFF - v17;
          v19 = v18 + v17;
          _mem_free(v12);
          result = httpd_cgi_ret(a1, (char *)v11, v19, 8);
        }
        else
        {
          _mem_free((void *)v11);
          _mem_free(v12);
          v27 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
          v28 = snprintf(v29, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
          if ( v28 >= 0x400 )
            v28 = 1023;
          result = httpd_cgi_ret(a1, v29, v28, 4);
        }
        return result;
      }
    }
    else
    {
      v4 = "1";
    }
    goto LABEL_24;
  }
  v4 = v2;
  v5 = J_atoi(v2);
  if ( v5 < 101 )
  {
    if ( v5 > 0 )
      --v5;
    v6 = jhl_nvget(&unk_64CC38, v5);
    v7 = (char *)nvram_get(v6);
    if ( !v7 )
      v7 = "0";
    v8 = J_atoi(v7);
    sprintf(v30, "/tmp/ping/ping_%d_%d", v5, v8);
    if ( v8 > 0 )
      goto LABEL_8;
LABEL_24:
    strcpy(v29, "{\"code\":0,\"error\":\"\",\"data\":{");
    v23 = jhl_nvget("wan_pinggw", v5);
    v24 = (const char *)nvram_get(v23);
    if ( !v24 )
      v24 = (const char *)jhl_get_wangw(v5);
    v21 = sprintf(&v29[29], "\"iface\":\"%s\",\"gw\":\"%s\",\"msg\":\"\"", v4, v24) + 29;
    goto LABEL_19;
  }
  strcpy(v29, "{\"code\":0,\"error\":\"\",\"data\":{");
  v21 = sprintf(&v29[29], "\"iface\":\"%s\",\"gw\":\"\",\"msg\":\"\"", v4) + 29;
LABEL_19:
  v22 = snprintf(&v29[v21], 1024 - v21, "}}");
  if ( v22 >= 1024 - v21 )
    v22 = 1023 - v21;
  return httpd_cgi_ret(a1, v29, v22 + v21, 4);
}
// 4A0DEC: variable 'v10' is possibly undefined
// 4A0DF8: variable 'v9' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64CC40: using guessed type void *off_64CC40;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81FC: using guessed type int __fastcall get_json_data_safe2(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8920: using guessed type int __fastcall jhl_get_wangw(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

