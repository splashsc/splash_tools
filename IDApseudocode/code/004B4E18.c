int __fastcall sub_4B4E18(int a1)
{
  char *v1; // $v0
  const char *v2; // $v0
  char *v3; // $s7
  const char *v4; // $s0
  const char *v5; // $v0
  const char *v6; // $s1
  int v7; // $s1
  const char *v8; // $s2
  const char *v9; // $s3
  const char *v10; // $s4
  const char *v11; // $s5
  const char *v12; // $s6
  const char *v13; // $fp
  const char *v14; // $v0
  int v15; // $s4
  int v16; // $s1
  char *v17; // $s3
  int v18; // $s5
  int v19; // $s0
  const char **v20; // $s2
  void *v21; // $v0
  char *v22; // $s6
  int v23; // $a1
  void *v24; // $s5
  int v25; // $s5
  int i; // $fp
  int v27; // $v0
  int v28; // $v0
  char *v29; // $a0
  int v30; // $s1
  int v31; // $v0
  int v32; // $s4
  int v33; // $v0
  const char *v34; // $v0
  int v35; // $s0
  int v36; // $v0
  int v37; // $s0
  int v38; // $v0
  int v39; // $a2
  int result; // $v0
  char v41[256]; // [sp+58h] [-228h] BYREF
  char v42[256]; // [sp+158h] [-128h] BYREF
  char *v43; // [sp+258h] [-28h]
  char *v44; // [sp+25Ch] [-24h]
  void *ptr; // [sp+260h] [-20h]
  const char *v46; // [sp+264h] [-1Ch]
  const char *v47; // [sp+268h] [-18h]
  const char *v48; // [sp+26Ch] [-14h]
  const char *v49; // [sp+270h] [-10h]
  const char *v50; // [sp+274h] [-Ch]
  const char *v51; // [sp+278h] [-8h]
  const char *v52; // [sp+27Ch] [-4h]

  v43 = v41;
  memset(v41, 0, sizeof(v41));
  _mem_malloc(10240, "usb_all_data", 90);
  if ( v1 )
  {
    v3 = v1;
    v2 = (const char *)nvram_get("http_lanport");
    v4 = v2;
    if ( !v2 || !*v2 )
      v4 = "80";
    v5 = (const char *)nvram_get("tggl_port");
    v6 = v5;
    if ( v5 && *v5 && (unsigned int)(J_ato10(v5) - 1) < 0xFFFF )
      v4 = v6;
    v7 = usb_get_current_device((int)v43);
    strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v3, "{\"code\":0,\"error\":\"\"", 20);
    v8 = (const char *)jhl_nv_get_def("usb_share_enable");
    v9 = (const char *)jhl_nv_get_def("usb_printer_en");
    v10 = (const char *)jhl_nv_get_def(&unk_64DE5C);
    v11 = (const char *)nvram_get("lan_ipaddr");
    v12 = (const char *)jhl_nv_get_def("usb_passwd");
    v13 = (const char *)jhl_nv_get_def("usb_username");
    v52 = (const char *)jhl_nv_get_def("usb_hpasswd");
    v51 = (const char *)jhl_nv_get_def("usb_husername");
    v50 = (const char *)jhl_nv_get_def(&unk_64E3C8);
    v49 = (const char *)jhl_nv_get_def(&unk_64E3D4);
    v48 = (const char *)jhl_nv_get_def("usb_acc_wan");
    v47 = (const char *)jhl_nv_get_def("usb_acc_auth");
    v46 = (const char *)jhl_nv_get_def(&unk_64E3E0);
    ptr = (void *)jhl_nv_get_def("usb_send_email_en");
    v44 = (char *)jhl_nv_get_def(&unk_64E404);
    v14 = (const char *)jhl_nv_get_def(&unk_64E418);
    v15 = sprintf(
            v3 + 29,
            "\"status\":%d,\"share_enable\":\"%s\",\"printer_enable\":\"%s\",\"printer_port\":\"%s\",\"lan_ipaddr\":\"%s\""
            ",\"http_lanport\":\"%s\",\"passwd\":\"%s\",\"name\":\"%s\",\"hpasswd\":\"%s\",\"hname\":\"%s\",\"usb_more\":"
            "\"0\",\"acc_ip\":\"%s\",\"acc_mac\":\"%s\",\"acc_wan\":\"%s\",\"acc_auth\":\"%s\",\"device_name\":\"%s\",\"s"
            "end_email_en\":\"%s\",\"send_email_name\":\"%s\",\"send_email_pwd\":\"%s\",\"email_list\":",
            v7 == 0,
            v8,
            v9,
            v10,
            v11,
            v4,
            v12,
            v13,
            v52,
            v51,
            v50,
            v49,
            v48,
            v47,
            v46,
            (const char *)ptr,
            v44,
            v14)
        + 29;
    v16 = 10240 - v15;
    v17 = &v3[v15];
    v18 = nvram_get("usb_send_email_list");
    v19 = snprintf(&v3[v15], 10240 - v15, (char *)&word_642A04);
    if ( v19 >= 10240 - v15 )
      v19 = 10239 - v15;
    if ( v18 )
    {
      v20 = (const char **)malloc(0x18u);
      v44 = (char *)malloc(0x4008u);
      v22 = v44;
      v21 = malloc(0x200000u);
      ptr = v21;
      if ( v21 )
      {
        if ( v20 )
        {
          v23 = v18;
          if ( v22 )
          {
            v24 = v21;
            strlcpy(v21, v23, 0x200000);
            v25 = split_string(v24, 60, v22, 4096);
            if ( v25 > 0 )
            {
              for ( i = 0; i != v25; ++i )
              {
                v27 = split_string(*(_DWORD *)v22, 124, v20, 4);
                format_usb_email_list_data(v20, v27, &v17[v19], v16 - v19);
                v19 += v28;
                v22 += 4;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v20 )
        free(v20);
      if ( v44 )
        free(v44);
    }
    v29 = &v17[v19];
    if ( v19 > 0 && *(v29 - 1) == 44 )
      v29 = &v17[--v19];
    v30 = v16 - v19;
    *v29 = 0;
    v31 = snprintf(v29, v30, &byte_6445A0);
    if ( v31 >= v30 )
      v31 = v30 - 1;
    v32 = v19 + v31 + v15;
    v33 = snprintf(
            &v3[v32],
            10240 - v32,
            ",\"usb_3g\":\"%d\",\"usb_printer\":\"%d\",\"accauth_flag\":\"%d\",\"usb_remove\":\"%d\"",
            1,
            1,
            0,
            1);
    if ( v33 >= 10240 - v32 )
      v33 = 10239 - v32;
    v35 = v33 + v32;
    v34 = (const char *)jhl_nv_get_def("usb_mount_dev");
    v36 = snprintf(&v3[v35], 10240 - v35, ",\"usb_dev\":\"%s\",\"cur_dev\":\"%s\",\"info\":", v34, v43);
    if ( v36 >= 10240 - v35 )
      v36 = 10239 - v35;
    v37 = v36 + v35 + get_all_disk_info(*(unsigned __int8 *)(a1 + 210102), &v3[v36 + v35], 10240 - (v36 + v35));
    v38 = snprintf(&v3[v37], 10240 - v37, "}}");
    if ( v38 >= 10240 - v37 )
      v39 = 10239 - v37;
    else
      v39 = v38;
    result = httpd_cgi_ret(a1, v3, v39 + v37, 8);
  }
  else
  {
    strcpy(v42, "{\"code\":0,\"error\":\"\",\"data\":{");
    result = httpd_cgi_ret(a1, v42, 29, 4);
  }
  return result;
}
// 4B4E94: variable 'v1' is possibly undefined
// 4B52F8: variable 'v28' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A853C: using guessed type int __fastcall J_ato10(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8914: using guessed type int __fastcall get_all_disk_info(_DWORD, _DWORD, _DWORD);

