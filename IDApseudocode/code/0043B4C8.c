int __fastcall sub_43B4C8(int a1)
{
  char *v2; // $s3
  char *v3; // $s4
  char *v4; // $s1
  int *v5; // $a2
  const char *v6; // $v0
  char *v7; // $v1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v11; // $a1
  unsigned int v12; // $a2
  const char *v14; // $v0
  uint32_t v15; // $v0
  char v16[1024]; // [sp+20h] [-600h] BYREF
  int v17[128]; // [sp+420h] [-200h] BYREF

  v2 = httpd_get_parm(a1, "ptr");
  v3 = httpd_get_parm(a1, "type");
  v4 = httpd_get_parm(a1, "hi");
  memset(v17, 0, sizeof(v17));
  v17[0] = 13;
  v17[3] = 7;
  v17[1] = 512;
  if ( v3 )
    v17[9] = atoi(v3);
  if ( v4 )
  {
    if ( strchr(v4, 46) || strchr(v4, 58) )
    {
      StrToIpaddr(v4, &v17[4]);
    }
    else
    {
      v15 = J_atoi(v4);
      v17[5] = htonl(v15);
    }
  }
  v5 = &v17[10];
  if ( v2 )
    sscanf(v2, "%lu");
  if ( jianhl_order_opt_fun(v17, v17[1], v5) )
  {
    v14 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    v12 = snprintf(v16, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v12 >= 0x400 )
      v12 = 1023;
  }
  else
  {
    v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v7 = v16;
    do
    {
      v8 = *(_DWORD *)v6;
      v9 = *((_DWORD *)v6 + 1);
      v10 = *((_DWORD *)v6 + 2);
      v11 = *((_DWORD *)v6 + 3);
      v6 += 16;
      *(_DWORD *)v7 = v8;
      *((_DWORD *)v7 + 1) = v9;
      *((_DWORD *)v7 + 2) = v10;
      *((_DWORD *)v7 + 3) = v11;
      v7 += 16;
    }
    while ( v6 != "}" );
    v12 = 33;
    *(_WORD *)v7 = *(_WORD *)v6;
  }
  return httpd_cgi_ret(a1, v16, v12, 4);
}
// 43B5FC: variable 'v5' is possibly undefined
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

