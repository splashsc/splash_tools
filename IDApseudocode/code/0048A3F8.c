int __fastcall sub_48A3F8(int a1)
{
  char *v1; // $v0
  int v3; // $s1
  int v4; // $v0
  char *v5; // $s0
  int v6; // $v0
  int v7; // $s1
  int v8; // $a2
  int v10; // $a1
  int v11; // $a2
  int v12; // $a0
  const char *v13; // $v0
  unsigned int v14; // $v0
  char v15[256]; // [sp+20h] [-100h] BYREF

  v1 = httpd_get_parm(a1, (char *)&off_64918C);
  if ( v1 && (v3 = J_atoi(v1), (unsigned int)(v3 - 1) < 0xFF) )
  {
    _mem_malloc(0x200000, "urlgidlist_data", 1096);
    v5 = (char *)v4;
    if ( v4 )
    {
      strcpy((char *)v4, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy((void *)v4, "{\"code\":0,\"error", 16);
      *(_DWORD *)(v4 + 24) = 975331700;
      v6 = url_gid_member_get(v4 + 29, 2097123, v3);
      v7 = v6 + 29;
      if ( v6 > 0 )
        v7 = v6 - 1 + 29;
      v8 = snprintf(&v5[v7], 0x200000 - v7, "]}");
      if ( v8 >= 0x200000 - v7 )
        v8 = 0x1FFFFF - v7;
      return jhl_data_giz(a1, v5, v8 + v7, 0x200000);
    }
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 0x200000;
    v12 = 4;
  }
  else
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = (int)&unk_649188;
    v12 = 12;
  }
  v13 = (const char *)_GET_LANG_TEXT(v12, v10, v11);
  v14 = snprintf(v15, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
  if ( v14 >= 0x100 )
    v14 = 255;
  return httpd_cgi_ret(a1, v15, v14, 4);
}
// 48A488: variable 'v4' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 64918C: using guessed type void *off_64918C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8530: using guessed type int __fastcall url_gid_member_get(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

