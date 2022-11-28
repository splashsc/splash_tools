int __fastcall sub_44CABC(int a1)
{
  int v2; // $v0
  const char *v3; // $s0
  const char *v4; // $s5
  const char *v5; // $s1
  const char *v6; // $s2
  const char *v7; // $s3
  const char *v8; // $s4
  const char *v9; // $v0
  int v10; // $v0
  char *v11; // $v1
  char v13[1024]; // [sp+30h] [-400h] BYREF

  v2 = nvram_get("speed_test_iface");
  if ( v2 )
    v3 = (const char *)v2;
  else
    v3 = "";
  v4 = (const char *)nvram_get("speed_test_ai_proxy_up");
  if ( !v4 )
    v4 = "";
  v5 = (const char *)nvram_get("speed_test_ai_proxy_down");
  if ( !v5 )
    v5 = "";
  v6 = (const char *)nvram_get("speed_test_ai_proxy_state");
  if ( !v6 )
    v6 = "";
  v7 = (const char *)nvram_get("speed_test_result");
  if ( !v7 )
    v7 = "";
  v8 = (const char *)nvram_get("speed_test_upload");
  if ( !v8 )
  {
    v9 = (const char *)nvram_get("speed_test_download");
    v8 = "";
    if ( v9 )
      goto LABEL_13;
LABEL_16:
    v9 = "";
    goto LABEL_13;
  }
  v9 = (const char *)nvram_get("speed_test_download");
  if ( !v9 )
    goto LABEL_16;
LABEL_13:
  v10 = sprintf(
          v13,
          "{\"iface\":\"%s\",\"speed_up\":\"%s\",\"speed_down\":\"%s\",\"speed_state\":\"%s\",\"msg\":\"%s\"\"speed_test_"
          "average_up\":\"%s\",\"speed_test_average_up\":\"%s\"",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9);
  v11 = &v13[v10];
  *v11 = 125;
  v11[1] = 0;
  return httpd_cgi_ret(a1, v13, v10 + 1, 4);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

