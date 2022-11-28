int __fastcall sub_491964(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  const char *v3; // $v0
  int v4; // $v0
  const char *v5; // $v0
  int v6; // $s1
  int v7; // $v0
  int v8; // $s1
  int v9; // $v0
  int v10; // $s1
  int v11; // $v0
  int v12; // $s1
  int v13; // $v0
  int v14; // $s1
  int v15; // $v0
  int v16; // $s3
  int v17; // $s1
  char *v18; // $s4
  int v19; // $s5
  int v20; // $s0
  const char **v21; // $s2
  void *v22; // $v0
  _DWORD *v23; // $s6
  int v24; // $a1
  void *v25; // $s5
  int v26; // $s5
  int i; // $s7
  int v28; // $v0
  int v29; // $v0
  char *v30; // $a0
  int v31; // $s1
  int v32; // $v0
  int v33; // $s3
  int v34; // $v0
  int v35; // $a2
  int result; // $v0
  const char *v37; // $v0
  unsigned int v38; // $v0
  char v39[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v40; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(1024000, "dns_more_dnswan_rule_data", 156);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("dns_more_def_out");
    v4 = snprintf(v2 + 29, 1023971, "\"def_out\":\"%s\"", v3);
    if ( v4 >= 1023971 )
      v4 = 1023970;
    v6 = v4 + 29;
    v5 = (const char *)jhl_nv_get_def("dns_more_def_pri");
    v7 = snprintf(&v2[v6], 1024000 - v6, ",\"pri\":\"%s\"", v5);
    if ( v7 >= 1024000 - v6 )
      v7 = 1023999 - v6;
    v8 = v7 + v6;
    v9 = snprintf(&v2[v8], 1024000 - v8, ",\"userzu\":");
    if ( v9 >= 1024000 - v8 )
      v9 = 1023999 - v8;
    v10 = v9 + v8 + get_ips_group_data(&v2[v9 + v8], 1024000 - (v9 + v8));
    v11 = snprintf(&v2[v10], 1024000 - v10, ",\"dnszu\":");
    if ( v11 >= 1024000 - v10 )
      v11 = 1023999 - v10;
    v12 = v11 + v10 + dns_more_dnstype_get_json(&v2[v11 + v10], 1024000 - (v11 + v10));
    v13 = snprintf(&v2[v12], 1024000 - v12, ",\"outzu\":");
    if ( v13 >= 1024000 - v12 )
      v13 = 1023999 - v12;
    v14 = v13 + v12 + get_dns_more_dnswan_data(&v2[v13 + v12], 1024000 - (v13 + v12));
    v15 = snprintf(&v2[v14], 1024000 - v14, ",\"all\":");
    if ( v15 >= 1024000 - v14 )
      v15 = 1023999 - v14;
    v16 = v15 + v14;
    v17 = 1024000 - (v15 + v14);
    v18 = &v2[v16];
    v19 = nvram_get("dns_more_dnswan_rule");
    v20 = snprintf(&v2[v16], 1024000 - v16, (char *)&word_642A04);
    if ( v20 >= 1024000 - v16 )
      v20 = 1023999 - v16;
    if ( v19 )
    {
      v21 = (const char **)malloc(0x20u);
      v40 = malloc(0x4008u);
      v23 = v40;
      v22 = malloc(0x200000u);
      ptr = v22;
      if ( v22 )
      {
        if ( v21 )
        {
          v24 = v19;
          if ( v40 )
          {
            v25 = v22;
            strlcpy(v22, v24, 0x200000);
            v26 = split_string(v25, 60, v40, 4096);
            if ( v26 > 0 )
            {
              for ( i = 0; i != v26; ++i )
              {
                v28 = split_string(*v23, 124, v21, 6);
                format_dns_more_dnswan_rule_data(v21, v28, &v18[v20], v17 - v20);
                v20 += v29;
                ++v23;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v21 )
        free(v21);
      if ( v40 )
        free(v40);
    }
    v30 = &v18[v20];
    if ( v20 > 0 && *(v30 - 1) == 44 )
      v30 = &v18[--v20];
    v31 = v17 - v20;
    *v30 = 0;
    v32 = snprintf(v30, v31, &byte_6445A0);
    if ( v32 >= v31 )
      v32 = v31 - 1;
    v33 = v20 + v32 + v16;
    v34 = snprintf(&v2[v33], 1024000 - v33, "}}");
    if ( v34 >= 1024000 - v33 )
      v35 = 1023999 - v33;
    else
      v35 = v34;
    result = httpd_cgi_ret(a1, v2, v35 + v33, 8);
  }
  else
  {
    v37 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v38 = snprintf(v39, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
    if ( v38 >= 0x100 )
      v38 = 255;
    result = httpd_cgi_ret(a1, v39, v38, 4);
  }
  return result;
}
// 4919C8: variable 'v1' is possibly undefined
// 491D50: variable 'v29' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8934: using guessed type int __fastcall dns_more_dnstype_get_json(_DWORD, _DWORD);

