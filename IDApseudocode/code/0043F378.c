int __fastcall sub_43F378(int a1)
{
  int v1; // $s5
  int v2; // $s0
  void *v3; // $v0
  char *v4; // $v0
  void *v5; // $s1
  char *v6; // $s4
  const char *v7; // $v0
  const char *v8; // $s0
  const char *v9; // $v0
  int v10; // $a0
  char *v11; // $v1
  const char *v12; // $v0
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  unsigned int v17; // $s0
  const char *v19; // $v0
  _DWORD *v20; // $s0
  int v21; // $v0
  int v22; // $s3
  int v23; // $s1
  int v24; // $s2
  int v25; // $s5
  int v26; // $s3
  char *v27; // $s7
  char *v28; // $v0
  char *v29; // $s1
  char *v30; // $v0
  char *v31; // $s2
  char *v32; // $v0
  unsigned int v33; // $v0
  const char *v34; // $v0
  int v35; // $a1
  int v36; // $a2
  int v37; // $a0
  char v38[256]; // [sp+28h] [-168h] BYREF
  char v39[32]; // [sp+128h] [-68h] BYREF
  char *v40; // [sp+148h] [-48h]
  char *v41; // [sp+14Ch] [-44h]
  char *v42; // [sp+150h] [-40h]
  char *v43; // [sp+154h] [-3Ch]
  char *s; // [sp+158h] [-38h]
  void *v45; // [sp+15Ch] [-34h]
  char *v46; // [sp+160h] [-30h]
  char *v47; // [sp+164h] [-2Ch]
  unsigned int v48; // [sp+168h] [-28h]
  char *v49; // [sp+16Ch] [-24h]
  char *v50; // [sp+170h] [-20h]
  char *v51; // [sp+174h] [-1Ch]
  char *v52; // [sp+178h] [-18h]
  char *format; // [sp+17Ch] [-14h]
  char *v54; // [sp+180h] [-10h]
  char *v55; // [sp+184h] [-Ch]
  const char *v56; // [sp+188h] [-8h]
  int v57; // [sp+1B8h] [+28h]

  v50 = "a";
  v1 = a1;
  v49 = "a";
  v2 = httpd_get_json_parm(a1, (int)"list");
  v46 = httpd_get_parm(v1, "increase_wan");
  v47 = httpd_get_parm(v1, "increase_base");
  v48 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "wan_extend_asp", 4012);
  v45 = v3;
  v5 = v3;
  _mem_malloc(0x200000, "wan_extend_asp", 4013);
  v6 = v4;
  if ( !v5 || !v4 )
  {
    v19 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(v1 + 210102), 0x200000);
    s = v38;
    v17 = snprintf(v38, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( v17 >= 0x100 )
      v17 = 255;
    goto LABEL_17;
  }
  jhl_parm_get("increase_wan_all", v45, 0x200000);
  if ( !v2
    || !cJSON_IsArray(v2)
    || (v56 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n",
        jhl_parm_set("increase_wan_all", ""),
        (v20 = *(_DWORD **)(v2 + 8)) == 0) )
  {
    s = v38;
LABEL_6:
    if ( v46 )
    {
      v7 = (const char *)nvram_get(v50 + 12148);
      if ( !v7 || strcmp(v7, v46) )
        nvram_set(v50 + 12148, v46);
    }
    v8 = v47;
    if ( v47 )
    {
      v9 = (const char *)nvram_get(v49 + 12164);
      if ( !v9 || strcmp(v9, v8) )
        nvram_set(v49 + 12164, v47);
    }
    nvram_set("increase_wan_flag", "1");
    jhl_parm_commit(v10);
    jhl_gl_net_restart_timer(1000);
    v11 = s;
    v12 = "{\"code\":4,\"error\":\"\",\"data\":null}";
    do
    {
      v13 = *(_DWORD *)v12;
      v14 = *((_DWORD *)v12 + 1);
      v15 = *((_DWORD *)v12 + 2);
      v16 = *((_DWORD *)v12 + 3);
      v12 += 16;
      *(_DWORD *)v11 = v13;
      *((_DWORD *)v11 + 1) = v14;
      *((_DWORD *)v11 + 2) = v15;
      *((_DWORD *)v11 + 3) = v16;
      v11 += 16;
    }
    while ( v12 != "}" );
    v17 = 33;
    *(_WORD *)v11 = *(_WORD *)v12;
    goto LABEL_17;
  }
  v52 = "a";
  v42 = "a";
  v57 = v1;
  v43 = "a";
  v40 = "a";
  v41 = "a";
  v55 = "a";
  s = v38;
  format = "%s%s|%s|%s|%s<";
  v54 = "2";
  v51 = "1";
  while ( 1 )
  {
    v22 = cJSON_GetObjectItem(v20, v42 + 12200);
    v23 = cJSON_GetObjectItem(v20, v43 + 12212);
    v24 = cJSON_GetObjectItem(v20, v40 + 12224);
    v25 = cJSON_GetObjectItem(v20, v41 + 12232);
    if ( !v22 )
      goto LABEL_24;
    v26 = *(_DWORD *)(v22 + 16);
    if ( !v26 || !v23 || !*(_DWORD *)(v23 + 16) || !v24 || !*(_DWORD *)(v24 + 16) || !v25 || !*(_DWORD *)(v25 + 16) )
      goto LABEL_24;
    jhl_parm_get("increase_wan_all", v6, 0x200000);
    if ( nvparm_find_str(v6, 60, 6, v26, 124, 0) )
    {
      v1 = v57;
      v35 = *(unsigned __int8 *)(v57 + 210102);
      v36 = (int)"same wan_name";
      v37 = 12;
      goto LABEL_56;
    }
    if ( check_rule_num_limit(v57, 35, (int)(v52 + 12180), 60, s, 0x100u) > 0 )
    {
      v1 = v57;
      v17 = 0;
      goto LABEL_54;
    }
    if ( (unsigned int)J_atoi(*(_DWORD *)(v25 + 16)) >= 0xFF1 || !J_atoi(*(_DWORD *)(v25 + 16)) )
    {
      v1 = v57;
      v34 = (const char *)_GET_LANG_TEXT(168, *(unsigned __int8 *)(v57 + 210102), 1);
      goto LABEL_52;
    }
    v27 = *(char **)(v23 + 16);
    if ( !v27 || !*v27 )
    {
      v28 = v51;
      *(_DWORD *)(v23 + 16) = v51;
      v27 = v28;
    }
    v29 = *(char **)(v24 + 16);
    if ( !v29 || !*v29 )
    {
      v30 = v51;
      *(_DWORD *)(v24 + 16) = v51;
      v29 = v30;
    }
    v31 = *(char **)(v25 + 16);
    if ( !v31 || !*v31 )
    {
      v32 = v54;
      *(_DWORD *)(v25 + 16) = v54;
      v31 = v32;
    }
    if ( (unsigned int)J_atoi(v27) >= 0xFA )
      break;
    v33 = J_atoi(v29);
    if ( v48 >= v33 )
    {
      v21 = nvram_get("increase_wan_all");
      if ( !v21 )
        goto LABEL_49;
    }
    else
    {
      v29 = v39;
      sprintf(v39, v55 + 24872, v48);
      v21 = nvram_get("increase_wan_all");
      if ( !v21 )
      {
LABEL_49:
        v21 = (int)(v56 - 1556);
        goto LABEL_23;
      }
    }
LABEL_23:
    snprintf(v6, 0x200000, format, v21, v26, v27, v29, v31);
    jhl_parm_set("increase_wan_all", v6);
LABEL_24:
    v20 = (_DWORD *)*v20;
    if ( !v20 )
    {
      v1 = v57;
      goto LABEL_6;
    }
  }
  v1 = v57;
  v35 = *(unsigned __int8 *)(v57 + 210102);
  v36 = 249;
  v37 = 167;
LABEL_56:
  v34 = (const char *)_GET_LANG_TEXT(v37, v35, v36);
LABEL_52:
  v17 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v34);
  if ( v17 >= 0x100 )
    v17 = 255;
LABEL_54:
  jhl_parm_set("increase_wan_all", v45);
LABEL_17:
  _mem_free(v45);
  _mem_free(v6);
  return httpd_cgi_ret(v1, s, v17, 4);
}
// 43F458: variable 'v3' is possibly undefined
// 43F46C: variable 'v4' is possibly undefined
// 43F5AC: variable 'v10' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

