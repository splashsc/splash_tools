int __fastcall httpd_send_data_file(int a1, const char *a2, int a3, int a4)
{
  FILE *v6; // $v0
  FILE *v8; // $s1
  int result; // $v0

  v6 = fopen(a2, "rb");
  if ( !v6 )
    goto LABEL_3;
  v8 = v6;
  fseek(v6, a4, 0);
  *(_DWORD *)(a1 + 205368) = 0;
  *(_DWORD *)(a1 + 205592) = v8;
  *(_DWORD *)(a1 + 209692) = 0;
  *(_BYTE *)(a1 + 42) = 2;
  *(_DWORD *)(a1 + 205376) = 0;
  *(_DWORD *)(a1 + 205380) = a3;
  result = httpd_conn_epoll_write(a1);
  if ( result )
  {
LABEL_3:
    httpd_conn_close((int *)a1);
    result = -1;
  }
  return result;
}

