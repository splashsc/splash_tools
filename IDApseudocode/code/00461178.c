int __fastcall ddos_data(int a1)
{
  char *v1; // $v0
  char *v2; // $s0
  int v3; // $v0
  _BYTE *v4; // $s3
  int v5; // $s1
  const char **v6; // $s2
  void *v7; // $v0
  _DWORD *v8; // $s7
  int v9; // $a1
  void *v10; // $s1
  int v11; // $s5
  _DWORD *v12; // $fp
  int v13; // $s1
  int i; // $s6
  int v15; // $v0
  int v16; // $v0
  int v17; // $s4
  char *v18; // $a0
  int v19; // $v0
  const char *v20; // $s4
  const char *v21; // $s5
  const char *v22; // $s7
  const char *v23; // $fp
  int v24; // $s1
  const char *v25; // $v0
  int v26; // $s1
  int v27; // $v0
  int v28; // $s1
  int v29; // $a2
  const char *v31; // $v0
  unsigned int v32; // $v0
  char v33[256]; // [sp+50h] [-228h] BYREF
  char v34[4]; // [sp+150h] [-128h] BYREF
  const char *v35; // [sp+154h] [-124h]
  const char *v36; // [sp+158h] [-120h]
  const char *v37; // [sp+160h] [-118h]
  const char *v38; // [sp+164h] [-114h]
  const char *v39; // [sp+16Ch] [-10Ch]
  const char *v40; // [sp+170h] [-108h]
  const char *v41; // [sp+178h] [-100h]
  const char *v42; // [sp+17Ch] [-FCh]
  const char *v43; // [sp+184h] [-F4h]
  const char *v44; // [sp+188h] [-F0h]
  void *ptr; // [sp+250h] [-28h]
  const char *v46; // [sp+254h] [-24h]
  const char *v47; // [sp+258h] [-20h]
  const char *v48; // [sp+25Ch] [-1Ch]
  const char *v49; // [sp+260h] [-18h]
  const char *v50; // [sp+264h] [-14h]
  const char *v51; // [sp+268h] [-10h]
  const char *v52; // [sp+26Ch] [-Ch]
  const char *v53; // [sp+270h] [-8h]
  const char *v54; // [sp+274h] [-4h]

  memset(v33, 0, sizeof(v33));
  _mem_malloc(102400, "ddos_data", 1079);
  v2 = v1;
  if ( v1 )
  {
    strcpy(v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v1, "{\"code\":0,\"error\":\"\"", 20);
    v3 = jhl_nv_get_def("hixz3");
    strlcpy(v33, v3, 256);
    split_string(v33, 60, v34, 15);
    v2[32] = 108;
    *(_DWORD *)(v2 + 29) = 1819042082;
    v2[33] = 34;
    v2[34] = 58;
    v2[35] = 0;
    v4 = v2 + 35;
    v5 = nvram_get("hixz_ddos");
    v2[35] = 91;
    v2[36] = 0;
    if ( v5 )
    {
      v6 = (const char **)malloc(0x24u);
      v8 = malloc(0x4008u);
      v7 = malloc(0x200000u);
      ptr = v7;
      if ( v7 )
      {
        if ( v6
          && (v9 = v5, v8)
          && (v10 = v7, strlcpy(v7, v9, 0x200000), v11 = split_string(v10, 60, v8, 4096), v11 > 0) )
        {
          v12 = v8;
          v13 = 1;
          for ( i = 0; i != v11; ++i )
          {
            v15 = split_string(*v12, 124, v6, 7);
            format_ddos_rule_data(v6, v15, &v4[v13], 102365 - v13);
            v13 += v16;
            ++v12;
          }
          v17 = v13;
        }
        else
        {
          v17 = 1;
          v13 = 1;
        }
        free(ptr);
      }
      else
      {
        v17 = 1;
        v13 = 1;
      }
      if ( v6 )
        free(v6);
      if ( v8 )
        free(v8);
      if ( v13 <= 0 )
      {
        v18 = &v4[v17];
        goto LABEL_17;
      }
      v18 = &v4[v17];
      if ( v4[v17 - 1] != 44 )
      {
LABEL_17:
        *v18 = 0;
        v19 = snprintf(v18, 102365 - v13, &byte_6445A0);
        if ( v19 >= 102365 - v13 )
          v19 = 102364 - v13;
        v54 = v39;
        v53 = v40;
        v52 = v41;
        v51 = v42;
        v50 = v43;
        v49 = v44;
        v20 = v35;
        v21 = v36;
        v22 = v37;
        v23 = v38;
        v24 = v13 + v19;
        v48 = (const char *)jhl_nv_get_def("ddos_maclist");
        v47 = (const char *)jhl_nv_get_def("ddos_wan_reconn_en");
        v46 = (const char *)jhl_nv_get_def("ddos_wan_reconn_limit");
        ptr = (void *)jhl_nv_get_def("drop_broadcast");
        v25 = (const char *)jhl_nv_get_def("drop_foreign_ip");
        v26 = v24 + 35;
        v27 = snprintf(
                &v2[v26],
                102400 - v26,
                ",\"def_max\":%s,\"def_time\":%s,\"def_tcp_max\":%s,\"def_tcp_time\":%s,\"def_udp_max\":%s,\"def_udp_time"
                "\":%s,\"def_icmp_max\":%s,\"def_icmp_time\":%s,\"def_other_max\":%s,\"def_other_time\":%s,\"maclist\":\""
                "%s\",\"reconn_en\":%s,\"reconn_limit\":%s,\"drop_broadcast\":%s,\"drop_foreign_ip\":%s",
                v20,
                v21,
                v22,
                v23,
                v54,
                v53,
                v52,
                v51,
                v50,
                v49,
                v48,
                v47,
                v46,
                (const char *)ptr,
                v25);
        if ( v27 >= 102400 - v26 )
          v27 = 102399 - v26;
        v28 = v27 + v26;
        v29 = snprintf(&v2[v28], 102400 - v28, "}}");
        if ( v29 >= 102400 - v28 )
          v29 = 102399 - v28;
        return httpd_cgi_ret(a1, v2, v29 + v28, 8);
      }
    }
    else
    {
      v18 = v2 + 36;
      v13 = 1;
      if ( *v4 != 44 )
        goto LABEL_17;
    }
    v18 = &v4[--v13];
    goto LABEL_17;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v32 = snprintf(v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( v32 >= 0x100 )
    v32 = 255;
  return httpd_cgi_ret(a1, v34, v32, 4);
}
// 4611F8: variable 'v1' is possibly undefined
// 4613F4: variable 'v16' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6459A8: using guessed type int dword_6459A8;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

