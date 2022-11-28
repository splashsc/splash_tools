int __fastcall httpd_send_html_file(int a1, const char *a2, char *a3, signed int a4)
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
  int v18; // $v1
  unsigned int v19; // $s0
  unsigned int v20; // $v0
  int v21; // $a0
  signed int v22; // $s0
  int v23; // $s0
  unsigned int v25; // $v0
  unsigned int v26; // $v0
  char v27[1400]; // [sp+18h] [-578h] BYREF

  v5 = httpd_oktok[0];
  *(_DWORD *)(a1 + 36) &= 0xFFFFFFFE;
  v9 = snprintf(v27, 1400, "%s", v5);
  if ( v9 >= 0x578 )
    v9 = 1399;
  v10 = snprintf(&v27[v9], 1400 - v9, "%s", httpd_servertok[0]);
  if ( v10 >= 1400 - v9 )
    v10 = 1399 - v9;
  v11 = v10 + v9;
  v12 = snprintf(&v27[v11], 1400 - v11, "%s", httpd_Accept_Ranges[0]);
  v13 = v12 + v11;
  if ( v12 >= 1400 - v11 )
    v13 = 1399;
  v14 = snprintf(&v27[v13], 1400 - v13, httpd_lengthtok[0], a4);
  if ( v14 >= 1400 - v13 )
    v14 = 1399 - v13;
  v15 = v14 + v13;
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v16 = httpd_ctalive;
  else
    v16 = httpd_ctclose;
  v17 = snprintf(&v27[v15], 1400 - v15, "%s", *v16);
  if ( v17 >= 1400 - v15 )
    v17 = 1399 - v15;
  v18 = *(_DWORD *)(a1 + 36);
  v19 = v17 + v15;
  if ( (v18 & 0x2000) != 0 )
  {
    v26 = snprintf(&v27[v19], 1400 - v19, "Content-Encoding: gzip\r\n");
    if ( v26 >= 1400 - v19 )
      v26 = 1399 - v19;
    v18 = *(_DWORD *)(a1 + 36);
    v19 += v26;
  }
  if ( (v18 & 0x4000) != 0 )
  {
    v25 = snprintf(&v27[v19], 1400 - v19, "Content-disposition: attachment; filename=%s\r\n", *(const char **)(a1 + 44));
    if ( v25 >= 1400 - v19 )
      v25 = 1399 - v19;
    v19 += v25;
  }
  v20 = snprintf(&v27[v19], 1400 - v19, "Content-Type: %s\r\n\r\n", a2);
  v21 = v20 + v19;
  if ( v20 >= 1400 - v19 )
    v21 = 1399;
  v22 = a4 + v21;
  if ( a4 + v21 >= 1400 )
  {
    if ( !httpd_send_data_alloc(a1, v27, v21) )
    {
      if ( !*(_DWORD *)(a1 + 205380) )
      {
        v23 = -1;
        if ( httpd_send_data_const(a1, a3, a4) )
          return v23;
        goto LABEL_21;
      }
      httpd_conn_close((int *)a1);
    }
    return -1;
  }
  memcpy(&v27[v21], a3, a4);
  if ( httpd_send_data_alloc(a1, v27, v22) )
    return -1;
LABEL_21:
  v23 = *(_DWORD *)(a1 + 205380);
  if ( v23 )
    return 0;
  httpd_conn_send_finish(a1);
  return v23;
}
// 6676B0: using guessed type char *httpd_Accept_Ranges[24];
// 6676B8: using guessed type char *httpd_lengthtok[22];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];

