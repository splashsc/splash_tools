int __fastcall sub_45A69C(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s6
  const char *v5; // $s1
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s5
  const char *v9; // $v0
  int v10; // $s3
  int v11; // $v0
  int v12; // $a2
  int result; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[256]; // [sp+28h] [-100h] BYREF

  _mem_malloc(10240, "parm_sendemail_data", 569);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\",\"da", 24);
    v4 = (const char *)jhl_nv_get_def("parm_email_en");
    v5 = (const char *)jhl_nv_get_def("parm_email_name");
    v6 = (const char *)jhl_nv_get_def("parm_email_url");
    v7 = (const char *)jhl_nv_get_def("parm_email_mode");
    v8 = (const char *)jhl_nv_get_def("parm_email_time");
    v9 = (const char *)jhl_nv_get_def("parm_email_hour");
    v10 = sprintf(
            v3 + 29,
            "\"enable\":\"%s\",\"name\":\"%s\",\"email\":\"%s\",\"mode\":\"%s\",\"time\":\"%s\",\"hour\":\"%s\"",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9)
        + 29;
    v11 = snprintf(&v3[v10], 10240 - v10, "}}");
    if ( v11 >= 10240 - v10 )
      v12 = 10239 - v10;
    else
      v12 = v11;
    result = httpd_cgi_ret(a1, v3, v12 + v10, 8);
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v15 = snprintf(v16, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v15 >= 0x100 )
      v15 = 255;
    result = httpd_cgi_ret(a1, v16, v15, 4);
  }
  return result;
}
// 45A6F4: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

