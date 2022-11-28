int __fastcall httpd_send_data_const(int a1, char *a2, signed int a3)
{
  int v6; // $v0
  int result; // $v0
  int *v8; // $v0
  char *v9; // $v0

  if ( *(_DWORD *)(a1 + 209984) )
    v6 = https_ssl_write(a1);
  else
    v6 = send(*(_DWORD *)(a1 + 205416), a2, a3, 0);
  if ( v6 < 0 )
  {
    if ( debug_level > 0 )
    {
      v8 = _errno_location();
      v9 = strerror(*v8);
      printf("%s:%d httpd_send_data_alloc failed: %s\n", "httpd_send_data_const", 1022, v9);
    }
    goto LABEL_8;
  }
  if ( v6 >= a3 )
  {
    *(_DWORD *)(a1 + 205380) = 0;
    return 0;
  }
  *(_DWORD *)(a1 + 205368) = &a2[v6];
  *(_DWORD *)(a1 + 205372) = a2;
  *(_BYTE *)(a1 + 42) = 0;
  *(_DWORD *)(a1 + 205380) = a3 - v6;
  result = httpd_conn_epoll_write(a1);
  if ( result )
  {
LABEL_8:
    httpd_conn_close((int *)a1);
    result = -1;
  }
  return result;
}
// 67D0BC: using guessed type int debug_level;

