int __fastcall sub_4AE1D4(int a1)
{
  int v2; // $v0
  char *v3; // $s1
  int v4; // $s0
  int v5; // $a2
  int v6; // $v0
  int v7; // $a2
  bool v8; // dc
  __int16 v9; // $v0
  int v10; // $v0
  _BOOL4 v11; // $v1
  int v12; // $a2
  int result; // $v0
  int v14; // $v0
  int v15; // $v0
  const char *v16; // $a2
  _DWORD v17[1251]; // [sp+18h] [-138Ch] BYREF

  v3 = httpd_get_parm(a1, "num");
  _mem_malloc(102400, "errinfo_htm", 833);
  if ( v2 )
  {
    v4 = v2;
    memset(v17, 0, 0x1388u);
    v5 = 3;
    if ( v3 )
    {
      v6 = memcmp(v3, "mem", 3u);
      v7 = 4;
      if ( !v6 )
      {
        v9 = 1;
LABEL_5:
        v17[0] = 1;
        v17[3] = 8;
        LOWORD(v17[4]) = v9;
        v17[1] = 5000;
        v17[5] = 4976;
        if ( !jianhl_order_opt_fun(v17, 5000, v7) )
        {
          v10 = v17[2];
          v11 = v17[2] < 0x33u;
          if ( !v17[2] )
          {
            if ( HIWORD(v17[4]) >= 2u )
            {
LABEL_8:
              v12 = sprintf((char *)v4, "%s", (const char *)&v17[6]);
              return httpd_cgi_ret(a1, (char *)v4, v12, 8);
            }
LABEL_14:
            v12 = 9;
            *(_DWORD *)v4 = 544501614;
            *(_DWORD *)v4 = 544501614;
            *(_DWORD *)(v4 + 4) = 1868983913;
            *(_BYTE *)(v4 + 8) = 10;
            *(_BYTE *)(v4 + 9) = 0;
            return httpd_cgi_ret(a1, (char *)v4, v12, 8);
          }
          goto LABEL_15;
        }
LABEL_18:
        result = 11;
        strcpy((char *)v4, "get opt err");
        *(_DWORD *)v4 = 544499047;
        *(_DWORD *)(v4 + 4) = 544501871;
        return result;
      }
      v8 = memcmp(v3, "cache", 4u) != 0;
      v9 = 2;
      if ( !v8 )
        goto LABEL_5;
      v14 = atoi(v3);
    }
    else
    {
      v14 = 0;
    }
    v17[3] = 5;
    v17[0] = 1;
    v17[1] = 5000;
    v17[4] = v14;
    if ( !jianhl_order_opt_fun(v17, 5000, v5) )
    {
      v10 = v17[2];
      v11 = v17[2] < 0x33u;
      if ( !v17[2] )
      {
        if ( v17[5] == 1 )
          goto LABEL_8;
        goto LABEL_14;
      }
LABEL_15:
      v15 = v10;
      if ( !v11 || (v16 = (const char *)jhlret_err_str[v15]) == 0 )
        v16 = "not find err!";
      v12 = sprintf((char *)v4, "err:%s \n", v16);
      return httpd_cgi_ret(a1, (char *)v4, v12, 8);
    }
    goto LABEL_18;
  }
  strcpy((char *)v17, "malloc err\n");
  return httpd_cgi_ret(a1, (char *)v17, 11, 4);
}
// 4AE238: variable 'v2' is possibly undefined
// 4AE2D0: variable 'v7' is possibly undefined
// 4AE390: variable 'v5' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

