int __fastcall websocket_console_do_rcv(int a1)
{
  int v2; // $s1
  int v4; // $s1
  int v5; // $v0
  int v6; // $v0
  int v7; // $v0
  int v8; // $a1
  int v9; // $v0
  int v10; // $s3
  const char *v11; // $s4
  size_t v12; // $a2
  int v13; // $a0
  ssize_t v14; // $v0
  int v15; // $a2
  int v16; // $v0
  int v17; // $v0
  const char *v18; // $s4
  char *v19; // $v0
  char *v20; // $s3
  __int16 v21; // $v0
  int v22; // $a0
  __int16 v23; // [sp+18h] [-2000h] BYREF
  __int16 v24; // [sp+1Ah] [-1FFEh]
  __int16 v25; // [sp+1Ch] [-1FFCh]
  __int16 v26; // [sp+1Eh] [-1FFAh]

  if ( *(_BYTE *)(a1 + 41) != 9 )
    return httpd_conn_close((int *)a1);
  v4 = a1 + 196608;
  v5 = *(_DWORD *)(a1 + 205412);
  if ( v5 == *(_DWORD *)(a1 + 205416) )
  {
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v7 = https_ssl_read(a1);
      if ( v7 != -2 )
      {
        if ( v7 <= 0 )
          return httpd_conn_close((int *)a1);
        goto LABEL_10;
      }
    }
    else
    {
      v7 = recv(
             *(_DWORD *)(a1 + 205412),
             (void *)(*(_DWORD *)(a1 + 210016) + *(_DWORD *)(a1 + 210024)),
             102400 - *(_DWORD *)(a1 + 210024),
             0);
      if ( v7 > 0 )
      {
LABEL_10:
        v8 = v7 + *(_DWORD *)(v4 + 13416);
        *(_DWORD *)(v4 + 13416) = v8;
        goto LABEL_11;
      }
      if ( !v7 || *_errno_location() != 11 )
        return httpd_conn_close((int *)a1);
    }
    v8 = *(_DWORD *)(v4 + 13416);
LABEL_11:
    websocket_recv_data(
      *(_BYTE **)(a1 + 210016),
      v8,
      (_BYTE *)(*(_DWORD *)(a1 + 210020) + *(_DWORD *)(a1 + 210028)),
      102400 - *(_DWORD *)(a1 + 210028));
    v10 = v9;
    if ( v9 < 0 )
      goto LABEL_6;
    *(_DWORD *)(a1 + 210024) = 0;
    if ( v9 >= 10 )
    {
      v11 = *(const char **)(a1 + 210020);
      v2 = strncmp(v11, "resize:", 7u);
      if ( !v2 )
      {
        v18 = v11 + 7;
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v26 = 0;
        v19 = strchr(v18, 44);
        v20 = v19;
        if ( v19 )
        {
          *v19 = 0;
          v24 = J_atoi(v18);
          v21 = J_atoi(v20 + 1);
          v22 = *(_DWORD *)(a1 + 205420);
          v23 = v21;
          ioctl(v22, 0x80087467, &v23);
        }
        *(_DWORD *)(a1 + 210028) = 0;
        return v2;
      }
    }
    else
    {
      if ( !v9 )
        goto LABEL_6;
      v11 = *(const char **)(a1 + 210020);
    }
    v12 = v10 + *(_DWORD *)(a1 + 210028);
    v13 = *(_DWORD *)(a1 + 205420);
    *(_DWORD *)(a1 + 210028) = v12;
    v14 = write(v13, v11, v12);
    if ( v14 < 0 )
    {
      if ( *_errno_location() != 11 )
        return httpd_conn_close((int *)a1);
      v16 = a1 + 196608;
    }
    else
    {
      if ( v14 )
      {
        v15 = *(_DWORD *)(a1 + 210028) - v14;
        *(_DWORD *)(a1 + 210028) = v15;
        if ( v15 <= 0 )
          goto LABEL_6;
        memmove(*(void **)(a1 + 210020), (void *)(*(_DWORD *)(a1 + 210020) + v14), v15);
      }
      v16 = a1 + 196608;
    }
    if ( *(int *)(v16 + 13420) > 0 )
      httpd_conn_epoll_write_pty(a1);
    goto LABEL_6;
  }
  if ( v5 == *(_DWORD *)(a1 + 205420) )
  {
    v17 = read(*(_DWORD *)(a1 + 205412), &v23, 0x2000u);
    if ( v17 > 0 )
    {
      websocket_send_data(a1, (int)&v23, v17);
      goto LABEL_6;
    }
    if ( v17 && *_errno_location() == 11 )
      goto LABEL_6;
    return httpd_conn_close((int *)a1);
  }
LABEL_6:
  v6 = jiffies_get();
  mod_timer(a1 + 205540, v6 + 900000);
  return 0;
}
// 4C814C: variable 'v9' is possibly undefined
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

