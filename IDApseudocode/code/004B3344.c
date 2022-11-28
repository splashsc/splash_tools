int __fastcall sub_4B3344(int a1)
{
  char *v2; // $v0
  const char *v3; // $s5
  unsigned int v4; // $v0
  bool v5; // dc
  char *v6; // $v0
  int v7; // $a1
  int v8; // $a2
  int v9; // $a0
  const char *v10; // $v0
  unsigned int v11; // $a2
  int v12; // $fp
  int v14; // $a2
  _BOOL4 v15; // $s7
  int v16; // $a2
  int v17; // $v0
  char *v18; // $s4
  int v19; // $v0
  int v20; // $s2
  int v21; // $fp
  DIR *v22; // $s3
  struct dirent *v23; // $v0
  const char *v24; // $s1
  int v25; // $v0
  int v26; // $s2
  int v27; // $a2
  int v28; // $a2
  int v29; // $s0
  int v30; // $v0
  const char *v31; // $v0
  char v32[512]; // [sp+28h] [-A58h] BYREF
  char v33[512]; // [sp+228h] [-858h] BYREF
  char v34[512]; // [sp+428h] [-658h] BYREF
  char v35[512]; // [sp+628h] [-458h] BYREF
  char v36[256]; // [sp+828h] [-258h] BYREF
  struct stat v37; // [sp+928h] [-158h] BYREF
  struct stat v38; // [sp+9C8h] [-B8h] BYREF
  char *format; // [sp+A68h] [-18h]
  char *name; // [sp+A6Ch] [-14h]
  char *v41; // [sp+A70h] [-10h]
  char *v42; // [sp+A74h] [-Ch]
  const char *v43; // [sp+A78h] [-8h]

  memset(v35, 0, sizeof(v35));
  memset(v34, 0, sizeof(v34));
  memset(v33, 0, sizeof(v33));
  memset(v32, 0, sizeof(v32));
  memset(v36, 0, sizeof(v36));
  v2 = httpd_get_parm(a1, "path");
  if ( v2 )
  {
    v3 = v2;
    if ( strcmp(v2, "/") )
    {
      if ( *v3 == 47 )
        ++v3;
      v4 = snprintf(v32, 512, "%s", v3);
      v5 = v4 < 0x200;
      v6 = &v32[v4];
      if ( !v5 )
        v6 = &v32[511];
      if ( *(v6 - 1) != 47 )
        *v6 = 47;
    }
  }
  if ( strstr(v32, "..") )
  {
    v7 = *(unsigned __int8 *)(a1 + 210102);
    v8 = (int)"error path";
    v9 = 12;
LABEL_11:
    v10 = (const char *)_GET_LANG_TEXT(v9, v7, v8);
LABEL_12:
    v11 = snprintf(v36, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x100 )
      v11 = 255;
    return httpd_cgi_ret(a1, v36, v11, 4);
  }
  v12 = nvram_match_def("usb_share_enable", "0");
  if ( v12 )
  {
    v10 = (const char *)_GET_LANG_TEXT(192, *(unsigned __int8 *)(a1 + 210102), v14);
    goto LABEL_12;
  }
  format = (char *)usb_acc_check((int *)(a1 + 205460));
  if ( !nvram_match_def("usb_acc_auth", "1") )
    goto LABEL_23;
  if ( usb_httpd_check_user(a1, 1) )
    return v12;
  v15 = v32[0] || *(_DWORD *)(a1 + 205588) >= 2;
  if ( format )
LABEL_23:
    v15 = 0;
  if ( !check_usb_state() )
  {
    v10 = (const char *)_GET_LANG_TEXT(186, *(unsigned __int8 *)(a1 + 210102), v16);
    goto LABEL_12;
  }
  snprintf(v35, 512, "/tmp/mnt/sda1/%s", v32);
  strcpy(v34, "/tmp/mnt/sda1/");
  unescape(v32);
  gbk_to_utf8(v32, &v34[14], 498);
  if ( stat(v35, &v38) )
  {
    if ( stat(v34, &v38) )
    {
      v10 = (const char *)_GET_LANG_TEXT(191, *(unsigned __int8 *)(a1 + 210102), v28);
      goto LABEL_12;
    }
    name = v34;
  }
  else
  {
    name = v35;
  }
  if ( (v38.st_uid & 0xF000) != 0x4000 )
  {
    v29 = *(unsigned __int8 *)(a1 + 210102);
    v30 = _GET_LANG_TEXT(191, v29, 2727);
    v31 = (const char *)_GET_LANG_TEXT(12, v29, v30);
    snprintf(v36, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
    return -1;
  }
  _mem_malloc(0x200000, "usb_list_data", 2727);
  v18 = (char *)v17;
  if ( !v17 )
  {
    v7 = *(unsigned __int8 *)(a1 + 210102);
    v8 = 0x200000;
    v9 = 4;
    goto LABEL_11;
  }
  strcpy((char *)v17, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy((void *)v17, "{\"code\":0,\"error", 16);
  *(_DWORD *)(v17 + 20) = 1633952300;
  v19 = snprintf((char *)(v17 + 29), 0x200000, "\"upload\":%d,\"list\":[", v15);
  v20 = v19 + 29;
  if ( v19 >= 0x200000 )
  {
    v21 = 2097180;
    if ( format )
    {
      v25 = 2097179;
      v20 = 2097180;
LABEL_48:
      if ( v18[v25] == 44 )
        v21 = --v20;
      goto LABEL_50;
    }
    v20 = 2097180;
  }
  else
  {
    v21 = v19 + 29;
    if ( format )
      goto LABEL_47;
  }
  if ( !v32[0] || !strncmp(v32, "usb/", 4u) || !strncmp(v32, "share/", 6u) )
  {
    v22 = opendir(name);
    if ( v22 )
    {
      format = "%s%s";
      v41 = "1\"";
      v42 = (char *)&off_4CFA50;
      v43 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      while ( 1 )
      {
        v23 = readdir(v22);
        if ( !v23 )
          break;
        v24 = &v23->d_name[8];
        if ( v20 >= 2096897 )
          break;
        if ( strcmp(&v23->d_name[8], ".")
          && strcmp(v24, "..")
          && (!v15 || v32[0] || *(int *)(a1 + 205588) >= 2 || !strcmp(v24, v42) || !strcmp(v24, v43 - 1452)) )
        {
          sprintf(v33, format, name, v24);
          if ( !stat(v33, &v37) )
            v20 += sprintf(
                     &v18[v20],
                     v41 - 7356,
                     v37.st_atim.tv_sec,
                     v37.st_atim.tv_nsec,
                     v24,
                     v37.st_ctim.tv_sec,
                     (v37.st_uid & 0xF000) == 0x4000);
        }
      }
      closedir(v22);
      v21 = v20;
    }
  }
LABEL_47:
  v25 = v21 - 1;
  if ( v20 > 0 )
    goto LABEL_48;
LABEL_50:
  v26 = v20 + 1;
  *(_WORD *)&v18[v21] = 93;
  v27 = snprintf(&v18[v26], 0x200000 - v26, "}}");
  if ( v27 >= 0x200000 - v26 )
    v27 = 0x1FFFFF - v26;
  *(_DWORD *)(a1 + 36) |= 0x8000u;
  return httpd_cgi_ret(a1, v18, v27 + v26, 8);
}
// 4B35B0: variable 'v14' is possibly undefined
// 4B368C: variable 'v16' is possibly undefined
// 4B3768: variable 'v17' is possibly undefined
// 4B3B60: variable 'v28' is possibly undefined
// 4CFA50: using guessed type void *off_4CFA50;
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A85C8: using guessed type int __fastcall gbk_to_utf8(_DWORD, _DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

