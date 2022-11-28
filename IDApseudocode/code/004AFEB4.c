int __fastcall sub_4AFEB4(int a1)
{
  char *v1; // $v1
  int *v2; // $v0
  int v3; // $t0
  int v4; // $a3
  int v5; // $a2
  int v6; // $a1
  int v7; // $t4
  const char *v8; // $s4
  const char *v9; // $s0
  const char *v10; // $v0
  int v11; // $s0
  int v12; // $s3
  unsigned int v13; // $v0
  const char **v15; // $s7
  int v16; // $a0
  int v17; // $a2
  const char *v18; // $v0
  char v19[10240]; // [sp+20h] [-2B20h] BYREF
  char v20[256]; // [sp+2820h] [-320h] BYREF
  char v21[256]; // [sp+2920h] [-220h] BYREF
  _BYTE v22[160]; // [sp+2A20h] [-120h] BYREF
  char v23; // [sp+2AC0h] [-80h] BYREF
  char v24; // [sp+2AC4h] [-7Ch] BYREF
  char *v25; // [sp+2B38h] [-8h]
  char v26; // [sp+2B3Ch] [-4h] BYREF

  memset(v21, 0, sizeof(v21));
  memset(v20, 0, sizeof(v20));
  memset(v19, 0, sizeof(v19));
  v1 = &v23;
  v2 = (int *)&unk_676DA0;
  do
  {
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)v1 = v3;
    *((_DWORD *)v1 + 1) = v4;
    *((_DWORD *)v1 + 2) = v5;
    *((_DWORD *)v1 + 3) = v6;
    v1 += 16;
  }
  while ( v2 != (int *)&unk_676E10 );
  v7 = v2[1];
  *(_DWORD *)v1 = *v2;
  *((_DWORD *)v1 + 1) = v7;
  strcpy(v19, "{\"code\":0,\"error\":\"\",\"data\":{");
  v8 = (const char *)nvram_get("usblogd_en");
  if ( !v8 )
    v8 = "0";
  v9 = (const char *)nvram_get("usblog_time_h");
  if ( v9 )
  {
    v10 = (const char *)nvram_get("usblog_time_m");
    if ( v10 )
      goto LABEL_7;
  }
  else
  {
    v10 = (const char *)nvram_get("usblog_time_m");
    v9 = "20";
    if ( v10 )
      goto LABEL_7;
  }
  v10 = "25";
LABEL_7:
  v11 = sprintf(&v19[29], "\"usblogd_en\":\"%s\",\"time_h\":\"%s\",\"time_m\":\"%s\",\"list\":[", v8, v9, v10) + 29;
  if ( get_usb_mount_dir(v20, 256) )
  {
    v25 = &v26;
    v15 = (const char **)&v24;
    do
    {
      sprintf(v21, "%s/%s", v20, *v15);
      memset(v22, 0, sizeof(v22));
      stat(v21, (struct stat *)v22);
      v16 = (int)*(v15 - 1);
      v15 += 2;
      v18 = (const char *)_GET_LANG_TEXT(v16, *(unsigned __int8 *)(a1 + 210102), v17);
      v11 += sprintf(&v19[v11], "{\"name\":\"%s\",\"file\":\"%s\",\"size\":%lld},", v18, v21, *(_QWORD *)&v22[56]);
    }
    while ( v25 != (char *)v15 );
  }
  if ( v11 > 0 && v19[v11 - 1] == 44 )
    --v11;
  v12 = v11 + 1;
  *(_WORD *)&v19[v11] = 93;
  v13 = snprintf(&v19[v11 + 1], 10240 - (v11 + 1), "}}");
  if ( v13 >= 10240 - (v11 + 1) )
    v13 = 10239 - v12;
  return httpd_cgi_ret(a1, v19, v13 + v12, 4);
}
// 4B01BC: variable 'v17' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A864C: using guessed type int __fastcall get_usb_mount_dir(_DWORD, _DWORD);

