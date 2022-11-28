int __fastcall sub_4C3CB0(int a1)
{
  char *v1; // $v1
  char **v2; // $v0
  char *v3; // $t0
  char *v4; // $a3
  char *v5; // $a2
  char *v6; // $a1
  char *v7; // $a0
  char *v8; // $v0
  int v9; // $v0
  char *v10; // $s6
  _BYTE *v11; // $s2
  int v12; // $s0
  void *v13; // $s1
  void *v14; // $v0
  void *v15; // $s5
  int v16; // $s3
  int v17; // $a1
  void *v18; // $s0
  int v19; // $s4
  _DWORD *v20; // $s7
  int v21; // $s0
  int i; // $fp
  int v23; // $v0
  int v24; // $v0
  char *v25; // $a0
  int v26; // $v0
  int v27; // $s0
  char *v28; // $v0
  int v29; // $s0
  char *v30; // $v0
  int v31; // $s0
  char *v32; // $v0
  int v33; // $v0
  int v34; // $s0
  char *v35; // $v0
  const char **v36; // $a0
  int v37; // $s0
  int v38; // $a2
  const char *v40; // $v0
  unsigned int v41; // $v0
  char v42[256]; // [sp+20h] [-130h] BYREF
  char v43[40]; // [sp+120h] [-30h] BYREF
  char *v44; // [sp+148h] [-8h]
  void *ptr; // [sp+14Ch] [-4h]

  v1 = v43;
  v44 = v43;
  v2 = off_678AF0;
  do
  {
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)v1 = v3;
    *((_DWORD *)v1 + 1) = v4;
    *((_DWORD *)v1 + 2) = v5;
    *((_DWORD *)v1 + 3) = v6;
    v1 += 16;
  }
  while ( v2 != (char **)&off_678B10 );
  v7 = *v2;
  v8 = v2[1];
  *(_DWORD *)v1 = v7;
  *((_DWORD *)v1 + 1) = v8;
  _mem_malloc(0x200000, "mrprot_data", 851);
  v10 = (char *)v9;
  if ( v9 )
  {
    strcpy((char *)v9, "{\"code\":0,\"error\":\"\",\"data\":{\"all\":");
    qmemcpy((void *)v9, "{\"code\":0,\"e", 12);
    *(_DWORD *)(v9 + 24) = 975331700;
    *(_BYTE *)(v9 + 32) = 108;
    v11 = (_BYTE *)(v9 + 35);
    v12 = nvram_get("mrprot2");
    v10[35] = 91;
    v10[36] = 0;
    if ( !v12 )
    {
      v25 = v10 + 36;
      v21 = 1;
      if ( *v11 != 44 )
        goto LABEL_19;
      goto LABEL_26;
    }
    v13 = malloc(0x38u);
    v15 = malloc(0x4008u);
    v14 = malloc(0x200000u);
    ptr = v14;
    v16 = 1;
    if ( !v14 )
    {
      v21 = 1;
LABEL_13:
      if ( v13 )
        free(v13);
      if ( v15 )
        free(v15);
      if ( v21 <= 0 )
      {
        v25 = &v11[v16];
        goto LABEL_19;
      }
      v25 = &v11[v16];
      if ( v11[v16 - 1] != 44 )
      {
LABEL_19:
        *v25 = 0;
        v26 = snprintf(v25, 2097117 - v21, &byte_6445A0);
        if ( v26 >= 2097117 - v21 )
          v26 = 2097116 - v21;
        v27 = v21 + v26;
        v28 = &v10[v27 + 35];
        strcpy(v28, ",\"wans\":");
        *(_DWORD *)v28 = 1635197484;
        *((_DWORD *)v28 + 1) = 975336302;
        v29 = v27 + 43 + get_wans_data(&v10[v27 + 43], 0x200000 - (v27 + 43));
        v30 = &v10[v29];
        strcpy(&v10[v29], ",\"vpns\":");
        *(_DWORD *)v30 = 1886790188;
        *((_DWORD *)v30 + 1) = 975336302;
        v31 = v29 + 8 + get_vpns_iface(&v10[v29 + 8]);
        v32 = &v10[v31];
        strcpy(&v10[v31], ",\"type\":");
        *(_DWORD *)v32 = 2037654060;
        *((_DWORD *)v32 + 1) = 975332720;
        v33 = v31 + 8 + get_mrcl_type_data((int)&v10[v31 + 8]);
        v34 = v33 + 1;
        v35 = &v10[v33];
        v36 = (const char **)v44;
        *v35 = 44;
        v35[1] = 0;
        v37 = v34 + get_nvarms(v36, (int)&v10[v34], 0x200000 - v34) - 1;
        v38 = snprintf(&v10[v37], 0x200000 - v37, "}}");
        if ( v38 >= 0x200000 - v37 )
          v38 = 0x1FFFFF - v37;
        return httpd_cgi_ret(a1, v10, v38 + v37, 8);
      }
LABEL_26:
      v25 = &v11[--v21];
      goto LABEL_19;
    }
    if ( v13 )
    {
      v17 = v12;
      if ( v15 )
      {
        v18 = v14;
        strlcpy(v14, v17, 0x200000);
        v19 = split_string(v18, 60, v15, 4096);
        if ( v19 > 0 )
        {
          v20 = v15;
          v21 = 1;
          for ( i = 0; i != v19; ++i )
          {
            v23 = split_string(*v20, 124, v13, 12);
            format_mrprot_data((const char **)v13, v23, &v11[v21], 2097117 - v21);
            v21 += v24;
            ++v20;
          }
          v16 = v21;
          goto LABEL_12;
        }
        v16 = 1;
      }
    }
    v21 = 1;
LABEL_12:
    free(ptr);
    goto LABEL_13;
  }
  v40 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v41 = snprintf(v42, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v40);
  if ( v41 >= 0x100 )
    v41 = 255;
  return httpd_cgi_ret(a1, v42, v41, 4);
}
// 4C3D64: variable 'v9' is possibly undefined
// 4C3F14: variable 'v24' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64331C: using guessed type int dword_64331C;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6459A8: using guessed type int dword_6459A8;
// 678AF0: using guessed type char *off_678AF0[8];
// 678B10: using guessed type void *off_678B10;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

