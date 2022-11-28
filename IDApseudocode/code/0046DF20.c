int __fastcall sub_46DF20(int a1)
{
  char v2[516]; // [sp+18h] [-204h] BYREF

  strcpy(v2, "{\"ret\":0,\"msg\":\"ok\"}");
  return httpd_cgi_ret(a1, v2, 20, 4);
}

