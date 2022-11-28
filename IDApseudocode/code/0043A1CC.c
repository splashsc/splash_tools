int __fastcall sub_43A1CC(int a1)
{
  const char *v2; // $v0
  int v3; // $v0
  const char *v4; // $s6
  const char *v5; // $v0
  unsigned int v6; // $v0
  size_t v7; // $v0
  size_t v8; // $v0
  unsigned int v9; // $s0
  unsigned int v10; // $v0
  size_t v11; // $s2
  char v13[4096]; // [sp+48h] [-3100h] BYREF
  char v14[4096]; // [sp+1048h] [-2100h] BYREF
  char v15[4096]; // [sp+2048h] [-1100h] BYREF
  char v16[128]; // [sp+3048h] [-100h] BYREF
  char v17[128]; // [sp+30C8h] [-80h] BYREF

  memset(v15, 0, sizeof(v15));
  memset(v14, 0, sizeof(v14));
  memset(v13, 0, sizeof(v13));
  memset(v17, 0, sizeof(v17));
  memset(v16, 0, sizeof(v16));
  sq_file_get_id(v17, 128);
  v2 = (const char *)custom_tb_version();
  v3 = sprintf(v16, "%s", v2);
  if ( v3 > 0 && v16[v3 - 1] == 45 )
    --v3;
  v16[v3] = 0;
  v4 = (const char *)wayos_version;
  v5 = (const char *)nvram_get("http_lanport");
  if ( !v5 )
    v5 = "";
  v6 = snprintf(
         v14,
         4096,
         "{\"tbv\":\"%s\",\"ver\":\"%s\",\"isap\":%s,\"acstate\":%d,\"apname\":\"%s\",\"gwsn\":\"%s\",\"gwip\":\"%s\",\"g"
         "wport\":%s,\"x86\":%d,\"common\":%d,\"oem\":%d,\"oem_type\":%d,\"ai\":%d",
         v16,
         v4,
         "0",
         0,
         "",
         v17,
         "127.0.0.1",
         v5,
         0,
         0,
         0,
         10,
         3);
  if ( v6 >= 0x1000 )
    v6 = 4095;
  snprintf(&v14[v6], 4096 - v6, "}");
  strcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":\"");
  gbk_to_utf8(v14, v15, 4095);
  v7 = strlen(v15);
  base64_encode(v15, &v13[29], v7);
  v8 = strlen(v13);
  v9 = 4096 - v8;
  v11 = v8;
  v10 = snprintf(&v13[v8], 4096 - v8, "\"}");
  if ( v10 >= v9 )
    v10 = 4095 - v11;
  return httpd_cgi_ret(a1, v13, v10 + v11, 4);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8474: using guessed type int __fastcall base64_encode(_DWORD, _DWORD, _DWORD);
// 6A84E4: using guessed type int __fastcall sq_file_get_id(_DWORD, _DWORD);
// 6A85C8: using guessed type int __fastcall gbk_to_utf8(_DWORD, _DWORD, _DWORD);
// 6A8788: using guessed type int custom_tb_version(void);

