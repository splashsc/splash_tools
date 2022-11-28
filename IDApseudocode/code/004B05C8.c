int __fastcall sub_4B05C8(int a1)
{
  char *v2; // $fp
  char *v3; // $s7
  char *v4; // $s6
  char *v5; // $s5
  char *v6; // $s4
  char *v7; // $s2
  int v8; // $s1
  int v9; // $a0
  char *v10; // $a1
  const char *v11; // $v0
  int v12; // $v0
  int *v13; // $v1
  const char *v14; // $v0
  int v15; // $t0
  int v16; // $a3
  int v17; // $a2
  int v18; // $a1
  int v20[64]; // [sp+18h] [-138h] BYREF
  char *v21; // [sp+118h] [-38h]
  char *v22; // [sp+11Ch] [-34h]
  char *v23; // [sp+120h] [-30h]
  char *v24; // [sp+124h] [-2Ch]
  char *v25; // [sp+128h] [-28h]
  char *v26; // [sp+12Ch] [-24h]
  char *v27; // [sp+130h] [-20h]
  char *v28; // [sp+134h] [-1Ch]
  char *v29; // [sp+138h] [-18h]
  char *v30; // [sp+13Ch] [-14h]
  char *v31; // [sp+140h] [-10h]
  char *v32; // [sp+144h] [-Ch]
  char *v33; // [sp+148h] [-8h]

  v25 = "1\"";
  v26 = "1\"";
  v27 = "1\"";
  v2 = httpd_get_parm(a1, "wan_3g_isp");
  v28 = "1\"";
  v3 = httpd_get_parm(a1, "wan_3g_apn");
  v29 = "1\"";
  v4 = httpd_get_parm(a1, "wan_3g_dial");
  v30 = "1\"";
  v5 = httpd_get_parm(a1, "wan_3g_pin");
  v31 = "1\"";
  v6 = httpd_get_parm(a1, "wan_3g_user");
  v32 = "1\"";
  v21 = httpd_get_parm(a1, "wan_3g_pass");
  v33 = "1\"";
  v7 = httpd_get_parm(a1, "wan_3g_connect_mode");
  v22 = httpd_get_parm(a1, "g3_warn_bytes");
  v23 = httpd_get_parm(a1, "g3_warn_time");
  v8 = jhl_get_3g_iface();
  v24 = httpd_get_parm(a1, "user_mode");
  v10 = httpd_get_parm(a1, "wan_3g_enable");
  if ( v10 )
    nvram_set("wan_3g_enable", v10);
  if ( v2 )
    nvram_set(v25 - 9184, v2);
  if ( v3 )
    nvram_set(v26 - 9172, v3);
  if ( v4 )
    nvram_set(v27 - 9160, v4);
  if ( v5 )
    nvram_set(v28 - 9148, v5);
  if ( v6 )
    nvram_set(v29 - 9136, v6);
  if ( v21 )
    nvram_set(v30 - 9124, v21);
  if ( v7 )
    nvram_set(v31 - 9112, v7);
  if ( v22 )
    nvram_set(v32 - 9072, v22);
  if ( v23 )
    nvram_set(v33 - 9056, v23);
  if ( v24 )
    nvram_set("wan_3g_user_mode", v24);
  if ( v8 >= 0 )
  {
    v11 = (const char *)nvram_get("wan_3g_enable");
    if ( v11 && !strncmp(v11, "enable", 6u) )
    {
      v20[0] = 0;
      v20[1] = 0;
      v20[2] = 0;
      v20[3] = 0;
      sprintf((char *)v20, "ppp%d", v8);
      jhl_set_wan_name(v8, v20);
      v12 = jhl_nvget("wan_proto", v8);
      nvram_set(v12, "3G");
      if ( !strncmp(v7, "auto", 4u) )
      {
        jhl_start_redial(v8);
      }
      else
      {
        jhl_stop_redial(v8);
        jhl_stop_3g(v8);
        system("echo -n \"WAN 4G manual connect\" >/var/3gstatus");
      }
    }
    else
    {
      jhl_stop_redial(v8);
      jhl_stop_3g(v8);
      system("echo -n \"WAN 4G manual connect\" >/var/3gstatus");
    }
  }
  jhl_parm_commit(v9);
  v13 = v20;
  v14 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v15 = *(_DWORD *)v14;
    v16 = *((_DWORD *)v14 + 1);
    v17 = *((_DWORD *)v14 + 2);
    v18 = *((_DWORD *)v14 + 3);
    v14 += 16;
    *v13 = v15;
    v13[1] = v16;
    v13[2] = v17;
    v13[3] = v18;
    v13 += 4;
  }
  while ( v14 != "}" );
  *(_WORD *)v13 = *(_WORD *)v14;
  return httpd_cgi_ret(a1, (char *)v20, 33, 4);
}
// 4B0A60: variable 'v9' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82AC: using guessed type int __fastcall jhl_set_wan_name(_DWORD, _DWORD);
// 6A8504: using guessed type int __fastcall jhl_stop_3g(_DWORD);
// 6A85A8: using guessed type int __fastcall jhl_start_redial(_DWORD);
// 6A880C: using guessed type int jhl_get_3g_iface(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89A8: using guessed type int __fastcall jhl_stop_redial(_DWORD);

