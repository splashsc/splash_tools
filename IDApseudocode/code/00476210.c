int __fastcall sub_476210(int a1)
{
  char *v2; // $s2
  char *v3; // $fp
  char *v4; // $s7
  char *v5; // $s6
  char *v6; // $s1
  char *v7; // $s3
  char *v8; // $s4
  char *v9; // $s5
  int v10; // $s2
  const char *v11; // $v0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  int v19; // $a0
  const char *v20; // $v0
  char v21[1024]; // [sp+18h] [-420h] BYREF
  char *v22; // [sp+418h] [-20h]
  char *v23; // [sp+41Ch] [-1Ch]
  char *v24; // [sp+420h] [-18h]
  char *v25; // [sp+424h] [-14h]
  char *v26; // [sp+428h] [-10h]
  char *v27; // [sp+42Ch] [-Ch]
  char *v28; // [sp+430h] [-8h]
  char *v29; // [sp+434h] [-4h]

  v23 = v21;
  memset(v21, 0, sizeof(v21));
  v2 = httpd_get_parm(a1, "wtqr_ServerEnable");
  v3 = httpd_get_parm(a1, "wtqr_AdsEnable");
  v4 = httpd_get_parm(a1, "wtqr_ShareEnable");
  v5 = httpd_get_parm(a1, "wtqr_SlaveMode");
  v6 = httpd_get_parm(a1, "wtqr_Ssid");
  v24 = httpd_get_parm(a1, "wtqr_JumpUrl");
  v25 = httpd_get_parm(a1, "wtqr_SuperCode");
  v26 = httpd_get_parm(a1, "wtqr_ScanCnt");
  v27 = httpd_get_parm(a1, "wtqr_CltNmae");
  v28 = httpd_get_parm(a1, "wtqr_Tips");
  v7 = httpd_get_parm(a1, "wtqr_Support");
  v8 = httpd_get_parm(a1, "wtqr_WanLanInfor");
  v9 = httpd_get_parm(a1, "wtqr_Ipaddr");
  v22 = httpd_get_parm(a1, "wtqr_Netmask");
  if ( v2 && (v29 = "a", !nvram_match_def("wtQR_SrvEnable", v2)) )
  {
    nvram_set(v29 + 29736, v2);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  if ( v3 )
  {
    v29 = "a";
    if ( !nvram_match_def("wtQR_AdsEnable", v3) )
    {
      nvram_set(v29 + 29752, v3);
      v10 = 1;
    }
  }
  if ( v4 && !nvram_match_def("wtQR_ShareEnable", v4) )
  {
    nvram_set("wtQR_ShareEnable", v4);
    v10 = 1;
  }
  if ( v5 && !nvram_match_def("wtQR_SlaveMode", v5) )
  {
    nvram_set("wtQR_SlaveMode", v5);
    v10 = 1;
  }
  if ( v6 )
  {
    v11 = (const char *)nvram_get("SSID1");
    if ( !v11 || strcmp(v11, v6) || (v20 = (const char *)nvram_get("SSID2")) == 0 || strcmp(v20, v6) )
    {
      nvram_set("SSID1", v6);
      nvram_set("SSID2", v6);
      v10 = 1;
      nvram_set("ssid_charset1", "0");
      nvram_set("ssid_charset2", "1");
    }
    if ( !nvram_match_def("wtQR_Ssid", v6) )
    {
      nvram_set("wtQR_Ssid", v6);
      v10 = 1;
    }
  }
  if ( v24 && !nvram_match_def("wtQR_JumpUrl", v24) )
  {
    nvram_set("wtQR_JumpUrl", v24);
    v10 = 1;
  }
  if ( v25 && !nvram_match_def("wtQR_SuperCode", v25) )
  {
    nvram_set("wtQR_SuperCode", v25);
    v10 = 1;
  }
  if ( v26 && !nvram_match_def("wtQR_ScanCnt", v26) )
  {
    nvram_set("wtQR_ScanCnt", v26);
    v10 = 1;
  }
  if ( v27 && !nvram_match_def("wtQRr_CltNmae", v27) )
  {
    nvram_set("wtQR_CltNmae", v27);
    v10 = 1;
  }
  if ( v28 && !nvram_match_def("wtQR_Tips", v28) )
  {
    nvram_set("wtQR_Tips", v28);
    v10 = 1;
  }
  if ( v7 && !nvram_match_def("wtQR_Support", v7) )
  {
    nvram_set("wtQR_Support", v7);
    v10 = 1;
  }
  if ( v8 && !nvram_match_def("wtQR_WanLanInfor", v8) )
  {
    nvram_set("wtQR_WanLanInfor", v8);
    v10 = 1;
  }
  if ( v9 && !nvram_match_def("wtQR_Ipaddr", v9) )
  {
    nvram_set("wtQR_Ipaddr", v9);
    if ( !v22 || nvram_match_def("wtQR_Netmask", v22) )
      goto LABEL_51;
    goto LABEL_50;
  }
  if ( v22 && !nvram_match_def("wtQR_Netmask", v22) )
  {
LABEL_50:
    nvram_set("wtQR_Netmask", v22);
    goto LABEL_51;
  }
  if ( v10 )
  {
LABEL_51:
    nvram_set("wt_config_modify", "1");
    start_rzgl(0);
    wt_client_restart(0);
    mng_client_restart(0);
    jhl_parm_commit(v19);
  }
  v12 = v23;
  v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v14 = *(_DWORD *)v13;
    v15 = *((_DWORD *)v13 + 1);
    v16 = *((_DWORD *)v13 + 2);
    v17 = *((_DWORD *)v13 + 3);
    v13 += 16;
    *(_DWORD *)v12 = v14;
    *((_DWORD *)v12 + 1) = v15;
    *((_DWORD *)v12 + 2) = v16;
    *((_DWORD *)v12 + 3) = v17;
    v12 += 16;
  }
  while ( v13 != "}" );
  *(_WORD *)v12 = *(_WORD *)v13;
  return httpd_cgi_ret(a1, v23, 33, 4);
}
// 476894: variable 'v19' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8354: using guessed type int __fastcall wt_client_restart(_DWORD);
// 6A83A0: using guessed type int __fastcall mng_client_restart(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

