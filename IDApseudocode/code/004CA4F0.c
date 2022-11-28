int __fastcall https_ssl_read(int a1)
{
  int v1; // $s0
  int v3; // $s1
  int result; // $v0

  v1 = a1 + 196608;
  v3 = SSL_read(*(_DWORD *)(a1 + 209984));
  switch ( SSL_get_error(*(_DWORD *)(v1 + 13376), v3) )
  {
    case 1:
    case 5:
      result = -1;
      break;
    case 2:
      result = -2;
      break;
    case 3:
      result = -(httpd_conn_epoll_write(a1) != 0);
      break;
    case 6:
      v3 = 0;
      goto LABEL_3;
    default:
LABEL_3:
      result = v3;
      break;
  }
  return result;
}
// 6A8690: using guessed type int __fastcall SSL_read(_DWORD);
// 6A8990: using guessed type int __fastcall SSL_get_error(_DWORD, _DWORD);

