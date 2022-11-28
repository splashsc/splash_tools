int __fastcall sub_471DB8(int a1)
{
  _DWORD *v1; // $v0
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $s1
  _DWORD *v5; // $s6
  _DWORD *v6; // $s0
  int v7; // $fp
  int v8; // $s2
  char *v9; // $v0
  const char *v10; // $v0
  int v11; // $a0
  int v12; // $v0
  char *v13; // $a0
  int v14; // $v0
  int v15; // $s2
  int result; // $v0
  const char *v17; // $v0
  int v18; // $s0
  int v19; // $a2
  const char *v20; // $v0
  unsigned int v21; // $v0
  char v22[128]; // [sp+38h] [-E0h] BYREF
  char v23[48]; // [sp+B8h] [-60h] BYREF
  char v24[32]; // [sp+E8h] [-30h] BYREF
  const char *v25; // [sp+108h] [-10h]
  int v26; // [sp+10Ch] [-Ch]
  char *v27; // [sp+110h] [-8h]

  v27 = "1\"";
  _mem_malloc(0x200000, "pppoe_web_user_data", 3085);
  v4 = v3;
  _mem_malloc(0x200000, "pppoe_web_user_data", 3086);
  v5 = v1;
  if ( !v4 || !v1 )
  {
    _mem_free(v4);
    _mem_free(v5);
    v20 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v21 = snprintf(v22, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
    if ( v21 >= 0x80 )
      result = httpd_cgi_ret(a1, v22, 127, 4);
    else
      result = httpd_cgi_ret(a1, v22, v21, 4);
    return result;
  }
  *v1 = 16;
  v1[3] = 44;
  v1[1] = 0x200000;
  if ( !jianhl_order_opt_fun(v1, 0x200000, v2) )
  {
    strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v4, "{\"code\":0,\"error", 16);
    v6 = v5 + 4;
    if ( (int)v5[2] <= 0 )
    {
      v12 = 28;
      v11 = 29;
      v8 = 29;
    }
    else
    {
      v7 = 0;
      v8 = 29;
      do
      {
        v9 = (char *)get_json_data(v6);
        strcpy(v22, v9);
        v26 = v6[16];
        v25 = (const char *)IpaddrToStr(v23, v6 + 22);
        v10 = (const char *)MacToStr(v24, v6 + 27);
        v8 += sprintf(
                &v4[v8],
                "{\"userid\":\"%u\",\"ip\":\"%s\",\"mac\":\"%s\",\"name\":\"%s\",\"speed\":\"%u/%u\",\"total\":\"%u/%u\","
                "\"type\":\"%d\"},",
                v26,
                v25,
                v10,
                v22,
                v6[20],
                v6[21],
                v6[18],
                v6[19],
                *((unsigned __int8 *)v6 + 114));
        ++v7;
        v6 += 29;
      }
      while ( v7 < v5[2] && 0x200000 - v8 >= 100 );
      v11 = v8;
      if ( v8 <= 0 )
      {
LABEL_12:
        v13 = &v4[v11];
        *v13 = 0;
        v14 = snprintf(v13, 0x200000 - v8, "]}");
        if ( v14 >= 0x200000 - v8 )
          v14 = 0x1FFFFF - v8;
        v15 = v8 + v14;
        _mem_free(v5);
        return jhl_data_giz(a1, v4, v15, 0x200000);
      }
      v12 = v8 - 1;
    }
    if ( v4[v12] == 44 )
      v11 = --v8;
    goto LABEL_12;
  }
  v17 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
  v18 = snprintf(v4, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
  _mem_free(v5);
  v19 = v18;
  if ( v18 >= 0x200000 )
    v19 = 0x1FFFFF;
  return httpd_cgi_ret(a1, v4, v19, 8);
}
// 471E30: variable 'v3' is possibly undefined
// 471E3C: variable 'v1' is possibly undefined
// 471E64: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

