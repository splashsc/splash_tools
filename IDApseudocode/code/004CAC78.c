int __fastcall sub_4CAC78(int a1)
{
  int result; // $v0
  time_t v3; // $v0
  unsigned int v4; // $v0
  char v5[1028]; // [sp+18h] [-404h] BYREF

  httpd_get_parm(a1, "token");
  httpd_get_parm(a1, (char *)&off_646724);
  httpd_get_parm(a1, "roomId");
  if ( !sq_file_get_device_id() || !nvram_get_int("iptv_en") )
    return httpd_cgi_ret(a1, v5, 59, 4);
  v3 = time(0);
  v4 = snprintf(v5, 1024, "{\"ret\":\"1\",\"msg\":\"ok\",\"channelGmt\":%lu,\"notice\":[]}", v3);
  *(_DWORD *)(a1 + 36) |= 0x8000u;
  if ( v4 >= 0x400 )
    result = httpd_cgi_ret(a1, v5, 1023, 4);
  else
    result = httpd_cgi_ret(a1, v5, v4, 4);
  return result;
}
// 646724: using guessed type void *off_646724;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A83B8: using guessed type int sq_file_get_device_id(void);

