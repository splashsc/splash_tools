int __fastcall sub_498D50(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  __int16 v4; // $v0
  unsigned int v5; // $v0
  int v6; // $a1
  bool v7; // dc
  unsigned int v8; // $v0
  char *v9; // $a2
  int v10; // $a0
  const char *v11; // $v0
  unsigned int v12; // $a2
  char v14[10244]; // [sp+20h] [-2804h] BYREF

  v3 = httpd_get_parm(a1, "s");
  v2 = httpd_get_parm(a1, "opt");
  if ( v2 && !strcmp(v2, "del") )
  {
    if ( v3 )
    {
      v4 = J_atoi(v3);
      v5 = pppoe_opt(0, v4);
      if ( v5 == -1 )
      {
        v6 = *(unsigned __int8 *)(a1 + 210102);
        v9 = "";
        v10 = 3;
      }
      else
      {
        if ( !v5 )
          return pppoe_list_data(a1);
        v6 = *(unsigned __int8 *)(a1 + 210102);
        v7 = v5 >= 0x33;
        v8 = v5;
        if ( v7 || (v9 = (char *)jhlret_err_str[v8]) == 0 )
          v9 = "not find err!";
        v10 = 3;
      }
    }
    else
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v9 = "not sid";
      v10 = 12;
    }
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v9 = "not opt";
    v10 = 12;
  }
  v11 = (const char *)_GET_LANG_TEXT(v10, v6, v9);
  v12 = snprintf(v14, 10240, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
  if ( v12 >= 0x2800 )
    v12 = 10239;
  return httpd_cgi_ret(a1, v14, v12, 4);
}
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

