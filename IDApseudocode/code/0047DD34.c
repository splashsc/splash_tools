int __fastcall sub_47DD34(int a1)
{
  char *v2; // $s0
  unsigned int v3; // $v0
  int v4; // $v0
  char *v6; // $s2
  const char *v7; // $s1
  const char *v8; // $v0
  unsigned int v9; // $s1
  size_t v10; // $v0
  const char **v11; // $s2
  int v12; // $s6
  int v13; // $s3
  const char *v14; // $s0
  int v15; // $v1
  const char *v16; // $a3
  char *v17; // $a2
  unsigned int v18; // $v0
  int v19; // $v0
  void *v20; // $v0
  void *v21; // $s0
  int v22; // $v0
  char v23[1024]; // [sp+20h] [-888h] BYREF
  char v24[1024]; // [sp+420h] [-488h] BYREF
  char v25[64]; // [sp+820h] [-88h] BYREF
  char v26[48]; // [sp+860h] [-48h] BYREF
  char *v27; // [sp+890h] [-18h]
  unsigned int v28; // [sp+894h] [-14h]
  char *v29; // [sp+898h] [-10h]
  char *v30; // [sp+89Ch] [-Ch]
  char *v31; // [sp+8A0h] [-8h]

  v2 = (char *)nvram_get("auth_htm");
  if ( nvram_match_def("billing_en", "1") )
  {
    memset(v25, 0, sizeof(v25));
    memset(v24, 0, sizeof(v24));
    v6 = httpd_get_parm(a1, "extend");
    IpaddrToStr(v25, a1 + 205460);
    v7 = (const char *)jhl_nv_get_def("lan_ipaddr");
    v8 = (const char *)jhl_nv_get_def("billing_httpd_port");
    v9 = snprintf(v24, 1024, "%s:%s/index.html?ip=%s", v7, v8, v25);
    if ( v9 >= 0x400 )
      v9 = 1023;
    if ( !v6
      || (memset(v23, 0, sizeof(v23)),
          v10 = strlen(v6),
          base64_decode(v6, v23, v10),
          v11 = (const char **)v26,
          v12 = split_string(v23, 38, v26, 8),
          v12 <= 0) )
    {
LABEL_25:
      v19 = jiffies_get();
      snprintf(&v24[v9], 1024 - v9, "&_t=%lu", v19);
      return httpd_send_redirect(a1, v24);
    }
    v29 = "1\"";
    v31 = "1\"";
    v13 = 0;
    v27 = "v1=";
    v30 = "r=";
    while ( 1 )
    {
      while ( 1 )
      {
        v14 = *v11;
        if ( strncmp(*v11, "m=", 2u) )
          break;
        v15 = 1024 - v9;
        v16 = v14 + 2;
        v17 = "&mac=%s";
LABEL_22:
        v28 = v15;
        v18 = snprintf(&v24[v9], v15, v17, v16);
        if ( v18 >= v28 )
          v18 = 1023 - v9;
        ++v13;
        v9 += v18;
        ++v11;
        if ( v12 == v13 )
          goto LABEL_25;
      }
      if ( !strncmp(v14, "t=", 2u) )
      {
        v15 = 1024 - v9;
        v16 = v14 + 2;
        v17 = "&netType=%s";
        goto LABEL_22;
      }
      if ( !strncmp(v14, v27, 3u) )
      {
        v15 = 1024 - v9;
        v16 = v14 + 3;
        v17 = "&vlan1=%s";
        goto LABEL_22;
      }
      if ( !strncmp(v14, v29 - 28036, 3u) )
      {
        v15 = 1024 - v9;
        v16 = v14 + 3;
        v17 = "&vlan2=%s";
        goto LABEL_22;
      }
      if ( !strncmp(v14, v30, 2u) )
      {
        v15 = 1024 - v9;
        v16 = v14 + 2;
        v17 = v31 - 28016;
        goto LABEL_22;
      }
      ++v13;
      ++v11;
      if ( v12 == v13 )
        goto LABEL_25;
    }
  }
  if ( v2 )
  {
    if ( !strcmp(v2, (const char *)&off_4CFA50) )
    {
      _mem_malloc(0x200000, "auth_htm", 4885);
      v21 = v20;
      if ( v20 )
      {
        v22 = read_tg_html_from_usb(v20, 0x200000, "webauthfile");
        if ( v22 >= 4 )
          return httpd_send_mime_file(a1, "text/html", v21, v22);
        _mem_free(v21);
      }
    }
    else if ( *v2 )
    {
      v3 = strlen(v2);
      if ( v3 >= 4 )
        return httpd_send_html_file(a1, "text/html", v2, v3);
    }
  }
  v4 = get_web_language_type(a1);
  if ( v4 == 1 )
    return httpd_cgi_ret(a1, "/auth_org_en.htm", 0, 2);
  if ( v4 == 99 )
    return httpd_cgi_ret(a1, "/auth_org_ft.htm", 0, 2);
  return httpd_cgi_ret(a1, "/auth_org.htm", 0, 2);
}
// 47E1E0: variable 'v20' is possibly undefined
// 4CFA50: using guessed type void *off_4CFA50;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8974: using guessed type int __fastcall read_tg_html_from_usb(_DWORD, _DWORD, _DWORD);

