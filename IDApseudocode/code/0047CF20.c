int __fastcall sub_47CF20(int a1)
{
  void *v2; // $v0
  void *v3; // $fp
  int v4; // $s1
  char *v5; // $v0
  char *v6; // $s6
  char *v7; // $v0
  int v8; // $a2
  int v9; // $v0
  int v10; // $a2
  const char *v11; // $v0
  unsigned int v12; // $a2
  const char *v14; // $v0
  int v15; // $a0
  char *v16; // $t0
  char *v17; // $a0
  int v18; // $v0
  const char *v19; // $s0
  int v20; // $v0
  const char *v21; // $s1
  const char *v22; // $s2
  const char *v23; // $s3
  const char *v24; // $s4
  char *v25; // $v0
  int v26; // $s4
  int v27; // $s3
  const char *v28; // $s4
  int v29; // $v0
  bool v30; // dc
  int v31; // $v0
  char v32[1024]; // [sp+58h] [-A10h] BYREF
  char v33[1024]; // [sp+458h] [-610h] BYREF
  char v34[256]; // [sp+858h] [-210h] BYREF
  const char *v35; // [sp+958h] [-110h] BYREF
  const char *v36; // [sp+95Ch] [-10Ch]
  const char *v37; // [sp+960h] [-108h]
  const char *v38; // [sp+964h] [-104h]
  const char *v39; // [sp+968h] [-100h]
  const char *v40; // [sp+96Ch] [-FCh]
  const char *v41; // [sp+970h] [-F8h]
  char *v42; // [sp+974h] [-F4h]
  char *v43; // [sp+978h] [-F0h]
  char *v44; // [sp+97Ch] [-ECh]
  int v45; // [sp+980h] [-E8h]
  int v46; // [sp+984h] [-E4h]
  int v47; // [sp+988h] [-E0h]
  int v48; // [sp+98Ch] [-DCh]
  int v49; // [sp+990h] [-D8h]
  const char *v50; // [sp+994h] [-D4h]
  const char *v51; // [sp+998h] [-D0h]
  const char *v52; // [sp+99Ch] [-CCh]
  const char *v53; // [sp+9A0h] [-C8h]
  int v54; // [sp+9A4h] [-C4h]
  struct tm v55; // [sp+9D0h] [-98h] BYREF
  int v56[3]; // [sp+9FCh] [-6Ch] BYREF
  char *v57; // [sp+A08h] [-60h]
  char *v58; // [sp+A0Ch] [-5Ch]
  char *v59; // [sp+A10h] [-58h]
  char *v60; // [sp+A14h] [-54h]
  char *v61; // [sp+A18h] [-50h]
  const char *v62; // [sp+A1Ch] [-4Ch]
  const char *v63; // [sp+A20h] [-48h]
  char *v64; // [sp+A24h] [-44h]
  int v65; // [sp+A28h] [-40h]
  int v66; // [sp+A2Ch] [-3Ch]
  int v67; // [sp+A30h] [-38h]
  int v68; // [sp+A34h] [-34h]
  int v69; // [sp+A38h] [-30h]
  const char *v70; // [sp+A3Ch] [-2Ch]
  const char *v71; // [sp+A40h] [-28h]
  const char *v72; // [sp+A44h] [-24h]
  int v73; // [sp+A48h] [-20h]
  char *v74; // [sp+A4Ch] [-1Ch]
  char *v75; // [sp+A50h] [-18h]
  const char *v76; // [sp+A54h] [-14h]
  int *v77; // [sp+A58h] [-10h]
  char *v78; // [sp+A5Ch] [-Ch]
  char *v79; // [sp+A60h] [-8h]

  strcpy(v34, "Error reading file");
  memset(&v34[19], 0, 0xEDu);
  _mem_malloc(0x200000, "usersfile_csv_cgi", 2336);
  v3 = v2;
  if ( v2 )
  {
    v4 = *(_DWORD *)(a1 + 205364);
    find_file_head(a1, *(const char **)(a1 + 205564));
    v6 = v5;
    if ( v5 )
    {
      v7 = find_file_end(a1, v5, *(_DWORD *)(a1 + 205564) + v4 - (_DWORD)v5);
      if ( v7 )
      {
        v57 = "a";
        *v7 = 0;
        if ( nvram_match_def("jf_en", "1") && sq_file_get_state_new("wys_jf")
          || nvram_match_def("billing_en", v57 + 9340) )
        {
          v9 = _GET_LANG_TEXT(74, *(unsigned __int8 *)(a1 + 210102), v8);
          strlcpy(v34, v9, 256);
          goto LABEL_7;
        }
        v58 = (char *)&unk_649204;
        v61 = "name";
        v78 = "a";
        v79 = "1\"";
        v64 = "auto";
        while ( 1 )
        {
          while ( 1 )
          {
            if ( !*v6 )
            {
              jhl_parm_commit(v15);
              v34[0] = 0;
              goto LABEL_7;
            }
            memset(v32, 0, sizeof(v32));
            v16 = v6 + 1002;
            v17 = v32;
            while ( 1 )
            {
              v18 = *v6;
              ++v17;
              if ( !*v6 )
                break;
              if ( v18 == 10 || v18 == 13 )
                goto LABEL_39;
              *(v17 - 1) = v18;
              if ( v6 + 1 == v16 )
              {
                v18 = v6[1];
                v6 = v16;
LABEL_39:
                while ( v18 == 10 || v18 == 13 )
                  v18 = *++v6;
                break;
              }
              ++v6;
            }
            if ( split_string(v32, 44, &v35, 30) >= 3 )
            {
              v19 = v35;
              v20 = strcmp(v35, v58);
              v21 = v36;
              if ( (v20 || strcmp(v36, byte_64920C)) && (strcmp(v19, v61) || strcmp(v21, "password")) )
              {
                v22 = v53;
                v62 = v39;
                v23 = v37;
                v76 = v40;
                v24 = v38;
                v63 = v41;
                v75 = v42;
                v60 = v43;
                v59 = v44;
                v65 = v45;
                v66 = v46;
                v67 = v47;
                v68 = v48;
                v69 = v49;
                v70 = v50;
                v71 = v51;
                v72 = v52;
                v73 = v54;
                if ( !v53 )
                  goto LABEL_43;
                v25 = strchr(v53, 47);
                if ( v25 )
                {
                  v74 = v25 + 1;
                  *v25 = 0;
                }
                else
                {
LABEL_43:
                  v74 = 0;
                }
                if ( v21 && v23 )
                  break;
              }
            }
          }
          v77 = v56;
          v56[0] = 0;
          v56[1] = 0;
          if ( v24 )
          {
            if ( !strcmp(v24, (const char *)&off_63F984) )
            {
              v26 = 4;
            }
            else if ( !strcmp(v24, "offjs") )
            {
              v26 = 132;
            }
            else if ( !strcmp(v24, "offll") )
            {
              v26 = 260;
            }
            else if ( !strcmp(v24, "offxzjs") )
            {
              v26 = 2052;
            }
            else if ( !strcmp(v24, "js") )
            {
              v26 = 128;
            }
            else
            {
              v26 = !strcmp(v24, "ll") ? 256 : (strcmp(v24, "xzjs") == 0) << 11;
            }
          }
          else
          {
            v26 = 0;
          }
          if ( !strcmp(v23, v78 + 13636) )
            break;
          if ( !strcmp(v23, "web") )
          {
            v27 = v26 | 0x40;
          }
          else
          {
            if ( !strcmp(v23, "mobile") )
            {
              v27 = v26 | 0x400;
              goto LABEL_45;
            }
            if ( !strcmp(v23, "pppoe/mobile") )
            {
              v27 = v26 | 0x420;
            }
            else
            {
              v31 = strcmp(v23, "pppoe/web");
              v27 = v26 | 0x60;
              if ( v31 )
                break;
            }
          }
LABEL_45:
          if ( v62 )
          {
            if ( !strcmp(v62, v64) )
            {
              v27 |= 8u;
              v62 = 0;
              v28 = 0;
            }
            else
            {
              v28 = (const char *)StrToIp(v62);
              if ( v28 )
                v27 |= 1u;
              if ( v76 && strcmp(v76, v64) )
                v62 = (const char *)StrToIp(v76);
              else
                v62 = v28;
            }
          }
          else
          {
            v62 = 0;
            v28 = 0;
          }
          if ( v63 )
          {
            if ( !strcmp(v63, v64) )
            {
              v27 |= 0x10u;
            }
            else if ( !StrToMac(v63, v77) )
            {
              v27 |= 2u;
            }
          }
          v29 = v27 & 0x980;
          if ( v22 )
          {
            if ( !strcmp(v22, v64) )
            {
              v27 |= 0x1000u;
LABEL_54:
              v29 = v27 & 0x980;
              goto LABEL_55;
            }
            v30 = J_atoi(v22) == 0;
            v29 = v27 & 0x980;
            if ( !v30 )
            {
              v27 |= 0x2000u;
              goto LABEL_54;
            }
          }
LABEL_55:
          if ( v29 )
          {
            if ( v75 )
            {
              v63 = (const char *)J_atoi(v75);
              goto LABEL_58;
            }
          }
          else if ( v75 )
          {
            v63 = (const char *)timeconvert(v75, &v55);
            goto LABEL_58;
          }
          v63 = 0;
LABEL_58:
          if ( !v60 )
            v60 = v79 - 10364;
          if ( !v59 )
            v59 = v57 + 9340;
          if ( v69 )
            v69 = J_atoi(v69);
          else
            v69 = 0;
          if ( v70 && !strcmp(v70, v57 + 9340) )
            v27 |= 0x200u;
          if ( v72 && !strcmp(v72, v57 + 9340) )
            v27 |= 0x8000u;
          if ( v71 && !strcmp(v71, v57 + 9340) )
            v27 |= 0x400u;
          user_add(v27, 0, v19, v21, v28, v62, v77, v63, v60, v59, v65, v66, v67, v68, v69, 1, v22, v74, v73);
        }
        v27 = v26 | 0x20;
        goto LABEL_45;
      }
    }
  }
LABEL_7:
  _mem_free(v3);
  if ( v34[0] )
  {
    v14 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v34);
    v12 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v12 < 0x400 )
      return httpd_cgi_ret(a1, v33, v12, 4);
LABEL_11:
    v12 = 1023;
    return httpd_cgi_ret(a1, v33, v12, 4);
  }
  v11 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v10);
  v12 = snprintf(v33, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v11);
  if ( v12 >= 0x400 )
    goto LABEL_11;
  return httpd_cgi_ret(a1, v33, v12, 4);
}
// 47CFD0: variable 'v2' is possibly undefined
// 47CFFC: variable 'v5' is possibly undefined
// 47D080: variable 'v8' is possibly undefined
// 47D0D8: variable 'v10' is possibly undefined
// 47D4F0: variable 'v15' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84DC: using guessed type int __fastcall user_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A85EC: using guessed type int __fastcall StrToMac(_DWORD, _DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8848: using guessed type int __fastcall sq_file_get_state_new(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

