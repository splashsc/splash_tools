int __fastcall httpd_proxy_is_self(int a1)
{
  int v1; // $v0
  bool v2; // dc
  int result; // $v0
  int v4; // $s0
  int v5; // $s1
  int v6; // $v0
  int v7; // $v0
  char v8[36]; // [sp+18h] [-24h] BYREF

  v1 = *(unsigned __int16 *)(a1 + 205448);
  if ( (unsigned __int16)gl_httpd_port == v1 || (v2 = (unsigned __int16)gl_httpd_https_port == v1, result = 0, v2) )
  {
    v4 = a1 + 196608;
    v5 = *(_DWORD *)(a1 + 205452);
    if ( v5 == htonl(0x7F000001u) || (v6 = IpToStr(v8, *(_DWORD *)(v4 + 8844)), check_ip_is_lanip(v6)) )
    {
      result = 1;
    }
    else
    {
      v7 = IpToStr(v8, *(_DWORD *)(v4 + 8844));
      result = check_ip_is_wanip(v7);
      if ( result )
        result = 1;
    }
  }
  return result;
}
// 666174: using guessed type __int16 gl_httpd_https_port;
// 666178: using guessed type __int16 gl_httpd_port;
// 6A8188: using guessed type int __fastcall check_ip_is_wanip(_DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A88D4: using guessed type int __fastcall check_ip_is_lanip(_DWORD);

