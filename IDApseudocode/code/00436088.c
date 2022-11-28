int __fastcall httpd_proxy_do_rcv(int a1)
{
  int v2; // $v1
  int (__fastcall *v3)(int); // $t9
  int v5; // $s1
  int v6; // $v0
  int v7; // $v0
  int *v8; // $v1
  int v9; // $a1
  size_t v10; // $a2
  _DWORD *v11; // $v1
  ssize_t v12; // $v0
  int *v13; // $v1
  int v14; // $a1
  size_t v15; // $a2
  _DWORD *v16; // $v1
  int v17; // $v0

  if ( *(_BYTE *)(a1 + 41) != 10 )
    goto LABEL_2;
  v5 = a1 + 196608;
  v6 = *(_DWORD *)(a1 + 205412);
  if ( v6 == *(_DWORD *)(a1 + 205416) )
  {
    v13 = *(int **)(a1 + 205444);
    v14 = *v13;
    v15 = 102400 - *v13;
    if ( *v13 == 102400 )
      return 0;
    v16 = v13 + 1;
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v17 = https_ssl_read(a1);
      if ( v17 != -2 )
      {
        if ( v17 <= 0 )
          goto LABEL_2;
        goto LABEL_19;
      }
    }
    else
    {
      v17 = recv(*(_DWORD *)(a1 + 205412), (char *)v16 + v14, v15, 0);
      if ( v17 > 0 )
      {
LABEL_19:
        **(_DWORD **)(v5 + 8836) += v17;
        goto LABEL_20;
      }
      if ( !v17 || *_errno_location() != 11 )
        goto LABEL_2;
    }
LABEL_20:
    httpd_conn_epoll_write_proxy(a1);
    goto LABEL_8;
  }
  if ( v6 != *(_DWORD *)(a1 + 205424) )
  {
LABEL_8:
    v7 = jiffies_get();
    mod_timer(a1 + 205540, v7 + 900000);
    return 0;
  }
  v8 = *(int **)(a1 + 205440);
  v9 = *v8;
  v10 = 102400 - *v8;
  v11 = v8 + 1;
  if ( !v10 )
    return 0;
  v12 = recv(*(_DWORD *)(a1 + 205412), (char *)v11 + v9, v10, 0);
  if ( v12 > 0 )
  {
    **(_DWORD **)(v5 + 8832) += v12;
LABEL_13:
    httpd_conn_epoll_write(a1);
    goto LABEL_8;
  }
  if ( v12 && *_errno_location() == 11 )
    goto LABEL_13;
LABEL_2:
  v2 = *(_DWORD *)(a1 + 205412);
  if ( v2 == *(_DWORD *)(a1 + 205424) )
  {
    v3 = httpd_proxy_client_close;
    return v3(a1);
  }
  if ( v2 != *(_DWORD *)(a1 + 205416) )
  {
    v3 = (int (__fastcall *)(int))httpd_conn_close;
    return v3(a1);
  }
  return httpd_proxy_server_close(a1);
}
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

