int __fastcall sub_498F4C(int a1)
{
  void *v1; // $v0
  int v2; // $v0
  int v3; // $s5
  int v4; // $s0
  int v5; // $v0
  int v6; // $s3
  char *v7; // $s2
  int v8; // $s1
  int v9; // $s7
  _DWORD *v10; // $s4
  int v11; // $s6
  int i; // $s3
  int v13; // $v0
  int v14; // $v0
  int v15; // $a0
  char *v16; // $a0
  char *v17; // $a2
  int v18; // $v0
  int v19; // $v0
  int v20; // $v1
  int v21; // $v0
  int v22; // $s1
  int v23; // $a3
  int v24; // $a2
  char *v25; // $a1
  const char *v27; // $v0
  unsigned int v28; // $v0
  char v29[8]; // [sp+28h] [-8060h] BYREF
  char v30[16384]; // [sp+4028h] [-4060h] BYREF
  _DWORD v31[13]; // [sp+8028h] [-60h] BYREF
  char *v32; // [sp+805Ch] [-2Ch]
  char *v33; // [sp+8060h] [-28h]
  char *v34; // [sp+8064h] [-24h]
  int v35; // [sp+8068h] [-20h]
  int v36; // [sp+806Ch] [-1Ch]
  _DWORD *v37; // [sp+8070h] [-18h]
  char *v38; // [sp+8074h] [-14h]
  char *v39; // [sp+8078h] [-10h]
  const char *v40; // [sp+807Ch] [-Ch]
  void *v41; // [sp+8080h] [-8h]
  char *v42; // [sp+8084h] [-4h]

  v42 = "1\"";
  _mem_malloc(102400, "pppoe_group_data", 587);
  v3 = v2;
  _mem_malloc(102400, "pppoe_group_data", 588);
  v41 = v1;
  if ( v3 && v1 )
  {
    strcpy((char *)v3, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy((void *)v3, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v3 + 24) = 975331700;
    jhl_parm_get("pppoe_group_list", v41, 102400);
    v36 = split_string(v41, 60, v30, 4096);
    if ( v36 <= 0 )
    {
      v20 = 28;
      v19 = 29;
      v4 = 29;
    }
    else
    {
      v38 = v29;
      v32 = "1\"";
      v33 = "a";
      v34 = v30;
      v35 = 0;
      v37 = v31;
      v39 = "{\"name\":\"%s\",\"ip\":\"%s\",\"mask\":\"%s\",\"dns\":\"%s\",\"speed\":[";
      v4 = 29;
      v40 = "]},";
      do
      {
        if ( split_string(*(_DWORD *)v34, 124, v37, 5) >= 5 )
        {
          v5 = snprintf(
                 (char *)(v3 + v4),
                 102400 - v4,
                 v39,
                 *((_DWORD *)v38 + 0x2000),
                 *((_DWORD *)v38 + 8193),
                 *((_DWORD *)v38 + 8194),
                 *((_DWORD *)v38 + 8196));
          if ( v5 >= 102400 - v4 )
            v5 = 102399 - v4;
          v6 = (int)v38;
          v7 = v38 + 0x10000;
          v8 = v5 + v4;
          v9 = split_string(*((_DWORD *)v38 + 8195), 62, v38, 4096);
          if ( v9 > 0 )
          {
            v10 = (_DWORD *)v6;
            v11 = v6 + 32796;
            for ( i = 0; i != v9; ++i )
            {
              split_string(*v10, 42, v11, 3);
              v14 = J_atoi(*((_DWORD *)v7 - 8185));
              v15 = *((_DWORD *)v7 - 8184);
              v31[12] = v14;
              J_atoi(v15);
              v13 = snprintf((char *)(v3 + v8), 102400 - v8, v32 - 15900);
              if ( v13 >= 102400 - v8 )
                v13 = 102399 - v8;
              v8 += v13;
              ++v10;
            }
          }
          v16 = (char *)(v3 + v8);
          if ( v8 > 0 && *(v16 - 1) == 44 )
          {
            --v8;
            v16 = (char *)(v3 + v8);
          }
          v17 = (char *)v40;
          *v16 = 0;
          v18 = snprintf(v16, 102400 - v8, v17);
          if ( v18 >= 102400 - v8 )
            v18 = 102399 - v8;
          v4 = v8 + v18;
        }
        ++v35;
        v34 += 4;
      }
      while ( v36 != v35 );
      v19 = v4;
      if ( v4 <= 0 )
        goto LABEL_25;
      v20 = v4 - 1;
    }
    if ( *(_BYTE *)(v3 + v20) == 44 )
      v19 = --v4;
LABEL_25:
    *(_BYTE *)(v3 + v19) = 0;
    v21 = snprintf((char *)(v3 + v19), 102400 - v4, "]}");
    if ( v21 < 102400 - v4 )
      v22 = v21;
    else
      v22 = 102399 - v4;
    _mem_free(v41);
    v23 = 8;
    v24 = v4 + v22;
    v25 = (char *)v3;
    return httpd_cgi_ret(a1, v25, v24, v23);
  }
  _mem_free((void *)v3);
  _mem_free(v41);
  v27 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v38 = v29;
  v28 = snprintf(v29, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
  if ( v28 >= 0x100 )
    v28 = 255;
  v24 = v28;
  v25 = v38;
  v23 = 4;
  return httpd_cgi_ret(a1, v25, v24, v23);
}
// 498FE0: variable 'v2' is possibly undefined
// 498FF4: variable 'v1' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

