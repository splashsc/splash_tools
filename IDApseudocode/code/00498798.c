int __fastcall pppoe_list_data(int a1)
{
  _DWORD *v1; // $v0
  char *v2; // $v0
  char *v3; // $fp
  _DWORD *v4; // $s1
  int v5; // $a2
  _DWORD *v6; // $s3
  int v7; // $s0
  int v8; // $s7
  uint32_t v9; // $a0
  uint32_t v10; // $v0
  int v11; // $a1
  int v12; // $v0
  int v13; // $s2
  int v14; // $v0
  int v15; // $s4
  char *v16; // $t7
  int v17; // $a2
  const char *v18; // $v0
  int v19; // $s0
  int v20; // $a2
  int result; // $v0
  int v22; // $a0
  int v23; // $v0
  char *v24; // $a0
  int v25; // $v0
  int v26; // $s0
  const char *v27; // $v0
  unsigned int v28; // $v0
  __int16 v29[64]; // [sp+48h] [-100h] BYREF
  char v30[64]; // [sp+C8h] [-80h] BYREF
  char v31[32]; // [sp+108h] [-40h] BYREF
  int v32; // [sp+128h] [-20h]
  uint32_t v33; // [sp+12Ch] [-1Ch]
  char *v34; // [sp+130h] [-18h]
  char *s; // [sp+134h] [-14h]
  char *v36; // [sp+138h] [-10h]
  char *format; // [sp+13Ch] [-Ch]
  char *v38; // [sp+140h] [-8h]
  char *v39; // [sp+144h] [-4h]

  v38 = "1\"";
  _mem_malloc(0x200000, "pppoe_list_data", 395);
  v3 = v2;
  _mem_malloc(0x200000, "pppoe_list_data", 396);
  v4 = v1;
  if ( v3 && v1 )
  {
    memset(v1, 0, 0x200000u);
    *v4 = 9;
    v4[3] = 3;
    v4[1] = 0x200000;
    if ( !jianhl_order_opt_fun(v4, 0x200000, v5) )
    {
      strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy(v3, "{\"code\":0,\"error", 16);
      v6 = v4 + 9;
      if ( (int)v4[2] <= 0 )
      {
        v23 = 28;
        v22 = 29;
        v8 = 29;
      }
      else
      {
        v36 = "1\"";
        s = (char *)v29;
        v7 = 0;
        format = "%d";
        v8 = 29;
        v39 = "%d.%d";
        do
        {
          v16 = &v3[v8];
          if ( *((_WORD *)v6 + 6) )
          {
            v17 = *((unsigned __int16 *)v6 + 6);
            if ( *((_WORD *)v6 + 7) )
              sprintf(s, v39, v17);
            else
              sprintf(s, format, v17);
            v16 = &v3[v8];
          }
          else
          {
            v29[0] = 32;
          }
          v9 = *(v6 - 4);
          v34 = v16;
          v10 = ntohl(v9);
          v11 = *(v6 - 4);
          v33 = v10;
          v32 = IpToStr(v30, v11);
          v12 = MacToStr(v31, v6);
          v13 = *(v6 - 5);
          v15 = v12;
          v14 = get_json_data(v6 + 6);
          v8 += sprintf(
                  v34,
                  v36 - 16092,
                  v33,
                  v32,
                  v15,
                  v13,
                  v14,
                  *((unsigned __int16 *)v6 + 3),
                  *(v6 - 3),
                  *(v6 - 1),
                  *(v6 - 2),
                  v6[2],
                  s,
                  v6[4],
                  v6[5]);
          if ( ++v7 >= v4[2] )
            break;
          v6 += 30;
        }
        while ( 0x200000 - v8 >= 100 );
        v22 = v8;
        if ( v8 <= 0 )
          goto LABEL_21;
        v23 = v8 - 1;
      }
      if ( v3[v23] == 44 )
        v22 = --v8;
LABEL_21:
      v24 = &v3[v22];
      *v24 = 0;
      v25 = snprintf(v24, 0x200000 - v8, "]}");
      if ( v25 >= 0x200000 - v8 )
        v25 = 0x1FFFFF - v8;
      v26 = v8 + v25;
      _mem_free(v4);
      return jhl_data_giz(a1, v3, v26, 0x200000);
    }
    v18 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    v19 = snprintf(v3, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v18);
    _mem_free(v4);
    v20 = v19;
    if ( v19 >= 0x200000 )
      v20 = 0x1FFFFF;
    result = httpd_cgi_ret(a1, v3, v20, 8);
  }
  else
  {
    _mem_free(v3);
    _mem_free(v4);
    v27 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    s = (char *)v29;
    v28 = snprintf((char *)v29, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
    if ( v28 >= 0x80 )
      v28 = 127;
    result = httpd_cgi_ret(a1, s, v28, 4);
  }
  return result;
}
// 498810: variable 'v2' is possibly undefined
// 49881C: variable 'v1' is possibly undefined
// 49885C: variable 'v5' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

