int __fastcall sub_4B0240(int a1)
{
  char *v2; // $s1
  char *v3; // $s3
  char *v4; // $s4
  char *v5; // $v0
  char *v6; // $s5
  const char *v7; // $s6
  int v8; // $a0
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  unsigned int v15; // $a2
  int v16; // $a2
  int v17; // $t0
  int v18; // $a3
  int v19; // $a2
  int v20; // $a1
  int v21; // $a1
  const char *v22; // $a2
  const char *v23; // $v0
  char v25[1024]; // [sp+20h] [-400h] BYREF

  v2 = httpd_get_parm(a1, "opt");
  v3 = httpd_get_parm(a1, "path");
  v4 = httpd_get_parm(a1, "time_h");
  v6 = httpd_get_parm(a1, "time_m");
  v5 = httpd_get_parm(a1, "usblogd_en");
  if ( !v2 )
  {
LABEL_17:
    v21 = *(unsigned __int8 *)(a1 + 210102);
    v22 = "not opt";
LABEL_18:
    v23 = (const char *)_GET_LANG_TEXT(12, v21, v22);
    goto LABEL_19;
  }
  v7 = v5;
  if ( strcmp(v2, "del") )
  {
    if ( !strcmp(v2, "set") )
    {
      if ( v4 && v6 && v7 )
      {
        if ( !strcmp(v7, "1") )
          nvram_set("usblogd_en", "1");
        else
          nvram_set("usblogd_en", "0");
        nvram_set("usblog_time_h", v4);
        nvram_set("usblog_time_m", v6);
        jhl_parm_commit(v8);
        usblogd_check_restart();
        v9 = v25;
        v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v11 = *(_DWORD *)v10;
          v12 = *((_DWORD *)v10 + 1);
          v13 = *((_DWORD *)v10 + 2);
          v14 = *((_DWORD *)v10 + 3);
          v10 += 16;
          *(_DWORD *)v9 = v11;
          *((_DWORD *)v9 + 1) = v12;
          *((_DWORD *)v9 + 2) = v13;
          *((_DWORD *)v9 + 3) = v14;
          v9 += 16;
        }
        while ( v10 != "}" );
        goto LABEL_11;
      }
      v21 = *(unsigned __int8 *)(a1 + 210102);
      v22 = (const char *)&unk_64E0EC;
      goto LABEL_18;
    }
    goto LABEL_17;
  }
  if ( !v3 )
  {
    v21 = *(unsigned __int8 *)(a1 + 210102);
    v22 = (const char *)&unk_64E0E0;
    goto LABEL_18;
  }
  if ( !remove(v3) )
  {
    v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v9 = v25;
    do
    {
      v17 = *(_DWORD *)v10;
      v18 = *((_DWORD *)v10 + 1);
      v19 = *((_DWORD *)v10 + 2);
      v20 = *((_DWORD *)v10 + 3);
      v10 += 16;
      *(_DWORD *)v9 = v17;
      *((_DWORD *)v9 + 1) = v18;
      *((_DWORD *)v9 + 2) = v19;
      *((_DWORD *)v9 + 3) = v20;
      v9 += 16;
    }
    while ( v10 != "}" );
LABEL_11:
    v15 = 33;
    *(_WORD *)v9 = *(_WORD *)v10;
    return httpd_cgi_ret(a1, v25, v15, 4);
  }
  v23 = (const char *)_GET_LANG_TEXT(60, *(unsigned __int8 *)(a1 + 210102), v16);
LABEL_19:
  v15 = snprintf(v25, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v23);
  if ( v15 >= 0x400 )
    v15 = 1023;
  return httpd_cgi_ret(a1, v25, v15, 4);
}
// 4B03D8: variable 'v8' is possibly undefined
// 4B0564: variable 'v16' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A894C: using guessed type int usblogd_check_restart(void);

