int __fastcall sub_48E578(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  int v4; // $s2
  char *v5; // $s0
  const char *v6; // $v0
  int v7; // $v0
  char *v8; // $a0
  int v9; // $a1
  int v10; // $s0
  int v11; // $a2
  int result; // $v0
  const char *v13; // $v0
  unsigned int v14; // $v0
  char v15[260]; // [sp+20h] [-104h] BYREF

  _mem_malloc(20580, "ipsec_state_data", 1141);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = 29;
    if ( show_ipsec_status() )
    {
      v8 = v3 + 29;
      v9 = 20551;
      v10 = 20551;
    }
    else
    {
      v5 = ipsec_info;
      do
      {
        if ( !*v5 )
          break;
        v6 = v5[64] ? "conn" : "disconn";
        v7 = sprintf(&v3[v4], "{\"n\":\"%s\",\"ip\":\"%s\",\"s\":\"%s\"},", v5, v5 + 32, v6);
        v5 += 65;
        v4 += v7;
      }
      while ( v5 != (char *)&switch_reboot_timer );
      v8 = &v3[v4];
      if ( v4 > 0 && *(v8 - 1) == 44 )
        v8 = &v3[--v4];
      v10 = 20580 - v4;
      *v8 = 0;
      v9 = 20580 - v4;
    }
    v11 = snprintf(v8, v9, "]}");
    if ( v11 >= v10 )
      v11 = 20579 - v4;
    result = httpd_cgi_ret(a1, v3, v4 + v11, 8);
  }
  else
  {
    v13 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 20580);
    v14 = snprintf(v15, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v14 >= 0x100 )
      v14 = 255;
    result = httpd_cgi_ret(a1, v15, v14, 4);
  }
  return result;
}
// 48E5D4: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

