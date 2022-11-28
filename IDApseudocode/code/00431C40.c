int __fastcall httpd_send_realm(int a1)
{
  const char *v2; // $v0
  const char *v3; // $s1
  size_t v4; // $v0
  int v5; // $v0
  int v6; // $v0
  int v7; // $v0
  int result; // $v0
  char v9[512]; // [sp+18h] [-200h] BYREF

  v2 = (const char *)nvram_get("router_name");
  if ( !v2 || (v3 = v2, !*v2) )
    v3 = "WAYOS";
  sprintf(v9, httpd_errtok[0], 401, "");
  v4 = strlen(v9);
  v5 = stpcpy(&v9[v4], httpd_servertok[0]);
  v6 = stpcpy(v5, httpd_ctclose[0]);
  strcpy((char *)v6, "WWW-Authenticate: Basic realm=\"");
  qmemcpy((void *)v6, "WWW-Authenticate: Ba", 20);
  *(_DWORD *)(v6 + 28) = 2243949;
  v7 = stpcpy(v6 + 31, v3);
  *(_DWORD *)v7 = 218762530;
  *(_DWORD *)v7 = 218762530;
  *(_BYTE *)(a1 + 41) = 2;
  *(_BYTE *)(v7 + 4) = 10;
  *(_BYTE *)(v7 + 5) = 0;
  *(_DWORD *)(a1 + 205392) = 0;
  result = httpd_send_data_alloc(a1, v9, v7 - (_DWORD)v9 + 5);
  if ( !result )
  {
    result = *(_DWORD *)(a1 + 205380);
    if ( !result )
      result = httpd_conn_close((int *)a1);
  }
  return result;
}
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D4: using guessed type char *httpd_errtok[15];
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A86C8: using guessed type int __fastcall stpcpy(_DWORD, _DWORD);

