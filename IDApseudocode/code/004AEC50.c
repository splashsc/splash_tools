int __fastcall sq_data(int a1, int a2)
{
  int v4; // $a0
  int v5; // $s0
  int v6; // $v0
  char *v7; // $v0
  int v8; // $s0
  int v9; // $s0
  int v10; // $v0
  int v11; // $s0
  const char *v12; // $v0
  int v13; // $s0
  const char *v14; // $v0
  int v15; // $s0
  int v16; // $s0
  unsigned int v17; // $v0
  int v18; // $a2
  char v20[4096]; // [sp+18h] [-1400h] BYREF
  char v21[1024]; // [sp+1018h] [-400h] BYREF

  memset(v21, 0, sizeof(v21));
  if ( a2 )
  {
    v4 = 34;
    strcpy(v20, "{\"code\":0,\"error\":\"\",\"data\":{");
    v5 = 34;
    v6 = 29;
  }
  else
  {
    strcpy(v20, "{");
    v4 = 6;
    v5 = 6;
    v6 = 1;
  }
  v7 = &v20[v6];
  strcpy(v7, "\"sq\":");
  *(_DWORD *)v7 = 577860386;
  v8 = sq_file_get_fun(&v20[v4]) + v5;
  sq2_file_get_auth_errinfo(1023, v21);
  v9 = v8 + sprintf(&v20[v8], ",\"errinfo\":\"%s\"", v21);
  v10 = flash_get_sec_status();
  v11 = v9 + sprintf(&v20[v9], ",\"hardid_info\":\"%d\"", v10);
  strcpy(&v20[v11], ",\"hd_info\":\"1\"");
  qmemcpy(&v20[v11], ",\"hd_info\":\"", 12);
  v12 = (const char *)custom_tb_version();
  v13 = v11 + 14 + sprintf(&v20[v11 + 14], ",\"version\":\"%s\"", v12);
  strcpy(&v20[v13], ",\"ff\":{");
  *(_DWORD *)&v20[v13 + 4] = 8075810;
  v14 = (const char *)nvram_get("mac_deflan");
  v15 = v13 + 7 + sprintf(&v20[v13 + 7], "\"def_mac\":\"%s\"", v14);
  *(_WORD *)&v20[v15] = 125;
  v16 = v15 + 1 + sprintf(&v20[v15 + 1], ",\"x86\":%d", 0);
  if ( a2 )
  {
    v17 = snprintf(&v20[v16], 4096 - v16, "}}");
    if ( v17 >= 4096 - v16 )
      v17 = 4095 - v16;
    v18 = v17 + v16;
  }
  else
  {
    *(_WORD *)&v20[v16] = 125;
    v18 = v16 + 1;
  }
  return httpd_cgi_ret(a1, v20, v18, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83D8: using guessed type int flash_get_sec_status(void);
// 6A84C0: using guessed type int __fastcall sq2_file_get_auth_errinfo(_DWORD, _DWORD);
// 6A8788: using guessed type int custom_tb_version(void);

