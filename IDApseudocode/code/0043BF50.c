int __fastcall sub_43BF50(int a1)
{
  char *v1; // $v0
  char *v3; // $s0
  int v4; // $s4
  char *v5; // $v0
  char *v6; // $s0
  int v7; // $a2
  const char *v8; // $v0
  unsigned int v9; // $a2
  int result; // $v0
  int v11; // $v0
  int v12; // $s1
  int v13; // $s4
  int v14; // $v0
  const char *v15; // $v0
  unsigned int v16; // $v0
  _QWORD v17[128]; // [sp+58h] [-400h] BYREF

  v1 = httpd_get_parm(a1, "iface");
  if ( v1 )
  {
    v3 = v1;
    LOWORD(v4) = 0;
    if ( strcmp(v1, "all") )
    {
      v4 = J_atoi(v3);
      if ( v4 < 101 )
        LOWORD(v4) = v4 + 1;
    }
  }
  else
  {
    LOWORD(v4) = 2;
  }
  _mem_malloc(102400, "wanll_tu_data", 364);
  v6 = v5;
  if ( v5 )
  {
    memset(v17, 0, sizeof(v17));
    v17[0] = 0x4000000000ELL;
    HIDWORD(v17[1]) = 4;
    LOWORD(v17[4]) = v4;
    if ( jianhl_order_opt_fun(v17, 1024, v7) )
    {
      v8 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
      v9 = snprintf((char *)v17, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
      if ( v9 >= 0x400 )
        v9 = 1023;
    }
    else
    {
      strcpy(v6, "{\"code\":0,\"error\":\"\",\"data\":{");
      qmemcpy(v6, "{\"code\":0,\"error", 16);
      v11 = snprintf(
              v6 + 29,
              102371,
              "\"totup\":%llu,\"totqup\":%llu,\"totupk\":%lu,\"totqupk\":%lu,\"totdw\":%llu,\"totqdw\":%llu,\"totdwk\":%l"
              "u,\"totqdwk\":%lu,\"zup\":%lu,\"zdw\":%lu,\"qzup\":%lu,\"qzdw\":%lu",
              v17[8],
              v17[16],
              LODWORD(v17[9]),
              LODWORD(v17[17]),
              v17[10],
              v17[18],
              LODWORD(v17[11]),
              LODWORD(v17[19]),
              LODWORD(v17[5]),
              HIDWORD(v17[5]),
              LODWORD(v17[7]),
              HIDWORD(v17[7]));
      if ( v11 >= 102371 )
        v11 = 102370;
      v12 = v11 + 29;
      v13 = 102400 - (v11 + 29);
      v14 = snprintf(&v6[v11 + 29], v13, "}}");
      if ( v14 >= v13 )
        v14 = 102399 - v12;
      v9 = v14 + v12;
    }
    result = httpd_cgi_ret(a1, v6, v9, 8);
  }
  else
  {
    v15 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v16 = snprintf((char *)v17, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
    if ( v16 >= 0x400 )
      v16 = 1023;
    result = httpd_cgi_ret(a1, (char *)v17, v16, 4);
  }
  return result;
}
// 43BFE0: variable 'v5' is possibly undefined
// 43C024: variable 'v7' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

