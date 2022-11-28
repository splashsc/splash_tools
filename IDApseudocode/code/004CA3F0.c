int __fastcall sub_4CA3F0(int a1)
{
  int v1; // $s0
  int v2; // $s1
  int v3; // $v0
  const char *v4; // $s2
  int v5; // $a0
  const char *v6; // $v0
  const char *v7; // $s1
  int v8; // $v0
  int v9; // $v0

  v1 = a1 + 196608;
  v2 = SSL_get_current_cipher(*(_DWORD *)(a1 + 209984));
  v4 = (const char *)SSL_get_version(*(_DWORD *)(v1 + 13376));
  v3 = SSL_CIPHER_get_version(v2);
  v5 = v2;
  v7 = (const char *)v3;
  v6 = (const char *)SSL_CIPHER_get_name(v5);
  printf("\n%s, cipher %s %s ", v4, v7, v6);
  v8 = SSL_get_ciphers(*(_DWORD *)(v1 + 13376));
  v9 = sk_num(v8);
  return printf("CIPHER_num:%d\n", v9);
}
// 6A8214: using guessed type int __fastcall SSL_CIPHER_get_name(_DWORD);
// 6A8240: using guessed type int __fastcall SSL_CIPHER_get_version(_DWORD);
// 6A8374: using guessed type int __fastcall sk_num(_DWORD);
// 6A8448: using guessed type int __fastcall SSL_get_ciphers(_DWORD);
// 6A8678: using guessed type int __fastcall SSL_get_current_cipher(_DWORD);
// 6A8734: using guessed type int __fastcall SSL_get_version(_DWORD);

