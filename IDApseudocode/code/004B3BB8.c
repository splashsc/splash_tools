int __fastcall sub_4B3BB8(int a1)
{
  char *v2; // $s4
  char *v3; // $s2
  char *v4; // $s1
  char *v5; // $s5
  char *v6; // $s6
  char *v7; // $fp
  char *v8; // $s7
  char *v9; // $s3
  const char *v10; // $v0
  const char *v11; // $s4
  unsigned int v12; // $v0
  int v13; // $s2
  const char *v14; // $v0
  const char *v15; // $v0
  int v16; // $a0
  const char **v17; // $v1
  const char *v18; // $v0
  const char *v19; // $t0
  const char *v20; // $a3
  const char *v21; // $a2
  const char *v22; // $a1
  unsigned int v23; // $a2
  const char *v25; // $v0
  const char *v26; // [sp+28h] [-428h] BYREF
  const char *v27; // [sp+2Ch] [-424h]
  const char *v28; // [sp+30h] [-420h]
  char *v29; // [sp+34h] [-41Ch]
  int v30; // [sp+38h] [-418h]
  char *v31; // [sp+428h] [-28h]
  char *v32; // [sp+42Ch] [-24h]
  char *v33; // [sp+430h] [-20h]
  char *v34; // [sp+434h] [-1Ch]
  char *v35; // [sp+438h] [-18h]
  char *v36; // [sp+43Ch] [-14h]
  char *v37; // [sp+440h] [-10h]
  char *v38; // [sp+444h] [-Ch]
  const char *v39; // [sp+448h] [-8h]

  v2 = httpd_get_parm(a1, "share_enable");
  v3 = httpd_get_parm(a1, "passwd");
  v4 = httpd_get_parm(a1, "name");
  v31 = httpd_get_parm(a1, "hpasswd");
  v32 = httpd_get_parm(a1, "hname");
  v5 = httpd_get_parm(a1, "acc_ip");
  v6 = httpd_get_parm(a1, "acc_mac");
  v33 = httpd_get_parm(a1, "acc_wan");
  v34 = httpd_get_parm(a1, "acc_auth");
  v35 = httpd_get_parm(a1, "device_name");
  v36 = httpd_get_parm(a1, "send_email_en");
  v37 = httpd_get_parm(a1, "send_email_name");
  v7 = httpd_get_parm(a1, "send_email_pwd");
  v38 = "1\"";
  v8 = httpd_get_parm(a1, "printer_enable");
  v9 = httpd_get_parm(a1, "printer_port");
  killall_tk("smbd");
  if ( *v2 == 49 )
    xstart(v38 - 8644, 0);
  if ( v3 )
  {
    if ( !v4 || !*v4 )
      v4 = "login";
    if ( v9 && (v38 = "1\"", !nvram_match_def(&unk_64DE5C, v9)) )
    {
      if ( !J_atoi(v9) )
        v9 = "9100";
      nvram_set(v38 - 8612, v9);
      if ( !v8 || nvram_match_def("usb_printer_en", v8) )
        goto LABEL_47;
    }
    else if ( !v8 || nvram_match_def("usb_printer_en", v8) )
    {
LABEL_10:
      nvram_set("usb_share_enable", v2);
      nvram_set("usb_passwd", v3);
      nvram_set("usb_username", v4);
      v38 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      if ( v32 )
        nvram_set("usb_husername", v32);
      if ( v31 )
        nvram_set("usb_hpasswd", v31);
      v28 = "smbguest";
      v31 = "smbguest";
      v26 = "smbpasswd";
      v39 = "smbpasswd";
      v27 = "-a";
      v32 = "-a";
      v29 = v3;
      v30 = 0;
      eval(&v26, 0, 0, 0);
      v26 = v39;
      v27 = v32;
      v28 = "smbadmin";
      v29 = (char *)jhl_nv_get_def("usb_hpasswd");
      v30 = 0;
      eval(&v26, 0, 0, 0);
      v11 = (const char *)jhl_nv_get_def("usb_username");
      v10 = (const char *)jhl_nv_get_def(v38 - 4920);
      v12 = snprintf((char *)&v26, 1024, "%s = %s\n%s = %s\n", v31, v11, "smbadmin", v10);
      if ( v12 >= 0x400 )
        v12 = 1023;
      f_write("/etc/smbusers", &v26, v12, 0, 420);
      if ( v5 && !nvram_match_def(&unk_64E3C8, v5) )
      {
        nvram_set(&unk_64E3C8, v5);
        v13 = 1;
      }
      else
      {
        v13 = 0;
      }
      if ( v6 && !nvram_match_def(&unk_64E3D4, v6) )
      {
        nvram_set(&unk_64E3D4, v6);
        ++v13;
      }
      if ( v33 )
        nvram_set("usb_acc_wan", v33);
      if ( v34 )
        nvram_set("usb_acc_auth", v34);
      if ( v35 )
        nvram_set(&unk_64E3E0, v35);
      if ( v36 )
        nvram_set("usb_send_email_en", v36);
      if ( v37 )
        nvram_set(&unk_64E404, v37);
      if ( v7 )
        nvram_set(&unk_64E418, v7);
      v14 = (const char *)jhl_nv_get_def("usb_passwd");
      usb_httpd_passwd_md5(gl_usb_password_md5, v14);
      v15 = (const char *)jhl_nv_get_def("usb_hpasswd");
      usb_httpd_passwd_md5(gl_usb_hpassword_md5, v15);
      if ( v13 )
        set_usb_acc_conf();
      jhl_parm_commit(v16);
      v17 = &v26;
      v18 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v19 = *(const char **)v18;
        v20 = (const char *)*((_DWORD *)v18 + 1);
        v21 = (const char *)*((_DWORD *)v18 + 2);
        v22 = (const char *)*((_DWORD *)v18 + 3);
        v18 += 16;
        *v17 = v19;
        v17[1] = v20;
        v17[2] = v21;
        v17[3] = v22;
        v17 += 4;
      }
      while ( v18 != "}" );
      v23 = 33;
      *(_WORD *)v17 = *(_WORD *)v18;
      return httpd_cgi_ret(a1, (char *)&v26, v23, 4);
    }
    nvram_set("usb_printer_en", v8);
LABEL_47:
    killall_tk("p910nd");
    if ( nvram_match_def("usb_printer_en", "1") )
    {
      jhl_nv_get_def(&unk_64DE5C);
      xstart("p910nd", "-f");
    }
    goto LABEL_10;
  }
  v25 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_64E388);
  v23 = snprintf((char *)&v26, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( v23 >= 0x400 )
    v23 = 1023;
  return httpd_cgi_ret(a1, (char *)&v26, v23, 4);
}
// 4B41BC: variable 'v16' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8204: using guessed type int __fastcall f_write(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8534: using guessed type int set_usb_acc_conf(void);
// 6A85AC: using guessed type int __fastcall xstart(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

