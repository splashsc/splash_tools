int __fastcall sub_489CDC(int a1)
{
  int v1; // $v0
  int v2; // $s2
  const char *v3; // $a1
  char *v4; // $v0
  char *v5; // $s0
  char *v6; // $s1
  char *v7; // $v0
  int v8; // $a1
  int v9; // $v1
  _BOOL4 v10; // $a2
  char *v11; // $t0
  char *v12; // $s3
  int v13; // $s5
  char *v14; // $s4
  int v15; // $s0
  int v16; // $a0
  char *v17; // $s1
  char *v18; // $s6
  char *v19; // $s7
  int v20; // $t7
  int v21; // $t6
  int v22; // $t5
  int v23; // $t4
  int v24; // $t3
  int v25; // $t1
  int v26; // $t0
  int v27; // $v0
  char *v28; // $t2
  char *v29; // $a0
  char *v30; // $v1
  const char **v31; // $s6
  int v32; // $fp
  int v33; // $s7
  char *v34; // $s1
  int v35; // $s0
  char *v36; // $s1
  int v37; // $a0
  int v38; // $a2
  const char *v39; // $v0
  unsigned int v40; // $v0
  unsigned int v41; // $a2
  const char *v43; // $v0
  char v44[222208]; // [sp+20h] [-36A58h] BYREF
  _BYTE v45[1024]; // [sp+36420h] [-658h] BYREF
  char *v46; // [sp+36A50h] [-28h]
  char *v47; // [sp+36A54h] [-24h]
  char *v48; // [sp+36A58h] [-20h]
  int v49; // [sp+36A5Ch] [-1Ch]
  int v50; // [sp+36A60h] [-18h]
  int v51; // [sp+36A64h] [-14h]
  char *v52; // [sp+36A68h] [-10h]
  char *v53; // [sp+36A6Ch] [-Ch]
  char *v54; // [sp+36A70h] [-8h]

  v46 = v44;
  memset(v45, 0, sizeof(v45));
  v1 = get_rule_num_limit(14);
  v2 = *(_DWORD *)(a1 + 205364);
  v3 = *(const char **)(a1 + 205564);
  v51 = v1;
  find_file_head(a1, v3);
  if ( v4 && (v5 = v4, (v6 = find_file_end(a1, v4, *(_DWORD *)(a1 + 205564) + v2 - (_DWORD)v4)) != 0) )
  {
    v53 = "a";
    *v6 = 0;
    jhl_parm_get("url_rules", v44, 102400);
    if ( v6 - v5 <= 0 )
    {
      v8 = 0;
    }
    else
    {
      v7 = v5;
      v8 = 0;
      do
      {
        v9 = *v7++;
        v10 = v8 + 1 < 102399;
        if ( v9 != 13 && v9 != 10 )
        {
          v44[v8++ + 102400] = v9;
          if ( !v10 )
            break;
        }
      }
      while ( v6 != v7 );
    }
    v11 = v46;
    v12 = v46 + 220160;
    v46[v8 + 102400] = 0;
    v49 = split_string(v11 + 102400, 60, v12, 512);
    if ( v49 > 0 )
    {
      v52 = "1\"";
      v54 = "1\"";
      v50 = 0;
      v47 = v46 + 215040;
      v48 = v46 + 223232;
      v13 = 0;
      v14 = v46 + 196608;
      do
      {
        strlcpy(v47, *(_DWORD *)v12, 5120);
        v15 = split_string(*(_DWORD *)v12, 124, v48, 128);
        if ( v15 >= 8 && !nvparm_find_str(v46, 60, 11, *((_DWORD *)v14 + 6656), 124, 0) )
        {
          v16 = *((_DWORD *)v14 + 6664);
          if ( v16 && J_atoi(v16) == 1 )
            v17 = v54 - 22528;
          else
            v17 = v52 - 22540;
          v18 = v46 + 222208;
          if ( get_time_group(*((_DWORD *)v14 + 6660), v46 + 222208, 1024) )
            strlcpy(v18, *((_DWORD *)v14 + 6660), 1024);
          v19 = v46;
          v20 = *((_DWORD *)v14 + 6656);
          v21 = *((_DWORD *)v14 + 6657);
          v22 = *((_DWORD *)v14 + 6658);
          v23 = *((_DWORD *)v14 + 6659);
          v24 = *((_DWORD *)v14 + 6660);
          v25 = *((_DWORD *)v14 + 6661);
          v26 = *((_DWORD *)v14 + 6662);
          v27 = *((_DWORD *)v14 + 6663);
          v28 = v46 + 222208;
          v29 = v46 + 223744;
          *((_DWORD *)v14 + 6784) = v17;
          *((_DWORD *)v14 + 6785) = v20;
          *((_DWORD *)v14 + 6786) = v21;
          *((_DWORD *)v14 + 6787) = v22;
          *((_DWORD *)v14 + 6788) = v23;
          *((_DWORD *)v14 + 6789) = v24;
          *((_DWORD *)v14 + 6790) = v28;
          *((_DWORD *)v14 + 6791) = v25;
          *((_DWORD *)v14 + 6792) = v26;
          *((_DWORD *)v14 + 6793) = v27;
          *((_DWORD *)v14 + 6794) = 0;
          eval(v29, 0, 0, 0);
          v30 = v19;
          v31 = (const char **)(v19 + 223232);
          v32 = 0;
          v33 = 0;
          v34 = v30 + 204800;
          do
          {
            ++v32;
            v33 += sprintf(&v34[v33], "%s|", *v31++);
          }
          while ( v15 != v32 );
          *(_WORD *)&v34[v33 - 1] = 60;
          v35 = ++v50;
          strcat(v46, v34);
          if ( v35 >= v51 )
            break;
        }
        ++v13;
        v12 += 4;
      }
      while ( v49 != v13 );
    }
    v36 = v46;
    jhl_parm_set(v53 + 27940, v46);
    jhl_parm_commit(v37);
    v39 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v38);
    v40 = snprintf(v36 + 215040, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v39);
    if ( v40 < 0x1400 )
      goto LABEL_23;
  }
  else
  {
    v43 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v41 = snprintf(v46 + 215040, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v43);
    if ( v41 < 0x1400 )
      return httpd_cgi_ret(a1, v46 + 215040, v41, 4);
  }
  v40 = 5119;
LABEL_23:
  v41 = v40;
  return httpd_cgi_ret(a1, v46 + 215040, v41, 4);
}
// 489DD4: variable 'v4' is possibly undefined
// 48A254: variable 'v37' is possibly undefined
// 48A284: variable 'v38' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

