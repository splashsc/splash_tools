int __fastcall sub_46A0B4(int a1)
{
  _BYTE *v2; // $v0
  int v3; // $s2
  int v4; // $s6
  char *v5; // $v0
  _BYTE *v6; // $s1
  char *v7; // $s0
  char *v8; // $v0
  char *v9; // $s5
  int v10; // $s6
  char *v11; // $v0
  int v12; // $a0
  int v13; // $v1
  _BOOL4 v14; // $a2
  char *v15; // $s5
  int v16; // $v0
  int v17; // $a0
  int v18; // $s6
  int v19; // $s0
  const char *v20; // $v0
  unsigned int v21; // $s0
  int v23; // $a2
  const char *v24; // $v0
  const char *v25; // $v0
  unsigned int v26; // $v0
  char v27[16384]; // [sp+20h] [-5400h] BYREF
  char v28[5120]; // [sp+4020h] [-1400h] BYREF

  v3 = get_rule_num_limit(32);
  _mem_malloc(0x200000, "dns_acc_cgi", 2250);
  if ( v2 )
  {
    v4 = *(_DWORD *)(a1 + 205364);
    v6 = v2;
    find_file_head(a1, *(const char **)(a1 + 205564));
    v7 = v5;
    if ( v5 )
    {
      v8 = find_file_end(a1, v5, *(_DWORD *)(a1 + 205564) + v4 - (_DWORD)v5);
      v9 = v8;
      if ( v8 )
      {
        *v8 = 0;
        v10 = v8 - v7;
        dns_acc_delall();
        if ( v10 <= 0 )
        {
          v12 = 0;
        }
        else
        {
          v11 = v7;
          v12 = 0;
          do
          {
            v13 = *v11++;
            v14 = v12 + 1 < 0x1FFFFF;
            if ( v13 != 13 && v13 != 10 )
            {
              v6[v12++] = v13;
              if ( !v14 )
                break;
            }
          }
          while ( v9 != v11 );
        }
        v6[v12] = 0;
        jhl_parm_set("dnsAcc", v6);
        v15 = v27;
        v16 = split_string(v6, 60, v27, 4096);
        v18 = v16 - 1;
        if ( v16 < 2 )
        {
LABEL_18:
          jhl_parm_commit(v17);
          v24 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v23);
          v21 = snprintf(v28, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v24);
          if ( v21 < 0x1400 )
            goto LABEL_16;
          goto LABEL_19;
        }
        v19 = 0;
        while ( 1 )
        {
          ++v19;
          if ( dns_acc_add(*(_DWORD *)v15) )
            break;
          if ( v19 < v3 )
          {
            v15 += 4;
            if ( v19 != v18 )
              continue;
          }
          goto LABEL_18;
        }
      }
      else if ( debug_level > 0 )
      {
        printf("%s:%d find_file_end err \n", "dns_acc_cgi", 2269);
      }
    }
    else if ( debug_level > 0 )
    {
      printf("%s:%d find_file_head err  \n", "dns_acc_cgi", 2262);
    }
    v20 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v21 = snprintf(v28, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
    if ( v21 < 0x1400 )
    {
LABEL_16:
      _mem_free(v6);
      return httpd_cgi_ret(a1, v28, v21, 4);
    }
LABEL_19:
    v21 = 5119;
    goto LABEL_16;
  }
  v25 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v26 = snprintf(v28, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( v26 >= 0x1400 )
    v26 = 5119;
  return httpd_cgi_ret(a1, v28, v26, 4);
}
// 46A11C: variable 'v2' is possibly undefined
// 46A14C: variable 'v5' is possibly undefined
// 46A318: variable 'v17' is possibly undefined
// 46A338: variable 'v23' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8784: using guessed type int __fastcall dns_acc_add(_DWORD);

