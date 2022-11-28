int __fastcall sub_44BE00(int a1)
{
  int v1; // $a2
  char v3[260]; // [sp+18h] [-104h] BYREF

  if ( *(_BYTE *)(a1 + 210100) == 2 )
  {
    strcpy(v3, "{\"list\":[]}");
    v1 = 11;
  }
  else
  {
    strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":{\"list\":[]}}");
    v1 = 40;
  }
  return httpd_cgi_ret(a1, v3, v1, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;

