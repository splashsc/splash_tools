int __fastcall sub_482FD4(int a1)
{
  char *v2; // $v0
  int v3; // $a2
  size_t v4; // $v0
  char *v5; // $s3
  int v6; // $a1
  int v7; // $a0
  const char *v8; // $v0
  int v9; // $s3
  unsigned int v10; // $v0
  const char *v12; // $v0
  char v13[1024]; // [sp+18h] [-610h] BYREF
  char v14[512]; // [sp+418h] [-210h] BYREF
  int v15[4]; // [sp+618h] [-10h] BYREF

  memset(v13, 0, sizeof(v13));
  v2 = httpd_get_parm(a1, "url");
  v3 = 572668450;
  strcpy(v14, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( v2 && (v5 = v2, v4 = strlen(v2), base64_decode(v5, v13, v4), !strncmp(v13, "http://", 7u)) )
  {
    v12 = (const char *)nvram_get("fw_upgrade_state");
    if ( !v12 || strcmp(v12, "4") )
    {
      system("killall fw_upgrade");
      nvram_set("fw_upgrade_state", "0");
      v15[1] = (int)v13;
      v15[0] = (int)"fw_upgrade";
      v15[2] = 0;
      eval_nowait(v15, 0, 0, 0);
      *(_DWORD *)(a1 + 205572) = 0;
      fw_upgrade_timeout(a1);
      return 0;
    }
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 21;
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 26;
  }
  v8 = (const char *)_GET_LANG_TEXT(v7, v6, v3);
  v9 = sprintf(&v14[29], "\"err\":\"%s\"", v8) + 29;
  v10 = snprintf(&v14[v9], 512 - v9, "}}");
  if ( v10 >= 512 - v9 )
    v10 = 511 - v9;
  return httpd_cgi_ret(a1, v14, v10 + v9, 4);
}
// 4830F4: variable 'v3' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

