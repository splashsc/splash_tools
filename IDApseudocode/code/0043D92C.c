int __fastcall sub_43D92C(int a1)
{
  unsigned __int16 *v1; // $v0
  int v2; // $a2
  int v3; // $v0
  int v4; // $s5
  unsigned __int16 *v5; // $s7
  int v6; // $a1
  int v7; // $a2
  int v8; // $a0
  const char *v9; // $v0
  unsigned int v10; // $s0
  char *v11; // $a1
  int v12; // $a3
  int v13; // $a2
  unsigned __int16 *v15; // $s1
  int v16; // $v1
  int v17; // $v0
  unsigned __int16 *v18; // $fp
  int v19; // $s0
  int v20; // $s6
  char *v21; // $s4
  int v22; // $v0
  int v23; // $s6
  char *v24; // $s4
  int v25; // $v0
  int v26; // $s0
  int v27; // $v0
  _BOOL4 v28; // $a0
  _BYTE *v29; // $v0
  int v30; // $s0
  int v31; // $s6
  const char *v32; // $s1
  const char *v33; // $v0
  int v34; // $s6
  int v35; // $v0
  int v36; // $s6
  int v37; // $v0
  int v38; // $v1
  const char *v39; // $v0
  char v40[102400]; // [sp+28h] [-19160h] BYREF
  _BYTE v41[256]; // [sp+19028h] [-160h] BYREF
  _BYTE v42[64]; // [sp+19128h] [-60h] BYREF
  int v43; // [sp+19168h] [-20h]
  char *v44; // [sp+1916Ch] [-1Ch]
  int v45; // [sp+19170h] [-18h]
  unsigned __int16 *v46; // [sp+19174h] [-14h]
  char *v47; // [sp+19178h] [-10h]
  char *v48; // [sp+1917Ch] [-Ch]
  char *v49; // [sp+19180h] [-8h]
  _BYTE *v50; // [sp+19184h] [-4h]

  v48 = "a";
  _mem_malloc(0x200000, "dns_cache_list_data", 2826);
  v4 = v3;
  _mem_malloc(0x100000, "dns_cache_list_data", 2827);
  v5 = v1;
  if ( !v4 )
  {
    v39 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v44 = v40;
    v10 = snprintf(v40, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v39);
    if ( v10 >= 0x80 )
      v10 = 127;
    goto LABEL_8;
  }
  if ( !v1 )
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 0x200000;
    v8 = 4;
    goto LABEL_5;
  }
  *(_DWORD *)v1 = 4;
  *((_DWORD *)v1 + 3) = 3;
  *((_DWORD *)v1 + 1) = 0x100000;
  if ( jianhl_order_opt_fun(v1, 0x100000, v2) )
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = (int)"";
    v8 = 3;
LABEL_5:
    v9 = (const char *)_GET_LANG_TEXT(v8, v6, v7);
    v44 = v40;
    v10 = snprintf(v40, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x80 )
      v10 = 127;
    _mem_free((void *)v4);
LABEL_8:
    if ( v5 )
      _mem_free(v5);
    v11 = v44;
    v12 = 4;
    v13 = v10;
    return httpd_cgi_ret(a1, v11, v13, v12);
  }
  qmemcpy((void *)v4, "{\"code\":0,\"error\":\"\",\"data\":{\"all", 33);
  qmemcpy((void *)v4, "{\"code\":0,\"error", 16);
  *(_DWORD *)(v4 + 24) = 975331700;
  *(_BYTE *)(v4 + 32) = 108;
  *(_DWORD *)(v4 + 33) = &unk_5B3A22;
  if ( !nvram_match_def("dnsEn", "0") )
  {
    v15 = v5 + 12;
    if ( *((int *)v5 + 5) <= 0 )
    {
      v43 = 36;
      v38 = 35;
      v37 = 36;
      v44 = v40;
    }
    else
    {
      v44 = v40;
      v49 = "a";
      v47 = "a";
      v45 = 0;
      v43 = 36;
      v50 = v41;
      do
      {
        v16 = *((_DWORD *)v15 + 1);
        v17 = *v15;
        v46 = v15 + 10;
        v18 = (unsigned __int16 *)((char *)v15 + v16 + 20);
        v19 = 0;
        if ( v17 )
        {
          v20 = 0;
          v21 = v47 + 11868;
          do
          {
            v22 = IpToStr(v42, *(_DWORD *)v18);
            ++v20;
            v19 += sprintf(&v41[v19], v21, v22);
            v18 += 2;
          }
          while ( v20 < *v15 );
        }
        if ( v15[1] )
        {
          v23 = 0;
          v24 = v47 + 11868;
          do
          {
            v25 = Ip6ToStr(v42, v18);
            ++v23;
            v19 += sprintf(&v41[v19], v24, v25);
            v18 += 8;
          }
          while ( v23 < v15[1] );
        }
        v44[v19 + 102399] = 0;
        v26 = v43;
        v27 = sprintf(
                (char *)(v4 + v43),
                v49 + 11872,
                v46,
                v50,
                *((_DWORD *)v15 + 4),
                *((_DWORD *)v15 + 2),
                *((unsigned __int8 *)v15 + 12),
                *((unsigned __int8 *)v15 + 13));
        v28 = ++v45 < *((_DWORD *)v5 + 5);
        v43 = v26 + v27;
        if ( !v28 )
          break;
        v15 = v18;
      }
      while ( 0x200000 - v43 >= 100 );
      if ( v43 <= 0 )
      {
        v37 = v43;
LABEL_33:
        v29 = (_BYTE *)(v4 + v37);
        v31 = v43 + 1;
        *v29 = 0;
        v30 = v31;
        goto LABEL_26;
      }
      v37 = v43;
      v38 = v43 - 1;
    }
    if ( *(_BYTE *)(v4 + v38) == 44 )
      v37 = --v43;
    goto LABEL_33;
  }
  v29 = (_BYTE *)(v4 + 36);
  v30 = 37;
  v31 = 37;
  v44 = v40;
LABEL_26:
  v32 = v44;
  *v29 = 93;
  v29[1] = 0;
  dns_more_dnstype_get(v32, 102400);
  v33 = (const char *)jhl_nv_get_def("dns_more_dnswan");
  v34 = sprintf((char *)(v4 + v30), ",\"dnszu\":\"%s\",\"outzu\":\"%s\"", v32, v33) + v31;
  v35 = snprintf((char *)(v4 + v34), 0x200000 - v34, "}}");
  if ( v35 >= 0x200000 - v34 )
    v35 = 0x1FFFFF - v34;
  v36 = v35 + v34;
  _mem_free(v5);
  v12 = 8;
  v13 = v36;
  v11 = (char *)v4;
  return httpd_cgi_ret(a1, v11, v13, v12);
}
// 43D9CC: variable 'v3' is possibly undefined
// 43D9D8: variable 'v1' is possibly undefined
// 43DA00: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A83E8: using guessed type int __fastcall dns_more_dnstype_get(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A86F8: using guessed type int __fastcall Ip6ToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

