int __fastcall sub_4821E4(int a1)
{
  int v2; // $v0
  const char *v3; // $s1
  const char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s1
  unsigned int v7; // $v0
  char v9[2052]; // [sp+20h] [-804h] BYREF

  memset(v9, 0, 0x800u);
  strcpy(v9, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = nvram_get("auto_upgrade_en");
  if ( v2 )
    v3 = (const char *)v2;
  else
    v3 = "0";
  v4 = (const char *)nvram_get("upgrade_auto_time");
  if ( v4 )
  {
    v5 = (const char *)nvram_get("upgrade_auto_info");
    if ( v5 )
      goto LABEL_5;
  }
  else
  {
    v5 = (const char *)nvram_get("upgrade_auto_info");
    v4 = "";
    if ( v5 )
      goto LABEL_5;
  }
  v5 = "";
LABEL_5:
  v6 = sprintf(
         &v9[29],
         "\"upgrade_auto_en\":\"%s\",\"upgrade_auto_time\":\"%s\",\"upgrade_auto_info\":\"%s\"",
         v3,
         v4,
         v5)
     + 29;
  v7 = snprintf(&v9[v6], 2048 - v6, "}}");
  if ( v7 >= 2048 - v6 )
    v7 = 2047 - v6;
  return httpd_cgi_ret(a1, v9, v7 + v6, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

