int __fastcall https_ssl_write(int a1)
{
  int v2; // $s0
  int result; // $v0

  v2 = SSL_write(*(_DWORD *)(a1 + 209984));
  if ( v2 == -1 && *_errno_location() == 11 )
    return 0;
  switch ( SSL_get_error(*(_DWORD *)(a1 + 209984), v2) )
  {
    case 1:
    case 4:
    case 5:
      result = -1;
      break;
    case 2:
    case 6:
      return 0;
    case 3:
      result = -(httpd_conn_epoll_write(a1) != 0);
      break;
    default:
      result = v2;
      break;
  }
  return result;
}
// 6A8908: using guessed type int __fastcall SSL_write(_DWORD);
// 6A8990: using guessed type int __fastcall SSL_get_error(_DWORD, _DWORD);

