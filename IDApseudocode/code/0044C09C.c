int __fastcall sub_44C09C(int a1)
{
  char v3[512]; // [sp+18h] [-200h] BYREF

  jhl_gl_reboot_timer(2000);
  strcpy(v3, "{\"code\":\"0\",\"msg\":\"ok\"}");
  return httpd_cgi_ret(a1, v3, 23, 4);
}

