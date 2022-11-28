int __fastcall user_data(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s3
  int v5; // $s1
  char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s6
  const char *v9; // $s5
  const char *v10; // $v0
  int v11; // $s1
  int v12; // $s1
  int v13; // $s1
  int v14; // $s4
  int v15; // $v0
  int result; // $v0
  const char *v17; // $v0
  unsigned int v18; // $v0
  char v19[256]; // [sp+40h] [-100h] BYREF

  _mem_malloc(0x200000, "user_data", 1161);
  v3 = v2;
  if ( v2 )
  {
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      *(_WORD *)v2 = 123;
      v4 = 1;
      v5 = 1;
    }
    else
    {
      v4 = 29;
      strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
      qmemcpy(v2, "{\"code\":0,\"error", 16);
      v5 = 29;
    }
    v6 = &v2[v4];
    v7 = (const char *)nvram_get("group");
    if ( !v7 )
      v7 = "";
    v8 = (const char *)jhl_nv_get_def("user_deltime");
    v9 = (const char *)nvram_get("user_hide_nouse");
    if ( !v9 )
      v9 = "";
    v10 = (const char *)jhl_nv_get_def("billing_en");
    v11 = v5
        + sprintf(
            v6,
            "\"pppoe_client\":\"%d\",\"pppoe_group\":\"%d\",\"rzgl_web\":\"%d\",\"rzgl\":\"%d\",\"vlan_en\":\"%d\",\"gid\""
            ":\"%s\",\"beizhu_show\":%d,\"type_show_flag\":\"%d\",\"deltime\":\"%s\",\"hide_nouse\":\"%s\",\"billing_en\":%s,\"all\":",
            0,
            1,
            0,
            1,
            0,
            v7,
            1,
            1,
            v8,
            v9,
            v10);
    v12 = v11 + user_get_state(a1, &v3[v11], 0x200000 - v11);
    strcpy(&v3[v12], ",\"type_list\":\";pppoe;\"");
    qmemcpy(&v3[v12], ",\"type_list\":\";p", 16);
    v13 = v12 + 22;
    v14 = 0x200000 - v13;
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      v15 = snprintf(&v3[v13], 0x200000 - v13, "}");
      if ( v15 >= v14 )
        v15 = 0x1FFFFF - v13;
    }
    else
    {
      v15 = snprintf(&v3[v13], 0x200000 - v13, "}}");
      if ( v15 >= v14 )
        v15 = 0x1FFFFF - v13;
    }
    result = jhl_data_giz(a1, v3, v15 + v13, 0x200000);
  }
  else
  {
    v17 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v18 = snprintf(v19, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
    if ( v18 >= 0x100 )
      v18 = 255;
    result = httpd_cgi_ret(a1, v19, v18, 4);
  }
  return result;
}
// 47A5E4: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

