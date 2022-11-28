int __fastcall sub_47FDEC(int a1)
{
  time_t v2; // $v0
  unsigned int v3; // $s3
  const char *v4; // $v0
  int v5; // $v0
  unsigned int v6; // $a0
  int v7; // $s3
  int v8; // $s0
  unsigned __int8 v9; // $s1
  const char *v10; // $s7
  const char *v11; // $fp
  const char *v12; // $v0
  unsigned int v13; // $v0
  int v14; // $s0
  unsigned int v15; // $v0
  const char *v17; // $v0
  char v18[10240]; // [sp+78h] [-2C38h] BYREF
  char v19[256]; // [sp+2878h] [-438h] BYREF
  char v20[256]; // [sp+2978h] [-338h] BYREF
  struct stat v21; // [sp+2A78h] [-238h] BYREF
  char v22[128]; // [sp+2B18h] [-198h] BYREF
  char v23[128]; // [sp+2B98h] [-118h] BYREF
  int v24[12]; // [sp+2C18h] [-98h] BYREF
  int v25[8]; // [sp+2C48h] [-68h] BYREF
  int v26[2]; // [sp+2C68h] [-48h] BYREF
  const char *v27; // [sp+2C70h] [-40h]
  const char *v28; // [sp+2C74h] [-3Ch]
  const char *v29; // [sp+2C78h] [-38h]
  const char *v30; // [sp+2C7Ch] [-34h]
  const char *v31; // [sp+2C80h] [-30h]
  const char *v32; // [sp+2C84h] [-2Ch]
  const char *v33; // [sp+2C88h] [-28h]
  const char *v34; // [sp+2C8Ch] [-24h]
  const char *v35; // [sp+2C90h] [-20h]
  const char *v36; // [sp+2C94h] [-1Ch]
  const char *v37; // [sp+2C98h] [-18h]
  const char *v38; // [sp+2C9Ch] [-14h]
  const char *v39; // [sp+2CA0h] [-10h]
  const char *v40; // [sp+2CA4h] [-Ch]
  const char *v41; // [sp+2CA8h] [-8h]
  const char *v42; // [sp+2CACh] [-4h]

  memset(v20, 0, sizeof(v20));
  memset(v18, 0, sizeof(v18));
  memset(v23, 0, sizeof(v23));
  memset(v22, 0, sizeof(v22));
  v2 = time(0);
  v26[0] = 0;
  v26[1] = 0;
  v25[0] = 0;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v25[4] = 0;
  v25[5] = 0;
  v25[6] = 0;
  v25[7] = 0;
  v24[0] = 0;
  v24[1] = 0;
  v24[2] = 0;
  v24[3] = 0;
  v24[4] = 0;
  v24[5] = 0;
  v24[6] = 0;
  v24[7] = 0;
  v24[8] = 0;
  v24[9] = 0;
  v24[10] = 0;
  v24[11] = 0;
  v3 = v2;
  user_name_pwd_get((int *)(a1 + 205460), v23, v22);
  MacToStr(v25, v26);
  IpaddrToStr(v24, a1 + 205460);
  if ( stat("/tmp/auth_pic", &v21) && check_usb_state() )
  {
    memset(v19, 0, sizeof(v19));
    v17 = (const char *)nvram_get("auth_pic_ext");
    if ( !v17 )
      v17 = ".jpg";
    snprintf(v19, 256, "/tmp/mnt/sda1/auth_pic/auth%s", v17);
    if ( !stat(v19, &v21) )
      system("cp -rf /tmp/mnt/sda1/auth_pic /tmp/auth_pic");
  }
  v4 = (const char *)nvram_get("auth_pic_ext");
  if ( !v4 )
    v4 = ".jpg";
  snprintf(v20, 256, "/tmp/auth_pic/auth%s", v4);
  v5 = stat(v20, &v21);
  v6 = v3;
  v7 = v5;
  srandom(v6);
  strcpy(v18, "{\"code\":0,\"error\":\"\",\"data\":{");
  v42 = (const char *)jhl_nv_get_def("user_sms_time");
  v8 = (unsigned __int8)random();
  v9 = random();
  v27 = (const char *)jhl_nv_get_def("user_sms_card_type");
  v28 = (const char *)jhl_nv_get_def("user_sms_card_atype");
  v10 = (const char *)jhl_nv_get_def("user_sms_card_dtype");
  v11 = (const char *)jhl_nv_get_def("user_sms_card_utype");
  v41 = (const char *)jhl_nv_get_def("user_sms_card_gotype");
  v40 = (const char *)jhl_nv_get_def("user_sms_card_gvtype");
  v39 = (const char *)jhl_nv_get_def("user_sms_card_lname");
  v29 = (const char *)jhl_nv_get_def("user_sms_card_dname");
  v38 = (const char *)jhl_nv_get_def("user_sms_card_uname");
  v37 = (const char *)jhl_nv_get_def("user_sms_card_gname");
  v36 = (const char *)jhl_nv_get_def("user_sms_card_acname");
  v35 = (const char *)jhl_nv_get_def("user_sms_card_dcname");
  v34 = (const char *)jhl_nv_get_def("user_sms_card_ucname");
  v33 = (const char *)jhl_nv_get_def("user_sms_card_gocname");
  v32 = (const char *)jhl_nv_get_def("user_sms_card_gvcname");
  v31 = (const char *)jhl_nv_get_def("user_sms_card_gctype");
  v30 = (const char *)jhl_nv_get_def("user_sms_card_goname");
  v12 = (const char *)jhl_nv_get_def("user_sms_card_gvname");
  v13 = snprintf(
          &v18[29],
          10211,
          "\"time\":\"%s\",\"pic_en\":\"%d\",\"card_pos\":\"%c%c\",\"card_type\":\"%s\",\"card_atype\":\"%s\",\"card_dtyp"
          "e\":\"%s\",\"card_utype\":\"%s\",\"card_gotype\":\"%s\",\"card_gvtype\":\"%s\",\"card_lname\":\"%s\",\"card_dn"
          "ame\":\"%s\",\"card_uname\":\"%s\",\"card_gname\":\"%s\",\"card_acname\":\"%s\",\"card_dcname\":\"%s\",\"card_"
          "ucname\":\"%s\",\"card_gocname\":\"%s\",\"card_gvcname\":\"%s\",\"card_gctype\":\"%s\",\"card_goname\":\"%s\","
          "\"card_gvname\":\"%s\",\"name\":\"%s\",\"pwd\":\"%s\"",
          v42,
          v7 == 0,
          v8 % 10 + 65,
          v9 % 9 + 49,
          v27,
          v28,
          v10,
          v11,
          v41,
          v40,
          v39,
          v29,
          v38,
          v37,
          v36,
          v35,
          v34,
          v33,
          v32,
          v31,
          v30,
          v12,
          v23,
          v22);
  v14 = v13 + 29;
  if ( v13 >= 0x27E3 )
    v14 = 10239;
  v15 = snprintf(&v18[v14], 10240 - v14, "}}");
  if ( v15 >= 10240 - v14 )
    v15 = 10239 - v14;
  return httpd_cgi_ret(a1, v18, v15 + v14, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

