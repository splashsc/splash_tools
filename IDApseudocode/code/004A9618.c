int __fastcall sub_4A9618(int a1)
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
  int v17; // $s5
  int v18; // $s0
  int v19; // $v0
  char *v20; // $s6
  int i; // $s7
  char *v22; // $v0
  _BOOL4 v23; // $a0
  char *v24; // $s0
  int v25; // $a0
  char *v26; // $v1
  const char *v27; // $v0
  int v28; // $t0
  int v29; // $a3
  int v30; // $a2
  int v31; // $a1
  int v32; // $a1
  const char *v33; // $v0
  unsigned int v34; // $v0
  int v36; // $a1
  const char *v37; // $a2
  int v38; // $a0
  const char *v39; // $v0
  char v40[2048]; // [sp+20h] [-B20h] BYREF
  char v41[4]; // [sp+820h] [-320h] BYREF
  int v42; // [sp+824h] [-31Ch]
  int v43; // [sp+828h] [-318h]
  int v44; // [sp+82Ch] [-314h]
  int v45; // [sp+830h] [-310h]
  char v46[256]; // [sp+A20h] [-120h] BYREF
  char *v47; // [sp+B20h] [-20h]
  _BYTE *v48; // [sp+B24h] [-1Ch]
  int v49; // [sp+B28h] [-18h]
  int v50; // [sp+B2Ch] [-14h]
  int v51; // [sp+B30h] [-10h]
  char *v52; // [sp+B34h] [-Ch]
  char *v53; // [sp+B38h] [-8h]

  v52 = "1\"";
  v51 = get_rule_num_limit(28);
  _mem_malloc(102400, "nat_convert_cgi", 1644);
  v48 = v1;
  v2 = v1;
  _mem_malloc(102400, "nat_convert_cgi", 1645);
  v5 = v4;
  _mem_malloc(102400, "nat_convert_cgi", 1646);
  v47 = v3;
  if ( !v2 || !v5 || !v3 )
  {
    v36 = *(unsigned __int8 *)(a1 + 210102);
    v37 = (const char *)102400;
    v38 = 4;
    goto LABEL_30;
  }
  v53 = "1\"";
  jhl_parm_get("nat_list_onebyone", v47, 102400);
  v6 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  v8 = v7;
  if ( !v7 || (v9 = find_file_end(a1, v7, *(_DWORD *)(a1 + 205564) + v6 - (_DWORD)v7)) == 0 )
  {
    v36 = *(unsigned __int8 *)(a1 + 210102);
    v37 = "Error reading file";
    v38 = 33;
LABEL_30:
    v39 = (const char *)_GET_LANG_TEXT(v38, v36, v37);
    goto LABEL_31;
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
        v48[v11++] = v12;
        if ( !v13 )
          break;
      }
    }
    while ( v9 != v10 );
  }
  v14 = v48;
  v15 = v40;
  v48[v11] = 0;
  v49 = split_string(v14, 60, v40, 512);
  if ( v49 <= 0 )
  {
LABEL_25:
    v24 = v47;
    strcat(v47, v5);
    jhl_parm_set(v53 - 11760, v24);
    jhl_parm_commit(v25);
    jhl_start_firewall();
    v26 = v46;
    v27 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v28 = *(_DWORD *)v27;
      v29 = *((_DWORD *)v27 + 1);
      v30 = *((_DWORD *)v27 + 2);
      v31 = *((_DWORD *)v27 + 3);
      v27 += 16;
      *(_DWORD *)v26 = v28;
      *((_DWORD *)v26 + 1) = v29;
      *((_DWORD *)v26 + 2) = v30;
      *((_DWORD *)v26 + 3) = v31;
      v26 += 16;
    }
    while ( v27 != "}" );
    v32 = *(unsigned __int8 *)(a1 + 210102);
    *(_WORD *)v26 = *(_WORD *)v27;
    v33 = (const char *)_GET_LANG_TEXT(34, v32, v30);
    v34 = snprintf(v46, 256, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v33);
    if ( v34 >= 0x100 )
      goto LABEL_32;
    goto LABEL_28;
  }
  v50 = 0;
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    v18 = split_string(*(_DWORD *)v15, 124, v41, 128);
    if ( v18 < 7 )
      goto LABEL_14;
    if ( nvparm_find_str(v47, 60, 9, v45, 124, 4) )
      break;
    if ( nvparm_find_str(v47, 60, 9, v42, 124, 1) )
    {
      v39 = (const char *)_GET_LANG_TEXT(84, *(unsigned __int8 *)(a1 + 210102), "in_addr");
      goto LABEL_31;
    }
    if ( nvparm_find_str(v47, 60, 9, v43, 124, 2) )
    {
      v39 = (const char *)_GET_LANG_TEXT(84, *(unsigned __int8 *)(a1 + 210102), "out_addr");
      goto LABEL_31;
    }
    if ( !v42 )
    {
      v36 = *(unsigned __int8 *)(a1 + 210102);
      v37 = (const char *)&unk_64D344;
      v38 = 12;
      goto LABEL_30;
    }
    if ( !v43 )
    {
      v36 = *(unsigned __int8 *)(a1 + 210102);
      v37 = (const char *)&unk_64D364;
      v38 = 12;
      goto LABEL_30;
    }
    v19 = J_atoi(v44);
    v20 = v41;
    if ( jhl_nat_onebyone_add_iface(v19, v43) )
    {
      v36 = *(unsigned __int8 *)(a1 + 210102);
      v37 = "error out_addr";
      v38 = 12;
      goto LABEL_30;
    }
    for ( i = 0; i != v18; ++i )
    {
      v17 += sprintf(&v5[v17], "%s|", *(const char **)v20);
      v20 += 4;
    }
    v22 = &v5[v17 - 1];
    v23 = ++v50 < v51;
    *v22 = 60;
    v22[1] = 0;
    if ( !v23 )
      goto LABEL_25;
LABEL_14:
    ++v16;
    v15 += 4;
    if ( v49 == v16 )
      goto LABEL_25;
  }
  v39 = (const char *)_GET_LANG_TEXT(84, *(unsigned __int8 *)(a1 + 210102), &off_647174);
LABEL_31:
  v34 = snprintf(v46, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v39);
  if ( v34 >= 0x100 )
LABEL_32:
    v34 = 255;
LABEL_28:
  v49 = v34;
  _mem_free(v48);
  _mem_free(v47);
  _mem_free(v5);
  return httpd_cgi_ret(a1, v46, v49, 4);
}
// 4A96A4: variable 'v1' is possibly undefined
// 4A96C8: variable 'v4' is possibly undefined
// 4A96CC: variable 'v3' is possibly undefined
// 4A9738: variable 'v7' is possibly undefined
// 4A99B8: variable 'v25' is possibly undefined
// 647174: using guessed type void *off_647174;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

