int __fastcall sub_44F02C(_DWORD *a1)
{
  char *v2; // $s0
  uint32_t v3; // $a0
  int v4; // $s2
  int result; // $v0
  char v6[256]; // [sp+18h] [-100h] BYREF

  v2 = httpd_get_parm((int)a1, "type");
  if ( ai_is_running(0) )
  {
    if ( v2 && (v3 = 10022, *v2 == 49) )
    {
      v4 = 10022;
    }
    else
    {
      v3 = 10021;
      v4 = 10021;
    }
    ai_unix_cgi_send(v3, a1[51354], 0, 0);
    a1[52524] = v4;
    a1[51393] = 0;
    ai_cgi_common_timeout(a1);
    result = 0;
  }
  else
  {
    strcpy(v6, "{\"code\":0,\"error\":\"\",\"data\":[]}");
    result = httpd_cgi_ret((int)a1, v6, 31, 4);
  }
  return result;
}

