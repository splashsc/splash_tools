int __fastcall sub_4C933C(int a1)
{
  int v2; // $v0
  int v3; // $s0
  int v4; // $s5
  size_t v5; // $v0
  int v6; // $s2
  int v7; // $v0
  size_t v8; // $s1
  int v9; // $s1
  int result; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[260]; // [sp+20h] [-104h] BYREF

  memset(v13, 0, 0x100u);
  _mem_malloc(0x200000, "switch_reboot_data", 190);
  if ( v2 )
  {
    v3 = v2;
    v4 = switch_reboot_auto_get();
    strcpy((char *)v3, "{\"code\":0,\"error\":\"\",\"data\":");
    qmemcpy((void *)v3, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v3 + 24) = *(_DWORD *)"ta\":";
    cJSON_PrintPreallocated(v4, v3 + 28, 2097124, 0);
    v5 = strlen((const char *)v3);
    v6 = 0x200000 - v5;
    v8 = v5;
    v7 = snprintf((char *)(v3 + v5), 0x200000 - v5, "}");
    if ( v7 >= v6 )
      v7 = 0x1FFFFF - v8;
    v9 = v7 + v8;
    cJSON_Delete(v4);
    result = httpd_cgi_ret(a1, (char *)v3, v9, 8);
  }
  else
  {
    v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v12 = snprintf(v13, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x100 )
      v12 = 255;
    result = httpd_cgi_ret(a1, v13, v12, 4);
  }
  return result;
}
// 4C93A8: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8740: using guessed type int __fastcall cJSON_PrintPreallocated(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

