int __fastcall sub_452698(int a1)
{
  char *v2; // $s0
  char *v3; // $s1
  const char *v4; // $v0
  int v5; // $s0
  unsigned int v6; // $v0
  int v7; // $s0
  unsigned int v8; // $v0
  char *v10; // $v0
  const char *v11; // $s1
  const char *v12; // $s3
  int v13; // $s4
  const char *v14; // $v0
  char v15[1024]; // [sp+20h] [-408h] BYREF
  int v16; // [sp+424h] [-4h] BYREF

  v2 = httpd_get_parm(a1, "nonce");
  v3 = httpd_get_parm(a1, "signature");
  strcpy(v15, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( !v2 || !v3 )
    goto LABEL_25;
  v4 = (const char *)nvram_get("ai_qrcode_nonce");
  if ( !v4 || strcmp(v4, v2) )
  {
    nvram_set("ai_qrcode_nonce_state", "100");
    v5 = 100;
    goto LABEL_6;
  }
  v10 = (char *)nvram_get("ai_qrcode_nonce_state");
  if ( !v10 )
    v10 = "0";
  v5 = J_atoi(v10);
  if ( (unsigned int)(v5 - 1) >= 3 )
    goto LABEL_14;
  v14 = (const char *)nvram_get("ai_qrcode_signature");
  if ( !v14 || strcmp(v14, v3) )
  {
LABEL_25:
    v5 = 0;
    goto LABEL_6;
  }
  nvram_set("ai_qrcode_signature", "");
  nvram_set("ai_qrcode_nonce", "");
LABEL_14:
  if ( v5 == 1 )
  {
    if ( gl_httpd_high_admin_en )
    {
      v11 = gl_httpd_high_adminpwd;
      v12 = gl_httpd_high_admin;
    }
    else if ( gl_httpd_admin_en )
    {
      v11 = gl_httpd_adminpwd;
      v12 = gl_httpd_admin;
    }
    else if ( gl_httpd_user_en )
    {
      v11 = gl_httpd_password;
      v12 = gl_httpd_user;
    }
    else if ( gl_httpd_guest_user_en )
    {
      v11 = gl_httpd_guest_pwd;
      v12 = gl_httpd_guest_user;
    }
    else
    {
      v11 = "";
      v12 = "";
    }
    v13 = httpd_cgi_user_check(v12, v11, &v16);
    if ( v13 <= 0 )
      jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)0x64, v12, 1);
    else
      *(_DWORD *)(a1 + 36) |= 0x1000u;
    ai_send_router_login(a1, v12, v11, v13 > 0, "scan");
  }
LABEL_6:
  v6 = snprintf(&v15[29], 995, "\"state\":%d", v5);
  v7 = v6 + 29;
  if ( v6 >= 0x3E3 )
    v7 = 1023;
  v8 = snprintf(&v15[v7], 1024 - v7, "}}");
  if ( v8 >= 1024 - v7 )
    v8 = 1023 - v7;
  return httpd_cgi_ret(a1, v15, v8 + v7, 4);
}
// 642164: using guessed type __int16 word_642164;
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

