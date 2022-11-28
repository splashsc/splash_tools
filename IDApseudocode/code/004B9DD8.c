int __fastcall sj_dev_info_data(int a1)
{
  const char *v2; // $v0
  char *v3; // $v0
  char *v4; // $s0
  unsigned int v5; // $v0
  int v6; // $a3
  const char *v8; // $v0
  const char *v9; // $v0
  char v10[256]; // [sp+20h] [-180h] BYREF
  char v11[128]; // [sp+120h] [-80h] BYREF

  memset(v11, 0, sizeof(v11));
  v2 = (const char *)nvram_get("sj_dev_name");
  if ( !v2 )
    v2 = "";
  snprintf(v11, 128, "%s", v2);
  if ( !v11[0] )
  {
    v8 = (const char *)custom_device_name();
    snprintf(v11, 128, "%s", v8);
  }
  _mem_malloc(40960, "sj_dev_info_data", 724);
  v4 = v3;
  if ( v3 )
  {
    v5 = shenji_get_dev_info(v3, 40960);
    v6 = 8;
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 40960);
    v4 = v10;
    v5 = snprintf(v10, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v5 >= 0x100 )
      v5 = 255;
    v6 = 4;
  }
  return httpd_cgi_ret(a1, v4, v5, v6);
}
// 4B9E8C: variable 'v3' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A885C: using guessed type int __fastcall shenji_get_dev_info(_DWORD, _DWORD);

