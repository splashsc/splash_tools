int __fastcall sub_4C1D58(int a1)
{
  char *v2; // $s1
  char *v3; // $s6
  char *v4; // $s5
  char *v5; // $s4
  char *v6; // $s3
  char *v7; // $s2
  const char *v8; // $v0
  int v9; // $s1
  const char *v10; // $v0
  const char *v11; // $v0
  const char *v12; // $v0
  const char *v13; // $v0
  const char *v14; // $v0
  int v15; // $a0

  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "dianxin_path");
  v4 = httpd_get_parm(a1, "wangtong_path");
  v5 = httpd_get_parm(a1, "yidong_path");
  v6 = httpd_get_parm(a1, "jiaoyu_path");
  v7 = httpd_get_parm(a1, "china_path");
  if ( !v2 || (v8 = (const char *)nvram_get("mr_addr_update_en")) != 0 && !strcmp(v8, v2) )
  {
    v9 = 0;
  }
  else
  {
    nvram_set("mr_addr_update_en", v2);
    v9 = 1;
  }
  if ( v3 )
  {
    v10 = (const char *)nvram_get("dianxin_update_path");
    if ( !v10 || strcmp(v10, v3) )
    {
      nvram_set("dianxin_update_path", v3);
      v9 = 1;
    }
  }
  if ( v4 )
  {
    v11 = (const char *)nvram_get("wangtong_update_path");
    if ( !v11 || strcmp(v11, v4) )
    {
      nvram_set("wangtong_update_path", v4);
      v9 = 1;
    }
  }
  if ( v5 )
  {
    v12 = (const char *)nvram_get("yidong_update_path");
    if ( !v12 || strcmp(v12, v5) )
    {
      nvram_set("yidong_update_path", v5);
      v9 = 1;
    }
  }
  if ( !v6 || (v13 = (const char *)nvram_get("jiaoyu_update_path")) != 0 && !strcmp(v13, v6) )
  {
    if ( !v7 )
      goto LABEL_28;
    v14 = (const char *)nvram_get("china_update_path");
    if ( !v14 )
      goto LABEL_22;
LABEL_27:
    if ( strcmp(v14, v7) )
      goto LABEL_22;
LABEL_28:
    if ( !v9 )
      return mr_addr_update_data(a1);
    goto LABEL_23;
  }
  nvram_set("jiaoyu_update_path", v6);
  if ( v7 )
  {
    v14 = (const char *)nvram_get("china_update_path");
    v9 = 1;
    if ( !v14 )
    {
LABEL_22:
      nvram_set("china_update_path", v7);
      goto LABEL_23;
    }
    goto LABEL_27;
  }
LABEL_23:
  nvram_unset("mr_addr_update_time");
  exec_service("mr_addr_update-restart");
  jhl_parm_commit(v15);
  return mr_addr_update_data(a1);
}
// 4C207C: variable 'v15' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

