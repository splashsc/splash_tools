int __fastcall sub_48B714(int a1)
{
  char *v2; // $s4
  char *v3; // $s3
  char *v4; // $s2
  char *v5; // $fp
  char *v6; // $s7
  char *v7; // $s6
  int v8; // $v0
  char *v9; // $s5
  int v10; // $a0
  const char *v12; // $v0
  int v13[8]; // [sp+18h] [-48h] BYREF
  char *v14; // [sp+38h] [-28h]
  char *v15; // [sp+3Ch] [-24h]
  char *v16; // [sp+40h] [-20h]
  char *v17; // [sp+44h] [-1Ch]
  char *v18; // [sp+48h] [-18h]
  char *v19; // [sp+4Ch] [-14h]
  char *v20; // [sp+50h] [-10h]
  char *v21; // [sp+54h] [-Ch]
  char *v22; // [sp+58h] [-8h]
  char *v23; // [sp+5Ch] [-4h]

  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  v13[4] = 0;
  v13[5] = 0;
  v13[6] = 0;
  v13[7] = 0;
  v2 = httpd_get_parm(a1, "host_ip");
  v3 = httpd_get_parm(a1, "host_mask");
  v23 = httpd_get_parm(a1, "ike_type");
  v22 = httpd_get_parm(a1, "psk_key");
  v4 = httpd_get_parm(a1, "enable");
  v21 = httpd_get_parm(a1, "ike_dh_group");
  v20 = httpd_get_parm(a1, "ike_encrypt");
  v19 = httpd_get_parm(a1, "ike_auth");
  v18 = httpd_get_parm(a1, "ike_lifetime");
  v17 = httpd_get_parm(a1, "ike_pfs_group");
  v16 = httpd_get_parm(a1, "ipsec_encrypt");
  v15 = httpd_get_parm(a1, "ipsec_auth");
  v14 = httpd_get_parm(a1, "ipsec_lifetime");
  v5 = httpd_get_parm(a1, "ip_compress");
  v6 = httpd_get_parm(a1, "ike_pfs");
  v7 = httpd_get_parm(a1, "dpd_time");
  v9 = httpd_get_parm(a1, "dpd_latertime");
  v8 = mask_addr_to_inet(v3);
  sprintf((char *)v13, "%s/%d", v2, v8);
  nvram_set("ipsec_road_enable", v4);
  nvram_set("ipsec_road_host_ip", v2);
  nvram_set("ipsec_road_host_mask", v3);
  nvram_set("ipsec_road_host_ip_mask", v13);
  nvram_set("ipsec_road_ike_type", v23);
  nvram_set("ipsec_road_psk_key", v22);
  nvram_set("ipsec_road_ike_dh_group", v21);
  nvram_set("ipsec_road_ike_encrypt", v20);
  nvram_set("ipsec_road_ike_auth", v19);
  nvram_set("ipsec_road_ike_lifetime", v18);
  nvram_set("ipsec_road_ike_pfs_group", v17);
  nvram_set("ipsec_road_ipsec_encrypt", v16);
  nvram_set("ipsec_road_ipsec_auth", v15);
  nvram_set("ipsec_road_ipsec_lifetime", v14);
  nvram_set("ipsec_road_ip_compress", v5);
  nvram_set("ipsec_road_ike_pfs", v6);
  nvram_set("ipsec_road_dpd_time", v7);
  nvram_set("ipsec_road_dpd_latertime", v9);
  if ( !strcmp(v4, "1") )
  {
    nvram_set("ipsec_mode", "road");
    nvram_set("ipsec_l2tp_enable", "0");
    nvram_set("ipsec_net_enable", "0");
    nvram_set("ipsec_l2tp_cli_enable", "0");
LABEL_3:
    jhl_parm_commit(v10);
    schedule_ipsec(1, 0);
    return ipsec_road_data(a1);
  }
  v12 = (const char *)nvram_get("ipsec_mode");
  if ( v12 && !strcmp(v12, "road") )
  {
    nvram_set("ipsec_mode", "none");
    goto LABEL_3;
  }
  return ipsec_road_data(a1);
}
// 48BC20: variable 'v10' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8724: using guessed type int __fastcall schedule_ipsec(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

