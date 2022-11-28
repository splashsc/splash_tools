int __fastcall mr_addr_update_data(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s1
  const char *v5; // $s3
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $s6
  const char *v9; // $s7
  const char *v10; // $fp
  const char *v11; // $v0
  int v12; // $s3
  int v13; // $v0
  int v14; // $a2
  int result; // $v0
  const char *v16; // $v0
  unsigned int v17; // $v0
  char v18[256]; // [sp+48h] [-110h] BYREF
  const char *v19; // [sp+148h] [-10h]
  const char *v20; // [sp+14Ch] [-Ch]
  const char *v21; // [sp+150h] [-8h]
  const char *v22; // [sp+154h] [-4h]

  _mem_malloc(1024, "mr_addr_update_data", 1353);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\",\"da", 24);
    v4 = (const char *)jhl_nv_get_def("mr_addr_update_en");
    v5 = (const char *)jhl_nv_get_def("dianxin_update_path");
    v6 = (const char *)jhl_nv_get_def("dianxin_modify_time");
    v7 = (const char *)jhl_nv_get_def("wangtong_update_path");
    v8 = (const char *)jhl_nv_get_def("wangtong_modify_time");
    v9 = (const char *)jhl_nv_get_def("yidong_update_path");
    v10 = (const char *)jhl_nv_get_def("yidong_modify_time");
    v22 = (const char *)jhl_nv_get_def("jiaoyu_update_path");
    v21 = (const char *)jhl_nv_get_def("jiaoyu_modify_time");
    v20 = (const char *)jhl_nv_get_def("china_update_path");
    v19 = (const char *)jhl_nv_get_def("china_modify_time");
    v11 = (const char *)jhl_nv_get_def("mr_addr_update_time");
    v12 = sprintf(
            v3 + 29,
            "\"mr_addr_update\":\"%s\",\"enable\":\"%s\",\"dianxin_path\":\"%s\",\"dianxin_mod_time\":\"%s\", \t\t\"wangt"
            "ong_path\":\"%s\",\"wangtong_mod_time\":\"%s\",\"yidong_path\":\"%s\",\"yidong_mod_time\":\"%s\", \t\t\"jiao"
            "yu_path\":\"%s\",\"jiaoyu_mod_time\":\"%s\",\"china_path\":\"%s\",\"china_mod_time\":\"%s\",\"update_time\":\"%s\"",
            "1",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v22,
            v21,
            v20,
            v19,
            v11)
        + 29;
    v13 = snprintf(&v3[v12], 1024 - v12, "}}");
    if ( v13 >= 1024 - v12 )
      v14 = 1023 - v12;
    else
      v14 = v13;
    result = httpd_cgi_ret(a1, v3, v14 + v12, 8);
  }
  else
  {
    v16 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024);
    v17 = snprintf(v18, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
    if ( v17 >= 0x100 )
      v17 = 255;
    result = httpd_cgi_ret(a1, v18, v17, 4);
  }
  return result;
}
// 4BE620: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

