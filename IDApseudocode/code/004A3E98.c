int __fastcall sub_4A3E98(int a1)
{
  char *v2; // $s1
  int v3; // $a0
  const char *v4; // $v0
  char *v5; // $v1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v9; // $a1
  unsigned int v10; // $a2
  int v12; // $s1
  char *v13; // $v0
  const char *v14; // $v0
  char v15[512]; // [sp+20h] [-200h] BYREF

  v2 = httpd_get_parm(a1, "exec_service");
  if ( save_variables(a1, 0) )
  {
    if ( save_variables(a1, 1) )
      jhl_parm_commit(v3);
    if ( v2 )
    {
      if ( !strcmp(v2, "upnp-restart") )
      {
        exec_service("upnp-restart");
      }
      else if ( !strcmp(v2, "firewall-restart") )
      {
        exec_service("firewall-restart");
      }
      else if ( !strcmp(v2, "telnetd-start") )
      {
        exec_service("telnetd-start");
      }
      else if ( !strcmp(v2, "telnetd-stop") )
      {
        exec_service("telnetd-stop");
      }
    }
    v4 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v5 = v15;
    do
    {
      v6 = *(_DWORD *)v4;
      v7 = *((_DWORD *)v4 + 1);
      v8 = *((_DWORD *)v4 + 2);
      v9 = *((_DWORD *)v4 + 3);
      v4 += 16;
      *(_DWORD *)v5 = v6;
      *((_DWORD *)v5 + 1) = v7;
      *((_DWORD *)v5 + 2) = v8;
      *((_DWORD *)v5 + 3) = v9;
      v5 += 16;
    }
    while ( v4 != "}" );
    v10 = 33;
    *(_WORD *)v5 = *(_WORD *)v4;
  }
  else
  {
    v12 = *(unsigned __int8 *)(a1 + 210102);
    v13 = resmsg_get();
    v14 = (const char *)_GET_LANG_TEXT(12, v12, v13);
    v10 = snprintf(v15, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v10 >= 0x200 )
      v10 = 511;
  }
  return httpd_cgi_ret(a1, v15, v10, 4);
}
// 4A40A4: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

