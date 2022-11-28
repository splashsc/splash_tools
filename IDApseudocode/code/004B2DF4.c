int __fastcall sub_4B2DF4(int a1)
{
  const char *v1; // $s4
  char *v3; // $s6
  char *v4; // $s3
  const char *v5; // $v0
  unsigned int v6; // $a2
  int v7; // $s2
  int v9; // $s7
  int v10; // $a2
  int v11; // $a1
  int v12; // $a0
  char *v13; // $v1
  const char *v14; // $v0
  int v15; // $t0
  int v16; // $a3
  int v17; // $a2
  int v18; // $a1
  char v19[512]; // [sp+20h] [-5B4h] BYREF
  char v20[512]; // [sp+220h] [-3B4h] BYREF
  char v21[256]; // [sp+420h] [-1B4h] BYREF
  struct stat v22; // [sp+520h] [-B4h] BYREF
  int v23[5]; // [sp+5C0h] [-14h] BYREF

  v1 = v20;
  memset(v20, 0, sizeof(v20));
  memset(v19, 0, sizeof(v19));
  memset(v21, 0, sizeof(v21));
  v3 = httpd_get_parm(a1, "opt");
  v4 = httpd_get_parm(a1, "path");
  if ( strstr(v4, "..") )
  {
    v5 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "error path");
    goto LABEL_3;
  }
  if ( nvram_match_def("usb_share_enable", "0") || (v7 = usb_acc_check((int *)(a1 + 205460))) != 0 )
  {
    httpd_conn_close((int *)a1);
    return 0;
  }
  if ( nvram_match_def("usb_acc_auth", "1") )
  {
    v9 = 1;
    if ( usb_httpd_check_user(a1, 1) )
      return v7;
  }
  else
  {
    v9 = 0;
  }
  if ( !check_usb_state() )
  {
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = 186;
LABEL_23:
    v5 = (const char *)_GET_LANG_TEXT(v12, v11, v10);
    goto LABEL_3;
  }
  if ( !v3 || strcmp(v3, "del") && strcmp(v3, "dir") )
  {
    v5 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_3;
  }
  if ( !*v4 )
  {
    v5 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_64E0E0);
LABEL_3:
    v6 = snprintf(v21, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v5);
    if ( v6 >= 0x100 )
      v6 = 255;
    return httpd_cgi_ret(a1, v21, v6, 4);
  }
  if ( !v9 )
  {
    v5 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "error opt");
    goto LABEL_3;
  }
  snprintf(v20, 512, "/tmp/mnt/sda1/%s", v4);
  strcpy(v19, "/tmp/mnt/sda1/");
  unescape(v4);
  gbk_to_utf8(v4, &v19[14], 498);
  if ( !strcmp(v3, "del") )
  {
    if ( stat(v20, &v22) )
    {
      v1 = v19;
      if ( stat(v19, &v22) )
      {
        v11 = *(unsigned __int8 *)(a1 + 210102);
        v12 = 143;
        goto LABEL_23;
      }
    }
    v23[0] = (int)"rm";
    v23[1] = (int)&off_64E318;
    v23[2] = (int)v1;
    v23[3] = 0;
    eval(v23, 0, 0, 0);
  }
  if ( strcmp(v3, "dir") )
    goto LABEL_30;
  if ( !stat(v1, &v22) || !stat(v19, &v22) )
  {
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = 187;
    goto LABEL_23;
  }
  create_dir(v19);
LABEL_30:
  v13 = v21;
  v14 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v15 = *(_DWORD *)v14;
    v16 = *((_DWORD *)v14 + 1);
    v17 = *((_DWORD *)v14 + 2);
    v18 = *((_DWORD *)v14 + 3);
    v14 += 16;
    *(_DWORD *)v13 = v15;
    *((_DWORD *)v13 + 1) = v16;
    *((_DWORD *)v13 + 2) = v17;
    *((_DWORD *)v13 + 3) = v18;
    v13 += 16;
  }
  while ( v14 != "}" );
  v6 = 33;
  *(_WORD *)v13 = *(_WORD *)v14;
  return httpd_cgi_ret(a1, v21, v6, 4);
}
// 4B3110: variable 'v10' is possibly undefined
// 64E318: using guessed type void *off_64E318;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A85C8: using guessed type int __fastcall gbk_to_utf8(_DWORD, _DWORD, _DWORD);
// 6A85D8: using guessed type int __fastcall create_dir(_DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

