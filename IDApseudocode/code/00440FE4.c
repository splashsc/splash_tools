int __fastcall sub_440FE4(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s4
  int v5; // $a0
  int v6; // $s3
  int v7; // $v0
  int v8; // $s1
  int v9; // $s1
  int v10; // $v0
  int v11; // $s1
  int v12; // $v0
  int v13; // $s1
  int v14; // $s3
  int v15; // $v0
  unsigned int v17; // $a2
  const char *v18; // $v0
  char v19[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(0x200000, "state_view_data", 3569);
  v3 = v2;
  if ( v2 )
  {
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      *(_WORD *)v2 = 123;
      v4 = 0x1FFFFF;
      v5 = 1;
      v6 = 1;
    }
    else
    {
      strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
      qmemcpy(v2, "{\"code\":0,\"error", 16);
      v4 = 2097123;
      v5 = 29;
      v6 = 29;
    }
    v7 = snprintf(&v2[v5], v4, "\"wans\":");
    v8 = v6 + v7;
    if ( v7 >= v4 )
      v8 = 0x1FFFFF;
    v9 = v8 + get_wans_data(&v3[v8], 0x200000 - v8);
    v10 = snprintf(&v3[v9], 0x200000 - v9, (char *)&dword_64331C);
    if ( v10 >= 0x200000 - v9 )
      v10 = 0x1FFFFF - v9;
    v11 = v10 + v9 + get_vpns_iface(&v3[v10 + v9]);
    v12 = snprintf(&v3[v11], 0x200000 - v11, ",\"x86\":%d", 0);
    if ( v12 >= 0x200000 - v11 )
    {
      v13 = 0x1FFFFF;
      v14 = 1;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
        goto LABEL_10;
    }
    else
    {
      v13 = v12 + v11;
      v14 = 0x200000 - v13;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
      {
LABEL_10:
        v15 = snprintf(&v3[v13], v14, "}}");
LABEL_11:
        if ( v15 >= v14 )
          v15 = 0x1FFFFF - v13;
        return httpd_cgi_ret(a1, v3, v15 + v13, 8);
      }
    }
    v15 = snprintf(&v3[v13], v14, "}");
    goto LABEL_11;
  }
  v17 = 2;
  if ( *(_BYTE *)(a1 + 210100) == 2 )
  {
    strcpy(v19, "{}");
  }
  else
  {
    v18 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v17 = snprintf(v19, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v18);
    if ( v17 >= 0x100 )
      v17 = 255;
  }
  return httpd_cgi_ret(a1, v19, v17, 4);
}
// 441034: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64331C: using guessed type int dword_64331C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

