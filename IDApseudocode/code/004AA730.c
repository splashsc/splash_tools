int __fastcall sub_4AA730(int a1)
{
  _BYTE *v1; // $v0
  _BYTE *v2; // $s2
  char *v3; // $v0
  char *v4; // $v0
  char *v5; // $s1
  int v6; // $s4
  char *v7; // $v0
  char *v8; // $s2
  char *v9; // $v0
  char *v10; // $v1
  int v11; // $a1
  int v12; // $a0
  _BOOL4 v13; // $a3
  _BYTE *v14; // $v0
  char *v15; // $s3
  int v16; // $s4
  int v17; // $s7
  int v18; // $s0
  const char *v19; // $fp
  const char *v20; // $fp
  char *v21; // $s5
  int i; // $fp
  char *v23; // $v0
  _BOOL4 v24; // $a0
  char *v25; // $s0
  int v26; // $a0
  int v27; // $a2
  const char *v28; // $v0
  unsigned int v29; // $s0
  int v31; // $v0
  int v32; // $a1
  const char *v33; // $a2
  int v34; // $a0
  const char *v35; // $v0
  char v36[2048]; // [sp+20h] [-B28h] BYREF
  char v37[4]; // [sp+820h] [-328h] BYREF
  char *v38; // [sp+824h] [-324h]
  const char *v39; // [sp+828h] [-320h]
  int v40; // [sp+82Ch] [-31Ch]
  char *s; // [sp+834h] [-314h]
  const char *v42; // [sp+83Ch] [-30Ch]
  int v43; // [sp+840h] [-308h]
  int v44; // [sp+844h] [-304h]
  char v45[256]; // [sp+A20h] [-128h] BYREF
  _BYTE *v46; // [sp+B20h] [-28h]
  int v47; // [sp+B24h] [-24h]
  char *v48; // [sp+B28h] [-20h]
  int v49; // [sp+B2Ch] [-1Ch]
  int v50; // [sp+B30h] [-18h]
  char *v51; // [sp+B34h] [-14h]
  char *v52; // [sp+B38h] [-10h]
  char *v53; // [sp+B3Ch] [-Ch]
  char *v54; // [sp+B40h] [-8h]

  v53 = "1\"";
  v50 = get_rule_num_limit(29);
  _mem_malloc(102400, "nat_convert_more_cgi", 1944);
  v46 = v1;
  v2 = v1;
  _mem_malloc(102400, "nat_convert_more_cgi", 1945);
  v5 = v4;
  _mem_malloc(102400, "nat_convert_more_cgi", 1946);
  v48 = v3;
  if ( !v2 || !v5 || !v3 )
  {
    v32 = *(unsigned __int8 *)(a1 + 210102);
    v33 = (const char *)102400;
    v34 = 4;
    goto LABEL_32;
  }
  v54 = "1\"";
  jhl_parm_get("nat_list_more", v48, 102400);
  v6 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  v8 = v7;
  if ( !v7 || (v9 = find_file_end(a1, v7, *(_DWORD *)(a1 + 205564) + v6 - (_DWORD)v7)) == 0 )
  {
    v32 = *(unsigned __int8 *)(a1 + 210102);
    v33 = "Error reading file";
    v34 = 33;
LABEL_32:
    v35 = (const char *)_GET_LANG_TEXT(v34, v32, v33);
    goto LABEL_33;
  }
  *v9 = 0;
  if ( v9 - v8 <= 0 )
  {
    v11 = 0;
  }
  else
  {
    v10 = v8;
    v11 = 0;
    do
    {
      v12 = *v10++;
      v13 = v11 + 1 < 102399;
      if ( v12 != 13 && v12 != 10 )
      {
        v46[v11++] = v12;
        if ( !v13 )
          break;
      }
    }
    while ( v9 != v10 );
  }
  v14 = v46;
  v15 = v36;
  v46[v11] = 0;
  v47 = split_string(v14, 60, v36, 512);
  v16 = 0;
  if ( v47 <= 0 )
  {
LABEL_29:
    v25 = v48;
    strcat(v48, v5);
    jhl_parm_set(v54 - 11388, v25);
    jhl_parm_commit(v26);
    jhl_start_firewall();
    v28 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v27);
    v29 = snprintf(v45, 256, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v28);
    if ( v29 >= 0x100 )
      goto LABEL_34;
    goto LABEL_30;
  }
  v52 = "a";
  v49 = 0;
  v17 = 0;
  v51 = "1";
  while ( 1 )
  {
    v18 = split_string(*(_DWORD *)v15, 124, v37, 128);
    if ( v18 < 9 )
      goto LABEL_14;
    if ( nvparm_find_str(v48, 60, 12, v44, 124, 9) )
      break;
    if ( nvparm_find_str(v48, 60, 12, v39, 124, 2) )
    {
      v35 = (const char *)_GET_LANG_TEXT(84, *(unsigned __int8 *)(a1 + 210102), "src_ip");
      goto LABEL_33;
    }
    v19 = v39;
    if ( !v39 || strlen(v39) < 7 )
    {
      v32 = *(unsigned __int8 *)(a1 + 210102);
      v33 = "not src_ip";
      v34 = 12;
      goto LABEL_32;
    }
    if ( !s || strlen(s) < 7 )
    {
      v32 = *(unsigned __int8 *)(a1 + 210102);
      v33 = "not target_ip";
      v34 = 12;
      goto LABEL_32;
    }
    if ( !strcmp(v38, v51) )
      jhl_nat_more_add_iface((int)v19, v40);
    v20 = v42;
    if ( strcmp(v42, v52 + 12480) )
    {
      v31 = J_atoi(v20);
      jhl_nat_more_add_wanip(v31, v43);
    }
    v21 = v37;
    for ( i = 0; i != v18; ++i )
    {
      v17 += sprintf(&v5[v17], "%s|", *(const char **)v21);
      v21 += 4;
    }
    v23 = &v5[v17 - 1];
    v24 = ++v49 < v50;
    *v23 = 60;
    v23[1] = 0;
    if ( !v24 )
      goto LABEL_29;
LABEL_14:
    ++v16;
    v15 += 4;
    if ( v47 == v16 )
      goto LABEL_29;
  }
  v35 = (const char *)_GET_LANG_TEXT(84, *(unsigned __int8 *)(a1 + 210102), "src_id");
LABEL_33:
  v29 = snprintf(v45, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
  if ( v29 >= 0x100 )
LABEL_34:
    v29 = 255;
LABEL_30:
  _mem_free(v46);
  _mem_free(v48);
  _mem_free(v5);
  return httpd_cgi_ret(a1, v45, v29, 4);
}
// 4AA7BC: variable 'v1' is possibly undefined
// 4AA7E0: variable 'v4' is possibly undefined
// 4AA7E4: variable 'v3' is possibly undefined
// 4AA850: variable 'v7' is possibly undefined
// 4AAB08: variable 'v26' is possibly undefined
// 4AAB44: variable 'v27' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

