int __fastcall sub_4655E8(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s4
  int v5; // $v0
  int v6; // $a2
  int result; // $v0
  const char *v8; // $v0
  unsigned int v9; // $v0
  char v10[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(1024000, "ips_group_data", 926);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = get_ips_group_data(v2 + 28, 1023972) + 28;
    v5 = snprintf(&v3[v4], 1024000 - v4, "}");
    if ( v5 >= 1024000 - v4 )
      v6 = 1023999 - v4;
    else
      v6 = v5;
    result = httpd_cgi_ret(a1, v3, v6 + v4, 8);
  }
  else
  {
    v8 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v9 = snprintf(v10, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
    if ( v9 >= 0x100 )
      v9 = 255;
    result = httpd_cgi_ret(a1, v10, v9, 4);
  }
  return result;
}
// 46563C: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

