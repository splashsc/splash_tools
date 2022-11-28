int __fastcall sub_490F1C(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  int v5; // $s1
  char *v6; // $a0
  int v7; // $v0
  int v8; // $a2
  int result; // $v0
  const char *v10; // $v0
  unsigned int v11; // $v0
  char v12[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(0x200000, "vpn_state_data", 1770);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = get_vpn_state((char *)(v2 + 29), 2097123);
    v5 = v4 + 29;
    v6 = &v3[v4 + 29];
    if ( v4 + 29 > 0 && *(v6 - 1) == 44 )
    {
      v5 = v4 + 28;
      v6 = &v3[v4 + 28];
    }
    *v6 = 0;
    v7 = snprintf(v6, 0x200000 - v5, "}}");
    if ( v7 >= 0x200000 - v5 )
      v8 = 0x1FFFFF - v5;
    else
      v8 = v7;
    result = httpd_cgi_ret(a1, v3, v5 + v8, 8);
  }
  else
  {
    v10 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v11 = snprintf(v12, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x100 )
      v11 = 255;
    result = httpd_cgi_ret(a1, v12, v11, 4);
  }
  return result;
}
// 490F6C: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

