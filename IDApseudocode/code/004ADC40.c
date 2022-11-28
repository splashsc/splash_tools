int __fastcall sub_4ADC40(int a1)
{
  const char *v2; // $v0
  int v3; // $a2
  const char *v4; // $s0
  int v5; // $v0
  int v6; // $a1
  int v7; // $a0
  int v8; // $v0
  const char *v9; // $s0
  const char *v10; // $s4
  const char *v11; // $v0
  unsigned int v12; // $v0
  int v13; // $s0
  unsigned int v14; // $v0
  char v16[1024]; // [sp+28h] [-500h] BYREF
  char v17[256]; // [sp+428h] [-100h] BYREF

  memset(v16, 0, sizeof(v16));
  v2 = (const char *)jhl_nv_get_def("task_manage_state");
  if ( v2 )
  {
    v4 = v2;
    if ( !strcmp(v2, "Exit") )
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v7 = 67;
      goto LABEL_10;
    }
    if ( !strcmp(v4, "Start") )
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v7 = 68;
      goto LABEL_10;
    }
    if ( !strcmp(v4, "Connecting") )
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v7 = 69;
      goto LABEL_10;
    }
    if ( !strcmp(v4, "Connected") )
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v7 = 70;
      goto LABEL_10;
    }
    if ( !*v4 )
    {
      v5 = a1 + 196608;
LABEL_8:
      v6 = *(unsigned __int8 *)(v5 + 13494);
      v7 = 71;
LABEL_10:
      v8 = _GET_LANG_TEXT(v7, v6, v3);
      strlcpy(v17, v8, 256);
      goto LABEL_11;
    }
  }
  else
  {
    v4 = "";
    if ( !asc_4CF9E8[4] )
    {
      v5 = a1 + 196608;
      goto LABEL_8;
    }
  }
  strlcpy(v17, v4, 256);
LABEL_11:
  strcpy(v16, "{\"code\":0,\"error\":\"\",\"data\":{");
  v9 = (const char *)jhl_nv_get_def("task_manage_en");
  v10 = (const char *)jhl_nv_get_def("task_server_addr");
  v11 = (const char *)jhl_nv_get_def("task_server_port");
  v12 = snprintf(
          &v16[29],
          995,
          "\"enable\":\"%s\",\"srv_addr\":\"%s\",\"srv_port\":\"%s\",\"state\":\"%s\"",
          v9,
          v10,
          v11,
          v17);
  v13 = v12 + 29;
  if ( v12 >= 0x3E3 )
    v13 = 1023;
  v14 = snprintf(&v16[v13], 1024 - v13, "}}");
  if ( v14 >= 1024 - v13 )
    v14 = 1023 - v13;
  return httpd_cgi_ret(a1, v16, v14 + v13, 4);
}
// 4ADD64: variable 'v3' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

