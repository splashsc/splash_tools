int __fastcall httpd_send_404_info(int a1, char *a2, int a3)
{
  unsigned int v6; // $s5
  unsigned int v7; // $v0
  unsigned int v8; // $s5
  char **v9; // $v0
  unsigned int v10; // $v0
  unsigned int v11; // $s1
  unsigned int v12; // $v0
  int v13; // $a3
  unsigned int v14; // $v0
  unsigned int v15; // $s1
  unsigned int v16; // $v0
  unsigned int v17; // $s1
  unsigned int v18; // $v0
  bool v19; // dc
  int result; // $v0
  char v21[4096]; // [sp+20h] [-2000h] BYREF
  char v22[4096]; // [sp+1020h] [-1000h] BYREF

  memset(v22, 0, sizeof(v22));
  memset(v21, 0, sizeof(v21));
  v6 = snprintf(v22, 4096, httpd_errtok[0], 404, "Page Not found");
  if ( v6 >= 0x1000 )
    v6 = 4095;
  v7 = snprintf(&v22[v6], 4096 - v6, "%s", httpd_servertok[0]);
  if ( v7 >= 4096 - v6 )
    v7 = 4095 - v6;
  v8 = v7 + v6;
  if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    v9 = httpd_ctalive;
  else
    v9 = httpd_ctclose;
  v10 = snprintf(&v22[v8], 4096 - v8, "%s", *v9);
  if ( v10 >= 4096 - v8 )
    v10 = 4095 - v8;
  v11 = v10 + v8;
  if ( a3 )
    v12 = snprintf(v21, 4096, a2, a3);
  else
    v12 = snprintf(v21, 4096, "%s", a2);
  v13 = v12;
  if ( v12 >= 0x1000 )
    v13 = 4095;
  v14 = snprintf(&v22[v11], 4096 - v11, "Content-Length: %d\r\n", v13);
  if ( v14 >= 4096 - v11 )
    v14 = 4095 - v11;
  v15 = v14 + v11;
  v16 = snprintf(&v22[v15], 4096 - v15, "Content-Type: text/html;charset=gb2312\r\n\r\n");
  if ( v16 >= 4096 - v15 )
    v16 = 4095 - v15;
  v17 = v16 + v15;
  v18 = snprintf(&v22[v17], 4096 - v17, "%s", v21);
  if ( v18 >= 4096 - v17 )
    v18 = 4095 - v17;
  v19 = httpd_send_data_alloc(a1, v22, v18 + v17) != 0;
  result = 196608;
  if ( !v19 )
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
// 6676D4: using guessed type char *httpd_errtok[15];

