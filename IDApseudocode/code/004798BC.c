int __fastcall _rzgl_mac_asp(int a1, int a2)
{
  int result; // $v0

  result = ApiFindWhiteMac();
  if ( result )
  {
    result = 0;
    if ( !a2 )
    {
      ApiAddWhiteMac(a1);
      result = 1;
    }
  }
  else if ( a2 )
  {
    ApiDelWhiteMac(a1);
    result = 1;
  }
  return result;
}
// 6A840C: using guessed type int __fastcall ApiAddWhiteMac(_DWORD);
// 6A84E8: using guessed type int ApiFindWhiteMac(void);
// 6A8668: using guessed type int __fastcall ApiDelWhiteMac(_DWORD);

