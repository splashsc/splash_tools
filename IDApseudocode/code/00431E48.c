int __fastcall httpd_send_realm_admin(int a1)
{
  time_t v2; // $v0
  size_t v3; // $v0
  int v4; // $v0
  int v5; // $v0
  int v6; // $v0
  int result; // $v0
  char v8[1024]; // [sp+50h] [-670h] BYREF
  char v9[512]; // [sp+450h] [-270h] BYREF
  unsigned int v10[22]; // [sp+650h] [-70h] BYREF
  int v11; // [sp+6A8h] [-18h]
  int v12; // [sp+6ACh] [-14h]
  int v13; // [sp+6B0h] [-10h]
  int v14; // [sp+6B4h] [-Ch]
  time_t v15; // [sp+6B8h] [-8h]

  v2 = time(0);
  v15 = v2;
  if ( !jhl_realm_init )
  {
    jhl_realm_str = v2;
    *(_DWORD *)&byte_6A38E4 = v2;
    *(_DWORD *)&byte_6A38E8 = v2;
    jhl_realm_init = 1;
    dword_6A38EC = v2;
  }
  FBR_MD5Init(v10);
  FBR_MD5Update(v10, (int)&jhl_realm_str, 0x10u);
  FBR_MD5Final(v10);
  jhl_realm_str = v11;
  *(_DWORD *)&byte_6A38E4 = v12;
  *(_DWORD *)&byte_6A38E8 = v13;
  dword_6A38EC = v14;
  sprintf(
    v9,
    "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned __int8)v11,
    BYTE1(v11),
    BYTE2(v11),
    HIBYTE(v11),
    (unsigned __int8)v12,
    BYTE1(v12),
    BYTE2(v12),
    HIBYTE(v12),
    (unsigned __int8)v13,
    BYTE1(v13),
    BYTE2(v13),
    HIBYTE(v13),
    (unsigned __int8)v14,
    BYTE1(v14),
    BYTE2(v14),
    HIBYTE(v14));
  sprintf(v8, httpd_errtok[0], 401, "");
  v3 = strlen(v8);
  v4 = stpcpy(&v8[v3], httpd_servertok[0]);
  v5 = stpcpy(v4, httpd_ctclose[0]);
  strcpy((char *)v5, "WWW-Authenticate: Basic realm=\"");
  qmemcpy((void *)v5, "WWW-Authenticate: Ba", 20);
  *(_DWORD *)(v5 + 28) = 2243949;
  v6 = stpcpy(v5 + 31, v9);
  *(_DWORD *)v6 = 218762530;
  *(_DWORD *)v6 = 218762530;
  *(_BYTE *)(a1 + 41) = 2;
  *(_BYTE *)(v6 + 4) = 10;
  *(_BYTE *)(v6 + 5) = 0;
  *(_DWORD *)(a1 + 205392) = 0;
  result = httpd_send_data_alloc(a1, v8, v6 - (_DWORD)v8 + 5);
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
// 67D2E0: using guessed type int jhl_realm_init;
// 6A38E0: using guessed type int jhl_realm_str;
// 6A38E4: using guessed type char byte_6A38E4;
// 6A38E8: using guessed type char byte_6A38E8;
// 6A38EC: using guessed type int dword_6A38EC;
// 6A86C8: using guessed type int __fastcall stpcpy(_DWORD, _DWORD);

