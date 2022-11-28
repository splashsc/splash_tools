int __fastcall sub_44D5A8(int a1)
{
  int v2; // $v0
  char v4[4100]; // [sp+18h] [-1004h] BYREF

  v2 = miitool_data_buf(v4, 4096);
  return httpd_cgi_ret(a1, v4, v2, 4);
}
// 6A82D0: using guessed type int __fastcall miitool_data_buf(_DWORD, _DWORD);

