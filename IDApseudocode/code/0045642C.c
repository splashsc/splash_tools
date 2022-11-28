int __fastcall spqos_data(const char *a1, int a2)
{
  int v2; // $v0
  int v3; // $fp
  _BYTE *v4; // $s2
  int v5; // $s0
  const char **v6; // $s1
  void *v7; // $v0
  _DWORD *v8; // $s5
  int v9; // $a1
  void *v10; // $s0
  int v11; // $s4
  _DWORD *v12; // $s6
  int v13; // $s0
  int i; // $s7
  int v15; // $v0
  int v16; // $v0
  int v17; // $s3
  char *v18; // $a0
  int v19; // $v0
  int v20; // $s0
  int v21; // $v0
  int v22; // $s0
  _DWORD *v23; // $v0
  int v24; // $v0
  int v25; // $a0
  const char *v26; // $a1
  int v27; // $a2
  int v28; // $a3
  int v29; // $a2
  char v30; // $t0
  char v31; // $a3
  int v32; // $s0
  int v33; // $a2
  const char *v35; // $s1
  const char *v36; // $v0
  const char *v37; // $v0
  unsigned int v38; // $v0
  char v39[64]; // [sp+20h] [-88h] BYREF
  char v40[64]; // [sp+60h] [-48h] BYREF
  void *ptr; // [sp+A0h] [-8h]

  memset(v39, 0, sizeof(v39));
  _mem_malloc(0x200000, "spqos_data", 260);
  if ( v2 )
  {
    v3 = v2;
    snprintf(v39, 64, "sqos_%s", a1);
    v4 = (_BYTE *)(v3 + 47);
    strcpy((char *)v3, "{\"code\":0,\"error\":\"\",\"data\":{\"sqos3\":\"1\",\"all\":");
    qmemcpy((void *)v3, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v3 + 24) = 975331700;
    *(_DWORD *)(v3 + 29) = 1869706018;
    *(_DWORD *)(v3 + 33) = 975319923;
    v5 = nvram_get(v39);
    *(_BYTE *)(v3 + 47) = 91;
    *(_BYTE *)(v3 + 48) = 0;
    if ( v5 )
    {
      v6 = (const char **)malloc(0x4Cu);
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
            v15 = split_string(*v12, 124, v6, 17);
            format_spqos_data(v6, v15, &v4[v13], 2097105 - v13);
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
        v19 = snprintf(v18, 2097105 - v13, &byte_6445A0);
        if ( v19 >= 2097105 - v13 )
          v19 = 2097104 - v13;
        v20 = v13 + v19;
        v21 = v3 + v20 + 47;
        strcpy((char *)v21, ",\"wans\":");
        *(_DWORD *)v21 = 1635197484;
        *(_DWORD *)(v21 + 4) = 975336302;
        v22 = v20 + 55 + get_wans_data((char *)(v3 + v20 + 55), 0x200000 - (v20 + 55));
        v23 = (_DWORD *)(v3 + v22);
        strcpy((char *)(v3 + v22), ",\"vpns\":");
        *v23 = 1886790188;
        v23[1] = 975336302;
        v24 = v22 + 8 + get_vpns_iface((_BYTE *)(v3 + v22 + 8));
        v25 = v3 + v24;
        v26 = ",\"qos_flowed\":\"1\",\"flowed_enable\":\"1\"";
        do
        {
          v27 = *((_DWORD *)v26 + 1);
          *(_DWORD *)v25 = *(_DWORD *)v26;
          *(_DWORD *)(v25 + 4) = v27;
          v28 = *((_DWORD *)v26 + 2);
          *(_DWORD *)(v25 + 4) = v27;
          *(_DWORD *)(v25 + 8) = v28;
          v29 = *((_DWORD *)v26 + 3);
          *(_DWORD *)(v25 + 8) = v28;
          *(_DWORD *)(v25 + 12) = v29;
          v26 += 16;
          *(_DWORD *)(v25 + 12) = v29;
          v25 += 16;
        }
        while ( v26 != "\":\"1\"" );
        v30 = v26[4];
        v31 = v26[5];
        *(_DWORD *)v25 = *(_DWORD *)v26;
        *(_BYTE *)(v25 + 4) = v30;
        *(_BYTE *)(v25 + 5) = v31;
        v32 = v24 + 37;
        if ( !strcmp(a1, "xz") )
        {
          v35 = (const char *)jhl_nv_get_def("qos_sp_ct_up");
          v36 = (const char *)jhl_nv_get_def("qos_sp_ct_dw");
          v32 += sprintf((char *)(v3 + v32), ",\"ct_up\":\"%s\",\"ct_dw\":\"%s\"", v35, v36);
        }
        v33 = snprintf((char *)(v3 + v32), 0x200000 - v32, "}}");
        if ( v33 >= 0x200000 - v32 )
          v33 = 0x1FFFFF - v32;
        return httpd_cgi_ret(a2, (char *)v3, v32 + v33, 8);
      }
    }
    else
    {
      v18 = (char *)(v3 + 48);
      v13 = 1;
      if ( *v4 != 44 )
        goto LABEL_17;
    }
    v18 = &v4[--v13];
    goto LABEL_17;
  }
  v37 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a2 + 210102), 0x200000);
  v38 = snprintf(v40, 64, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
  if ( v38 >= 0x40 )
    v38 = 63;
  return httpd_cgi_ret(a2, v40, v38, 4);
}
// 4564A8: variable 'v2' is possibly undefined
// 45669C: variable 'v16' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64331C: using guessed type int dword_64331C;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6459A8: using guessed type int dword_6459A8;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

