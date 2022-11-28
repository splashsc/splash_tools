int __fastcall sub_46DF94(int a1)
{
  const char *v2; // $s0
  const char *v3; // $s1
  const char *v4; // $s4
  const char *v5; // $s5
  const char *v6; // $s6
  const char *v7; // $s7
  const char *v8; // $fp
  const char *v9; // $v0
  unsigned int v10; // $v0
  int v11; // $s0
  unsigned int v12; // $v0
  char v14[1024]; // [sp+48h] [-410h] BYREF
  const char *v15; // [sp+448h] [-10h]
  const char *v16; // [sp+44Ch] [-Ch]
  const char *v17; // [sp+450h] [-8h]
  const char *v18; // [sp+454h] [-4h]

  memset(v14, 0, sizeof(v14));
  strcpy(v14, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("wtQR_SrvEnable");
  v3 = (const char *)jhl_nv_get_def("wtQR_AdsEnable");
  v4 = (const char *)jhl_nv_get_def("wtQR_ShareEnable");
  v5 = (const char *)jhl_nv_get_def("wtQR_SlaveMode");
  v6 = (const char *)jhl_nv_get_def("SSID1");
  v7 = (const char *)jhl_nv_get_def("wtQR_JumpUrl");
  v8 = (const char *)jhl_nv_get_def("wtQR_SuperCode");
  v18 = (const char *)jhl_nv_get_def("wtQR_ScanCnt");
  v17 = (const char *)jhl_nv_get_def("wtQR_CltNmae");
  v16 = (const char *)jhl_nv_get_def("wtQR_Tips");
  v15 = (const char *)jhl_nv_get_def("wtQR_Support");
  v9 = (const char *)jhl_nv_get_def("wtQR_WanLanInfor");
  v10 = snprintf(
          &v14[29],
          995,
          "\"wtqr_ServerEnable\":\"%s\",\"wtqr_AdsEnable\":\"%s\",\"wtqr_ShareEnable\":\"%s\",\"wtqr_SlaveMode\":\"%s\",\""
          "wtqr_Ssid\":\"%s\",\"wtqr_JumpUrl\":\"%s\",\"wtqr_SuperCode\":\"%s\",\"wtqr_ScanCnt\":\"%s\",\"wtqr_CltNmae\":"
          "\"%s\",\"wtqr_Tips\":\"%s\",\"wtqr_Support\":\"%s\",\"wtqr_WanLanInfor\":\"%s\"",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v18,
          v17,
          v16,
          v15,
          v9);
  v11 = v10 + 29;
  if ( v10 >= 0x3E3 )
    v11 = 1023;
  v12 = snprintf(&v14[v11], 1024 - v11, "}}");
  if ( v12 >= 1024 - v11 )
    v12 = 1023 - v11;
  return httpd_cgi_ret(a1, v14, v12 + v11, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

