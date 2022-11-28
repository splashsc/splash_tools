int __fastcall sub_46A5BC(int a1)
{
  int v2; // $s4
  _BYTE *v3; // $v0
  void *v4; // $v0
  void *v5; // $s5
  _BYTE *v6; // $s1
  int v7; // $s7
  char *v8; // $v0
  char *v9; // $s0
  char *v10; // $v0
  char *v11; // $a1
  int v12; // $a0
  int v13; // $v1
  _BOOL4 v14; // $a3
  char *v15; // $s6
  int v16; // $v0
  int v17; // $a0
  int v18; // $s7
  int v19; // $s0
  const char *v20; // $v0
  unsigned int v21; // $s4
  int result; // $v0
  int v23; // $a2
  const char *v24; // $v0
  const char *v25; // $v0
  unsigned int v26; // $v0
  char v27[16384]; // [sp+20h] [-5410h] BYREF
  char v28[5120]; // [sp+4020h] [-1410h] BYREF
  int v29[4]; // [sp+5420h] [-10h] BYREF

  v2 = get_rule_num_limit(31);
  _mem_malloc(0x200000, "dns_url_cgi", 2374);
  v5 = v4;
  _mem_malloc(0x200000, "dns_url_cgi", 2375);
  v6 = v3;
  if ( v5 && v3 )
  {
    v7 = *(_DWORD *)(a1 + 205364);
    find_file_head(a1, *(const char **)(a1 + 205564));
    v9 = v8;
    if ( v8 )
    {
      v10 = find_file_end(a1, v8, *(_DWORD *)(a1 + 205564) + v7 - (_DWORD)v8);
      if ( v10 )
      {
        *v10 = 0;
        if ( v10 - v9 <= 0 )
        {
          v12 = 0;
        }
        else
        {
          v11 = v9;
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
          while ( v10 != v11 );
        }
        v6[v12] = 0;
        if ( dns_url_delall() >= 0 )
        {
          jhl_parm_set("dnsUrl", v6);
          v15 = v27;
          v16 = split_string(v6, 60, v27, 4096);
          v18 = v16 - 1;
          if ( v16 < 2 )
          {
LABEL_20:
            jhl_parm_commit(v17);
            v24 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v23);
            v21 = snprintf(v28, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v24);
            if ( v21 < 0x1400 )
              goto LABEL_18;
            goto LABEL_21;
          }
          v19 = 0;
          while ( 1 )
          {
            split_string(*(_DWORD *)v15, 58, v29, 2);
            ++v19;
            if ( dns_url_add(v29[0], v29[1], 0) )
              break;
            if ( v19 < v2 )
            {
              v15 += 4;
              if ( v19 != v18 )
                continue;
            }
            goto LABEL_20;
          }
        }
      }
      else if ( debug_level > 0 )
      {
        printf("%s:%d find_file_end err \n", "dns_url_cgi", 2396);
      }
    }
    else if ( debug_level > 0 )
    {
      printf("%s:%d find_file_head err  \n", "dns_url_cgi", 2389);
    }
    v20 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v21 = snprintf(v28, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
    if ( v21 < 0x1400 )
    {
LABEL_18:
      _mem_free(v5);
      _mem_free(v6);
      return httpd_cgi_ret(a1, v28, v21, 4);
    }
LABEL_21:
    v21 = 5119;
    goto LABEL_18;
  }
  _mem_free(v3);
  _mem_free(v5);
  v25 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v26 = snprintf(v28, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( v26 >= 0x1400 )
    result = httpd_cgi_ret(a1, v28, 5119, 4);
  else
    result = httpd_cgi_ret(a1, v28, v26, 4);
  return result;
}
// 46A640: variable 'v4' is possibly undefined
// 46A64C: variable 'v3' is possibly undefined
// 46A67C: variable 'v8' is possibly undefined
// 46A894: variable 'v17' is possibly undefined
// 46A8B4: variable 'v23' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8548: using guessed type int __fastcall dns_url_add(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

