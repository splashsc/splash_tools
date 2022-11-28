int __fastcall httpd_send_file(int a1, int a2)
{
  int v4; // $v0
  const char *v5; // $s1
  int v6; // $s1
  int v7; // $s1
  char *v8; // $s1
  int *v9; // $v0
  int v10; // $s2
  int v11; // $a1
  int *v12; // $s2
  int *v13; // $v0
  int *v14; // $s2
  const char *v15; // $s1
  char *v16; // $a1
  int v17; // $s3
  char *v19; // $s1
  size_t v20; // $v0
  const char **v21; // $s2
  int v22; // $s3
  const char *v23; // $s1
  int v24; // $s1
  const char *v25; // $v0
  time_t v26; // $s1
  int v27; // $v0
  int v28; // $v0
  time_t v29; // $s1
  int v30; // $a3
  const char *v31; // $s1
  unsigned int v32; // $s1
  int v33; // $a2
  const char *v34; // $s3
  int v35; // $v0
  const char *v36; // $a0
  int v37; // $v0
  int v38; // $v0
  time_t v39; // $v0
  unsigned int v40; // $v0
  char *v41; // $v0
  void (__fastcall *v42)(int); // $t9
  const char *v43; // $v0
  const char *v44; // $s3
  char *v45; // $v0
  const char *v46; // $s1
  const char *v47; // $v0
  int v48; // $v0
  char v49[1024]; // [sp+50h] [-750h] BYREF
  char v50[256]; // [sp+450h] [-350h] BYREF
  char v51[104]; // [sp+550h] [-250h] BYREF
  char v52[64]; // [sp+5B8h] [-1E8h] BYREF
  char v53[64]; // [sp+5F8h] [-1A8h] BYREF
  char v54[64]; // [sp+638h] [-168h] BYREF
  char v55[64]; // [sp+678h] [-128h] BYREF
  char v56[64]; // [sp+6B8h] [-E8h] BYREF
  char v57[64]; // [sp+6F8h] [-A8h] BYREF
  int v58[8]; // [sp+738h] [-68h] BYREF
  int v59[8]; // [sp+758h] [-48h] BYREF
  int v60; // [sp+778h] [-28h]
  char *v61; // [sp+780h] [-20h]
  char *v62; // [sp+784h] [-1Ch]
  char *v63; // [sp+788h] [-18h]
  const char *v64; // [sp+78Ch] [-14h]
  char *v65; // [sp+790h] [-10h]
  char *v66; // [sp+794h] [-Ch]
  char *v67; // [sp+798h] [-8h]
  char *v68; // [sp+79Ch] [-4h]

  v4 = nvram_match_def("billing_en", "1");
  v5 = *(const char **)(a1 + 44);
  if ( v4 && !strcmp(*(const char **)(a1 + 44), "/user_pppoe_group.htm") )
  {
    *(_DWORD *)(a1 + 44) = "/user.htm";
  }
  else if ( !strncmp(v5, "/welcome/gethiipmac.", 0x14u) )
  {
    memset(v49, 0, 0x200u);
    v45 = httpd_get_parm(a1, "ld");
    v46 = v45;
    if ( v45 && *v45 && !jhl_get_hi_redirect_ipmac((_DWORD *)a1, v49) )
    {
      httpds_send_redirect_ipmac(a1, v46, v49);
      return -1;
    }
LABEL_98:
    httpd_conn_close((int *)a1);
    return -1;
  }
  if ( *(_DWORD *)(a1 + 209984) )
  {
    memset(v49, 0, sizeof(v49));
    v6 = jhl_get_hi_redirect_url((_DWORD *)a1, v49, 1024);
    if ( *(_DWORD *)(a1 + 205504) && !hs_addr_loopback(a1) )
    {
      if ( nvram_match_def("https_lanport", "443") )
      {
        v25 = (const char *)jhl_nv_get_def("lan_ipaddr");
        snprintf(v50, 128, "%s", v25);
      }
      else
      {
        v44 = (const char *)jhl_nv_get_def("lan_ipaddr");
        v43 = (const char *)jhl_nv_get_def("https_lanport");
        snprintf(v50, 128, "%s:%s", v44, v43);
      }
      if ( !strcmp(*(const char **)(a1 + 205504), v50) )
        v6 = 1;
    }
    if ( v6 == 3 )
    {
      httpds_send_redirect(a1, v49);
      return -1;
    }
    if ( !v6 )
    {
      v47 = (const char *)jhl_nv_get_def("https_auth_redirect");
      httpds_send_redirect(a1, v47);
      return -1;
    }
  }
  if ( *(_BYTE *)(a1 + 41) != 2 )
    goto LABEL_98;
  v7 = *(_DWORD *)(a1 + 44);
  if ( !v7 )
    goto LABEL_98;
  if ( *(_BYTE *)(v7 + 1) )
  {
    v8 = (char *)(v7 + 1);
    if ( !a2 )
      goto LABEL_13;
    goto LABEL_20;
  }
  v59[0] = 0;
  v59[1] = 0;
  v59[2] = 0;
  v59[3] = 0;
  v59[4] = 0;
  v59[5] = 0;
  v59[6] = 0;
  v59[7] = 0;
  v58[0] = 0;
  v58[1] = 0;
  v58[2] = 0;
  v58[3] = 0;
  v58[4] = 0;
  v58[5] = 0;
  v58[6] = 0;
  v58[7] = 0;
  v60 = 0;
  v67 = v57;
  memset(v50, 0, sizeof(v50));
  memset(v57, 0, sizeof(v57));
  v66 = v56;
  memset(v56, 0, sizeof(v56));
  v62 = v55;
  memset(v55, 0, sizeof(v55));
  memset(v54, 0, sizeof(v54));
  v65 = v53;
  memset(v53, 0, sizeof(v53));
  v63 = v52;
  memset(v52, 0, sizeof(v52));
  v19 = httpd_get_parm(a1, "extend");
  if ( !v19 || !hs_addr_loopback(a1) )
    goto LABEL_42;
  v20 = strlen(v19);
  base64_decode(v19, v50, v20);
  v21 = (const char **)v49;
  v60 = split_string(v50, 38, v49, 60);
  if ( v60 <= 0 )
    goto LABEL_59;
  v64 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
  v61 = "sign=";
  v22 = 0;
  v68 = "letmego";
  while ( 1 )
  {
    v23 = *v21;
    if ( !strncmp(*v21, "tag=", 4u) )
    {
      strlcpy(v62, v23 + 4, 64);
      goto LABEL_38;
    }
    if ( !strncmp(v23, "time=", 5u) )
      break;
    if ( !strncmp(v23, v61, 5u) )
    {
      strlcpy(v65, v23 + 5, 64);
    }
    else if ( !strncmp(v23, v64 - 2120, 4u) )
    {
      strlcpy(v63, v23 + 4, 64);
      if ( strcmp(v63, v68) )
      {
        printf("%s[%d]: cmd:%s error \n", "httpd_send_file", 3670, v63);
        goto LABEL_59;
      }
    }
LABEL_38:
    ++v22;
    ++v21;
    if ( v22 >= v60 )
      goto LABEL_59;
  }
  strlcpy(v54, v23 + 5, 64);
  v26 = time(0);
  v27 = v26 - atoi(v54);
  if ( v27 < 0 )
    v27 = -v27;
  if ( v27 < 601 )
    goto LABEL_38;
  v29 = time(0);
  v28 = atoi(v54);
  v30 = v29 - v28;
  if ( v29 - v28 < 0 )
    v30 = v28 - v29;
  printf("%s[%d]: %d timeout 600\n", "httpd_send_file", 3657, v30);
LABEL_59:
  if ( v55[0] && v54[0] && v53[0] && v52[0] )
  {
    v31 = v67;
    sq_file_get_ssid_en(v67, 64);
    v32 = snprintf(v50, 256, "%s%s%s", v31, v54, v62);
    MD5Init(v51);
    v33 = v32;
    if ( v32 >= 0x100 )
      v33 = 255;
    MD5Update(v51, v50, v33);
    MD5Final(v51);
    v34 = v66;
    sprintf(
      v66,
      "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
      (unsigned __int8)v51[88],
      (unsigned __int8)v51[89],
      (unsigned __int8)v51[90],
      (unsigned __int8)v51[91],
      (unsigned __int8)v51[92],
      (unsigned __int8)v51[93],
      (unsigned __int8)v51[94],
      (unsigned __int8)v51[95],
      (unsigned __int8)v51[96],
      (unsigned __int8)v51[97],
      (unsigned __int8)v51[98],
      (unsigned __int8)v51[99],
      (unsigned __int8)v51[100],
      (unsigned __int8)v51[101],
      (unsigned __int8)v51[102],
      (unsigned __int8)v51[103]);
    if ( !strcmp(v65, v34) )
    {
      if ( gl_httpd_high_admin_en )
      {
        v35 = jhl_nv_get_def("http_hadmin");
        strlcpy(v59, v35, 32);
        v36 = "http_hadminpwd";
      }
      else
      {
        v48 = jhl_nv_get_def("http_username");
        strlcpy(v59, v48, 32);
        v36 = "http_passwd";
      }
      v37 = jhl_nv_get_def(v36);
      strlcpy(v58, v37, 32);
      httpd_cgi_user_check((const char *)v59, (const char *)v58, (_DWORD *)(a1 + 205588));
      v38 = *(_DWORD *)(a1 + 36) | 0x1000;
      *(_BYTE *)(a1 + 43) = 1;
      *(_DWORD *)(a1 + 36) = v38;
      v39 = time(0);
      v40 = snprintf(
              v50,
              256,
              "<html><head><script type='text/javascript'>function init(){window.open('/index.htm?_%lu','_self');}</scrip"
              "t></head><body onLoad='init();'></body></html>",
              v39);
      if ( v40 >= 0x100 )
        v40 = 255;
      return httpd_cgi_ret(a1, v50, v40, 4);
    }
    printf("%s[%d]: error sign:%s, md5:%s\n", "httpd_send_file", 3698, v65, v66);
  }
LABEL_42:
  v8 = "index.htm";
  if ( a2 )
  {
LABEL_20:
    v15 = *(const char **)(a1 + 44);
    if ( !strncmp(v15, "/usb/", 5u) )
    {
      v24 = httpd_send_usb_file(a1);
    }
    else
    {
      if ( !strncmp(v15, "/usb_json/", 0xAu) )
      {
        v17 = 0;
        if ( !httpd_send_usb_file_json((int *)a1) )
          return v17;
        goto LABEL_26;
      }
      if ( !strncmp(v15, "/auth_pic/", 0xAu) )
      {
        v17 = 0;
        if ( !httpd_send_auth_pic_file(a1) )
          return v17;
        goto LABEL_26;
      }
      if ( !strncmp(v15, "/auth_html/", 0xBu) )
      {
        v17 = 0;
        if ( !httpd_send_auth_html_file(a1) )
          return v17;
        goto LABEL_26;
      }
      if ( strncmp(v15, "/logs/", 6u) )
      {
        if ( strncmp(v15, "/sj/", 4u) )
        {
LABEL_26:
          v16 = httpd_not_found[0];
          *(_BYTE *)(a1 + 41) = 2;
          httpd_send_404_info(a1, v16, 0);
          return 0;
        }
LABEL_92:
        v17 = 0;
        if ( httpd_check_user(a1, 4u) )
          return v17;
        v17 = 0;
        if ( !httpd_send_sj_file((_DWORD *)a1) )
          return v17;
        goto LABEL_26;
      }
      v17 = 0;
      if ( httpd_check_user(a1, 4u) )
        return v17;
      v24 = httpd_send_logs_file(a1);
      if ( !strncmp(*(const char **)(a1 + 44), "/sj/", 4u) )
        goto LABEL_92;
    }
    v17 = 0;
    if ( !v24 )
      return v17;
    goto LABEL_26;
  }
LABEL_13:
  while ( 1 )
  {
    v10 = get_name_hash((unsigned __int8 *)v8);
    v9 = httpd_get_file(v8, v10);
    v11 = v10;
    v12 = v9;
    if ( v9 )
      break;
    v13 = httpd_find_ext_file(v8, v11);
    v14 = v13;
    if ( v13 )
    {
      v17 = httpd_check_user(a1, v13[4]);
      if ( !v17 )
      {
        v42 = (void (__fastcall *)(int))v14[6];
        if ( v42 )
        {
          v42(a1);
          return v17;
        }
      }
      return 0;
    }
    if ( !strcmp(v8, "index.htm") )
    {
      v8 = "index.html";
    }
    else
    {
      if ( strcmp(v8, "login.htm") )
      {
        if ( debug_level > 0 )
          printf("%s:%d not find ext file, %s\n", "httpd_send_file", 3789, v8);
        goto LABEL_20;
      }
      v8 = "login.html";
    }
  }
  *(_DWORD *)(a1 + 205392) = v9;
  *(_DWORD *)(a1 + 205400) = 0;
  if ( !strcmp(v8, "index.html") && httpd_get_parm(a1, "ip") && httpd_get_parm(a1, "port") && httpd_get_parm(a1, "sn") )
    v12[3] = 0;
  if ( !strcmp(v8, "config.html") )
    goto LABEL_20;
  v17 = httpd_check_user(a1, v12[3]);
  if ( v17 )
    return 0;
  v41 = httpd_find_type(v8);
  httpd_start(a1, (int)v41);
  return v17;
}
// 6676A4: using guessed type char *httpd_not_found[27];
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D0BC: using guessed type int debug_level;
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8384: using guessed type int __fastcall MD5Init(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8800: using guessed type int __fastcall sq_file_get_ssid_en(_DWORD, _DWORD);
// 6A8850: using guessed type int __fastcall MD5Final(_DWORD);
// 6A8928: using guessed type int __fastcall MD5Update(_DWORD, _DWORD, _DWORD);

