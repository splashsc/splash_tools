int __fastcall sub_4CAB60(int a1)
{
  char v2[2052]; // [sp+18h] [-804h] BYREF

  *(_DWORD *)(a1 + 36) |= 0x8000u;
  return httpd_cgi_ret(a1, v2, 0, 4);
}

