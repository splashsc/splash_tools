int __fastcall sub_492BA4(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  const char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s3
  const char *v7; // $v0
  int v8; // $a0

  v3 = httpd_get_parm(a1, "enable");
  v2 = httpd_get_parm(a1, "srv_path");
  v4 = v2;
  if ( v3 )
  {
    v5 = (const char *)nvram_get("dns_more_check_en");
    if ( !v5 || strcmp(v5, v3) )
    {
      nvram_set("dns_more_check_en", v3);
      v6 = 1;
      if ( !v4 )
      {
LABEL_8:
        exec_service("dns_more_check-restart");
        jhl_parm_commit(v8);
        return dns_more_check_data(a1);
      }
LABEL_5:
      v7 = (const char *)nvram_get("dns_more_check_path2");
      if ( v7 && !strcmp(v7, v4) )
      {
        if ( !v6 )
          return dns_more_check_data(a1);
      }
      else
      {
        nvram_set("dns_more_check_path2", v4);
      }
      goto LABEL_8;
    }
    if ( !v4 )
      return dns_more_check_data(a1);
LABEL_11:
    v6 = 0;
    goto LABEL_5;
  }
  if ( v2 )
    goto LABEL_11;
  return dns_more_check_data(a1);
}
// 492CD8: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

