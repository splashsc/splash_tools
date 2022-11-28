int __fastcall set_jhttpd_info(int a1, int a2, _WORD *a3, int a4, int a5, _WORD *a6, _WORD *a7)
{
  char *v7; // $s4
  const char *v8; // $s6
  const char *v9; // $s2
  const char *v10; // $fp
  const char *v11; // $s7
  const char *v12; // $s1
  char *v13; // $s5
  const char *v14; // $s0
  const char *v15; // $v0
  const char *v16; // $v0
  _BYTE *v17; // $v0
  int v18; // $s3
  const char *v19; // $s6
  int v20; // $v0
  int v21; // $a1
  int v22; // $s3
  int v23; // $s4
  const char *v24; // $s2
  int v25; // $v0
  int v26; // $a1
  int v27; // $s4
  char v29[256]; // [sp+18h] [-100h] BYREF

  memset(v29, 0, sizeof(v29));
  v7 = (char *)nvram_get("http_gname_en");
  v8 = (const char *)nvram_get("http_gname");
  v9 = (const char *)nvram_get("http_gpwd");
  v10 = (const char *)nvram_get("http_lanport");
  v11 = (const char *)nvram_get("https_lanport");
  v12 = (const char *)nvram_get("http_username");
  v13 = (char *)nvram_get("http_username_en");
  v14 = (const char *)nvram_get("http_passwd");
  if ( !v12 || !*v12 )
    v12 = "root";
  if ( !v13 || !*v13 )
    v13 = "1";
  if ( !v7 || !*v7 )
    v7 = "0";
  if ( !v8 || !*v8 )
    v8 = "guest";
  if ( !v9 || !*v9 )
    v9 = "guest";
  if ( !v10 || !*v10 )
    v10 = "80";
  if ( !v11 || !*v11 )
    v11 = "443";
  if ( !v14 || !*v14 )
    v14 = "admin";
  v15 = (const char *)jhl_nv_get_def("usb_username");
  sprintf(v29, "echo \"%s = %s\" > /etc/smbusers", "smbguest", v15);
  system(v29);
  v16 = (const char *)jhl_nv_get_def("usb_husername");
  sprintf(v29, "echo \"%s = %s\" >> /etc/smbusers", "smbadmin", v16);
  system(v29);
  strlcpy(a4, v12, 32);
  strlcpy(a5, v14, 32);
  strlcpy(a1, v8, 32);
  strlcpy(a2, v9, 32);
  *a3 = J_atoi(v10);
  *a7 = J_atoi(v11);
  v17 = (_BYTE *)nvram_get("tggl_port");
  if ( v17 && *v17 )
    *a6 = J_atoi(v17);
  else
    *a6 = *a3;
  v18 = jhl_nv_get_def("http_hadmin");
  v19 = (const char *)jhl_nv_get_def("http_hadminpwd");
  v20 = jhl_nv_get_def("http_hadmin_en");
  v21 = v18;
  v22 = v20;
  strlcpy(gl_httpd_high_admin, v21, 32);
  strlcpy(gl_httpd_high_adminpwd, v19, 32);
  gl_httpd_high_admin_en = J_atoi(v22);
  gl_httpd_admin_en = J_atoi(v13);
  gl_httpd_user_en = J_atoi(v7);
  memset(gl_httpd_adminpwd_md5, 0, sizeof(gl_httpd_adminpwd_md5));
  memset(gl_httpd_password_md5, 0, sizeof(gl_httpd_password_md5));
  memset(gl_httpd_high_adminpwd_md5, 0, sizeof(gl_httpd_high_adminpwd_md5));
  httpd_passwd_md5(gl_httpd_adminpwd_md5, v14);
  httpd_passwd_md5(gl_httpd_password_md5, v9);
  httpd_passwd_md5(gl_httpd_high_adminpwd_md5, v19);
  v23 = jhl_nv_get_def("http_guest_user");
  v24 = (const char *)jhl_nv_get_def("http_guest_pwd");
  v25 = jhl_nv_get_def("http_guest_en");
  v26 = v23;
  v27 = v25;
  strlcpy(gl_httpd_guest_user, v26, 32);
  strlcpy(gl_httpd_guest_pwd, v24, 32);
  gl_httpd_guest_user_en = J_atoi(v27);
  memset(gl_httpd_guest_pwd_md5, 0, sizeof(gl_httpd_guest_pwd_md5));
  httpd_passwd_md5(gl_httpd_guest_pwd_md5, v24);
  if ( gl_httpd_high_admin_en )
    nvram_set("httpd_pwd_md5", gl_httpd_high_adminpwd_md5);
  else
    nvram_set("httpd_pwd_md5", gl_httpd_adminpwd_md5);
  pppoe_bridge_user_md5(gl_httpd_pppoe_br_md5, v12, v14);
  return 0;
}
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

