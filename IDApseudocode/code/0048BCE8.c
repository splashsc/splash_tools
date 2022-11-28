int __fastcall sub_48BCE8(int a1)
{
  int v2; // $v0
  const char *v3; // $s7
  const char *v4; // $s0
  const char *v5; // $s1
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s5
  const char *v9; // $s6
  const char *v10; // $v0
  int v11; // $s1
  unsigned int v12; // $v0
  char v14[1028]; // [sp+30h] [-404h] BYREF

  strcpy(v14, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = nvram_get("ipsec_l2tp_enable");
  if ( v2 )
    v3 = (const char *)v2;
  else
    v3 = "0";
  v4 = (const char *)nvram_get("ipsec_l2tp_max");
  if ( !v4 )
    v4 = " ";
  v5 = (const char *)nvram_get("ipsec_l2tp_psk_key");
  if ( !v5 )
    v5 = " ";
  v6 = (const char *)nvram_get("l2tpd_stip");
  if ( !v6 )
    v6 = " ";
  v7 = (const char *)nvram_get("l2tpd_endip");
  if ( !v7 )
    v7 = " ";
  v8 = (const char *)nvram_get("l2tpd_port");
  if ( !v8 )
    v8 = "1701";
  v9 = (const char *)nvram_get("l2tpd_dns1");
  if ( v9 )
  {
    v10 = (const char *)nvram_get("l2tpd_dns2");
    if ( v10 )
      goto LABEL_15;
  }
  else
  {
    v10 = (const char *)nvram_get("l2tpd_dns2");
    v9 = " ";
    if ( v10 )
      goto LABEL_15;
  }
  v10 = " ";
LABEL_15:
  v11 = sprintf(
          &v14[29],
          "\"enable\":%s,\"max\":%s,\"psk_key\":\"%s\",\"start_ip\":\"%s\",\"end_ip\":%s,\"port\":%s,\"dns1\":\"%s\",\"dns2\":\"%s\"",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10)
      + 29;
  v12 = snprintf(&v14[v11], 1024 - v11, "}}");
  if ( v12 >= 1024 - v11 )
    v12 = 1023 - v11;
  return httpd_cgi_ret(a1, v14, v12 + v11, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

