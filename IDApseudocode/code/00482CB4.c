int __fastcall sub_482CB4(int a1)
{
  const char *v2; // $v0
  int v3; // $v0
  bool v4; // dc
  char *v5; // $v0
  int v6; // $fp
  const char *v7; // $s4
  const char *v8; // $s5
  const char *v9; // $s6
  const char *v10; // $s7
  const char *v11; // $s0
  const char *v12; // $a1
  const char *v13; // $v0
  int v14; // $s2
  unsigned int v15; // $v0
  char v17[2048]; // [sp+58h] [-848h] BYREF
  int v18[8]; // [sp+858h] [-48h] BYREF
  char v19[12]; // [sp+878h] [-28h] BYREF
  int v20; // [sp+884h] [-1Ch]
  const char *v21; // [sp+888h] [-18h]
  const char *v22; // [sp+88Ch] [-14h]
  const char *v23; // [sp+890h] [-10h]
  const char *v24; // [sp+894h] [-Ch]
  char *v25; // [sp+898h] [-8h]

  memset(v17, 0, sizeof(v17));
  v18[0] = 0;
  v18[1] = 0;
  v18[2] = 0;
  v18[3] = 0;
  v18[4] = 0;
  v18[5] = 0;
  v18[6] = 0;
  v18[7] = 0;
  get_memory(v19);
  v2 = (const char *)custom_tb_version();
  v3 = sprintf((char *)v18, "%s", v2);
  v4 = v3 <= 0;
  v5 = &v17[v3];
  if ( !v4 )
    v5[2047] = 0;
  strcpy(v17, "{\"code\":0,\"error\":\"\",\"data\":{");
  v6 = v20;
  v7 = (const char *)wys_svn_info;
  v8 = (const char *)jhl_nv_get_def("vs_type");
  v9 = (const char *)tomato_buildtime;
  v10 = (const char *)wayos_version;
  v11 = (const char *)nvram_get("upgrade_version_name");
  if ( !v11 )
    v11 = "";
  v12 = (const char *)nvram_get("backup_firmware_status");
  if ( !v12 )
    v12 = "0";
  v25 = "0";
  v24 = v12;
  v23 = (const char *)jhl_nv_get_def("auto_upgrade_en");
  v22 = (const char *)jhl_nv_get_def("upgrade_auto_time");
  v21 = (const char *)jhl_nv_get_def("upgrade_auto_info");
  v13 = (const char *)custom_device_name();
  v14 = sprintf(
          &v17[29],
          "\"jffs2_on\":\"0\",\"totalfreeram\":%lu ,\"svn\":%s,\"vs_type\":%s,\"vtm\":\"%s\" ,\"tbv\":\"%s\",\"pre_ver\":"
          "\"%s\",\"version\":\"%s\",\"tmp_version\":\"%s\",\"back_show\":\"%s\",\"back_state\":\"%s\",\"upgrade_auto_en\""
          ":\"%s\",\"upgrade_auto_time\":\"%s\",\"upgrade_auto_info\":\"%s\",\"ramfs\":\"%d\",\"model\":\"%s\",\"tb_versi"
          "on_def\":\"%s\",\"device_name_def\":\"%s\"",
          v6,
          v7,
          v8,
          v9,
          (const char *)v18,
          "V2.0",
          v10,
          v11,
          v25,
          v24,
          v23,
          v22,
          v21,
          1,
          v13,
          "FBM-1008V-",
          "FBM-1008V")
      + 29;
  v15 = snprintf(&v17[v14], 2048 - v14, "}}");
  if ( v15 >= 2048 - v14 )
    v15 = 2047 - v14;
  return httpd_cgi_ret(a1, v17, v15 + v14, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85CC: using guessed type int __fastcall get_memory(_DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A8788: using guessed type int custom_tb_version(void);

