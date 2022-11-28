int __fastcall sub_49E860(int a1)
{
  void *v1; // $v0
  int v2; // $s1
  char *v3; // $v0
  char *v4; // $fp
  char *v5; // $v0
  int v6; // $a0
  char *v7; // $a2
  char *v8; // $v1
  int v9; // $v0
  int v10; // $v0
  bool v11; // dc
  int v12; // $v0
  char *v13; // $a2
  char *v14; // $t1
  const char *v15; // $s1
  const char *v16; // $s0
  char *v17; // $s4
  char *v18; // $s5
  char *v19; // $s6
  const char *v20; // $s3
  const char *v21; // $s7
  char *i; // $v0
  int v23; // $v1
  const char *v24; // $v0
  unsigned int v25; // $v0
  _BOOL4 v27; // $s7
  time_t v28; // $s5
  time_t v29; // $s4
  int v30; // $s0
  char *v31; // $v0
  int v32; // $s6
  int v33; // $v0
  char *v34; // $v1
  const char *v35; // $v0
  int v36; // $t0
  int v37; // $a3
  int v38; // $a2
  int v39; // $a1
  __int16 v40; // $a0
  char v41[1024]; // [sp+40h] [-8E0h] BYREF
  char v42[1024]; // [sp+440h] [-4E0h] BYREF
  char v43[120]; // [sp+840h] [-E0h] BYREF
  struct tm v44; // [sp+8B8h] [-68h] BYREF
  int v45; // [sp+8E4h] [-3Ch] BYREF
  __int16 v46; // [sp+8E8h] [-38h]
  char *v47; // [sp+8F0h] [-30h]
  char *v48; // [sp+8F4h] [-2Ch]
  char *v49; // [sp+8F8h] [-28h]
  char *v50; // [sp+8FCh] [-24h]
  char *v51; // [sp+900h] [-20h]
  int v52; // [sp+904h] [-1Ch]
  void *v53; // [sp+908h] [-18h]
  char *v54; // [sp+90Ch] [-14h]
  char *v55; // [sp+910h] [-10h]
  char *v56; // [sp+914h] [-Ch]
  char *v57; // [sp+918h] [-8h]
  char *v58; // [sp+91Ch] [-4h]

  v54 = "1\"";
  _mem_malloc(0x200000, "pppoe_br_usersfile_cgi", 2035);
  v53 = v1;
  if ( v1
    && (v2 = *(_DWORD *)(a1 + 205364), find_file_head(a1, *(const char **)(a1 + 205564)), (v4 = v3) != 0)
    && (v5 = find_file_end(a1, v3, *(_DWORD *)(a1 + 205564) + v2 - (_DWORD)v3)) != 0 )
  {
    *v5 = 0;
    v55 = (char *)&off_643784;
    v56 = "1\"";
    v57 = (char *)&unk_64C76C;
    v58 = "1\"";
LABEL_5:
    while ( *v4 )
    {
      memset(v41, 0, sizeof(v41));
      v7 = v4 + 1002;
      v8 = v41;
      while ( 1 )
      {
        v9 = *v4;
        if ( !*v4 )
          break;
        if ( v9 == 10 )
          goto LABEL_58;
        ++v8;
        if ( v9 == 13 )
          goto LABEL_58;
        v6 = (int)(v4 + 1);
        *(v8 - 1) = v9;
        if ( v4 + 1 == v7 )
        {
          v9 = v4[1];
          v4 = v7;
LABEL_58:
          v6 = 13;
          while ( v9 == 10 || v9 == 13 )
            v9 = *++v4;
          break;
        }
        ++v4;
      }
      if ( v41[0] == 35 )
        goto LABEL_5;
      v10 = split_string(v41, 44, v43, 30);
      v11 = v10 <= 0;
      v12 = 4 * v10;
      if ( v11 )
        goto LABEL_5;
      v13 = v43;
      v14 = &v43[v12];
      v51 = 0;
      v50 = 0;
      v49 = 0;
      v15 = 0;
      v16 = 0;
      v48 = 0;
      v17 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v47 = 0;
      v21 = 0;
      v6 = 32;
      do
      {
        for ( i = *(char **)v13; ; ++i )
        {
          v23 = *i;
          if ( v23 != 32 && v23 != 9 )
            break;
        }
        if ( i[1] == 58 )
        {
          switch ( (char)v23 )
          {
            case 'b':
              v20 = i + 2;
              break;
            case 'c':
              v18 = i + 2;
              break;
            case 'd':
              v21 = i + 2;
              break;
            case 'e':
              v17 = i + 2;
              break;
            case 'i':
              v16 = i + 2;
              break;
            case 'm':
              v19 = i + 2;
              break;
            case 'n':
              v48 = i + 2;
              break;
            case 'o':
              v49 = i + 2;
              break;
            case 'p':
              v51 = i + 2;
              break;
            case 'q':
              v50 = i + 2;
              break;
            case 'u':
              v47 = i + 2;
              break;
            case 'v':
              v15 = i + 2;
              break;
            default:
              break;
          }
        }
        v13 += 4;
      }
      while ( v13 != v14 );
      if ( !v47 )
        goto LABEL_5;
      if ( !v21 || !strncmp(v21, v58 - 14508, 4u) )
      {
        v27 = 1;
        if ( !v20 )
        {
LABEL_63:
          v52 = 0;
          if ( v19 )
            goto LABEL_31;
          goto LABEL_64;
        }
      }
      else
      {
        v27 = strncmp(v21, byte_64C75C, 4u) != 0;
        if ( !v20 )
          goto LABEL_63;
      }
      if ( !strncmp(v20, v56 - 14492, 6u) )
        v52 = 2;
      else
        v52 = strncmp(v20, v57, 4u) == 0;
      if ( v19 )
      {
LABEL_31:
        StrToMac(v19, &v45);
        if ( v18 )
          goto LABEL_32;
        goto LABEL_65;
      }
LABEL_64:
      v45 = 0;
      v46 = 0;
      if ( v18 )
      {
LABEL_32:
        v28 = timeconvert(v18, &v44);
        if ( v17 )
          goto LABEL_33;
        goto LABEL_66;
      }
LABEL_65:
      v28 = 0;
      if ( v17 )
      {
LABEL_33:
        v29 = timeconvert(v17, &v44);
        if ( !v16 )
          goto LABEL_67;
        goto LABEL_34;
      }
LABEL_66:
      v29 = 0;
      if ( !v16 )
      {
LABEL_67:
        v30 = 1;
        if ( v15 )
          goto LABEL_37;
        goto LABEL_68;
      }
LABEL_34:
      if ( !strncmp(v16, v55, 3u) )
        v16 += 3;
      v30 = (unsigned __int8)J_atoi(v16);
      if ( v15 )
      {
LABEL_37:
        v31 = strchr(v15, 46);
        v32 = 0;
        if ( v31 )
        {
          *v4 = 0;
          v32 = (unsigned __int16)J_atoi(v31);
          ++v4;
        }
        v33 = (unsigned __int16)J_atoi(v15);
        goto LABEL_40;
      }
LABEL_68:
      v32 = 0;
      v33 = 0;
LABEL_40:
      pppoe_br_user_add(v27, v52, &v45, v30, v28, v29, v47, v48, v33, v32, v49, v50, v51);
    }
    jhl_parm_commit(v6);
    _mem_free(v53);
    v34 = v42;
    v35 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v36 = *(_DWORD *)v35;
      v37 = *((_DWORD *)v35 + 1);
      v38 = *((_DWORD *)v35 + 2);
      v39 = *((_DWORD *)v35 + 3);
      v35 += 16;
      *(_DWORD *)v34 = v36;
      *((_DWORD *)v34 + 1) = v37;
      *((_DWORD *)v34 + 2) = v38;
      *((_DWORD *)v34 + 3) = v39;
      v34 += 16;
    }
    while ( v35 != "}" );
    v40 = *(_WORD *)v35;
    v25 = 33;
    *(_WORD *)v34 = v40;
  }
  else
  {
    _mem_free(v53);
    v24 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v25 = snprintf(v42, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
    if ( v25 >= 0x400 )
      v25 = 1023;
  }
  return httpd_cgi_ret(a1, v42, v25, 4);
}
// 49E8BC: variable 'v1' is possibly undefined
// 49E8F8: variable 'v3' is possibly undefined
// 49ED40: variable 'v6' is possibly undefined
// 643784: using guessed type void *off_643784;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82A8: using guessed type int __fastcall pppoe_br_user_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A85EC: using guessed type int __fastcall StrToMac(_DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

