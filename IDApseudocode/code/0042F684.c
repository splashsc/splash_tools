int __fastcall httpd_poll(int timeout)
{
  int v1; // $s4
  int v2; // $s2
  int v3; // $a0
  int v4; // $s2
  int v5; // $a0
  int v6; // $s5
  struct pollfd *v7; // $s0
  int v8; // $a0
  __int16 v9; // $v0
  int v10; // $v0
  int *v11; // $s7
  __int16 v12; // $v0
  bool v13; // dc
  int v14; // $v0
  int v16; // $v0
  int v17; // $s2
  struct sockaddr v18; // [sp+18h] [-28h] BYREF
  socklen_t v19; // [sp+34h] [-Ch] BYREF
  struct pollfd *v20; // [sp+38h] [-8h]

  v1 = poll(&array_conn, curfds, timeout);
  if ( v1 <= 0 )
    return 0;
  v20 = &array_conn;
  if ( (array_conn.revents & 1) == 0 )
    goto LABEL_9;
  while ( 1 )
  {
    v19 = 28;
    v2 = accept(dword_667724, &v18, &v19);
    if ( v2 < 0 )
    {
      if ( --v1 )
        goto LABEL_9;
      return 0;
    }
    if ( !ip_allow_to_access(&v18) )
      break;
    if ( httpd_conn_add(v2, (int)&v18, 0) )
      close(v2);
  }
  --v1;
  close(v2);
  if ( !v1 )
    return 0;
LABEL_9:
  v3 = dword_667720;
  v4 = 1;
  if ( dword_667720 == -1 )
    goto LABEL_12;
  if ( (v20[1].revents & 1) == 0 )
  {
    v4 = 2;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v19 = 28;
    v16 = accept(v3, &v18, &v19);
    v17 = v16;
    if ( v16 < 0 )
      break;
    if ( httpd_conn_add(v16, (int)&v18, dword_667720) )
      close(v17);
    v3 = dword_667720;
  }
  --v1;
  v4 = 2;
  if ( v1 )
  {
LABEL_12:
    v5 = https_fd;
    if ( https_fd == -1 )
      goto LABEL_22;
    if ( (v20[v4].revents & 1) != 0 )
    {
      while ( 1 )
      {
        v19 = 28;
        v6 = accept(v5, &v18, &v19);
        if ( v6 < 0 )
          break;
        if ( !ip_allow_to_access(&v18) )
        {
          --v1;
          close(v6);
          ++v4;
          if ( !v1 )
            return 0;
LABEL_22:
          if ( v4 >= curfds )
            return 0;
          v7 = &v20[v4];
          while ( 2 )
          {
            v8 = v7->fd;
            if ( v7->fd >= 0 )
            {
              v9 = v7->revents;
              if ( (v9 & 0xD) != 0 )
              {
                v10 = v9 & 1;
                if ( v8 == gl_httpd_unix_fd )
                {
                  if ( v10 )
                    httpd_unix_recv();
                }
                else
                {
                  v11 = _httpd_conn_find(v8);
                  if ( v11 )
                  {
                    v12 = v7->revents;
                    v13 = (v12 & 1) == 0;
                    v14 = v12 & 4;
                    if ( v13 )
                    {
                      if ( !v14 )
                        goto LABEL_48;
                      httpd_enable_write((int)v11);
                      --v1;
                    }
                    else
                    {
                      if ( !v11[52496] || v11[52497] )
                      {
                        httpd_do_recv((int)v11);
                        goto LABEL_35;
                      }
                      if ( https_do_accept_recv((int)v11) )
                      {
LABEL_48:
                        httpd_conn_close(v11);
                        --v1;
                      }
                      else
                      {
LABEL_35:
                        --v1;
                      }
                    }
                  }
                  else
                  {
                    --v1;
                    close(v7->fd);
                    v7->fd = -1;
                  }
                  if ( !v1 )
                    return 0;
                }
              }
            }
            ++v4;
            ++v7;
            if ( v4 >= curfds )
              return 0;
            continue;
          }
        }
        if ( httpd_conn_add(v6, (int)&v18, https_fd) )
          close(v6);
        v5 = https_fd;
      }
      if ( !--v1 )
        return 0;
    }
    ++v4;
    goto LABEL_22;
  }
  return 0;
}
// 667720: using guessed type int dword_667720;
// 667724: using guessed type int dword_667724;
// 66B5F0: using guessed type int gl_httpd_unix_fd;
// 67BD44: using guessed type int https_fd;
// 67D0A4: using guessed type int curfds;

