int __fastcall sub_471870(int a1)
{
  char *v1; // $s1
  _DWORD *v2; // $v0
  int v3; // $a2
  char *v4; // $v0
  char *v5; // $s0
  _DWORD *v6; // $s3
  _DWORD *v7; // $s5
  int v8; // $s2
  int v9; // $s1
  int v10; // $v0
  char *v11; // $v0
  int v12; // $a2
  const char *v13; // $v0
  int v14; // $s1
  int v15; // $a2
  int result; // $v0
  int v17; // $a0
  int v18; // $v0
  char *v19; // $a0
  int v20; // $v0
  int v21; // $s1
  const char *v22; // $v0
  unsigned int v23; // $a2
  __int16 v24[64]; // [sp+40h] [-170h] BYREF
  char v25[128]; // [sp+C0h] [-F0h] BYREF
  char v26[48]; // [sp+140h] [-70h] BYREF
  char v27[32]; // [sp+170h] [-40h] BYREF
  int v28; // [sp+190h] [-20h]
  uint32_t v29; // [sp+194h] [-1Ch]
  char *s; // [sp+198h] [-18h]
  char *v31; // [sp+19Ch] [-14h]
  char *format; // [sp+1A0h] [-10h]
  char *v33; // [sp+1A4h] [-Ch]
  char *v34; // [sp+1A8h] [-8h]

  v33 = "1\"";
  v1 = httpd_get_parm(a1, "id");
  _mem_malloc(0x200000, "web_user_data", 2975);
  v5 = v4;
  _mem_malloc(0x200000, "web_user_data", 2976);
  v6 = v2;
  if ( v5 && v2 )
  {
    *v2 = 16;
    if ( v1 && J_atoi(v1) == 2 )
      v6[3] = 39;
    else
      v6[3] = 11;
    v6[1] = 0x200000;
    if ( !jianhl_order_opt_fun(v6, 0x200000, v3) )
    {
      strcpy(v5, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy(v5, "{\"code\":0,\"error", 16);
      v7 = v6 + 4;
      if ( (int)v6[2] <= 0 )
      {
        v18 = 28;
        v17 = 29;
        v9 = 29;
      }
      else
      {
        s = (char *)v24;
        v31 = "1\"";
        v8 = 0;
        format = "%d";
        v9 = 29;
        v34 = "%d.%d";
        do
        {
          v11 = (char *)get_json_data(v7 + 13);
          strcpy(v25, v11);
          if ( *((_WORD *)v7 + 20) )
          {
            v12 = *((unsigned __int16 *)v7 + 20);
            if ( *((_WORD *)v7 + 21) )
              sprintf(s, v34, v12);
            else
              sprintf(s, format, v12);
          }
          else
          {
            v24[0] = 32;
          }
          v29 = ntohl(v7[1]);
          v28 = IpaddrToStr(v26, v7);
          v10 = MacToStr(v27, v7 + 8);
          v9 += sprintf(
                  &v5[v9],
                  v31 - 31052,
                  v29,
                  v28,
                  v10,
                  v7[5],
                  v25,
                  v7[6],
                  v7[7],
                  *((unsigned __int8 *)v7 + 38),
                  s,
                  v7[11],
                  v7[12]);
          ++v8;
          v7 += 29;
        }
        while ( v8 < v6[2] && 0x200000 - v9 >= 100 );
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_24;
        v18 = v9 - 1;
      }
      if ( v5[v18] == 44 )
        v17 = --v9;
LABEL_24:
      v19 = &v5[v17];
      *v19 = 0;
      v20 = snprintf(v19, 0x200000 - v9, "]}");
      if ( v20 >= 0x200000 - v9 )
        v20 = 0x1FFFFF - v9;
      v21 = v9 + v20;
      _mem_free(v6);
      return jhl_data_giz(a1, v5, v21, 0x200000);
    }
    v13 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    v14 = snprintf(v5, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    _mem_free(v6);
    v15 = v14;
    if ( v14 >= 0x200000 )
      v15 = 0x1FFFFF;
    result = httpd_cgi_ret(a1, v5, v15, 8);
  }
  else
  {
    _mem_free(v5);
    _mem_free(v6);
    v22 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    s = (char *)v24;
    v23 = snprintf((char *)v24, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
    if ( v23 >= 0x80 )
      v23 = 127;
    result = httpd_cgi_ret(a1, s, v23, 4);
  }
  return result;
}
// 471900: variable 'v4' is possibly undefined
// 47190C: variable 'v2' is possibly undefined
// 471958: variable 'v3' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

