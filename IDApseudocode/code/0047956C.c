int __fastcall _rzgl_ip_asp(int a1, int a2)
{
  uint32_t v2; // $v0
  uint32_t v4; // $v0
  int result; // $v0
  char v6[36]; // [sp+18h] [-24h] BYREF

  v2 = J_atoi(a1);
  v4 = htonl(v2);
  IpToStr(v6, v4);
  result = ApiFindWhiteIp(v6);
  if ( result )
  {
    result = 0;
    if ( !a2 )
    {
      ApiAddWhiteIp(v6);
      result = 1;
    }
  }
  else if ( a2 )
  {
    ApiDelWhiteIp(v6);
    result = 1;
  }
  return result;
}
// 6A82F8: using guessed type int __fastcall ApiDelWhiteIp(_DWORD);
// 6A8310: using guessed type int __fastcall ApiAddWhiteIp(_DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A87D8: using guessed type int __fastcall ApiFindWhiteIp(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

