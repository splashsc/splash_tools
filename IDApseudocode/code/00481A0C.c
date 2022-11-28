int __fastcall sub_481A0C(int a1)
{
  char *v2; // $s3
  char *v3; // $v0
  char *v4; // $s2
  const char *v5; // $s0
  const char *v6; // $v0
  char *v7; // $v1
  int v8; // $t1
  int v9; // $t0
  int v10; // $a3
  int v11; // $a2
  const char *v13; // $v0
  int v14; // $s3
  const char *v15; // $v0
  int v16; // $a0
  char v17[516]; // [sp+18h] [-204h] BYREF

  v2 = httpd_get_parm(a1, "enable");
  v4 = httpd_get_parm(a1, "time");
  v3 = httpd_get_parm(a1, "opt");
  if ( !v3 )
  {
    if ( v2 )
    {
      v13 = (const char *)nvram_get(&unk_649DB8);
      if ( v13 && !strcmp(v13, v2) )
      {
        if ( !v4 )
          goto LABEL_5;
        v14 = 0;
      }
      else
      {
        nvram_set(&unk_649DB8, v2);
        v14 = 1;
        if ( !v4 )
        {
LABEL_16:
          start_module_upgrade_auto();
          jhl_parm_commit(v16);
          goto LABEL_5;
        }
      }
    }
    else
    {
      if ( !v4 )
        goto LABEL_5;
      v14 = 0;
    }
    v15 = (const char *)nvram_get("filter_auto_upgrade_time2");
    if ( v15 && !strcmp(v15, v4) )
    {
      if ( !v14 )
        goto LABEL_5;
    }
    else
    {
      nvram_set("filter_auto_upgrade_time2", v4);
    }
    goto LABEL_16;
  }
  v5 = v3;
  if ( !strcmp(v3, "insmod") )
  {
    load_module("wys_pg2.ko");
    wys_sj_module_add();
    exec_service("shibie_fbr_check-restart");
  }
  else if ( !strcmp(v5, "rmmod") )
  {
    wys_sj_module_del();
    system("rmmod wys_pg2.ko");
    exec_service("shibie_fbr_check-stop");
  }
LABEL_5:
  v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v7 = v17;
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
  *(_WORD *)v7 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 481CC0: variable 'v16' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8378: using guessed type int wys_sj_module_add(void);
// 6A8428: using guessed type int start_module_upgrade_auto(void);
// 6A8458: using guessed type int __fastcall load_module(_DWORD);
// 6A88FC: using guessed type int wys_sj_module_del(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

