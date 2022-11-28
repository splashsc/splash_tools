int __fastcall sub_470548(int a1)
{
  char *v2; // $s3
  char *v3; // $s2
  char *v4; // $s4
  int v5; // $a2
  int v6; // $a2
  int v7; // $a1
  int v8; // $a0
  const char *v9; // $v0
  const char *v10; // $a2
  unsigned int v11; // $a2
  int v13[256]; // [sp+20h] [-600h] BYREF
  char v14[512]; // [sp+420h] [-200h] BYREF

  v2 = httpd_get_parm(a1, (char *)&off_649194);
  v3 = httpd_get_parm(a1, "old_pwd");
  v4 = httpd_get_parm(a1, "u");
  memset(v13, 0, sizeof(v13));
  v13[0] = 16;
  v13[3] = 51;
  v13[1] = 1024;
  strlcpy(&v13[4], v4, 64);
  strlcpy(&v13[36], v2, 64);
  strlcpy(&v13[20], v3, 64);
  if ( jianhl_order_opt_fun(v13, v13[1], v5) )
  {
    v9 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
  }
  else
  {
    if ( !v13[2] )
    {
      if ( v13[62] == 1 )
      {
        v7 = *(unsigned __int8 *)(a1 + 210102);
        v8 = 78;
        goto LABEL_8;
      }
      if ( v13[62] < 2 )
      {
        if ( !v13[62] )
        {
          v7 = *(unsigned __int8 *)(a1 + 210102);
          v8 = 79;
          goto LABEL_8;
        }
      }
      else
      {
        if ( v13[62] == 2 )
        {
          v7 = *(unsigned __int8 *)(a1 + 210102);
          v8 = 76;
          goto LABEL_8;
        }
        if ( v13[62] == 13 )
        {
          v7 = *(unsigned __int8 *)(a1 + 210102);
          v8 = 77;
LABEL_8:
          v9 = (const char *)_GET_LANG_TEXT(v8, v7, v6);
          goto LABEL_13;
        }
      }
      v7 = *(unsigned __int8 *)(a1 + 210102);
      v8 = 80;
      goto LABEL_8;
    }
    if ( v13[2] >= 0x33u || (v10 = (const char *)jhlret_err_str[v13[2]]) == 0 )
      v10 = "not find err!";
    v9 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v10);
  }
LABEL_13:
  v11 = snprintf(v14, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
  if ( v11 >= 0x200 )
    v11 = 511;
  return httpd_cgi_ret(a1, v14, v11, 4);
}
// 470650: variable 'v5' is possibly undefined
// 4706B0: variable 'v6' is possibly undefined
// 649194: using guessed type char *off_649194;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

