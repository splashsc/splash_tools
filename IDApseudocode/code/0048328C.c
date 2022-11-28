int __fastcall sub_48328C(int a1)
{
  char *v1; // $v0
  const char *v3; // $s0
  char *v4; // $s1
  char *v5; // $s0
  const char *v6; // $v0
  unsigned int v7; // $v0
  int v8; // $s0
  unsigned int v9; // $v0
  int v11; // $a0
  char v12[516]; // [sp+20h] [-204h] BYREF

  v1 = httpd_get_parm(a1, "opt");
  if ( !v1 )
    goto LABEL_4;
  v3 = v1;
  if ( !strcmp(v1, "get") )
  {
    v5 = (char *)nvram_get("tzk_time");
    if ( !v5 )
      v5 = "";
    v4 = (char *)nvram_get("tzk_name");
    if ( !v4 )
      v4 = "";
  }
  else
  {
    if ( strcmp(v3, "set") )
    {
LABEL_4:
      v4 = 0;
      v5 = 0;
      goto LABEL_5;
    }
    v5 = httpd_get_parm(a1, "time");
    v4 = httpd_get_parm(a1, "name");
    if ( v5 )
    {
      nvram_set("tzk_time", v5);
    }
    else
    {
      v5 = (char *)nvram_get("tzk_time");
      if ( !v5 )
        v5 = "";
    }
    if ( v4 )
    {
      nvram_set("tzk_name", v4);
    }
    else
    {
      v4 = (char *)nvram_get("tzk_name");
      if ( !v4 )
        v4 = "";
    }
    jhl_parm_commit(v11);
  }
LABEL_5:
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  v6 = (const char *)custom_device_name();
  v7 = snprintf(&v12[29], 483, "\"tzktime\":\"%s\",\"tzkname\":\"%s\",\"JHL_ROUTER_MODEL\":\"%s\"", v5, v4, v6);
  v8 = v7 + 29;
  if ( v7 >= 0x1E3 )
    v8 = 511;
  v9 = snprintf(&v12[v8], 512 - v8, "}}");
  if ( v9 >= 512 - v8 )
    v9 = 511 - v8;
  return httpd_cgi_ret(a1, v12, v9 + v8, 4);
}
// 4834EC: variable 'v11' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

