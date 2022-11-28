int __fastcall sub_4C0BFC(int a1)
{
  char *v2; // $v0
  int v3; // $a2
  const char *v4; // $a2
  const char *v5; // $v0
  unsigned int v6; // $a2
  int v8; // $a1
  char *v9; // $a2
  int v10; // $a0
  const char *v11; // $v0
  unsigned int v12; // $v0
  int v13; // $s3
  unsigned int v14; // $v0
  int v15[256]; // [sp+20h] [-504h] BYREF
  char v16[260]; // [sp+420h] [-104h] BYREF

  memset(v15, 0, sizeof(v15));
  v2 = httpd_get_parm(a1, "ip");
  if ( v2 )
  {
    v15[0] = 10;
    v15[3] = 11;
    v15[1] = 1024;
    v15[4] = get_ip_from_str(v2);
    if ( v15[4] )
    {
      if ( !jianhl_order_opt_fun(v15, v15[1], v3) )
      {
        if ( v15[2] )
        {
          if ( v15[2] >= 0x33u || (v4 = (const char *)jhlret_err_str[v15[2]]) == 0 )
            v4 = "not find err!";
          v5 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v4);
          v6 = snprintf(v16, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v5);
          if ( v6 >= 0x100 )
            v6 = 255;
        }
        else
        {
          strcpy(v16, "{\"code\":0,\"error\":\"\",\"data\":{");
          v13 = sprintf(&v16[29], "\"type\":%d", LOBYTE(v15[5])) + 29;
          v14 = snprintf(&v16[v13], 256 - v13, "}}");
          if ( v14 >= 256 - v13 )
            v14 = 255 - v13;
          v6 = v14 + v13;
        }
        return httpd_cgi_ret(a1, v16, v6, 4);
      }
      v8 = *(unsigned __int8 *)(a1 + 210102);
      v9 = "";
      v10 = 3;
    }
    else
    {
      v8 = *(unsigned __int8 *)(a1 + 210102);
      v9 = "ip error";
      v10 = 12;
    }
  }
  else
  {
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = "not ip";
    v10 = 12;
  }
  v11 = (const char *)_GET_LANG_TEXT(v10, v8, v9);
  v12 = snprintf(v16, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
  if ( v12 >= 0x100 )
    v12 = 255;
  return httpd_cgi_ret(a1, v16, v12, 4);
}
// 4C0CA0: variable 'v3' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8748: using guessed type int __fastcall get_ip_from_str(_DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

