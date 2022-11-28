int __fastcall sub_452BD0(int a1)
{
  char v2[1024]; // [sp+18h] [-40Ch] BYREF
  int v3; // [sp+418h] [-Ch]

  v3 = a1;
  start_diagnosis();
  strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":0}");
  return httpd_cgi_ret(v3, v2, 30, 4);
}

