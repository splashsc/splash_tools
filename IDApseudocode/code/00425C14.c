int __fastcall httpd_send_big_file(int a1, int a2, unsigned int a3)
{
  const char *v3; // $s0
  const char *v7; // $s2
  char *v8; // $v0
  int v9; // $v1
  char *v10; // $s0
  int v11; // $v0
  unsigned int v12; // $v1
  unsigned int v13; // $s5
  unsigned int v14; // $s6
  unsigned int v15; // $v0
  unsigned int v16; // $s6
  unsigned int v17; // $v0
  unsigned int v18; // $s7
  unsigned int v19; // $v0
  unsigned int v20; // $s6
  char **v21; // $v0
  unsigned int v22; // $v0
  int v23; // $v1
  unsigned int v24; // $s0
  char *v25; // $v0
  unsigned int v26; // $v0
  unsigned int v27; // $s0
  const char *v28; // $v0
  unsigned int v29; // $v0
  int v30; // $s0
  unsigned int v32; // $v0
  unsigned int v33; // $v0
  unsigned int v34; // $s0
  char v35[2048]; // [sp+28h] [-880h] BYREF
  char v36[128]; // [sp+828h] [-80h] BYREF

  v3 = *(const char **)(a1 + 205532);
  *(_DWORD *)(a1 + 36) &= 0xFFFFFFFE;
  if ( !v3 )
    goto LABEL_9;
  if ( (*(_DWORD *)(a1 + 32) & 0x20000) == 0 )
    goto LABEL_9;
  v7 = v3 + 6;
  if ( strncmp(v3, "bytes=", 6u) )
    goto LABEL_9;
  v8 = strchr(v3 + 6, 45);
  if ( !v8 )
    goto LABEL_9;
  *v8 = 0;
  v9 = v3[6];
  v10 = v8 + 1;
  if ( v9 )
  {
    v13 = J_atoi(v7);
    v12 = J_atoi(v10);
    if ( !v12 )
      v12 = a3 - 1;
  }
  else
  {
    v11 = J_atoi(v8 + 1);
    v12 = a3 - 1;
    v13 = a3 - v11;
  }
  if ( v13 < a3 && v12 >= v13 )
  {
    v34 = v12 + 1 - v13;
    v18 = snprintf(
            v35,
            2048,
            "HTTP/1.1 206 Partial Content\r\nContent-Length: %u\r\nContent-Range: bytes %u-%u/%u\r\n",
            v34,
            v13,
            v12,
            a3);
    if ( v18 >= 0x800 )
      v18 = 2047;
    a3 = v34;
  }
  else
  {
LABEL_9:
    v14 = snprintf(v35, 2048, "%s", httpd_oktok[0]);
    if ( v14 >= 0x800 )
      v14 = 2047;
    v15 = snprintf(&v35[v14], 2048 - v14, "%s", httpd_Accept_Ranges[0]);
    if ( v15 >= 2048 - v14 )
      v15 = 2047 - v14;
    v16 = v15 + v14;
    v17 = snprintf(&v35[v16], 2048 - v16, httpd_lengthtok[0], a3);
    if ( v17 >= 2048 - v16 )
      v17 = 2047 - v16;
    v18 = v17 + v16;
    v13 = 0;
  }
  v19 = snprintf(&v35[v18], 2048 - v18, "%s", httpd_servertok[0]);
  if ( v19 >= 2048 - v18 )
    v19 = 2047 - v18;
  v20 = v19 + v18;
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v21 = httpd_ctalive;
  else
    v21 = httpd_ctclose;
  v22 = snprintf(&v35[v20], 2048 - v20, "%s", *v21);
  if ( v22 >= 2048 - v20 )
    v22 = 2047 - v20;
  v23 = *(_DWORD *)(a1 + 36);
  v24 = v22 + v20;
  if ( (v23 & 0x2000) != 0 )
  {
    v33 = snprintf(&v35[v24], 2048 - v24, "Content-Encoding: gzip\r\n");
    if ( v33 >= 2048 - v24 )
      v33 = 2047 - v24;
    v23 = *(_DWORD *)(a1 + 36);
    v24 += v33;
  }
  if ( (v23 & 0x4000) != 0 )
  {
    v32 = snprintf(&v35[v24], 2048 - v24, "Content-disposition: attachment; filename=%s\r\n", *(const char **)(a1 + 44));
    if ( v32 >= 2048 - v24 )
      v32 = 2047 - v24;
    v24 += v32;
  }
  v25 = GetDateString(v36, 0);
  v26 = snprintf(&v35[v24], 2048 - v24, "Date: %s\r\n", v25);
  if ( v26 >= 2048 - v24 )
    v26 = 2047 - v24;
  v27 = v26 + v24;
  v28 = httpd_find_type2((const char *)a2);
  v29 = snprintf(&v35[v27], 2048 - v27, "Content-Type: %s\r\n\r\n", v28);
  if ( v29 >= 2048 - v27 )
    v29 = 2047 - v27;
  if ( httpd_send_data_alloc(a1, v35, v29 + v27) )
    return -1;
  v30 = httpd_send_data_file(a1, (const char *)a2, a3, v13);
  if ( v30 )
    return -1;
  if ( !*(_DWORD *)(a1 + 205380) )
    httpd_conn_send_finish(a1);
  return v30;
}
// 6676B0: using guessed type char *httpd_Accept_Ranges[24];
// 6676B8: using guessed type char *httpd_lengthtok[22];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

