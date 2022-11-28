int __fastcall sub_4A6904(int a1)
{
  char *v2; // $v0
  const char *v3; // $v0
  char *v4; // $s0
  int v5; // $s3
  int v6; // $v0
  int v7; // $a2
  int result; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[260]; // [sp+20h] [-104h] BYREF

  _mem_malloc(10240, "nat_trig_data", 872);
  if ( v2 )
  {
    v4 = v2;
    v3 = (const char *)nvram_get("trigforward");
    strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v4, "{\"code\":0,\"error\":\"\"", 20);
    v5 = sprintf(v4 + 29, "\"trigforward\":\"%s\"", v3) + 29;
    v6 = snprintf(&v4[v5], 10240 - v5, "}}");
    if ( v6 >= 10240 - v5 )
      v7 = 10239 - v5;
    else
      v7 = v6;
    result = httpd_cgi_ret(a1, v4, v7 + v5, 8);
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v10 = snprintf(v11, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    result = httpd_cgi_ret(a1, v11, v10, 4);
  }
  return result;
}
// 4A694C: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

