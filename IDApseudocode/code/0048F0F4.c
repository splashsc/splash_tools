int __fastcall sub_48F0F4(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  char *v4; // $s0
  const char *v5; // $s3
  const char *v6; // $s5
  int v7; // $s1
  int v8; // $s1
  char *v9; // $v0
  int v10; // $s1
  int v11; // $v0
  int v12; // $a2
  const char *v14; // $v0
  int v15; // $v0
  int v16; // $a3
  const char *v17; // $v0
  char v18[260]; // [sp+20h] [-104h] BYREF

  v3 = httpd_get_parm(a1, "id");
  _mem_malloc(1024000, "vpn_user_data", 1315);
  if ( !v2 )
  {
    v17 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v4 = v18;
    v15 = snprintf(v18, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
    if ( (unsigned int)v15 >= 0x100 )
      v15 = 255;
    v16 = 4;
    return httpd_cgi_ret(a1, v4, v15, v16);
  }
  v4 = v2;
  if ( !v3 )
    goto LABEL_13;
  if ( strcmp(v3, "pptp") )
  {
    if ( !strcmp(v3, "l2tp") )
    {
      v5 = "l2tp_vpn_users_st";
      v6 = "l2tp_vpn_users";
      goto LABEL_5;
    }
    if ( strcmp(v3, "pptp_l2tp") )
    {
LABEL_13:
      v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "error type");
      v15 = snprintf(v4, 1024000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
      if ( v15 >= 1024000 )
        v15 = 1023999;
      v16 = 8;
      return httpd_cgi_ret(a1, v4, v15, v16);
    }
  }
  v5 = "pptp_vpn_users_st";
  v6 = "pptp_vpn_users";
LABEL_5:
  strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":", 28);
  v7 = sprintf(v4 + 29, "\"vpn_type\":\"%s\",\"all\":", "all") + 29;
  v8 = v7 + get_vpn_user_data((int)v6, &v4[v7], 1024000 - v7);
  v9 = &v4[v8];
  strcpy(&v4[v8], ",\"state\":");
  *(_DWORD *)v9 = 1953702444;
  *((_DWORD *)v9 + 1) = 577074273;
  v10 = v8 + 9 + get_vpn_user_state_data((int)v5, &v4[v8 + 9], 1024000 - (v8 + 9));
  v11 = snprintf(&v4[v10], 1024000 - v10, "}}");
  if ( v11 >= 1024000 - v10 )
    v12 = 1023999 - v10;
  else
    v12 = v11;
  return httpd_cgi_ret(a1, v4, v12 + v10, 8);
}
// 48F160: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

