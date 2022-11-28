int __fastcall ai_check_upgrade_data(int a1)
{
  unsigned int v2; // $v0
  int v3; // $s2
  unsigned int v4; // $s1
  unsigned int v5; // $v0
  char v7[1024]; // [sp+18h] [-804h] BYREF
  int v8[257]; // [sp+418h] [-404h] BYREF

  memset(v7, 0, sizeof(v7));
  strcpy((char *)v8, "{\"code\":0,\"error\":\"\",\"data\":");
  if ( ai_read_upgrade_state((int)v7, 1024) )
  {
    v4 = 985;
    strcpy((char *)&v8[7], "{\"state\":0}");
    v3 = 39;
  }
  else
  {
    v2 = snprintf((char *)&v8[7], 996, "%s", v7);
    if ( v2 >= 0x3E4 )
      v2 = 995;
    v3 = v2 + 28;
    v4 = 1024 - (v2 + 28);
  }
  v5 = snprintf((char *)v8 + v3, v4, "}");
  if ( v5 >= v4 )
    v5 = 1023 - v3;
  return httpd_cgi_ret(a1, (char *)v8, v5 + v3, 4);
}

