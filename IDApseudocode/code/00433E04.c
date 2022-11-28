int httpd_unix_recv()
{
  char *v0; // $v0
  char *v1; // $s0
  int v2; // $s1
  ssize_t v3; // $v0
  ssize_t v4; // $s7
  uint32_t v5; // $v0
  unsigned int v6; // $s6
  struct sockaddr addr; // [sp+20h] [-80h] BYREF
  socklen_t addr_len[2]; // [sp+90h] [-10h] BYREF
  char *format; // [sp+98h] [-8h]
  char *v11; // [sp+9Ch] [-4h]

  addr_len[0] = 110;
  _mem_malloc(0x200000, "httpd_unix_recv", 119);
  v1 = v0;
  if ( v0 )
  {
    format = "%s:%d datalen is %d != %d\n";
    v2 = 10;
    v11 = "%s:%d cmdid:%d do error\n";
    while ( 1 )
    {
      while ( 1 )
      {
        addr_len[0] = 110;
        v3 = recvfrom(gl_httpd_unix_fd, v1, 0x1FFFFFu, 0, &addr, addr_len);
        v4 = v3;
        if ( v3 <= 0 )
        {
          if ( debug_level > 0 )
            printf("%s:%d recvfrom ret = %d\n", "httpd_unix_recv", 132, v3);
          _mem_free(v1);
          return -1;
        }
        v1[v3] = 0;
        v6 = ntohl(*(_DWORD *)v1);
        v5 = ntohl(*((_DWORD *)v1 + 1));
        if ( v6 >= 0x7539 )
        {
          if ( debug_level > 0 )
            printf("%s:%d cmdid > AC_UNIX_CMD_max is %d\n", "httpd_unix_recv", 144, v6);
          goto LABEL_5;
        }
        if ( !v5 || v4 != v5 )
          break;
        if ( v6 < 0x2725 )
        {
          if ( httpd_unix_ac_cmd_do() == -1 && debug_level > 0 )
          {
            printf(v11, "httpd_unix_recv", 169, v6);
            --v2;
            goto LABEL_6;
          }
        }
        else if ( httpd_unix_cmd_do(v6, *((_DWORD *)v1 + 2), v1 + 12, v4 - 12) == -1 && debug_level > 0 )
        {
          printf(v11, "httpd_unix_recv", 160, v6);
          --v2;
          goto LABEL_6;
        }
LABEL_5:
        --v2;
LABEL_6:
        if ( !v2 )
          goto LABEL_13;
      }
      if ( debug_level <= 0 )
        goto LABEL_5;
      --v2;
      printf(format, "httpd_unix_recv", 151, v5, v4);
      if ( !v2 )
      {
LABEL_13:
        _mem_free(v1);
        return 0;
      }
    }
  }
  if ( debug_level > 0 )
    printf("%s:%d buf malloc failed\n", "httpd_unix_recv", 122);
  return -1;
}
// 433E68: variable 'v0' is possibly undefined
// 66B5F0: using guessed type int gl_httpd_unix_fd;
// 67D0BC: using guessed type int debug_level;

