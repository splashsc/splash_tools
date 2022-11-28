int __fastcall sub_4C641C(int a1)
{
  int v1; // $v0
  int v2; // $s5
  int v3; // $s7
  int v4; // $s4
  int v5; // $v0
  _DWORD *v6; // $s6
  int v7; // $v0
  int v8; // $a0
  int v9; // $s1
  int v10; // $s3
  const char *v11; // $a2
  const char *v12; // $s0
  int v13; // $v0
  const char *v14; // $v0
  int v15; // $v0
  char *v16; // $v1
  const char *v17; // $v0
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  unsigned int v22; // $a2
  const char *v24; // $v0
  char v25[1024]; // [sp+20h] [-430h] BYREF
  int v26[8]; // [sp+420h] [-30h] BYREF
  const char *v27; // [sp+440h] [-10h]
  int v28; // [sp+444h] [-Ch]
  char *s; // [sp+448h] [-8h]

  s = v25;
  memset(v25, 0, sizeof(v25));
  v1 = httpd_get_json_parm(a1, (int)"wans");
  if ( v1 )
  {
    v2 = v1;
    v3 = cJSON_GetArraySize(v1);
    if ( v3 > 0 )
    {
      v4 = 0;
      v28 = 0;
      v27 = "iface";
      do
      {
        v26[0] = 0;
        v26[1] = 0;
        v26[2] = 0;
        v26[3] = 0;
        v26[4] = 0;
        v26[5] = 0;
        v26[6] = 0;
        v26[7] = 0;
        v5 = cJSON_GetArrayItem(v2, v4);
        v6 = *(_DWORD **)(v5 + 8);
        v7 = cJSON_GetObjectItem(v5, v27);
        v9 = cJSON_GetIntvalue(v7);
        if ( !v6 )
          goto LABEL_12;
        v10 = 0;
        do
        {
          v11 = (const char *)v6[8];
          v12 = (const char *)v6[4];
          v6 = (_DWORD *)*v6;
          sprintf((char *)v26, "ipv6.wan_%s", v11);
          v13 = jhl_nvget(v26, v9);
          v14 = (const char *)nvram_get(v13);
          if ( !v14 || !v12 || strcmp(v14, v12) )
          {
            v15 = jhl_nvget(v26, v9);
            nvram_set(v15, v12);
            v10 = 1;
          }
        }
        while ( v6 );
        if ( v10 )
        {
          ++v28;
          ipv6wan_start(v9, 0, 0);
          ++v4;
        }
        else
        {
LABEL_12:
          ++v4;
        }
      }
      while ( v3 != v4 );
      if ( v28 )
        jhl_parm_commit(v8);
    }
    v16 = s;
    v17 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v18 = *(_DWORD *)v17;
      v19 = *((_DWORD *)v17 + 1);
      v20 = *((_DWORD *)v17 + 2);
      v21 = *((_DWORD *)v17 + 3);
      v17 += 16;
      *(_DWORD *)v16 = v18;
      *((_DWORD *)v16 + 1) = v19;
      *((_DWORD *)v16 + 2) = v20;
      *((_DWORD *)v16 + 3) = v21;
      v16 += 16;
    }
    while ( v17 != "}" );
    v22 = 33;
    *(_WORD *)v16 = *(_WORD *)v17;
  }
  else
  {
    v24 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_650A58);
    v22 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
    if ( v22 >= 0x400 )
      v22 = 1023;
  }
  return httpd_cgi_ret(a1, s, v22, 4);
}
// 4C66E0: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8998: using guessed type int __fastcall ipv6wan_start(_DWORD, _DWORD, _DWORD);

