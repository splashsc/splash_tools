int __fastcall sub_4823A4(int a1)
{
  const char *v2; // $s6
  const char *v3; // $s7
  const char *v4; // $fp
  int v5; // $v0
  const char *v6; // $s0
  const char *v7; // $s1
  const char *v8; // $s4
  const char *v9; // $s5
  const char *v10; // $v0
  unsigned int v11; // $v0
  int v12; // $s0
  unsigned int v13; // $v0
  char v15[1024]; // [sp+40h] [-400h] BYREF

  memset(v15, 0, sizeof(v15));
  strcpy(v15, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)tomato_buildtime;
  v3 = (const char *)custom_tb_version();
  v4 = (const char *)wayos_version;
  v5 = nvram_get("time_upgrade_en");
  if ( v5 )
    v6 = (const char *)v5;
  else
    v6 = "";
  v7 = (const char *)nvram_get("time_upgrade_bb");
  if ( !v7 )
    v7 = "";
  v8 = (const char *)nvram_get("time_upgrade_path");
  if ( !v8 )
    v8 = "";
  v9 = (const char *)nvram_get("time_upgrade_time");
  if ( !v9 )
    v9 = "";
  v10 = (const char *)custom_device_name();
  v11 = snprintf(
          &v15[29],
          995,
          "\"vtm\":\"%s\",\"version\":\"%s%s  R(%s)\",\"time_upgrade_en\":\"%s\",\"time_upgrade_bb\":\"%s\",\"time_upgrad"
          "e_path\":\"%s\",\"time\":\"%s\",\"model\":\"%s\",\"svn\":\"%s\"",
          v2,
          v3,
          v4,
          wys_svn_info,
          v6,
          v7,
          v8,
          v9,
          v10,
          wys_svn_info);
  v12 = v11 + 29;
  if ( v11 >= 0x3E3 )
    v12 = 1023;
  v13 = snprintf(&v15[v12], 1024 - v12, "}}");
  if ( v13 >= 1024 - v12 )
    v13 = 1023 - v12;
  return httpd_cgi_ret(a1, v15, v13 + v12, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A8788: using guessed type int custom_tb_version(void);

