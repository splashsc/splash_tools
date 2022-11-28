int __fastcall httpd_start(int a1, int a2)
{
  unsigned int v4; // $s5
  unsigned int v5; // $v0
  unsigned int v6; // $s5
  unsigned int v7; // $s0
  int v8; // $v0
  int v9; // $s5
  unsigned int v10; // $v0
  unsigned int v11; // $s0
  char **v12; // $v0
  unsigned int v13; // $s6
  unsigned int v14; // $v0
  unsigned int v15; // $v0
  unsigned int v16; // $s0
  unsigned int v17; // $v0
  char *v18; // $v0
  unsigned int v19; // $v0
  unsigned int v20; // $s0
  unsigned int v21; // $v0
  int result; // $v0
  unsigned int v23; // $v0
  unsigned int v24; // $v0
  unsigned int v25; // $v0
  char v26[1024]; // [sp+18h] [-480h] BYREF
  char v27[128]; // [sp+418h] [-80h] BYREF

  if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
    *(_DWORD *)(a1 + 36) |= 1u;
  v4 = snprintf(v26, 1024, "%s", httpd_oktok[0]);
  if ( v4 >= 0x400 )
    v4 = 1023;
  v5 = snprintf(&v26[v4], 1024 - v4, "%s", httpd_servertok[0]);
  if ( v5 >= 1024 - v4 )
    v5 = 1023 - v4;
  v6 = v5 + v4;
  v7 = v6;
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 205392) + 16) == 2 )
  {
    v25 = snprintf(&v26[v6], 1024 - v6, "%s", "Content-Encoding: gzip\r\n");
    if ( v25 >= 1024 - v6 )
      v25 = 1023 - v6;
    v7 = v25 + v6;
  }
  if ( (*(_DWORD *)(a1 + 36) & 0x1000) != 0 )
  {
    v24 = snprintf(&v26[v7], 1024 - v7, "Set-Cookie: %s; path=/\r\n", httpd_set_cookie);
    if ( v24 >= 1024 - v7 )
      v24 = 1023 - v7;
    *(_DWORD *)(a1 + 36) &= 0xFFFFEFFF;
    v7 += v24;
    memset(httpd_set_cookie, 0, sizeof(httpd_set_cookie));
  }
  v8 = *(_DWORD *)(a1 + 205392);
  if ( *(_DWORD *)(v8 + 16) == 1 || *(_BYTE *)(a1 + 43) == 3 )
  {
    *(_DWORD *)(a1 + 36) &= 0xFFFFFFFE;
    v14 = snprintf(&v26[v7], 1024 - v7, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
    if ( v14 >= 1024 - v7 )
      v14 = 1023 - v7;
    v11 = v14 + v7;
    *(_DWORD *)(a1 + 36) = 0;
    v9 = 0;
  }
  else
  {
    v9 = *(_DWORD *)(v8 + 20);
    v10 = snprintf(&v26[v7], 1024 - v7, "Last-modified: %s\r\n", *(const char **)(v8 + 28));
    if ( v10 >= 1024 - v7 )
      v10 = 1023 - v7;
    v11 = v10 + v7;
    if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
    {
      v12 = httpd_ctalive;
      v13 = 1024 - v11;
      goto LABEL_19;
    }
  }
  v12 = httpd_ctclose;
  v13 = 1024 - v11;
LABEL_19:
  v15 = snprintf(&v26[v11], v13, "%s", *v12);
  if ( v15 >= v13 )
    v15 = 1023 - v11;
  v16 = v15 + v11;
  if ( a2 )
  {
    v17 = snprintf(&v26[v16], 1024 - v16, httpd_typetok[0], a2);
    if ( v17 >= 1024 - v16 )
      v17 = 1023 - v16;
    v16 += v17;
  }
  if ( v9 )
  {
    v23 = snprintf(&v26[v16], 1024 - v16, httpd_lengthtok[0], v9);
    if ( v23 >= 1024 - v16 )
      v23 = 1023 - v16;
    v16 += v23;
  }
  v18 = GetDateString(v27, 0);
  v19 = snprintf(&v26[v16], 1024 - v16, "Date: %s\r\n", v18);
  if ( v19 >= 1024 - v16 )
    v19 = 1023 - v16;
  v20 = v19 + v16;
  v21 = snprintf(&v26[v20], 1024 - v20, "\r\n");
  if ( v21 >= 1024 - v20 )
    v21 = 1023 - v20;
  result = httpd_send_data_alloc(a1, v26, v21 + v20);
  if ( result )
    return -1;
  if ( !*(_DWORD *)(a1 + 205380) )
    result = httpd_send_continue(a1);
  return result;
}
// 6676B8: using guessed type char *httpd_lengthtok[22];
// 6676BC: using guessed type char *httpd_typetok[21];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];

