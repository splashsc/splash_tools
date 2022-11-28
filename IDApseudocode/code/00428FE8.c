int __fastcall sub_428FE8(int *a1)
{
  int v2; // $s5
  int v3; // $s1
  void *v4; // $v0
  void *v5; // $s1
  char *v6; // $v0
  char *v7; // $s4
  const char *v8; // $s3
  const char *v9; // $v0
  int v10; // $s6
  int v12; // $s0
  int v13; // $v0
  DIR *v14; // $fp
  int v15; // $s7
  struct dirent *v16; // $v0
  const char *v17; // $s3
  struct tm *v18; // $v0
  int v19; // $v0
  char *v20; // $a1
  int v21; // $v1
  struct stat v22; // [sp+30h] [-1E0h] BYREF
  struct stat v23; // [sp+D0h] [-140h] BYREF
  char v24[128]; // [sp+170h] [-A0h] BYREF
  char *v25; // [sp+1F0h] [-20h]
  char *v26; // [sp+1F4h] [-1Ch]
  char *format; // [sp+1F8h] [-18h]
  const char *v28; // [sp+1FCh] [-14h]
  char *v29; // [sp+200h] [-10h]
  const char *v30; // [sp+204h] [-Ch]
  char *v31; // [sp+208h] [-8h]

  if ( !nvram_match_def("usb_acc_auth", "1") )
  {
    v2 = 0;
    v3 = check_usb_state();
    if ( v3 )
      goto LABEL_4;
LABEL_14:
    httpd_conn_close(a1);
    return v3;
  }
  if ( usb_httpd_check_user((int)a1, 1) )
    return 0;
  v2 = 1;
  v3 = check_usb_state();
  if ( !v3 )
    goto LABEL_14;
LABEL_4:
  _mem_malloc(512, "httpd_send_usb_file_json", 1937);
  v5 = v4;
  if ( !v4 )
    return -1;
  _mem_malloc(512, "httpd_send_usb_file_json", 1943);
  v7 = v6;
  if ( !v6 )
  {
    _mem_free(v5);
    return -1;
  }
  v8 = (const char *)a1[11];
  v9 = &v8[strlen(v8) - 1];
  if ( *v9 == 47 )
  {
    *v9 = 0;
    v8 = (const char *)a1[11];
  }
  v10 = strcmp(v8, "/usb_json");
  snprintf((char *)v5, 512, "/tmp/mnt/sda1/%s", v8 + 10);
  if ( !stat((const char *)v5, &v23) || (unescape((char *)v5), !stat((const char *)v5, &v23)) )
  {
    if ( (v23.st_uid & 0xF000) != 0x4000 )
    {
      if ( *(_QWORD *)&v23.st_atim >= 0x80000000LL )
        httpd_send_big_file_ll((int)a1, (int)v5, v23.st_atim.tv_sec, v23.st_atim.tv_nsec);
      else
        httpd_send_big_file((int)a1, (int)v5, v23.st_atim.tv_sec);
      v12 = 0;
      goto LABEL_12;
    }
    _mem_malloc(1024000, "httpd_send_usb_file_json", 1968);
    v26 = (char *)v13;
    if ( v13 )
    {
      *(_BYTE *)v13 = 91;
      *(_WORD *)(v13 + 1) = 32;
      v14 = opendir((const char *)v5);
      if ( v14 )
      {
        v15 = 2;
        v25 = ".";
        format = "%s/%s";
        v30 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
        v31 = "{\"filesize\":%lld,\"filename\":\"%s\",\"lastdate\":\"%s\",\"url\":\"%s/%s\",\"type\":\"%d\"},";
        v28 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
        while ( 1 )
        {
          v16 = readdir(v14);
          if ( !v16 )
            break;
          v17 = &v16->d_name[8];
          if ( v15 >= 1022977 )
          {
            closedir(v14);
            v19 = v15;
            goto LABEL_40;
          }
          if ( strcmp(&v16->d_name[8], v25)
            && (v10
             || strcmp(v17, v28 - 1460)
             && (!v2 || a1[51397] >= 2 || !strcmp(v17, (const char *)&off_4CFA50) || !strcmp(v17, "share"))) )
          {
            sprintf(v7, format, v5, v17);
            if ( !stat(v7, &v22) )
            {
              v18 = localtime(&v22.st_ctim.tv_sec);
              v29 = v24;
              strftime(v24, 0x80u, v30 - 2456, v18);
              v15 += sprintf(
                       &v26[v15],
                       v31,
                       v22.st_atim.tv_sec,
                       v22.st_atim.tv_nsec,
                       v17,
                       v29,
                       a1[11],
                       v17,
                       2 - ((v22.st_uid & 0xF000) != 0x4000));
            }
          }
        }
        closedir(v14);
        v19 = v15;
        if ( v15 <= 0 )
          goto LABEL_37;
LABEL_40:
        v21 = v15 - 1;
      }
      else
      {
        v21 = 1;
        v19 = 2;
        v15 = 2;
      }
      if ( v26[v21] == 44 )
      {
        --v15;
LABEL_37:
        v19 = v15;
      }
      v20 = v26;
      *(_WORD *)&v26[v19] = 93;
      a1[9] |= 0x8000u;
      httpd_cgi_ret((int)a1, v20, v15 + 1, 8);
      v12 = 0;
      goto LABEL_12;
    }
  }
  v12 = -1;
LABEL_12:
  _mem_free(v5);
  _mem_free(v7);
  return v12;
}
// 4290A4: variable 'v4' is possibly undefined
// 4290C4: variable 'v6' is possibly undefined
// 4292E4: variable 'v13' is possibly undefined
// 4CFA50: using guessed type void *off_4CFA50;
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

