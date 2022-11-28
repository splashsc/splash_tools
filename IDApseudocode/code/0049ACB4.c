int __fastcall sub_49ACB4(int a1)
{
  int v2; // $s0
  void *v3; // $v0
  char *v4; // $v0
  void *v5; // $s1
  char *v6; // $s2
  const char *v7; // $v0
  int v8; // $a0
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  unsigned int v15; // $s0
  const char *v17; // $v0
  _DWORD *v18; // $s0
  int v19; // $v0
  int v20; // $s1
  int v21; // $s3
  int v22; // $fp
  int v23; // $s1
  char *v24; // $a1
  char *v25; // $v0
  char *v26; // $s3
  char *v27; // $v0
  int v28; // $v0
  char *v29; // $fp
  unsigned int v30; // $v0
  int v31; // $v0
  int v32; // $a1
  int v33; // $a2
  int v34; // $a0
  const char *v35; // $v0
  char v36[256]; // [sp+28h] [-180h] BYREF
  char v37[32]; // [sp+128h] [-80h] BYREF
  char v38[32]; // [sp+148h] [-60h] BYREF
  int v39[2]; // [sp+168h] [-40h] BYREF
  char *s; // [sp+170h] [-38h]
  char *v41; // [sp+174h] [-34h]
  char *v42; // [sp+178h] [-30h]
  char *v43; // [sp+17Ch] [-2Ch]
  void *v44; // [sp+180h] [-28h]
  char *v45; // [sp+184h] [-24h]
  char *v46; // [sp+188h] [-20h]
  unsigned int v47; // [sp+18Ch] [-1Ch]
  char *v48; // [sp+190h] [-18h]
  char *v49; // [sp+194h] [-14h]
  int v50; // [sp+198h] [-10h]
  char *format; // [sp+19Ch] [-Ch]
  const char *v52; // [sp+1A0h] [-8h]

  v2 = httpd_get_json_parm(a1, (int)"list");
  v45 = httpd_get_parm(a1, "enable");
  v47 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "pppoe_br_more_asp", 987);
  v44 = v3;
  v5 = v3;
  _mem_malloc(0x200000, "pppoe_br_more_asp", 988);
  v6 = v4;
  if ( !v5 || !v4 )
  {
    v17 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    s = v36;
    v15 = snprintf(v36, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
    if ( v15 >= 0x100 )
      v15 = 255;
    goto LABEL_13;
  }
  jhl_parm_get("pppoe_br_all", v44, 0x200000);
  if ( !v2
    || !cJSON_IsArray(v2)
    || (v52 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n",
        jhl_parm_set("pppoe_br_all", ""),
        (v18 = *(_DWORD **)(v2 + 8)) == 0) )
  {
    s = v36;
LABEL_6:
    if ( v45 )
    {
      v7 = (const char *)nvram_get("pppoe_br_more_enable");
      if ( !v7 || strcmp(v7, v45) )
        nvram_set("pppoe_br_more_enable", v45);
    }
    v39[0] = (int)"pppoe_br_more_clean.sh";
    v39[1] = 0;
    eval(v39, 0, 0, 0);
    jhl_parm_commit(v8);
    jhl_gl_net_restart_timer(1000);
    v9 = s;
    v10 = "{\"code\":4,\"error\":\"\",\"data\":null}";
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
    v15 = 33;
    *(_WORD *)v9 = *(_WORD *)v10;
    goto LABEL_13;
  }
  v41 = "a";
  v42 = "a";
  v43 = "a";
  v48 = "a";
  s = v36;
  v50 = (int)"pppoe_br_all";
  format = "%s%s|%s|%s<";
  v49 = "1";
  while ( 1 )
  {
    v20 = cJSON_GetObjectItem(v18, v41 + 12200);
    v21 = cJSON_GetObjectItem(v18, v42 + 12212);
    v22 = cJSON_GetObjectItem(v18, v43 + 12224);
    if ( !v20 )
      goto LABEL_20;
    v23 = *(_DWORD *)(v20 + 16);
    if ( !v23 || !v21 || !*(_DWORD *)(v21 + 16) || !v22 || !*(_DWORD *)(v22 + 16) )
      goto LABEL_20;
    jhl_parm_get("pppoe_br_all", v6, 0x200000);
    if ( nvparm_find_str(v6, 60, 5, v23, 124, 0) )
    {
      v32 = *(unsigned __int8 *)(a1 + 210102);
      v33 = (int)"same name";
      v34 = 12;
      goto LABEL_40;
    }
    if ( check_rule_num_limit(a1, 34, v50, 60, s, 0x100u) > 0 )
    {
      v15 = 0;
      goto LABEL_42;
    }
    v24 = *(char **)(v21 + 16);
    if ( !v24 || !*v24 )
    {
      v25 = v49;
      *(_DWORD *)(v21 + 16) = v49;
      v24 = v25;
    }
    v26 = *(char **)(v22 + 16);
    if ( !v26 || !*v26 )
    {
      v27 = v49;
      *(_DWORD *)(v22 + 16) = v49;
      v26 = v27;
    }
    v46 = v24;
    if ( (unsigned int)J_ato10(v24) >= 0xFA )
      break;
    v28 = J_ato10(v46);
    v29 = v48;
    sprintf(v37, v48 + 24872, v28);
    v30 = J_ato10(v26);
    if ( v47 < v30 )
    {
      sprintf(v38, v29 + 24872, v47);
      v19 = nvram_get("pppoe_br_all");
      if ( !v19 )
        goto LABEL_38;
    }
    else
    {
      v31 = J_ato10(v26);
      sprintf(v38, v48 + 24872, v31);
      v19 = nvram_get("pppoe_br_all");
      if ( !v19 )
      {
LABEL_38:
        v19 = (int)(v52 - 1556);
        goto LABEL_19;
      }
    }
LABEL_19:
    snprintf(v6, 0x200000, format, v19, v23, v37, v38);
    jhl_parm_set("pppoe_br_all", v6);
LABEL_20:
    v18 = (_DWORD *)*v18;
    if ( !v18 )
      goto LABEL_6;
  }
  v32 = *(unsigned __int8 *)(a1 + 210102);
  v33 = 249;
  v34 = 167;
LABEL_40:
  v35 = (const char *)_GET_LANG_TEXT(v34, v32, v33);
  v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
  if ( v15 >= 0x100 )
    v15 = 255;
LABEL_42:
  jhl_parm_set("pppoe_br_all", v44);
LABEL_13:
  _mem_free(v44);
  _mem_free(v6);
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 49AD68: variable 'v3' is possibly undefined
// 49AD7C: variable 'v4' is possibly undefined
// 49AE68: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A853C: using guessed type int __fastcall J_ato10(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

