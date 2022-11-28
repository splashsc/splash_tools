int __fastcall sub_45C558(int a1)
{
  char *v2; // $s1
  int v3; // $a0
  const char *v4; // $v0
  const char *v5; // $v0
  char *v6; // $v1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  int v10; // $a1
  unsigned int v11; // $a2
  int v13; // $s1
  char *v14; // $v0
  const char *v15; // $v0
  char *v16; // $v0
  int v17; // $v0
  int v18; // $a0
  char v19[512]; // [sp+20h] [-200h] BYREF

  v2 = httpd_get_parm(a1, "time_type");
  if ( save_variables(a1, 0) )
  {
    if ( save_variables(a1, 1) )
      jhl_parm_commit(v3);
    if ( v2 )
    {
      if ( *v2 )
      {
        nvram_set("time_type", v2);
        jhl_parm_commit(v18);
      }
      if ( !strcmp(v2, "hand") )
      {
        v16 = httpd_get_parm(a1, "time_string");
        if ( v16 )
        {
          v17 = J_atoi(v16);
          set_systime(v17);
        }
      }
    }
    v4 = (const char *)nvram_get("time_type");
    if ( v4 && !strcmp(v4, "hand") )
      exec_service("ntpc-stop");
    else
      exec_service("ntpc-restart");
    v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v6 = v19;
    do
    {
      v7 = *(_DWORD *)v5;
      v8 = *((_DWORD *)v5 + 1);
      v9 = *((_DWORD *)v5 + 2);
      v10 = *((_DWORD *)v5 + 3);
      v5 += 16;
      *(_DWORD *)v6 = v7;
      *((_DWORD *)v6 + 1) = v8;
      *((_DWORD *)v6 + 2) = v9;
      *((_DWORD *)v6 + 3) = v10;
      v6 += 16;
    }
    while ( v5 != "}" );
    v11 = 33;
    *(_WORD *)v6 = *(_WORD *)v5;
  }
  else
  {
    v13 = *(unsigned __int8 *)(a1 + 210102);
    v14 = resmsg_get();
    v15 = (const char *)_GET_LANG_TEXT(12, v13, v14);
    v11 = snprintf(v19, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
    if ( v11 >= 0x200 )
      v11 = 511;
  }
  return httpd_cgi_ret(a1, v19, v11, 4);
}
// 45C774: variable 'v3' is possibly undefined
// 45C7FC: variable 'v18' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84F0: using guessed type int __fastcall set_systime(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

