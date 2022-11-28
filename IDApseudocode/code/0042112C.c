int __fastcall httpd_send_data_file_ll(int a1, const char *a2, int a3, int a4, int a5)
{
  FILE *v8; // $v0
  FILE *v10; // $s1
  int result; // $v0

  v8 = fopen(a2, "rb");
  if ( v8 )
  {
    v10 = v8;
    fseek(v8, a5, 0);
    *(_DWORD *)(a1 + 205368) = 0;
    *(_DWORD *)(a1 + 205592) = v10;
    *(_DWORD *)(a1 + 209692) = 0;
    *(_BYTE *)(a1 + 42) = 2;
    *(_DWORD *)(a1 + 205376) = 1;
    *(_DWORD *)(a1 + 205384) = a3;
    *(_DWORD *)(a1 + 205388) = a4;
    result = httpd_conn_epoll_write(a1);
    if ( result )
    {
      httpd_conn_close((int *)a1);
      result = -1;
    }
  }
  else
  {
    perror(a2);
    httpd_conn_close((int *)a1);
    result = -1;
  }
  return result;
}

