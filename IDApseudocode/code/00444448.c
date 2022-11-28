int __fastcall lans_data(int a1)
{
  char *v1; // $v0
  char *v2; // $s5
  char *v3; // $v0
  char *v4; // $v0
  char *v5; // $s6
  char *v6; // $s4
  int v7; // $s2
  const char *v8; // $s3
  const char *v9; // $v0
  int v10; // $s2
  int v11; // $s2
  const char *v12; // $v0
  int v13; // $s2
  int v14; // $v0
  char *v15; // $v1
  char *v16; // $v0
  int v17; // $s7
  char **v18; // $s3
  const char *v19; // $s1
  char *v20; // $s0
  int v21; // $v0
  const char *v22; // $s0
  int v23; // $v0
  const char *v24; // $v0
  const char *v25; // $s3
  int v26; // $v0
  int v27; // $v0
  int v28; // $v0
  int v29; // $v0
  int v30; // $v0
  int v31; // $v0
  int v32; // $v0
  int v33; // $v0
  int v34; // $v0
  int v35; // $v0
  int v36; // $v0
  int v37; // $v0
  int v38; // $v0
  const char *v39; // $v0
  const char *v40; // $fp
  int v41; // $v0
  int v42; // $v0
  const char *v43; // $v0
  char *v44; // $v0
  char *v45; // $v0
  int v46; // $v0
  const char *v47; // $s2
  int v48; // $v0
  const char *v49; // $v0
  char *v50; // $v0
  char *v51; // $v0
  int v52; // $v0
  int v53; // $v0
  const char *v54; // $s4
  int v55; // $v0
  const char *v56; // $s1
  int v57; // $v0
  const char *v58; // $v0
  const char *v59; // $a2
  int v60; // $a3
  int v61; // $v0
  int v62; // $s1
  int v63; // $s0
  int v64; // $v0
  int v65; // $v0
  const char *v66; // $v0
  int v67; // $s0
  int v68; // $v0
  int v69; // $s0
  int v70; // $v0
  int v71; // $s0
  int result; // $v0
  const char *v73; // $v0
  unsigned int v74; // $s0
  char v75[2048]; // [sp+78h] [-CC0h] BYREF
  char v76[1024]; // [sp+878h] [-4C0h] BYREF
  char v77[32]; // [sp+C78h] [-C0h] BYREF
  int v78[8]; // [sp+C98h] [-A0h] BYREF
  char *v79; // [sp+CB8h] [-80h] BYREF
  int v80; // [sp+CC0h] [-78h]
  int v81; // [sp+CC4h] [-74h]
  char *v82; // [sp+CC8h] [-70h]
  char *v83; // [sp+CCCh] [-6Ch]
  const char *v84; // [sp+CD0h] [-68h]
  const char *v85; // [sp+CD4h] [-64h]
  const char *v86; // [sp+CD8h] [-60h]
  const char *v87; // [sp+CDCh] [-5Ch]
  char *v88; // [sp+CE0h] [-58h]
  const char *v89; // [sp+CE4h] [-54h]
  char *v90; // [sp+CE8h] [-50h]
  const char *v91; // [sp+CECh] [-4Ch]
  char *v92; // [sp+CF0h] [-48h]
  char *v93; // [sp+CF4h] [-44h]
  char *v94; // [sp+CF8h] [-40h]
  char *v95; // [sp+CFCh] [-3Ch]
  char *v96; // [sp+D00h] [-38h]
  char *v97; // [sp+D04h] [-34h]
  char *v98; // [sp+D08h] [-30h]
  int v99; // [sp+D0Ch] [-2Ch]
  char *v100; // [sp+D10h] [-28h]
  int *v101; // [sp+D14h] [-24h]
  char *v102; // [sp+D18h] [-20h]
  char *v103; // [sp+D1Ch] [-1Ch]
  char *v104; // [sp+D20h] [-18h]
  char *v105; // [sp+D24h] [-14h]
  char *v106; // [sp+D28h] [-10h]
  const char *v107; // [sp+D2Ch] [-Ch]
  void *ptr; // [sp+D30h] [-8h]

  memset(v75, 0, sizeof(v75));
  v106 = "a";
  memset(v76, 0, sizeof(v76));
  _mem_malloc(10240, "lans_data", 1994);
  v2 = v1;
  _mem_malloc(10240, "lans_data", 1995);
  v5 = v4;
  _mem_malloc(102400, "lans_data", 1996);
  v6 = v3;
  if ( v2 && v5 && v3 )
  {
    strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v3, "{\"code\":0,\"error\":\"\",\"da", 24);
    v7 = sprintf(v3 + 29, "\"x86\":%d,", 0) + 29;
    v8 = (const char *)jhl_nv_get_def("dual_lan_mode");
    v9 = (const char *)jhl_nv_get_def("dhcp_bind_ipmac_en");
    v10 = v7 + sprintf(&v6[v7], "\"dual_lan_mode\":\"%s\",\"dhcp_bind_ipmac_en\":\"%s\"", v8, v9);
    v11 = v10 + sprintf(&v6[v10], ",\"duolan_en\":\"%d\"", 1);
    v12 = (const char *)jhl_nv_get_def("duolan_enble");
    v13 = v11 + sprintf(&v6[v11], ",\"duolan_enble\":\"%s\",\"duolanlist\":", v12);
    v14 = v13 + get_duolanlist_data(&v6[v13], 102400 - v13);
    v15 = &v6[v14];
    strcpy(&v6[v14], ",\"lans\":[");
    *(_DWORD *)v15 = 1634476588;
    *((_DWORD *)v15 + 1) = 975336302;
    v80 = v14 + 9;
    get_lan_ifnames(v75, 2048);
    v16 = strdup(v75);
    ptr = v16;
    if ( v16 )
    {
      v79 = v16;
      v81 = 1;
      v100 = "1\"";
      v17 = 0;
      v83 = (char *)&unk_643780;
      v82 = v6;
      v103 = (char *)&off_643784;
      v101 = (int *)&v79;
      v105 = "a";
      v104 = "a";
      v107 = "lan_ifacebind";
LABEL_6:
      v18 = (char **)v101;
      v19 = v100 - 10364;
      while ( 1 )
      {
        v20 = strsep(v18, v19);
        if ( !v20 )
          break;
        do
          v21 = *v20++;
        while ( v21 == 32 );
        v22 = v20 - 1;
        if ( !v21 )
          break;
        if ( strncmp(v22, v83, 3u) )
        {
          if ( !strncmp(v22, v103, 3u) )
          {
            v99 = 1;
            if ( v17 )
              goto LABEL_76;
LABEL_13:
            v84 = v104 - 1660;
          }
          else
          {
            v99 = 2 * (strncmp(v22, v105 + 14216, 3u) == 0);
            if ( !v17 )
              goto LABEL_13;
LABEL_76:
            v65 = jhl_langet(v107, v17);
            v66 = (const char *)nvram_get(v65);
            v84 = v66;
            if ( v66 )
            {
              if ( strlen(v66) < 3 )
                v84 = "LAN1";
            }
            else
            {
              v84 = "LAN1";
            }
          }
          v23 = jhl_langet("dhcp_type", v17);
          v24 = (const char *)nvram_get(v23);
          v25 = v24;
          if ( v24 )
          {
            if ( strcmp(v24, (const char *)&off_63F984) )
              v25 = "admin";
          }
          else
          {
            v25 = (const char *)&off_63F984;
          }
          v26 = jhl_langet("dhcp_lease", v17);
          v85 = (const char *)nvram_get(v26);
          if ( !v85 )
            v85 = "3600";
          v27 = jhl_langet("dhcp_start", v17);
          v86 = (const char *)nvram_get(v27);
          if ( !v86 )
            v86 = "0.0.0.0";
          v28 = jhl_langet("dhcp_end", v17);
          v87 = (const char *)nvram_get(v28);
          if ( !v87 )
            v87 = "0.0.0.0";
          v29 = jhl_langet("lan_ipaddr", v17);
          v88 = (char *)nvram_get(v29);
          if ( !v88 )
            v88 = "";
          v30 = jhl_langet("lan_netmask", v17);
          v89 = (const char *)nvram_get(v30);
          if ( !v89 )
            v89 = "255.255.255.0";
          v31 = jhl_langet("dhcp_gw", v17);
          v90 = (char *)nvram_get(v31);
          if ( !v90 )
            v90 = "";
          v32 = jhl_langet("dhcp_mask", v17);
          v91 = (const char *)nvram_get(v32);
          if ( !v91 )
            v91 = "255.255.255.0";
          v33 = jhl_langet("dhcp_dns0", v17);
          v92 = (char *)nvram_get(v33);
          if ( !v92 )
            v92 = "";
          v34 = jhl_langet("dhcp_dns1", v17);
          v93 = (char *)nvram_get(v34);
          if ( !v93 )
            v93 = "";
          v35 = jhl_langet("dhcp_option43", v17);
          v94 = (char *)nvram_get(v35);
          if ( !v94 )
            v94 = "";
          v36 = jhl_langet("dhcp_filter", v17);
          v95 = (char *)nvram_get(v36);
          if ( !v95 )
            v95 = "";
          v37 = jhl_langet("mac_deflan", v17);
          v96 = (char *)nvram_get(v37);
          if ( !v96 )
            v96 = "";
          v38 = jhl_langet("mac_lan", v17);
          v39 = (const char *)nvram_get(v38);
          v40 = v39;
          if ( v39 )
          {
            if ( strlen(v39) >= 5 )
            {
LABEL_43:
              v41 = jhl_langet("dhcp_static_en", v17);
              v97 = (char *)nvram_get(v41);
              if ( !v97 )
                v97 = "0";
              v42 = jhl_langet("dhcp_static_addr", v17);
              v43 = (const char *)nvram_get(v42);
              if ( !v43 )
                v43 = "";
              snprintf(v2, 10240, "%s", v43);
              while ( 1 )
              {
                v44 = strchr(v2, 60);
                if ( !v44 )
                  break;
                *v44 = 62;
              }
              while ( 1 )
              {
                v45 = strchr(v2, 124);
                if ( !v45 )
                  break;
                *v45 = 44;
              }
              v46 = jhl_langet("dhcp_notan_en", v17);
              v47 = (const char *)nvram_get(v46);
              if ( !v47 )
                v47 = "0";
              v48 = jhl_langet("dhcp_notan_addr", v17);
              v49 = (const char *)nvram_get(v48);
              if ( !v49 )
                v49 = "";
              snprintf(v5, 10240, "%s", v49);
              while ( 1 )
              {
                v50 = strchr(v5, 60);
                if ( !v50 )
                  break;
                *v50 = 62;
              }
              while ( 1 )
              {
                v51 = strchr(v5, 124);
                if ( !v51 )
                  break;
                *v51 = 44;
              }
              v52 = jhl_langet("dhcp_pool_en", v17);
              v98 = (char *)nvram_get(v52);
              if ( !v98 )
                v98 = "0";
              v53 = jhl_langet("dhcp_ip_pool", v17);
              v54 = (const char *)nvram_get(v53);
              if ( !v54 )
                v54 = "";
              v55 = jhl_langet("lan_showname", v17);
              v56 = (const char *)nvram_get(v55);
              if ( v56 )
              {
                v102 = v77;
                sprintf(v77, "LAN%d", v81);
                if ( strlen(v56) < 4 )
                  v56 = v102;
              }
              else
              {
                v56 = v77;
                sprintf(v77, "LAN%d", v81);
              }
              v57 = jhl_langet("lan_mem", v17);
              v58 = (const char *)nvram_get(v57);
              if ( !v58 )
                v58 = "";
              if ( v17 )
                v59 = &byte_643D4C;
              else
                v59 = "";
              v60 = v17++;
              v61 = sprintf(
                      &v82[v80],
                      "%s{\"iface\":\"%d\",\"ifname\":\"%s\",\"lan_showname\":\"%s\",\"eth_flag\":\"%d\",\"iface_bind\":\""
                      "%s\",\"lan_ipaddr\":\"%s\",\"lan_netmask\":\"%s\",\"mac_deflan\":\"%s\",\"mac_lan\":\"%s\",\"dhcp_"
                      "type\":\"%s\",\"dhcp_start\":\"%s\",\"dhcp_end\":\"%s\",\"dhcp_lease\":\"%s\",\"dhcp_gw\":\"%s\",\""
                      "dhcp_mask\":\"%s\",\"dhcp_dns0\":\"%s\",\"dhcp_dns1\":\"%s\",\"dhcp_option43\":\"%s\",\"dhcp_stati"
                      "c_en\":\"%s\",\"dhcp_static_addr\":\"%s\",\"dhcp_notan_en\":\"%s\",\"dhcp_notan_addr\":\"%s\",\"dh"
                      "cp_pool_en\":\"%s\",\"dhcp_ip_pool\":\"%s\",\"mem\":\"%s\"",
                      v59,
                      v60,
                      v22,
                      v56,
                      v99,
                      v84,
                      v88,
                      v89,
                      v96,
                      v40,
                      v25,
                      v86,
                      v87,
                      v85,
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      v97,
                      v2,
                      v47,
                      v5,
                      v98,
                      v54,
                      v58);
              v62 = (int)v82;
              v63 = v80 + v61;
              v64 = v63 + sprintf(&v82[v80 + v61], ",\"dhcp_filter\":\"%s\"", v95);
              v80 = v64 + 1;
              ++v81;
              *(_WORD *)(v62 + v64) = 125;
              goto LABEL_6;
            }
          }
          else
          {
            v40 = "";
          }
          if ( !check_ifname_is_wan(v22) )
          {
            v78[0] = 0;
            v78[1] = 0;
            v78[2] = 0;
            v78[3] = 0;
            v78[4] = 0;
            v78[5] = 0;
            v78[6] = 0;
            v78[7] = 0;
            dual_getIfMac(v22, v78);
            v40 = (const char *)v78;
          }
          goto LABEL_43;
        }
      }
      v6 = v82;
      free(ptr);
    }
    strcpy(&v6[v80], "],\"dual_lan_list\":");
    qmemcpy(&v6[v80], "],\"dual_lan_list", 16);
    v67 = v80 + 18;
    v68 = v67 + get_dual_lan_list_data(&v6[v67], 102400 - v67);
    *(_WORD *)&v6[v68] = 44;
    v69 = v68 + 1 + get_lan_vlan_data(&v6[v68 + 1], 102400 - (v68 + 1));
    v70 = snprintf(&v6[v69], 102400 - v69, "}}");
    if ( v70 >= 102400 - v69 )
      v70 = 102399 - v69;
    v71 = v70 + v69;
    _mem_free(v5);
    _mem_free(v2);
    result = httpd_cgi_ret(a1, v6, v71, 8);
  }
  else
  {
    v73 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v74 = snprintf(v76, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v73);
    _mem_free(v5);
    _mem_free(v2);
    _mem_free(v6);
    if ( v74 >= 0x400 )
      result = httpd_cgi_ret(a1, v76, 1023, 4);
    else
      result = httpd_cgi_ret(a1, v76, v74, 4);
  }
  return result;
}
// 4444F8: variable 'v1' is possibly undefined
// 444518: variable 'v4' is possibly undefined
// 444524: variable 'v3' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 643784: using guessed type void *off_643784;
// 643D4C: using guessed type char byte_643D4C;
// 6A8190: using guessed type int __fastcall dual_getIfMac(_DWORD, _DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8440: using guessed type int __fastcall get_lan_ifnames(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8830: using guessed type int __fastcall check_ifname_is_wan(_DWORD);
// 6A8994: using guessed type int __fastcall jhl_langet(_DWORD, _DWORD);

