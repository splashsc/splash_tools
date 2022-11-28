int __fastcall https_do_accept_recv(int a1)
{
  int v1; // $s0
  int v2; // $v0
  int v3; // $v0

  v1 = a1 + 196608;
  v2 = SSL_accept(*(_DWORD *)(a1 + 209984));
  if ( v2 <= 0 )
    return -(SSL_get_error(*(_DWORD *)(v1 + 13376), v2) != 2);
  v3 = https_accept_num + 1;
  *(_DWORD *)(v1 + 13380) = 1;
  https_accept_num = v3;
  return 0;
}
// 681500: using guessed type int https_accept_num;
// 6A8570: using guessed type int __fastcall SSL_accept(_DWORD);
// 6A8990: using guessed type int __fastcall SSL_get_error(_DWORD, _DWORD);

