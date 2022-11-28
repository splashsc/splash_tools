int __fastcall sub_49B514(int a1)
{
  char *v2; // $v0
  _BYTE *v3; // $v0
  _BYTE *v4; // $s4
  char *v5; // $s2
  int v6; // $s3
  char *v7; // $v0
  char *v8; // $s0
  char *v9; // $s1
  char *v10; // $v0
  int v11; // $a0
  int v12; // $v1
  _BOOL4 v13; // $a2
  char *v14; // $s0
  int v15; // $s1
  int v16; // $s7
  int v17; // $a0
  char *v18; // $v1
  const char *v19; // $v0
  int v20; // $t0
  int v21; // $a3
  int v22; // $a2
  int v23; // $a1
  unsigned int v24; // $s0
  const char *v25; // $v0
  unsigned int v26; // $a2
  const char *v28; // $v0
  char v29[16384]; // [sp+20h] [-4420h] BYREF
  char v30[1024]; // [sp+4020h] [-420h] BYREF
  int v31[6]; // [sp+4420h] [-20h] BYREF
  char *format; // [sp+4438h] [-8h]
  char *v33; // [sp+443Ch] [-4h]

  _mem_malloc(0x200000, "pppoe_br_more_cgi", 1120);
  v4 = v3;
  _mem_malloc(0x200000, "pppoe_br_more_cgi", 1121);
  v5 = v2;
  if ( v4 && v2 )
  {
    v6 = *(_DWORD *)(a1 + 205364);
    find_file_head(a1, *(const char **)(a1 + 205564));
    v8 = v7;
    if ( v7 )
    {
      v9 = find_file_end(a1, v7, *(_DWORD *)(a1 + 205564) + v6 - (_DWORD)v7);
      if ( v9 )
      {
        v33 = "1\"";
        *v9 = 0;
        jhl_parm_get("pppoe_br_all", v5, 0x200000);
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
            v13 = v11 + 1 < 0x1FFFFF;
            if ( v12 != 13 && v12 != 10 )
            {
              v4[v11++] = v12;
              if ( !v13 )
                break;
            }
          }
          while ( v9 != v10 );
        }
        v14 = v29;
        v4[v11] = 0;
        v15 = split_string(v4, 60, v29, 512);
        if ( v15 > 0 )
        {
          v16 = 0;
          format = "%s|%s|%s<";
          do
          {
            while ( 1 )
            {
              ++v16;
              if ( split_string(*(_DWORD *)v14, 124, v31, 5) >= 3 && !nvparm_find_str(v5, 60, 5, v31[0], 124, 0) )
                break;
              v14 += 4;
              if ( v15 == v16 )
                goto LABEL_17;
            }
            snprintf(v30, 1024, format, v31[0], v31[1], v31[2]);
            strcat(v5, v30);
            v14 += 4;
          }
          while ( v15 != v16 );
        }
LABEL_17:
        jhl_parm_set(v33 - 15648, v5);
        jhl_parm_commit(v17);
        jhl_gl_net_restart_timer(1000);
        v18 = v30;
        v19 = "{\"code\":4,\"error\":\"\",\"data\":null}";
        do
        {
          v20 = *(_DWORD *)v19;
          v21 = *((_DWORD *)v19 + 1);
          v22 = *((_DWORD *)v19 + 2);
          v23 = *((_DWORD *)v19 + 3);
          v19 += 16;
          *(_DWORD *)v18 = v20;
          *((_DWORD *)v18 + 1) = v21;
          *((_DWORD *)v18 + 2) = v22;
          *((_DWORD *)v18 + 3) = v23;
          v18 += 16;
        }
        while ( v19 != "}" );
        v24 = 33;
        *(_WORD *)v18 = *(_WORD *)v19;
        goto LABEL_28;
      }
      if ( debug_level > 0 )
        printf("%s:%d find_file_end err \n", "pppoe_br_more_cgi", 1141);
    }
    else if ( debug_level > 0 )
    {
      printf("%s:%d find_file_head err  \n", "pppoe_br_more_cgi", 1134);
    }
    v28 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v24 = snprintf(v30, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
    if ( v24 >= 0x400 )
      v24 = 1023;
LABEL_28:
    _mem_free(v4);
    _mem_free(v5);
    return httpd_cgi_ret(a1, v30, v24, 4);
  }
  _mem_free(v4);
  _mem_free(v5);
  v25 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v26 = snprintf(v30, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( v26 >= 0x400 )
    v26 = 1023;
  return httpd_cgi_ret(a1, v30, v26, 4);
}
// 49B584: variable 'v3' is possibly undefined
// 49B590: variable 'v2' is possibly undefined
// 49B5C0: variable 'v7' is possibly undefined
// 49B77C: variable 'v17' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

