int __fastcall sub_44DD30(int a1)
{
  char *v2; // $s2
  char *v3; // $s1
  char *v4; // $v0
  char *v5; // $s3
  const char *v6; // $v0
  unsigned int v7; // $s1
  int v8; // $s2
  unsigned int v9; // $v0
  const char *v11; // $v0
  char v12[1028]; // [sp+18h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "nonce");
  v3 = httpd_get_parm(a1, "sn");
  v5 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, (char *)&off_649194);
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( v3 && v2 && v5 && v4 )
  {
    v6 = (const char *)get_sn();
    if ( !strcmp(v3, v6) )
    {
      v11 = (const char *)nvram_get("ai_qrcode_nonce");
      if ( v11 && !strcmp(v11, v2) )
      {
        v7 = 995;
        v8 = 29;
      }
      else
      {
        nvram_set("ai_qrcode_nonce_state", "2");
        v7 = 968;
        strcpy(&v12[29], "\"msg\":\"session id mismatch\"");
        v8 = 56;
      }
    }
    else
    {
      nvram_set("ai_qrcode_nonce_state", "2");
      v7 = 965;
      strcpy(&v12[29], "\"msg\":\"Serial number mismatch\"");
      v8 = 59;
    }
  }
  else
  {
    nvram_set("ai_qrcode_nonce_state", "2");
    v7 = 970;
    strcpy(&v12[29], "\"msg\":\"Missing parameter\"");
    v8 = 54;
  }
  v9 = snprintf(&v12[v8], v7, "}}");
  if ( v9 >= v7 )
    v9 = 1023 - v8;
  return httpd_cgi_ret(a1, v12, v9 + v8, 4);
}
// 642164: using guessed type __int16 word_642164;
// 649194: using guessed type char *off_649194;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81D8: using guessed type int get_sn(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

