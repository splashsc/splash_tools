int __fastcall sub_4B5FD0(int a1)
{
  const char *v2; // $v0
  const char *v3; // $s0
  const char *v4; // $v0
  unsigned int v5; // $v0
  int v6; // $s0
  unsigned int v7; // $v0
  char v9[1024]; // [sp+28h] [-424h] BYREF
  int v10; // [sp+428h] [-24h] BYREF
  int v11; // [sp+42Ch] [-20h]
  int v12[7]; // [sp+430h] [-1Ch] BYREF

  memset(v9, 0, sizeof(v9));
  v10 = 0;
  v11 = 0;
  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  v12[3] = 0;
  v12[4] = 0;
  v12[5] = 0;
  v2 = (const char *)nvram_get("sj_palce_code_backup");
  if ( !v2 )
    v2 = "";
  snprintf((char *)&v10, 32, "%s", v2);
  strcpy(v9, "{\"code\":0,\"error\":\"\",\"data\":{");
  v3 = (const char *)nvram_get("sj_palce_num_backup");
  if ( v3 )
  {
    v4 = (const char *)nvram_get("sj_palce_num_dst_backup");
    if ( v4 )
      goto LABEL_5;
  }
  else
  {
    v4 = (const char *)nvram_get("sj_palce_num_dst_backup");
    v3 = "";
    if ( v4 )
      goto LABEL_5;
  }
  v4 = "";
LABEL_5:
  v5 = snprintf(
         &v9[29],
         995,
         "\"place_num\":\"%s\",\"place_num_dst\":\"%s\",\"place_type\":\"%c\",\"nowork_type\":\"%c\",\"police_num\":\"%s\"",
         v3,
         v4,
         SBYTE2(v11),
         SHIBYTE(v11),
         (const char *)v12);
  v6 = v5 + 29;
  if ( v5 >= 0x3E3 )
    v6 = 1023;
  v7 = snprintf(&v9[v6], 1024 - v6, "}}");
  if ( v7 >= 1024 - v6 )
    v7 = 1023 - v6;
  return httpd_cgi_ret(a1, v9, v7 + v6, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

