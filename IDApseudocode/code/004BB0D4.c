int __fastcall sub_4BB0D4(int a1)
{
  char *v2; // $s2
  char *v3; // $s4
  int v4; // $a1
  const char *v5; // $a2
  int v6; // $a0
  const char *v7; // $v0
  unsigned int v8; // $a2
  const char *v10; // $v0
  int v11; // $s2
  int v12; // $v0
  const char *v13; // $s6
  void *v14; // $v0
  int v15; // $s5
  void *v16; // $s4
  int v17; // $v0
  int v18; // $a0
  int v19; // $a3
  const char *v20; // $v0
  char *v21; // $v1
  const char *v22; // $v0
  int v23; // $t0
  int v24; // $a3
  int v25; // $a2
  int v26; // $a1
  char v27[128]; // [sp+20h] [-188h] BYREF
  char v28[128]; // [sp+A0h] [-108h] BYREF
  char v29[128]; // [sp+120h] [-88h] BYREF
  int v30; // [sp+1A0h] [-8h]

  memset(v29, 0, sizeof(v29));
  memset(v28, 0, sizeof(v28));
  memset(v27, 0, sizeof(v27));
  v2 = httpd_get_parm(a1, "type");
  v3 = httpd_get_parm(a1, "id");
  if ( !v2 || !*v2 || !v3 || !*v3 )
  {
    v4 = *(unsigned __int8 *)(a1 + 210102);
    v5 = "not type or id";
    v6 = 12;
LABEL_4:
    v7 = (const char *)_GET_LANG_TEXT(v6, v4, v5);
    v8 = snprintf(v29, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v7);
    if ( v8 >= 0x80 )
      v8 = 127;
    return httpd_cgi_ret(a1, v29, v8, 4);
  }
  if ( !strcmp(v3, "param") )
  {
    v20 = (const char *)nvram_get("sj_devparam_type");
    if ( v20 && !strcmp(v20, v2) )
    {
      v11 = 0;
    }
    else
    {
      nvram_set("sj_devparam_type", v2);
      v11 = 1;
    }
    v21 = v27;
    v22 = "/tmp/sj_html/sj_dev_info_hide.htm";
    do
    {
      v23 = *(_DWORD *)v22;
      v24 = *((_DWORD *)v22 + 1);
      v25 = *((_DWORD *)v22 + 2);
      v26 = *((_DWORD *)v22 + 3);
      v22 += 16;
      *(_DWORD *)v21 = v23;
      *((_DWORD *)v21 + 1) = v24;
      *((_DWORD *)v21 + 2) = v25;
      *((_DWORD *)v21 + 3) = v26;
      v21 += 16;
    }
    while ( v22 != "m" );
    *(_WORD *)v21 = *(_WORD *)v22;
  }
  else
  {
    if ( strcmp(v3, "srv") )
    {
      sprintf(v28, "not id: %s", v3);
      v4 = *(unsigned __int8 *)(a1 + 210102);
      v5 = v28;
      v6 = 12;
      goto LABEL_4;
    }
    v10 = (const char *)nvram_get("sj_srv_type");
    if ( v10 && !strcmp(v10, v2) )
    {
      v11 = 0;
    }
    else
    {
      nvram_set("sj_srv_type", v2);
      v11 = 1;
    }
    strcpy(v27, "/tmp/sj_html/sj_state_hide.htm");
  }
  if ( !f_exists(v27) )
  {
    sprintf(v28, "not found path: %s", v27);
    v4 = *(unsigned __int8 *)(a1 + 210102);
    v5 = "not find path";
    v6 = 12;
    goto LABEL_4;
  }
  v12 = f_size(v27);
  v13 = (const char *)(v12 + 1);
  v15 = v12;
  _mem_malloc(v12 + 1, "shenji_info_htm", 1102);
  v16 = v14;
  if ( !v14 )
  {
    v4 = *(unsigned __int8 *)(a1 + 210102);
    v5 = v13;
    v6 = 4;
    goto LABEL_4;
  }
  v17 = f_read(v27, v14, v15);
  v19 = v17;
  if ( v11 )
  {
    v30 = v17;
    jhl_parm_commit(v18);
    v19 = v30;
  }
  return httpd_send_mime_file(a1, "text/html", v16, v19);
}
// 4BB414: variable 'v14' is possibly undefined
// 4BB4FC: variable 'v18' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8950: using guessed type int __fastcall f_size(_DWORD);

