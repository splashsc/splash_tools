int __fastcall sub_448C00(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int v5; // $v0
  int v6; // $s1
  int v7; // $v0
  int v8; // $s1
  int v9; // $v0
  int v10; // $a2
  int result; // $v0
  const char *v12; // $v0
  unsigned int v13; // $v0
  char v14[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(0x200000, "wan_extend_list_data", 4126);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"reaal_wans\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = get_realwans_data(0, v2 + 41, 2097111) + 41;
    v5 = snprintf(&v3[v4], 0x200000 - v4, ",\"ex_wans\":");
    if ( v5 >= 0x200000 - v4 )
      v5 = 0x1FFFFF - v4;
    v6 = v5 + v4 + get_wans_increase_data(&v3[v5 + v4], 0x200000 - (v5 + v4));
    v7 = snprintf(&v3[v6], 0x200000 - v6, ",\"br_wans\":");
    if ( v7 >= 0x200000 - v6 )
      v7 = 0x1FFFFF - v6;
    v8 = v7 + v6 + get_wans_pppoebr_data(&v3[v7 + v6], 0x200000 - (v7 + v6));
    v9 = snprintf(&v3[v8], 0x200000 - v8, "}}");
    if ( v9 >= 0x200000 - v8 )
      v10 = 0x1FFFFF - v8;
    else
      v10 = v9;
    result = httpd_cgi_ret(a1, v3, v10 + v8, 8);
  }
  else
  {
    v12 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v13 = snprintf(v14, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v12);
    if ( v13 >= 0x100 )
      v13 = 255;
    result = httpd_cgi_ret(a1, v14, v13, 4);
  }
  return result;
}
// 448C50: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A85B4: using guessed type int __fastcall get_realwans_data(_DWORD, _DWORD, _DWORD);

