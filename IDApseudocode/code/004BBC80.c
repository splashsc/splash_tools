int __fastcall sub_4BBC80(int a1)
{
  char *v2; // $s1
  char *v3; // $s7
  char *v4; // $s6
  char *v5; // $s5
  char *v6; // $v0
  char *v7; // $s3
  char *v8; // $s4
  const char *v9; // $v0
  int v10; // $s1
  const char *v11; // $v0
  const char *v12; // $v0
  const char *v13; // $v0
  const char *v14; // $s6
  const char *v15; // $v0
  const char *v16; // $s6
  const char *v17; // $v0
  const char *v18; // $s6
  const char *v19; // $v0
  const char *v20; // $s6
  const char *v21; // $v0
  const char *v22; // $s6
  const char *v23; // $v0
  const char *v24; // $s6
  const char *v25; // $v0
  const char *v26; // $s6
  const char *v27; // $v0
  const char *v28; // $s6
  const char *v29; // $v0
  const char *v30; // $s6
  const char *v31; // $v0
  const char *v32; // $s6
  const char *v33; // $v0
  const char *v34; // $s6
  const char *v35; // $v0
  const char *v36; // $s6
  const char *v37; // $v0
  const char *v38; // $s6
  const char *v39; // $v0
  const char *v40; // $s6
  const char *v41; // $v0
  const char *v42; // $s6
  const char *v43; // $v0
  const char *v44; // $s6
  const char *v45; // $v0
  const char *v46; // $v0
  const char *v47; // $v0
  const char *v48; // $v0
  _BYTE *v49; // $v0
  struct tm *v50; // $v0
  char *v51; // $s2
  int v52; // $a0
  char *v53; // $v1
  const char *v54; // $v0
  int v55; // $t0
  int v56; // $a3
  int v57; // $a2
  int v58; // $a1
  char v60[256]; // [sp+30h] [-198h] BYREF
  char v61[64]; // [sp+130h] [-98h] BYREF
  time_t v62; // [sp+170h] [-58h] BYREF
  char *v63; // [sp+178h] [-50h]
  char *v64; // [sp+17Ch] [-4Ch]
  char *v65; // [sp+180h] [-48h]
  char *v66; // [sp+184h] [-44h]
  char *v67; // [sp+188h] [-40h]
  char *v68; // [sp+18Ch] [-3Ch]
  char *v69; // [sp+190h] [-38h]
  char *v70; // [sp+194h] [-34h]
  char *v71; // [sp+198h] [-30h]
  char *v72; // [sp+19Ch] [-2Ch]
  char *v73; // [sp+1A0h] [-28h]
  char *v74; // [sp+1A4h] [-24h]
  char *v75; // [sp+1A8h] [-20h]
  char *v76; // [sp+1ACh] [-1Ch]
  char *v77; // [sp+1B0h] [-18h]
  char *v78; // [sp+1B4h] [-14h]
  char *v79; // [sp+1B8h] [-10h]
  char *v80; // [sp+1BCh] [-Ch]
  char *v81; // [sp+1C0h] [-8h]

  v79 = v60;
  memset(v60, 0, sizeof(v60));
  v81 = v61;
  memset(v61, 0, sizeof(v61));
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "srv_addr");
  v4 = httpd_get_parm(a1, "srv_user");
  v5 = httpd_get_parm(a1, "srv_pwd");
  v63 = httpd_get_parm(a1, "srv_port");
  v64 = httpd_get_parm(a1, "other_srv_addr");
  v65 = httpd_get_parm(a1, "other_srv_port");
  v66 = httpd_get_parm(a1, "udp_srv_port");
  v67 = httpd_get_parm(a1, "tcp_srv_port");
  v68 = httpd_get_parm(a1, "heart_udp_port");
  v69 = httpd_get_parm(a1, "enable2");
  v70 = httpd_get_parm(a1, "srv_addr2");
  v71 = httpd_get_parm(a1, "srv_user2");
  v72 = httpd_get_parm(a1, "srv_pwd2");
  v73 = httpd_get_parm(a1, "srv_port2");
  v74 = httpd_get_parm(a1, "createtime");
  v75 = httpd_get_parm(a1, "ztcp_srv_addr");
  v76 = httpd_get_parm(a1, "ztcp_srv_port");
  v77 = httpd_get_parm(a1, "des_iv");
  v6 = httpd_get_parm(a1, "des_key");
  v80 = "1\"";
  v78 = v6;
  v7 = httpd_get_parm(a1, "yh_platform_addr");
  v8 = httpd_get_parm(a1, "yh_platform_port");
  if ( !v2 || (v9 = (const char *)nvram_get("sj_en")) != 0 && !strcmp(v9, v2) )
  {
    v10 = 0;
  }
  else
  {
    syslog(7, "%s[%d]:  set sj_en=%s\n", "sj_state_asp", 1228, v2);
    nvram_set("sj_en", v2);
    v10 = 1;
  }
  if ( v3 )
  {
    v11 = (const char *)nvram_get("sj_ftp_srvaddr");
    if ( !v11 || strcmp(v11, v3) )
    {
      nvram_set("sj_ftp_srvaddr", v3);
      v10 = 1;
    }
  }
  if ( v4 )
  {
    v12 = (const char *)nvram_get("sj_ftp_user");
    if ( !v12 || strcmp(v12, v4) )
    {
      nvram_set("sj_ftp_user", v4);
      v10 = 1;
    }
  }
  if ( v5 )
  {
    v13 = (const char *)nvram_get("sj_ftp_pass");
    if ( !v13 || strcmp(v13, v5) )
    {
      nvram_set("sj_ftp_pass", v5);
      v10 = 1;
    }
  }
  v14 = v63;
  if ( v63 )
  {
    v15 = (const char *)nvram_get("sj_ftp_port");
    if ( !v15 || strcmp(v15, v14) )
    {
      nvram_set("sj_ftp_port", v63);
      v10 = 1;
    }
  }
  v16 = v64;
  if ( v64 )
  {
    v17 = (const char *)nvram_get("sj_other_srvaddr");
    if ( !v17 || strcmp(v17, v16) )
    {
      nvram_set("sj_other_srvaddr", v64);
      v10 = 1;
    }
  }
  v18 = v65;
  if ( v65 )
  {
    v19 = (const char *)nvram_get("sj_other_port");
    if ( !v19 || strcmp(v19, v18) )
    {
      nvram_set("sj_other_port", v65);
      v10 = 1;
    }
  }
  v20 = v75;
  if ( v75 )
  {
    v21 = (const char *)nvram_get("sj_ztcp_srvaddr");
    if ( !v21 || strcmp(v21, v20) )
    {
      nvram_set("sj_ztcp_srvaddr", v75);
      v10 = 1;
    }
  }
  v22 = v76;
  if ( v76 )
  {
    v23 = (const char *)nvram_get("sj_ztcp_srvport");
    if ( !v23 || strcmp(v23, v22) )
    {
      nvram_set("sj_ztcp_srvport", v76);
      v10 = 1;
    }
  }
  v24 = v66;
  if ( v66 )
  {
    v25 = (const char *)nvram_get("sj_other_udpport");
    if ( !v25 || strcmp(v25, v24) )
    {
      nvram_set("sj_other_udpport", v66);
      v10 = 1;
    }
  }
  v26 = v68;
  if ( v68 )
  {
    v27 = (const char *)nvram_get("sj_heart_udpport");
    if ( !v27 || strcmp(v27, v26) )
    {
      nvram_set("sj_heart_udpport", v68);
      v10 = 1;
    }
  }
  v28 = v67;
  if ( v67 )
  {
    v29 = (const char *)nvram_get("sj_other_tcpport");
    if ( !v29 || strcmp(v29, v28) )
    {
      nvram_set("sj_other_tcpport", v67);
      v10 = 1;
    }
  }
  v30 = v69;
  if ( v69 )
  {
    v31 = (const char *)nvram_get("sj_ftp_en2");
    if ( !v31 || strcmp(v31, v30) )
    {
      nvram_set("sj_ftp_en2", v69);
      v10 = 1;
    }
  }
  v32 = v70;
  if ( v70 )
  {
    v33 = (const char *)nvram_get("sj_ftp_srvaddr2");
    if ( !v33 || strcmp(v33, v32) )
    {
      nvram_set("sj_ftp_srvaddr2", v70);
      v10 = 1;
    }
  }
  v34 = v71;
  if ( v71 )
  {
    v35 = (const char *)nvram_get("sj_ftp_user2");
    if ( !v35 || strcmp(v35, v34) )
    {
      nvram_set("sj_ftp_user2", v71);
      v10 = 1;
    }
  }
  v36 = v72;
  if ( v72 )
  {
    v37 = (const char *)nvram_get("sj_ftp_pass2");
    if ( !v37 || strcmp(v37, v36) )
    {
      nvram_set("sj_ftp_pass2", v72);
      v10 = 1;
    }
  }
  v38 = v73;
  if ( v73 )
  {
    v39 = (const char *)nvram_get("sj_ftp_port2");
    if ( !v39 || strcmp(v39, v38) )
    {
      nvram_set("sj_ftp_port2", v73);
      v10 = 1;
    }
  }
  v40 = v74;
  if ( v74 )
  {
    v41 = (const char *)nvram_get("sj_create_time");
    if ( !v41 || strcmp(v41, v40) )
    {
      nvram_set("sj_create_time", v74);
      v10 = 1;
    }
  }
  v42 = v78;
  if ( v78 )
  {
    v43 = (const char *)nvram_get("sj_des_key");
    if ( !v43 || strcmp(v43, v42) )
    {
      nvram_set("sj_des_key", v78);
      v10 = 1;
    }
  }
  v44 = v77;
  if ( v77 )
  {
    v45 = (const char *)nvram_get("sj_des_iv");
    if ( !v45 || strcmp(v45, v44) )
    {
      nvram_set("sj_des_iv", v77);
      v10 = 1;
    }
  }
  if ( !v7 )
    goto LABEL_94;
  v46 = (const char *)nvram_get("yh_platform_addr");
  if ( !v46 || strcmp(v46, v7) )
  {
    nvram_set("yh_platform_addr", v7);
    v10 = 1;
  }
  v47 = (const char *)nvram_get("yh_platform_addr");
  if ( v47 )
  {
    if ( !strcmp(v47, v7) )
    {
LABEL_94:
      if ( !v8 )
        goto LABEL_97;
      v48 = (const char *)nvram_get(v80 - 2844);
      if ( !v48 )
        goto LABEL_89;
LABEL_96:
      if ( strcmp(v48, v8) )
        goto LABEL_89;
LABEL_97:
      if ( !v10 )
        goto LABEL_98;
      goto LABEL_90;
    }
  }
  nvram_set("yh_platform_addr", v7);
  if ( !v8 )
    goto LABEL_90;
  v48 = (const char *)nvram_get(v80 - 2844);
  v10 = 1;
  if ( v48 )
    goto LABEL_96;
LABEL_89:
  nvram_set(v80 - 2844, v8);
LABEL_90:
  v49 = (_BYTE *)nvram_get("sj_create_time");
  if ( v49 && !*v49 )
  {
    time(&v62);
    v50 = localtime(&v62);
    v51 = v81;
    snprintf(
      v81,
      63,
      "%04d-%02d-%02d %02d:%02d:%02d",
      v50->tm_year + 1900,
      v50->tm_mon + 1,
      v50->tm_mday,
      v50->tm_hour,
      v50->tm_min,
      v50->tm_sec);
    nvram_set("sj_create_time", v51);
  }
  shenji_ctrl_set_en();
  nvram_set("sj_state", "");
  jhl_parm_commit(v52);
  exec_service("wys_sj-restart");
LABEL_98:
  v53 = v79;
  v54 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v55 = *(_DWORD *)v54;
    v56 = *((_DWORD *)v54 + 1);
    v57 = *((_DWORD *)v54 + 2);
    v58 = *((_DWORD *)v54 + 3);
    v54 += 16;
    *(_DWORD *)v53 = v55;
    *((_DWORD *)v53 + 1) = v56;
    *((_DWORD *)v53 + 2) = v57;
    *((_DWORD *)v53 + 3) = v58;
    v53 += 16;
  }
  while ( v54 != "}" );
  *(_WORD *)v53 = *(_WORD *)v54;
  return httpd_cgi_ret(a1, v79, 33, 4);
}
// 4BC940: variable 'v52' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

