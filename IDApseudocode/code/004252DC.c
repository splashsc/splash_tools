int __fastcall httpd_send_mime_file(int a1, const char *a2, void *a3, int a4)
{
  const char *v5; // $a3
  unsigned int v9; // $s1
  unsigned int v10; // $v0
  unsigned int v11; // $s1
  unsigned int v12; // $v0
  int v13; // $s2
  unsigned int v14; // $v0
  unsigned int v15; // $s1
  char **v16; // $v0
  unsigned int v17; // $v0
  unsigned int v18; // $s0
  unsigned int v19; // $v0
  signed int v20; // $a0
  signed int v21; // $s0
  int v22; // $s0
  unsigned int v24; // $v0
  unsigned int v25; // $v0
  char v26[1400]; // [sp+18h] [-578h] BYREF

  v5 = httpd_oktok[0];
  *(_DWORD *)(a1 + 36) &= 0xFFFFFFFE;
  v9 = snprintf(v26, 1400, "%s", v5);
  if ( v9 >= 0x578 )
    v9 = 1399;
  v10 = snprintf(&v26[v9], 1400 - v9, "%s", httpd_servertok[0]);
  if ( v10 >= 1400 - v9 )
    v10 = 1399 - v9;
  v11 = v10 + v9;
  v12 = snprintf(&v26[v11], 1400 - v11, "%s", httpd_Accept_Ranges[0]);
  v13 = v12 + v11;
  if ( v12 >= 1400 - v11 )
    v13 = 1399;
  v14 = snprintf(&v26[v13], 1400 - v13, httpd_lengthtok[0], a4);
  if ( v14 >= 1400 - v13 )
    v14 = 1399 - v13;
  v15 = v14 + v13;
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v16 = httpd_ctalive;
  else
    v16 = httpd_ctclose;
  v17 = snprintf(&v26[v15], 1400 - v15, "%s", *v16);
  if ( v17 >= 1400 - v15 )
    v17 = 1399 - v15;
  v18 = v17 + v15;
  if ( (*(_DWORD *)(a1 + 36) & 0x2000) == 0 )
  {
    if ( (*(_DWORD *)(a1 + 36) & 0x4000) == 0 )
      goto LABEL_15;
    goto LABEL_30;
  }
  v24 = snprintf(&v26[v18], 1400 - v18, "Content-Encoding: gzip\r\n");
  if ( v24 >= 1400 - v18 )
    v24 = 1399 - v18;
  v18 += v24;
  if ( (*(_DWORD *)(a1 + 36) & 0x4000) != 0 )
  {
LABEL_30:
    v25 = snprintf(&v26[v18], 1400 - v18, "Content-disposition: attachment; filename=%s\r\n", *(const char **)(a1 + 44));
    if ( v25 >= 1400 - v18 )
      v25 = 1399 - v18;
    v18 += v25;
  }
LABEL_15:
  v19 = snprintf(&v26[v18], 1400 - v18, "Content-Type: %s\r\n\r\n", a2);
  v20 = v18 + v19;
  if ( v19 >= 1400 - v18 )
    v20 = 1399;
  v21 = a4 + v20;
  if ( a4 + v20 < 1400 )
  {
    memcpy(&v26[v20], a3, a4);
    _mem_free(a3);
    if ( httpd_send_data_alloc(a1, v26, v21) )
      return -1;
    goto LABEL_25;
  }
  if ( httpd_send_data_alloc(a1, v26, v20) )
  {
    if ( a3 )
    {
      v22 = -1;
      _mem_free(a3);
      return v22;
    }
    return -1;
  }
  if ( !*(_DWORD *)(a1 + 205380) )
  {
    v22 = -1;
    if ( httpd_send_data_not_alloc(a1, (char *)a3, a4) )
      return v22;
LABEL_25:
    v22 = *(_DWORD *)(a1 + 205380);
    if ( v22 )
      return 0;
    httpd_conn_send_finish(a1);
    return v22;
  }
  if ( a3 )
    _mem_free(a3);
  httpd_conn_close((int *)a1);
  return -1;
}
// 6676B0: using guessed type char *httpd_Accept_Ranges[24];
// 6676B8: using guessed type char *httpd_lengthtok[22];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];

