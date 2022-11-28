int __fastcall sub_462BF4(int a1)
{
  char *v1; // $v0
  int v3; // $s4
  const char *v4; // $s3
  const char *v5; // $s4
  const char *v6; // $v0
  unsigned int v7; // $v0
  int v8; // $s0
  unsigned int v9; // $v0
  char v11[102400]; // [sp+20h] [-19018h] BYREF
  _DWORD v12[6]; // [sp+19020h] [-18h] BYREF

  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  v12[3] = 0;
  v12[4] = 0;
  v1 = httpd_get_parm(a1, "fy_type");
  if ( !v1 )
    v1 = "0";
  v3 = atoi(v1);
  v4 = (const char *)jhl_nv_get_def("ddos_fy_en");
  if ( !v4 )
    v4 = "0";
  sprintf((char *)v12, "ddos_fy_rule%d", v3);
  v5 = (const char *)jhl_nv_get_def(v12);
  if ( !v5 )
    v5 = "0|2|1000|10";
  strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
  v6 = (const char *)jhl_nv_get_def(&unk_646654);
  v7 = snprintf(&v11[29], 102371, "\"fy_en\":%s,\"fy_rule\":\"%s\",\"maclist\":\"%s\",\"all\":", v4, v5, v6);
  if ( v7 >= 0x18FE3 )
    v7 = 102370;
  v8 = v7 + 29 + ddos_fy_black_list(&v11[v7 + 29], 102400 - (v7 + 29));
  v9 = snprintf(&v11[v8], 102400 - v8, "}}");
  if ( v9 >= 102400 - v8 )
    v9 = 102399 - v8;
  return httpd_cgi_ret(a1, v11, v9 + v8, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

