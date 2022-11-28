int __fastcall sub_45F604(int a1)
{
  char *v2; // $s3
  char *v3; // $s2
  char *v4; // $v0
  char *v5; // $s4
  const char *v6; // $s5
  int v7; // $a2
  const char *v8; // $v0
  unsigned int v9; // $a2
  int v11; // $v0
  int v12; // $a0
  const char *v13; // $v0
  char *v14; // $v0
  const char **v15; // $v1
  const char *v16; // $v0
  const char *v17; // $t0
  const char *v18; // $a3
  const char *v19; // $a2
  const char *v20; // $a1
  char v21[2048]; // [sp+20h] [-C28h] BYREF
  const char *v22; // [sp+820h] [-428h] BYREF
  const char *v23; // [sp+824h] [-424h]
  char *v24; // [sp+828h] [-420h]
  void *v25; // [sp+82Ch] [-41Ch]
  char *v26; // [sp+830h] [-418h]
  int v27; // [sp+834h] [-414h]
  int v28; // [sp+838h] [-410h]
  int v29; // [sp+83Ch] [-40Ch]
  int v30; // [sp+840h] [-408h]
  char *v31; // [sp+844h] [-404h]
  int v32; // [sp+848h] [-400h]
  int v33[5]; // [sp+C20h] [-28h] BYREF
  int v34; // [sp+C34h] [-14h] BYREF
  int v35; // [sp+C38h] [-10h]
  int v36; // [sp+C3Ch] [-Ch]
  int v37; // [sp+C40h] [-8h]

  memset(v21, 0, sizeof(v21));
  v33[0] = 0;
  v33[1] = 0;
  v33[2] = 0;
  v33[3] = 0;
  v33[4] = 0;
  v2 = httpd_get_parm(a1, "fy_en");
  v3 = httpd_get_parm(a1, "fy_rule");
  v5 = httpd_get_parm(a1, "fy_type");
  v4 = httpd_get_parm(a1, "maclist");
  if ( v3 && v2 )
  {
    v6 = v4;
    strlcpy(v21, v3, 2048);
    split_string(v21, 124, &v34, 4);
    if ( J_atoi(v35) && J_atoi(v36) && J_atoi(v37) )
    {
      v11 = J_atoi(v5);
      sprintf((char *)v33, "ddos_fy_rule%d", v11);
      nvram_set(v33, v3);
      nvram_set("ddos_fy_en", v2);
      if ( v6 )
      {
        v13 = (const char *)nvram_get(&unk_646654);
        if ( !v13 || strcmp(v13, v6) )
        {
          nvram_set(&unk_646654, v6);
          v22 = "wys";
          v23 = "ddos_fy";
          v24 = "mac_set";
          v25 = (void *)v6;
          v26 = 0;
          eval(&v22, 0, 0, 0);
        }
      }
      jhl_parm_commit(v12);
      v22 = "wys";
      v24 = "set";
      v27 = v34;
      v28 = v35;
      v23 = "ddos_fy";
      v29 = v36;
      v25 = v2;
      v26 = v5;
      v30 = v37;
      v14 = (char *)nvram_get("lan_hwaddr");
      if ( !v14 )
        v14 = "";
      v31 = v14;
      v32 = 0;
      eval(&v22, 0, 0, 0);
      v15 = &v22;
      v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v17 = *(const char **)v16;
        v18 = (const char *)*((_DWORD *)v16 + 1);
        v19 = (const char *)*((_DWORD *)v16 + 2);
        v20 = (const char *)*((_DWORD *)v16 + 3);
        v16 += 16;
        *v15 = v17;
        v15[1] = v18;
        v15[2] = v19;
        v15[3] = v20;
        v15 += 4;
      }
      while ( v16 != "}" );
      v9 = 33;
      *(_WORD *)v15 = *(_WORD *)v16;
      return httpd_cgi_ret(a1, (char *)&v22, v9, 4);
    }
    v8 = (const char *)_GET_LANG_TEXT(207, *(unsigned __int8 *)(a1 + 210102), v7);
  }
  else
  {
    v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not fy_rule or not fy_en");
  }
  v9 = snprintf((char *)&v22, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
  if ( v9 >= 0x400 )
    v9 = 1023;
  return httpd_cgi_ret(a1, (char *)&v22, v9, 4);
}
// 45F764: variable 'v7' is possibly undefined
// 45F950: variable 'v12' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

