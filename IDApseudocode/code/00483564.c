int __fastcall sub_483564(int a1)
{
  char *v2; // $s5
  char *v3; // $s4
  int v4; // $v0
  int v5; // $v0
  int v6; // $a0
  int v7; // $a2
  int v9; // $a1
  const char *v10; // $v0
  int v11; // $s3
  unsigned int v12; // $v0
  _DWORD v13[129]; // [sp+18h] [-204h] BYREF

  v2 = httpd_get_parm(a1, "path");
  v3 = httpd_get_parm(a1, "time");
  nvram_set(&unk_649E44, "");
  nvram_set("tzk_state", "0");
  v4 = jiffies_get();
  mod_timer(a1 + 205540, v4 + 100000);
  v13[0] = "wys";
  v13[1] = "wget";
  v13[2] = "download";
  v13[3] = v2;
  v13[4] = 0;
  eval(v13, 0, 0, 0);
  v5 = nvram_get("tzk_state");
  if ( J_atoi(v5) )
  {
    v9 = *(unsigned __int8 *)(a1 + 210102);
    strcpy((char *)v13, "{\"code\":0,\"error\":\"\",\"data\":{");
    v10 = (const char *)_GET_LANG_TEXT(27, v9, 572668450);
    v11 = sprintf((char *)&v13[7] + 1, "\"ret\":1,\"msg\":\"%s\"", v10) + 29;
    v12 = snprintf((char *)v13 + v11, 512 - v11, "}}");
    if ( v12 >= 512 - v11 )
      v12 = 511 - v11;
    v7 = v12 + v11;
  }
  else
  {
    if ( v3 )
      nvram_set("tzk_time", v3);
    jhl_parm_commit(v6);
    strcpy((char *)v13, "{\"code\":0,\"error\":\"\",\"data\":{\"ret\":0,\"msg\":\"ok\"}}");
    v7 = 49;
  }
  return httpd_cgi_ret(a1, (char *)v13, v7, 4);
}
// 4836EC: variable 'v6' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

