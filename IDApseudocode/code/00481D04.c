int __fastcall sub_481D04(int a1)
{
  int v2; // $v0
  const char *v3; // $s7
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s4
  _BOOL4 v7; // $s5
  const char *v8; // $s6
  const char *v9; // $fp
  const char *v10; // $v0
  int v11; // $s2
  unsigned int v12; // $v0
  char v14[1024]; // [sp+38h] [-608h] BYREF
  char v15[512]; // [sp+438h] [-208h] BYREF
  const char *v16; // [sp+638h] [-8h]

  memset(v14, 0, sizeof(v14));
  v2 = nvram_get("tzk_time");
  if ( v2 )
    v3 = (const char *)v2;
  else
    v3 = "";
  v4 = (const char *)nvram_get("tzk_name");
  if ( !v4 )
    v4 = "22.10.17";
  v5 = (const char *)nvram_get(&unk_649DB8);
  if ( !v5 )
    v5 = "1";
  v6 = (const char *)jhl_nv_get_def("filter_auto_upgrade_time2");
  system("lsmod > /tmp/feature.txt");
  v7 = 0;
  if ( f_read("/tmp/feature.txt", v14, 1023) >= 7 )
    v7 = strstr(v14, "wys_pg2") != 0;
  strcpy(v15, "{\"code\":0,\"error\":\"\",\"data\":{");
  v8 = (const char *)nvram_get("tzk_state");
  if ( !v8 )
    v8 = "";
  v9 = (const char *)nvram_get(&unk_649E44);
  if ( !v9 )
    v9 = "";
  v16 = (const char *)wys_svn_info;
  v10 = (const char *)jhl_nv_get_def("vs_type");
  v11 = sprintf(
          &v15[29],
          "\"tzktime\":\"%s\",\"tzkname\":\"%s\",\"enable\":\"%s\",\"time\":\"%s\",\"status\":\"%s\",\"tzk_upgrade_info\""
          ":\"%s\",\"feature_ko\":%d,\"svn\":%s,\"platform\":\"%s\",\"vs_type\":%s",
          v3,
          v4,
          v5,
          v6,
          v8,
          v9,
          v7,
          v16,
          "RT-7621-44-DNS-MR",
          v10)
      + 29;
  v12 = snprintf(&v15[v11], 512 - v11, "}}");
  if ( v12 >= 512 - v11 )
    v12 = 511 - v11;
  return httpd_cgi_ret(a1, v15, v12 + v11, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);

