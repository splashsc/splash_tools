int __fastcall httpd_send_data_alloc(int a1, char *a2, signed int a3)
{
  int v6; // $s1
  int result; // $v0
  int v8; // $s2
  void *v9; // $v0
  int *v10; // $v0
  char *v11; // $v0

  if ( *(_DWORD *)(a1 + 209984) )
    v6 = https_ssl_write(a1);
  else
    v6 = send(*(_DWORD *)(a1 + 205416), a2, a3, 0);
  if ( v6 < 0 )
  {
    if ( debug_level > 0 )
    {
      v10 = _errno_location();
      v11 = strerror(*v10);
      printf("%s:%d httpd_send_data_alloc failed: %s\n", "httpd_send_data_alloc", 936, v11);
    }
    goto LABEL_9;
  }
  if ( v6 >= a3 )
  {
    *(_DWORD *)(a1 + 205380) = 0;
    return 0;
  }
  v8 = a3 - v6;
  _mem_malloc(v8, "httpd_send_data_alloc", 943);
  *(_DWORD *)(a1 + 205372) = v9;
  if ( !v9
    || (memcpy(v9, &a2[v6], v8),
        *(_DWORD *)(a1 + 205368) = *(_DWORD *)(a1 + 205372),
        *(_BYTE *)(a1 + 42) = 1,
        *(_DWORD *)(a1 + 205380) = v8,
        (result = httpd_conn_epoll_write(a1)) != 0) )
  {
LABEL_9:
    httpd_conn_close((int *)a1);
    result = -1;
  }
  return result;
}
// 420BAC: variable 'v9' is possibly undefined
// 67D0BC: using guessed type int debug_level;

