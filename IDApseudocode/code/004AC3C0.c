int __fastcall sub_4AC3C0(int a1)
{
  void *v2; // $v0
  char *v3; // $v0
  char *v4; // $s0
  void *v5; // $s2
  int v6; // $s1
  int v7; // $s1
  int v8; // $v0
  int v9; // $s1
  int result; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char *v13; // [sp+30h] [-100h] BYREF
  char *v14; // [sp+34h] [-FCh]
  const char *v15; // [sp+38h] [-F8h]
  char *v16; // [sp+3Ch] [-F4h]
  const char *v17; // [sp+40h] [-F0h]
  char *v18; // [sp+44h] [-ECh]

  _mem_malloc(0x200000, "jingx_data", 190);
  v4 = v3;
  _mem_malloc(10240, "jingx_data", 191);
  v5 = v2;
  if ( !v4 || !v2 )
  {
    _mem_free(v4);
    _mem_free(v5);
    v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v12 = snprintf((char *)&v13, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x100 )
      result = httpd_cgi_ret(a1, (char *)&v13, 255, 4);
    else
      result = httpd_cgi_ret(a1, (char *)&v13, v12, 4);
    return result;
  }
  jhl_parm_get("jingx2", v2, 10240);
  split_string(v5, 60, &v13, 6);
  if ( !v13 )
    v13 = "0";
  if ( v14 )
  {
    if ( v15 )
      goto LABEL_7;
  }
  else
  {
    v14 = "all";
    if ( v15 )
    {
LABEL_7:
      if ( v16 )
        goto LABEL_8;
      goto LABEL_19;
    }
  }
  v15 = "192.168.1.2";
  if ( v16 )
  {
LABEL_8:
    if ( v17 )
      goto LABEL_9;
LABEL_20:
    v17 = "WAN1";
    if ( v18 )
      goto LABEL_10;
LABEL_21:
    v18 = "0";
    goto LABEL_10;
  }
LABEL_19:
  v16 = "0";
  if ( !v17 )
    goto LABEL_20;
LABEL_9:
  if ( !v18 )
    goto LABEL_21;
LABEL_10:
  strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy(v4, "{\"code\":0,\"error\":\"\"", 20);
  v6 = sprintf(
         v4 + 29,
         "\"en\":%s,\"fx\":\"%s\",\"ip\":\"%s\",\"type\":\"%s\",\"outdev\":\"%s\",\"dual_show\":%d,\"indev\":\"%s\",\"wans\":",
         v13,
         v14,
         v15,
         v16,
         v17,
         1,
         v18)
     + 29;
  v7 = v6 + get_wans_data(&v4[v6], 0x200000 - v6);
  v8 = snprintf(&v4[v7], 0x200000 - v7, "}}");
  if ( v8 >= 0x200000 - v7 )
    v8 = 0x1FFFFF - v7;
  v9 = v8 + v7;
  _mem_free(v5);
  return httpd_cgi_ret(a1, v4, v9, 8);
}
// 4AC428: variable 'v3' is possibly undefined
// 4AC434: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

