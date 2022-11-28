int __fastcall httpd_send_usb_file(int a1)
{
  const char *v2; // $s5
  int v3; // $s1
  int v4; // $s4
  void *v6; // $v0
  void *v7; // $s2
  char *v8; // $v0
  char *v9; // $s3
  const char *v10; // $s6
  const char *v11; // $v0
  int v12; // $s0
  char *v13; // $v0
  int v14; // $s7
  DIR *v15; // $fp
  struct dirent *v16; // $v0
  char *v17; // $s6
  struct tm *v18; // $v0
  int v19; // $a3
  char *v20; // $v0
  int v21; // $s7
  const char *v22; // $a2
  int v23; // $v0
  char *v24; // $a1
  _BYTE v25[1024]; // [sp+30h] [-538h] BYREF
  struct stat v26; // [sp+430h] [-138h] BYREF
  char v27[128]; // [sp+4D0h] [-98h] BYREF
  char *v28; // [sp+550h] [-18h]
  char *v29; // [sp+554h] [-14h]
  char *format; // [sp+558h] [-10h]
  const char *v31; // [sp+55Ch] [-Ch]
  char *v32; // [sp+560h] [-8h]
  const char *v33; // [sp+564h] [-4h]

  v2 = (const char *)jhl_nv_get_def("lan_ipaddr");
  if ( !strncmp(*(const char **)(a1 + 44), "/usb/app/", 9u) )
    goto LABEL_7;
  if ( nvram_match_def("usb_share_enable", "0") )
    goto LABEL_9;
  v3 = usb_acc_check((int *)(a1 + 205460));
  if ( v3 )
    goto LABEL_9;
  if ( !nvram_match_def("usb_acc_auth", "1") )
  {
LABEL_7:
    v4 = 0;
    goto LABEL_8;
  }
  v4 = 1;
  if ( !usb_httpd_check_user(a1, 1) )
  {
LABEL_8:
    if ( !check_usb_state() )
    {
LABEL_9:
      v3 = 0;
      httpd_conn_close((int *)a1);
      return v3;
    }
    _mem_malloc(512, "httpd_send_usb_file", 1786);
    v7 = v6;
    if ( !v6 )
      return -1;
    _mem_malloc(512, "httpd_send_usb_file", 1792);
    v9 = v8;
    if ( !v8 )
    {
      _mem_free(v7);
      return -1;
    }
    v10 = *(const char **)(a1 + 44);
    v11 = &v10[strlen(v10) - 1];
    if ( *v11 == 47 )
    {
      *v11 = 0;
      v10 = *(const char **)(a1 + 44);
    }
    if ( !strcmp(v10, "/usb") )
    {
      memset(v25, 0, sizeof(v25));
      snprintf(v25, 1024, "%s%s", *(const char **)(a1 + 205504), "/usb_list.html");
      return httpd_send_redirect(a1, v25);
    }
    snprintf((char *)v7, 512, "/tmp/mnt/sda1/%s", v10 + 5);
    if ( !stat((const char *)v7, &v26) || (unescape((char *)v7), !stat((const char *)v7, &v26)) )
    {
      if ( (v26.st_uid & 0xF000) != 0x4000 )
      {
        if ( *(_QWORD *)&v26.st_atim < 0x80000000LL )
          httpd_send_big_file(a1, (int)v7, v26.st_atim.tv_sec);
        else
          httpd_send_big_file_ll(a1, (int)v7, v26.st_atim.tv_sec, v26.st_atim.tv_nsec);
        v12 = 0;
        goto LABEL_20;
      }
      _mem_malloc(1024000, "httpd_send_usb_file", 1823);
      v29 = v13;
      if ( v13 )
      {
        v14 = sprintf(
                v13,
                "<html><head><META http-eqiu='Content-Type' content='text/html; charset=UTF-8'><title>%s - %s/</title></h"
                "ead><body><H1>%s - %s/</H1><hr><pre>",
                v2,
                (const char *)(*(_DWORD *)(a1 + 44) + 5),
                v2,
                (const char *)(*(_DWORD *)(a1 + 44) + 5));
        v15 = opendir((const char *)v7);
        if ( v15 )
        {
          v28 = ".";
          format = "%s/%s";
          v31 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
          v32 = "%s   %lld   <A HREF='%s/%s'>%s</A><br>\r\n";
          v33 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
          while ( 1 )
          {
            v16 = readdir(v15);
            v17 = &v16->d_name[8];
            if ( !v16 || v14 >= 1022977 )
              break;
            if ( strcmp(&v16->d_name[8], v28) )
            {
              sprintf(v9, format, v7, v17);
              if ( stat(v9, (struct stat *)v25) == -1 )
              {
                perror("stat");
              }
              else
              {
                v18 = localtime((const time_t *)&v25[72]);
                strftime(v27, 0x80u, v31 - 2456, v18);
                if ( (*(_WORD *)&v25[24] & 0xF000) == 0x4000 )
                  v14 += sprintf(&v29[v14], (char *)v33 - 2444, v27, *(_DWORD *)(a1 + 44), v17, v17);
                else
                  v14 += sprintf(&v29[v14], v32, v27);
              }
            }
          }
          closedir(v15);
        }
        v19 = (int)v29;
        v20 = &v29[v14];
        strcpy(&v29[v14], "</pre>");
        v21 = v14 + 6;
        *(_DWORD *)v20 = *(_DWORD *)"</pre>";
        if ( v4 )
          v22 = "<iframe src='/usb_upload.htm'  id='fram_id' height='200px' width='1000' frameborder='0' scrolling='no'> </iframe>";
        else
          v22 = "";
        v23 = sprintf((char *)(v19 + v21), "<hr>%s</body></html>", v22);
        v24 = v29;
        *(_DWORD *)(a1 + 36) |= 0x8000u;
        httpd_cgi_ret(a1, v24, v21 + v23, 8);
        v12 = 0;
        goto LABEL_20;
      }
    }
    v12 = -1;
LABEL_20:
    _mem_free(v7);
    _mem_free(v9);
    v3 = v12;
  }
  return v3;
}
// 426A0C: variable 'v6' is possibly undefined
// 426A2C: variable 'v8' is possibly undefined
// 426C4C: variable 'v13' is possibly undefined
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

