int __fastcall sub_47C34C(int a1)
{
  void *v2; // $v0
  void *v3; // $fp
  int v4; // $s1
  char *v5; // $v0
  char *v6; // $s2
  char *v7; // $v0
  int v8; // $a2
  int v9; // $v0
  int v10; // $a2
  const char *v11; // $v0
  unsigned int v12; // $v0
  const char *v14; // $v0
  char *v15; // $a0
  char *v16; // $a3
  char *v17; // $a0
  int v18; // $v0
  int v19; // $v0
  int v20; // $v0
  int v21; // $v0
  char *v22; // $t0
  char *v23; // $t1
  char *i; // $v0
  int v25; // $v1
  unsigned int v26; // $v1
  int v27; // $v0
  bool v28; // dc
  char v29[1024]; // [sp+58h] [-A20h] BYREF
  char v30[1024]; // [sp+458h] [-620h] BYREF
  char v31[256]; // [sp+858h] [-220h] BYREF
  char v32[120]; // [sp+958h] [-120h] BYREF
  char *v33; // [sp+A08h] [-70h]
  int v34; // [sp+A0Ch] [-6Ch]
  int v35; // [sp+A10h] [-68h]
  int v36; // [sp+A14h] [-64h]
  int v37; // [sp+A18h] [-60h]
  char *v38; // [sp+A1Ch] [-5Ch]
  char *v39; // [sp+A20h] [-58h]
  const char *v40; // [sp+A24h] [-54h]
  int v41; // [sp+A28h] [-50h]
  int v42; // [sp+A2Ch] [-4Ch]
  int v43; // [sp+A30h] [-48h]
  int v44; // [sp+A34h] [-44h]
  int v45; // [sp+A38h] [-40h]
  int v46; // [sp+A3Ch] [-3Ch]
  int v47; // [sp+A40h] [-38h]
  int v48; // [sp+A44h] [-34h]
  int v49; // [sp+A48h] [-30h]
  int v50; // [sp+A4Ch] [-2Ch]
  int v51; // [sp+A50h] [-28h]
  int v52; // [sp+A54h] [-24h]
  int v53; // [sp+A58h] [-20h]
  int v54; // [sp+A5Ch] [-1Ch]

  strcpy(v31, "Error reading file");
  memset(&v31[19], 0, 0xEDu);
  _mem_malloc(0x200000, "usersfile_cgi", 1970);
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
        *v7 = 0;
        if ( nvram_match_def("jf_en", "1") && sq_file_get_state_new("wys_jf") || nvram_match_def("billing_en", "1") )
        {
          v9 = _GET_LANG_TEXT(74, *(unsigned __int8 *)(a1 + 210102), v8);
          strlcpy(v31, v9, 256);
          goto LABEL_7;
        }
        v38 = "pppoe";
        v39 = "1\"";
        v33 = "auto";
        v40 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
        while ( 1 )
        {
          while ( 1 )
          {
            if ( !*v6 )
            {
              jhl_parm_commit(v15);
              v31[0] = 0;
              goto LABEL_7;
            }
            memset(v29, 0, sizeof(v29));
            v16 = v6 + 1002;
            v17 = v29;
            while ( 1 )
            {
              v18 = *v6;
              if ( !*v6 )
                break;
              if ( v18 == 10 || v18 == 13 )
                goto LABEL_37;
              *v17++ = v18;
              if ( v6 + 1 == v16 )
              {
                v18 = v6[1];
                v6 = v16;
LABEL_37:
                while ( v18 == 10 || v18 == 13 )
                  v18 = *++v6;
                break;
              }
              ++v6;
            }
            v15 = v17 - 1;
            if ( v29[0] == 123 )
            {
              while ( 1 )
              {
                v19 = *v15;
                if ( v19 != 9 && v19 != 44 )
                  break;
                --v15;
              }
              if ( v19 == 125 )
                break;
            }
          }
          *v15 = 0;
          v20 = split_string(&v29[1], 9, v32, 30);
          if ( v20 < 3 )
          {
            v27 = split_string(&v29[1], 44, v32, 30);
            v28 = v27 > 0;
            v21 = 4 * v27;
            if ( v28 )
              goto LABEL_28;
          }
          else
          {
            v21 = 4 * v20;
LABEL_28:
            v22 = v32;
            v23 = &v32[v21];
            v54 = 0;
            v53 = 0;
            v52 = 0;
            v51 = 0;
            v50 = 0;
            v49 = 0;
            v48 = 0;
            v47 = 0;
            v46 = 0;
            v45 = 0;
            v36 = 0;
            v44 = 0;
            v35 = 0;
            v43 = 0;
            v42 = 0;
            v37 = 0;
            v41 = 0;
            v34 = 0;
            do
            {
              for ( i = *(char **)v22; ; ++i )
              {
                v25 = *i;
                if ( v25 != 32 && v25 != 9 )
                  break;
              }
              v15 = (char *)i[1];
              if ( v15 == (char *)58 )
              {
                v26 = (unsigned __int8)(v25 - 68);
                v15 = (char *)(v26 < 0x34);
                if ( v26 < 0x34 )
                  __asm { jr      $v1 }
              }
              v22 += 4;
            }
            while ( v22 != v23 );
          }
        }
      }
    }
  }
LABEL_7:
  _mem_free(v3);
  if ( v31[0] )
  {
    v14 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v31);
    v12 = snprintf(v30, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v12 < 0x400 )
      return httpd_cgi_ret(a1, v30, v12, 4);
LABEL_11:
    v12 = 1023;
    return httpd_cgi_ret(a1, v30, v12, 4);
  }
  v11 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v10);
  v12 = snprintf(v30, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v11);
  if ( v12 >= 0x400 )
    goto LABEL_11;
  return httpd_cgi_ret(a1, v30, v12, 4);
}
// 47C3FC: variable 'v2' is possibly undefined
// 47C428: variable 'v5' is possibly undefined
// 47C4A8: variable 'v8' is possibly undefined
// 47C500: variable 'v10' is possibly undefined
// 47CBD0: variable 'v15' is possibly undefined
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

