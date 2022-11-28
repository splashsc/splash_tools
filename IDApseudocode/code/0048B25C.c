int __fastcall ipsec_road_data(int a1)
{
  int v1; // $v0
  const char *v2; // $fp
  const char *v3; // $s0
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s5
  const char *v9; // $s6
  const char *v10; // $s7
  const char *v11; // $v1
  const char *v12; // $v0
  int v13; // $s1
  unsigned int v14; // $v0
  char v16[1024]; // [sp+58h] [-420h] BYREF
  char *v17; // [sp+458h] [-20h]
  char *v18; // [sp+45Ch] [-1Ch]
  const char *v19; // [sp+460h] [-18h]
  char *v20; // [sp+464h] [-14h]
  char *v21; // [sp+468h] [-10h]
  const char *v22; // [sp+46Ch] [-Ch]
  const char *v23; // [sp+470h] [-8h]

  strcpy(v16, "{\"code\":0,\"error\":\"\",\"data\":{");
  v1 = nvram_get("ipsec_road_enable");
  if ( v1 )
    v2 = (const char *)v1;
  else
    v2 = "0";
  v17 = (char *)nvram_get("ipsec_road_host_ip");
  if ( !v17 )
    v17 = "";
  v18 = (char *)nvram_get("ipsec_road_host_mask");
  if ( !v18 )
    v18 = "";
  v19 = (const char *)nvram_get("ipsec_road_ike_type");
  if ( !v19 )
    v19 = "psk";
  v20 = (char *)nvram_get("ipsec_road_psk_key");
  if ( !v20 )
    v20 = "";
  v21 = (char *)nvram_get("ipsec_road_ike_dh_group");
  if ( !v21 )
    v21 = "2";
  v22 = (const char *)nvram_get("ipsec_road_ike_encrypt");
  if ( !v22 )
    v22 = "3des";
  v3 = (const char *)nvram_get("ipsec_road_ike_auth");
  if ( !v3 )
    v3 = "md5";
  v4 = (const char *)nvram_get("ipsec_road_ike_lifetime");
  if ( !v4 )
    v4 = "3600";
  v5 = (const char *)nvram_get("ipsec_road_ike_pfs_group");
  if ( !v5 )
    v5 = "2";
  v6 = (const char *)nvram_get("ipsec_road_ipsec_encrypt");
  if ( !v6 )
    v6 = "3des";
  v7 = (const char *)nvram_get("ipsec_road_ipsec_auth");
  if ( !v7 )
    v7 = "md5";
  v8 = (const char *)nvram_get("ipsec_road_ipsec_lifetime");
  if ( !v8 )
    v8 = "3600";
  v9 = (const char *)nvram_get("ipsec_road_ip_compress");
  if ( !v9 )
    v9 = "1";
  v10 = (const char *)nvram_get("ipsec_road_ike_pfs");
  if ( !v10 )
    v10 = "1";
  v11 = (const char *)nvram_get("ipsec_road_dpd_time");
  if ( !v11 )
    v11 = "20";
  v23 = v11;
  v12 = (const char *)nvram_get("ipsec_road_dpd_latertime");
  if ( !v12 )
    v12 = "60";
  v13 = sprintf(
          &v16[29],
          "\"enable\":%s,\"host_ip\":\"%s\",\"host_mask\":\"%s\",\"ike_type\":\"%s\",\"psk_key\":\"%s\",\"ike_dh_group\":"
          "%s,\"ike_encrypt\":\"%s\",\"ike_auth\":\"%s\",\"ike_lifetime\":%s,\"ike_pfs_group\":%s,\"ipsec_encrypt\":\"%s\""
          ",\"ipsec_auth\":\"%s\",\"ipsec_lifetime\":\"%s\",\"ip_compress\":%s,\"ike_pfs\":%s,\"dpd_time\":%s,\"dpd_latertime\":%s",
          v2,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v23,
          v12)
      + 29;
  v14 = snprintf(&v16[v13], 1024 - v13, "}}");
  if ( v14 >= 1024 - v13 )
    v14 = 1023 - v13;
  return httpd_cgi_ret(a1, v16, v14 + v13, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

