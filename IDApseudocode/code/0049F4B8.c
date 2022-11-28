int __fastcall sub_49F4B8(int a1)
{
  char *v2; // $s2
  bool v3; // dc
  int result; // $v0
  int v5; // $a1
  char *v6; // $a2
  int v7; // $a0
  const char *v8; // $v0
  unsigned int v9; // $v0
  int v10; // $a2
  int v11; // $a2
  int v12; // $s2
  int v13; // $s5
  int v14; // $v0
  const char *v15; // $s6
  int v16; // $fp
  int v17; // $s1
  int v18; // $v0
  const char *v19; // $s7
  unsigned int v20; // $v0
  int v21; // $s1
  unsigned int v22; // $v0
  const char *v23; // $v0
  char v24[2048]; // [sp+68h] [-1080h] BYREF
  int v25[512]; // [sp+868h] [-880h] BYREF
  char v26[32]; // [sp+1068h] [-80h] BYREF
  char v27[32]; // [sp+1088h] [-60h] BYREF
  char v28[32]; // [sp+10A8h] [-40h] BYREF
  int v29; // [sp+10C8h] [-20h]
  int v30; // [sp+10CCh] [-1Ch]
  int v31; // [sp+10D0h] [-18h]
  int v32; // [sp+10D4h] [-14h]
  int v33; // [sp+10D8h] [-10h]
  int v34; // [sp+10DCh] [-Ch]
  char *v35; // [sp+10E0h] [-8h]

  memset(v25, 0, sizeof(v25));
  memset(v24, 0, sizeof(v24));
  v2 = httpd_get_parm(a1, "user");
  v3 = pppoe_bridge_check_token(a1) != 0;
  result = 0;
  if ( !v3 )
  {
    if ( !v2 || !*v2 )
    {
      v5 = *(unsigned __int8 *)(a1 + 210102);
      v6 = "not user";
      v7 = 12;
      goto LABEL_5;
    }
    v25[0] = 41;
    v25[3] = 18;
    v25[1] = 2048;
    strlcpy(&v25[10], v2, 64);
    if ( jianhl_order_opt_fun(v25, v25[1], v10) )
    {
      v5 = *(unsigned __int8 *)(a1 + 210102);
      v6 = "";
      v7 = 3;
LABEL_5:
      v8 = (const char *)_GET_LANG_TEXT(v7, v5, v6);
      v9 = snprintf((char *)v25, 2048, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
      if ( v9 < 0x800 )
        return httpd_cgi_ret(a1, (char *)v25, v9, 4);
LABEL_18:
      v9 = 2047;
      return httpd_cgi_ret(a1, (char *)v25, v9, 4);
    }
    if ( v25[2] == 3 )
    {
      v23 = (const char *)_GET_LANG_TEXT(206, *(unsigned __int8 *)(a1 + 210102), v11);
      v9 = snprintf(v24, 2048, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v23);
      if ( v9 < 0x800 )
        return httpd_cgi_ret(a1, (char *)v25, v9, 4);
      goto LABEL_18;
    }
    v35 = v28;
    if ( HIWORD(v25[6]) )
      sprintf(v28, "%u.%u", LOWORD(v25[6]), HIWORD(v25[6]));
    else
      sprintf(v28, "%u", LOWORD(v25[6]));
    strcpy(v24, "{\"code\":0,\"error\":\"\",\"data\":{");
    v12 = LOBYTE(v25[4]);
    v13 = BYTE1(v25[4]);
    v15 = (const char *)MacToStr(v27, (char *)&v25[4] + 2);
    v14 = MacToStr(v26, &v25[83]);
    v34 = v25[7];
    v33 = v25[98];
    v32 = v25[94];
    v31 = v25[95];
    v30 = v25[96];
    v29 = v25[97];
    v16 = v25[8];
    v17 = v25[9];
    v19 = (const char *)v14;
    v18 = ntohs(v25[82]);
    v20 = snprintf(
            &v24[29],
            2019,
            "\"en\":%d,\"user\":\"%s\",\"bind\":%d,\"mac_bind\":\"%s\",\"mac_cur\":\"%s\",\"c_data\":%u,\"d_date\":%u,\"m"
            "em\":\"%s\",\"dev\":%d,\"vlan_id\":\"%s\",name\":\"%s\",\"cid\":\"%s\",\"phone\":\"%s\",\"online_time\":%lu,"
            "\"qup\":%u,\"qdw\":%u,\"zup\":%u,\"zdw\":%u,\"in_dev\":\"%s\",\"out_dev\":\"%s\",\"session\":%u",
            v12,
            (const char *)&v25[10],
            v13,
            v15,
            v19,
            v16,
            v17,
            (const char *)&v25[26],
            v34,
            v35,
            (const char *)&v25[58],
            (const char *)&v25[66],
            (const char *)&v25[74],
            v33,
            v32,
            v31,
            v30,
            v29,
            (const char *)&v25[85],
            (const char *)&v25[89],
            v18);
    v21 = v20 + 29;
    if ( v20 >= 0x7E3 )
      v21 = 2047;
    v22 = snprintf(&v24[v21], 2048 - v21, "}}");
    if ( v22 >= 2048 - v21 )
      v22 = 2047 - v21;
    result = httpd_cgi_ret(a1, v24, v22 + v21, 4);
  }
  return result;
}
// 49F660: variable 'v10' is possibly undefined
// 49F89C: variable 'v11' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

