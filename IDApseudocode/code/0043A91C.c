int __fastcall sub_43A91C(int a1)
{
  char *v1; // $v0
  int v2; // $a2
  const char *v4; // $s0
  int v5; // $a2
  int v6; // $a2
  int v7; // $a1
  char *v8; // $a2
  uint32_t v9; // $v0
  const char *v10; // $v0
  unsigned int v11; // $a2
  unsigned int v13; // $v0
  int v14; // $s2
  unsigned int v15; // $v0
  const char *v16; // $v0
  unsigned int v17; // $v0
  char v18[2048]; // [sp+48h] [-D94h] BYREF
  int v19[256]; // [sp+848h] [-594h] BYREF
  char v20[200]; // [sp+C48h] [-194h] BYREF
  char v21[204]; // [sp+D10h] [-CCh] BYREF

  v1 = httpd_get_parm(a1, "hi");
  if ( v1 )
  {
    v4 = v1;
    memset(v19, 0, sizeof(v19));
    v19[0] = 13;
    v19[3] = 4;
    v19[1] = 1024;
    if ( strchr(v4, 46) || strchr(v4, 58) )
    {
      StrToIpaddr(v4, &v19[4]);
    }
    else
    {
      v9 = J_atoi(v4);
      v19[5] = htonl(v9);
    }
    if ( jianhl_order_opt_fun(v19, v19[1], v5) )
    {
      v7 = *(unsigned __int8 *)(a1 + 210102);
      v8 = "";
    }
    else
    {
      if ( !v19[2] )
      {
        snprintf(v21, 200, "ALL:%u; TCP:%u; UDP:%u; ICMP:%u; OTHER:%u", v19[12], v19[13], v19[14], v19[15], v19[16]);
        snprintf(v20, 200, "ALL:%u; TCP:%u; UDP:%u; ICMP:%u; OTHER:%u", v19[41], v19[42], v19[43], v19[44], v19[45]);
        strcpy(v18, "{\"code\":0,\"error\":\"\",\"data\":{");
        v13 = snprintf(
                &v18[29],
                2019,
                "\"ctm\":%u,\"ct\":%u,\"zct\":%u,\"ct_max\":\"%s\",\"ddos\":\"%s\",\"totqup\":%u,\"totqupk\":%u,\"totqdw\""
                ":%u,\"totqdwk\":%u,\"zup\":%u,\"qzup\":%u,\"zdw\":%u,\"qzdw\":%u",
                v19[10],
                v19[11],
                v19[19],
                v21,
                v20,
                v19[20],
                v19[22],
                v19[21],
                v19[23],
                v19[24],
                v19[25],
                v19[26],
                v19[27]);
        v14 = v13 + 29;
        if ( v13 >= 0x7E3 )
          v14 = 2047;
        v15 = snprintf(&v18[v14], 2048 - v14, "}}");
        if ( v15 >= 2048 - v14 )
          v15 = 2047 - v14;
        v11 = v15 + v14;
        return httpd_cgi_ret(a1, v18, v11, 4);
      }
      if ( v19[2] == 3 )
      {
        v10 = (const char *)_GET_LANG_TEXT(16, *(unsigned __int8 *)(a1 + 210102), v6);
LABEL_14:
        v11 = snprintf(v18, 2048, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
        if ( v11 >= 0x800 )
          v11 = 2047;
        return httpd_cgi_ret(a1, v18, v11, 4);
      }
      v7 = *(unsigned __int8 *)(a1 + 210102);
      if ( v19[2] >= 0x33u || (v8 = (char *)jhlret_err_str[v19[2]]) == 0 )
        v8 = "not find err!";
    }
    v10 = (const char *)_GET_LANG_TEXT(3, v7, v8);
    goto LABEL_14;
  }
  v16 = (const char *)_GET_LANG_TEXT(16, *(unsigned __int8 *)(a1 + 210102), v2);
  v17 = snprintf(v18, 2048, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
  if ( v17 >= 0x800 )
    v17 = 2047;
  return httpd_cgi_ret(a1, v18, v17, 4);
}
// 43A9D4: variable 'v5' is possibly undefined
// 43ACE0: variable 'v2' is possibly undefined
// 43AD68: variable 'v6' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

