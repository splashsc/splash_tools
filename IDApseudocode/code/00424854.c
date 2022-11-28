int __fastcall httpd_send_info(int a1, char *a2, int a3)
{
  unsigned int v6; // $s7
  unsigned int v7; // $v0
  unsigned int v8; // $s0
  char **v9; // $v0
  unsigned int v10; // $v0
  unsigned int v11; // $s0
  unsigned int v12; // $v0
  unsigned int v13; // $s0
  unsigned int v14; // $v0
  unsigned int v15; // $s0
  unsigned int v16; // $v0
  bool v17; // dc
  int result; // $v0
  char v19[4100]; // [sp+18h] [-1004h] BYREF

  v6 = snprintf(v19, 4096, "%s", httpd_oktok[0]);
  if ( v6 >= 0x1000 )
    v6 = 4095;
  v7 = snprintf(&v19[v6], 4096 - v6, "%s", httpd_servertok[0]);
  if ( v7 >= 4096 - v6 )
    v7 = 4095 - v6;
  v8 = v7 + v6;
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v9 = httpd_ctalive;
  else
    v9 = httpd_ctclose;
  v10 = snprintf(&v19[v8], 4096 - v8, "%s", *v9);
  if ( v10 >= 4096 - v8 )
    v10 = 4095 - v8;
  v11 = v10 + v8;
  v12 = snprintf(&v19[v11], 4096 - v11, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
  if ( v12 >= 4096 - v11 )
    v12 = 4095 - v11;
  v13 = v12 + v11;
  v14 = snprintf(&v19[v13], 4096 - v13, "Content-Type: text/html;charset=gb2312\r\n\r\n");
  if ( v14 >= 4096 - v13 )
    v14 = 4095 - v13;
  v15 = v14 + v13;
  if ( a3 )
  {
    v16 = snprintf(&v19[v15], 4096 - v15, a2, a3);
    if ( v16 < 4096 - v15 )
      goto LABEL_15;
  }
  else
  {
    v16 = snprintf(&v19[v15], 4096 - v15, "%s", a2);
    if ( v16 < 4096 - v15 )
      goto LABEL_15;
  }
  v16 = 4095 - v15;
LABEL_15:
  v17 = httpd_send_data_alloc(a1, v19, v16 + v15) != 0;
  result = 196608;
  if ( !v17 )
  {
    result = *(_DWORD *)(a1 + 205380);
    if ( !result )
      result = httpd_conn_send_finish(a1);
  }
  return result;
}
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];

