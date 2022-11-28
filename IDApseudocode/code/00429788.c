int __fastcall httpd_send_auth_html_file(int a1)
{
  const char *v2; // $s3
  const char *v3; // $s0
  const char *v4; // $v0
  int v5; // $s7
  int result; // $v0
  bool v7; // dc
  char *v8; // $v0
  char *v9; // $fp
  int v10; // $s3
  DIR *v11; // $s4
  struct dirent *v12; // $v0
  const char *v13; // $s0
  struct tm *v14; // $v0
  char *v15; // $a0
  char v16[1024]; // [sp+30h] [-9D0h] BYREF
  int v17[3]; // [sp+430h] [-5D0h] BYREF
  char v18; // [sp+43Ch] [-5C4h]
  struct stat v19; // [sp+830h] [-1D0h] BYREF
  struct stat v20; // [sp+8D0h] [-130h] BYREF
  char v21[128]; // [sp+970h] [-90h] BYREF
  char *format; // [sp+9F0h] [-10h]
  const char *v23; // [sp+9F4h] [-Ch]
  char *v24; // [sp+9F8h] [-8h]
  const char *v25; // [sp+9FCh] [-4h]

  v2 = (const char *)jhl_nv_get_def("lan_ipaddr");
  if ( stat("/tmp/auth_html", &v20) && check_usb_state() && !stat("/tmp/mnt/sda1/auth_html/auth.tar.gz", &v20) )
  {
    system("mkdir -p /tmp/auth_html");
    system("tar -zxf /tmp/mnt/sda1/auth_html/auth.tar.gz -C /tmp/auth_html");
  }
  v3 = *(const char **)(a1 + 44);
  v4 = &v3[strlen(v3) - 1];
  if ( *v4 == 47 )
  {
    *v4 = 0;
    v3 = *(const char **)(a1 + 44);
  }
  v5 = strcmp(v3, "/auth_html");
  snprintf((char *)v17, 1024, "/tmp%s", v3);
  if ( !stat((const char *)v17, &v20)
    || (unescape((char *)v17), v7 = stat((const char *)v17, &v20) == 0, result = -1, v7) )
  {
    if ( (v20.st_uid & 0xF000) == 0x4000 )
    {
      _mem_malloc(1024000, "httpd_send_auth_html_file", 2494);
      v9 = v8;
      if ( v8 )
      {
        v10 = sprintf(
                v8,
                "<html><head><META http-eqiu='Content-Type' content='text/html; charset=UTF-8'><title>%s - %s/</title></h"
                "ead><body><H1>%s - %s/</H1><hr><pre>",
                v2,
                (const char *)(*(_DWORD *)(a1 + 44) + 11),
                v2,
                (const char *)(*(_DWORD *)(a1 + 44) + 11));
        v11 = opendir((const char *)v17);
        if ( v11 )
        {
          format = "%s/%s";
          v23 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
          v24 = "%s   %lld   <A HREF='%s/%s'>%s</A><br>\r\n";
          v25 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
          while ( 1 )
          {
            v12 = readdir(v11);
            v13 = &v12->d_name[8];
            if ( !v12 || v10 >= 1022977 )
              break;
            if ( strcmp(&v12->d_name[8], ".") && (v5 || strcmp(v13, "..")) )
            {
              sprintf(v16, format, v17, v13);
              if ( !stat(v16, &v19) )
              {
                v14 = localtime(&v19.st_ctim.tv_sec);
                strftime(v21, 0x80u, v23 - 2456, v14);
                v15 = &v9[v10];
                if ( (v19.st_uid & 0xF000) == 0x4000 )
                  v10 += sprintf(v15, (char *)v25 - 2444, v21, *(_DWORD *)(a1 + 44), v13, v13);
                else
                  v10 += sprintf(v15, v24, v21);
              }
            }
          }
          closedir(v11);
        }
        strcpy(&v9[v10], "</pre><hr></body></html>");
        qmemcpy(&v9[v10], "</pre><hr></body></html>", 24);
        *(_DWORD *)(a1 + 36) |= 0x8000u;
        httpd_cgi_ret(a1, v9, v10 + 24, 8);
        result = 0;
      }
      else
      {
        v17[0] = -456796489;
        v17[1] = -424355132;
        v17[2] = -592402486;
        v18 = 0;
        result = httpd_cgi_ret(a1, (char *)v17, 12, 4);
      }
    }
    else
    {
      httpd_send_big_file(a1, (int)v17, v20.st_atim.tv_sec);
      result = 0;
    }
  }
  return result;
}
// 4299D4: variable 'v8' is possibly undefined
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

