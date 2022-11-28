int __fastcall httpd_send_big_file_ll(int a1, int a2, unsigned int a3, signed int a4)
{
  const char *v4; // $s0
  const char *v9; // $s2
  char *v10; // $v0
  int v11; // $v1
  char *v12; // $s0
  unsigned int v13; // $s0
  __int64 v14; // $v0
  int v15; // $fp
  unsigned int v16; // $s7
  signed int v17; // $s5
  _BOOL4 v18; // $v0
  unsigned int v19; // $fp
  unsigned int v20; // $v0
  int v21; // $s5
  unsigned int v22; // $v0
  unsigned int v23; // $fp
  unsigned int v24; // $v0
  unsigned int v25; // $t0
  unsigned int v26; // $fp
  char **v27; // $v0
  const char *v28; // $a3
  unsigned int v29; // $v0
  int v30; // $v1
  unsigned int v31; // $s0
  char *v32; // $v0
  unsigned int v33; // $v0
  const char *v34; // $v0
  unsigned int v35; // $s0
  unsigned int v36; // $v0
  int v37; // $s0
  unsigned int v39; // $v0
  unsigned int v40; // $v0
  __int64 v41; // kr00_8
  __int64 v42; // kr08_8
  char v43[2048]; // [sp+38h] [-888h] BYREF
  char v44[128]; // [sp+838h] [-88h] BYREF
  unsigned int v45; // [sp+8B8h] [-8h]
  unsigned int v46; // [sp+8BCh] [-4h]

  v4 = *(const char **)(a1 + 205532);
  *(_DWORD *)(a1 + 36) &= 0xFFFFFFFE;
  if ( !v4 )
    goto LABEL_9;
  if ( (*(_DWORD *)(a1 + 32) & 0x20000) == 0 )
    goto LABEL_9;
  v9 = v4 + 6;
  if ( strncmp(v4, "bytes=", 6u) )
    goto LABEL_9;
  v10 = strchr(v4 + 6, 45);
  if ( !v10 )
    goto LABEL_9;
  *v10 = 0;
  v11 = v4[6];
  v12 = v10 + 1;
  if ( v11 )
  {
    v41 = J_atoi_ull(v9);
    v17 = HIDWORD(v41);
    v16 = v41;
    v42 = J_atoi_ull(v12);
    v15 = HIDWORD(v42);
    v13 = v42;
    if ( !v42 )
    {
      v13 = a3 - 1;
      v15 = (a3 != 0) + a4 - 1;
    }
  }
  else
  {
    v13 = a3 - 1;
    v15 = (a3 != 0) + a4 - 1;
    v14 = J_atoi_ull(v10 + 1);
    v16 = a3 - v14;
    v17 = (__PAIR64__(a4, a3) - __PAIR64__(HIDWORD(v14), a3 - (unsigned int)v14)) >> 32;
  }
  if ( ((v18 = v15 < v17, v17 < a4) || a4 == v17 && (v18 = v15 < v17, v16 < a3)) && !v18 && (v17 != v15 || v13 >= v16) )
  {
    v46 = v13 - v16 + 1;
    v45 = (__PAIR64__(v15, v13) - __PAIR64__(v17, v16) + 1) >> 32;
    v23 = snprintf(
            v43,
            2048,
            "HTTP/1.1 206 Partial Content\r\nContent-Length: %lld\r\nContent-Range: bytes %lld-%lld/%lld\r\n",
            __PAIR64__(v15, v13) - __PAIR64__(v17, v16) + 1,
            __PAIR64__(v17, v16),
            __PAIR64__(v15, v13),
            __PAIR64__(a4, a3));
    if ( v23 >= 0x800 )
      v23 = 2047;
    a3 = v46;
    a4 = v45;
  }
  else
  {
LABEL_9:
    v19 = snprintf(v43, 2048, "%s", httpd_oktok[0]);
    if ( v19 >= 0x800 )
      v19 = 2047;
    v20 = snprintf(&v43[v19], 2048 - v19, "%s", httpd_Accept_Ranges[0]);
    v21 = v20 + v19;
    if ( v20 >= 2048 - v19 )
      v21 = 2047;
    v22 = snprintf(&v43[v21], 2048 - v21, httpd_lengthtok_ll[0]);
    if ( v22 >= 2048 - v21 )
      v22 = 2047 - v21;
    v23 = v22 + v21;
    v16 = 0;
  }
  v45 = 2048 - v23;
  v24 = snprintf(&v43[v23], 2048 - v23, "%s", httpd_servertok[0]);
  if ( v24 >= v45 )
    v24 = 2047 - v23;
  v25 = v24 + v23;
  v26 = 2048 - (v24 + v23);
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v27 = httpd_ctalive;
  else
    v27 = httpd_ctclose;
  v28 = *v27;
  v45 = v25;
  v29 = snprintf(&v43[v25], v26, "%s", v28);
  if ( v29 >= v26 )
    v29 = 2047 - v45;
  v30 = *(_DWORD *)(a1 + 36);
  v31 = v29 + v45;
  if ( (v30 & 0x2000) != 0 )
  {
    v40 = snprintf(&v43[v31], 2048 - v31, "Content-Encoding: gzip\r\n");
    if ( v40 >= 2048 - v31 )
      v40 = 2047 - v31;
    v30 = *(_DWORD *)(a1 + 36);
    v31 += v40;
  }
  if ( (v30 & 0x4000) != 0 )
  {
    v39 = snprintf(&v43[v31], 2048 - v31, "Content-disposition: attachment; filename=%s\r\n", *(const char **)(a1 + 44));
    if ( v39 >= 2048 - v31 )
      v39 = 2047 - v31;
    v31 += v39;
  }
  v32 = GetDateString(v44, 0);
  v33 = snprintf(&v43[v31], 2048 - v31, "Date: %s\r\n", v32);
  if ( v33 >= 2048 - v31 )
    v33 = 2047 - v31;
  v35 = v33 + v31;
  v34 = httpd_find_type2((const char *)a2);
  v36 = snprintf(&v43[v35], 2048 - v35, "Content-Type: %s\r\n\r\n", v34);
  if ( v36 >= 2048 - v35 )
    v36 = 2047 - v35;
  if ( httpd_send_data_alloc(a1, v43, v36 + v35) )
    return -1;
  v37 = httpd_send_data_file_ll(a1, (const char *)a2, a3, a4, v16);
  if ( v37 )
    return -1;
  if ( !*(_QWORD *)(a1 + 205384) )
    httpd_conn_send_finish(a1);
  return v37;
}
// 6676B0: using guessed type char *httpd_Accept_Ranges[24];
// 6676B4: using guessed type char *httpd_lengthtok_ll[23];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];
// 6A83B0: using guessed type __int64 __fastcall J_atoi_ull(_DWORD);

