int __fastcall sub_49D5E4(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s3
  const char *v5; // $s4
  const char *v6; // $s5
  const char *v7; // $s6
  const char *v8; // $v0
  int v9; // $v0
  int v10; // $s1
  int v11; // $s3
  int v12; // $v0
  int v13; // $s1
  int v14; // $v0
  int v15; // $s1
  int v16; // $v0
  int v17; // $a2
  int result; // $v0
  const char *v19; // $v0
  unsigned int v20; // $v0
  char v21[132]; // [sp+30h] [-84h] BYREF

  _mem_malloc(0x200000, "pppoe_br_user_data", 1729);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = (const char *)nvram_get("pppoe_br_user_date_expire_en");
    if ( !v4 )
      v4 = "0";
    v5 = (const char *)nvram_get("pppoe_br_user_mac_err_en");
    if ( !v5 )
      v5 = "0";
    v6 = (const char *)nvram_get("pppoe_br_user_no_exist_en");
    if ( !v6 )
      v6 = "0";
    v7 = (const char *)nvram_get("pppoe_br_user_dev_err_en");
    if ( !v7 )
      v7 = "0";
    v8 = (const char *)jhl_nv_get_def("pppoe_br_user_time");
    v9 = snprintf(
           v3 + 29,
           2097123,
           "\"date_expire\":\"%s\",\"mac_err\":\"%s\",\"no_exist\":\"%s\",\"dev_err\":\"%s\",\"user_time\":\"%s\",\"wan_max\":\"%d\"",
           v4,
           v5,
           v6,
           v7,
           v8,
           2);
    if ( v9 >= 2097123 )
      v9 = 2097122;
    v10 = v9 + 29;
    v11 = 0x200000 - (v9 + 29);
    v12 = snprintf(&v3[v9 + 29], v11, ",\"all\":[");
    if ( v12 >= v11 )
      v12 = 0x1FFFFF - v10;
    v13 = v12 + v10 + pppoe_br_user_get_state(&v3[v12 + v10], 0x200000 - (v12 + v10));
    v14 = snprintf(&v3[v13], 0x200000 - v13, &byte_6445A0);
    if ( v14 >= 0x200000 - v13 )
      v14 = 0x1FFFFF - v13;
    v15 = v14 + v13;
    v16 = snprintf(&v3[v15], 0x200000 - v15, "}}");
    if ( v16 >= 0x200000 - v15 )
      v17 = 0x1FFFFF - v15;
    else
      v17 = v16;
    result = jhl_data_giz(a1, v3, v17 + v15, 0x200000);
  }
  else
  {
    v19 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v20 = snprintf(v21, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( v20 >= 0x80 )
      v20 = 127;
    result = httpd_cgi_ret(a1, v21, v20, 4);
  }
  return result;
}
// 49D640: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

