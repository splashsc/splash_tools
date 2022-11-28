int __fastcall sub_49635C(int a1)
{
  char *v1; // $v0
  char *v2; // $s0
  const char *v3; // $v0
  int v4; // $v0
  const char *v5; // $v0
  int v6; // $s1
  int v7; // $v0
  int v8; // $s3
  int v9; // $s2
  char *v10; // $s5
  int v11; // $s6
  int v12; // $s1
  const char **v13; // $s4
  void *v14; // $v0
  char *v15; // $s7
  int v16; // $a1
  void *v17; // $s6
  int v18; // $s6
  int i; // $fp
  int v20; // $v0
  int v21; // $v0
  char *v22; // $a0
  int v23; // $s2
  int v24; // $v0
  int v25; // $s1
  int v26; // $s1
  char *v27; // $v0
  int v28; // $s1
  char *v29; // $v0
  int v30; // $s1
  char *v31; // $v0
  const char *v32; // $v0
  int v33; // $s1
  const char *v34; // $s2
  const char *v35; // $s3
  const char *v36; // $v0
  char *v37; // $s3
  int v38; // $s1
  int v39; // $a2
  int result; // $v0
  int v41; // $v0
  const char *v42; // $a0
  int v43; // $s2
  char *v44; // $v0
  const char *v45; // $s7
  int v46; // $v0
  char *v47; // $s7
  int v48; // $v0
  int v49; // $v0
  const char *v50; // $v1
  int v51; // $v0
  const char *v52; // $v0
  void *v53; // $a0
  const char *v54; // $v0
  unsigned int v55; // $v0
  char *v56[64]; // [sp+28h] [-120h] BYREF
  char *v57; // [sp+128h] [-20h]
  char *v58; // [sp+12Ch] [-1Ch]
  char *v59; // [sp+130h] [-18h]
  char *v60; // [sp+134h] [-14h]
  void *ptr; // [sp+138h] [-10h]
  char *v62; // [sp+13Ch] [-Ch]
  void *v63; // [sp+140h] [-8h]

  _mem_malloc(0x200000, "router_data", 120);
  v2 = v1;
  if ( v1 )
  {
    strcpy(v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    v57 = "a";
    qmemcpy(v1, "{\"code\":0,\"error\":\"\"", 20);
    v58 = "a";
    v3 = (const char *)jhl_nv_get_def("dual_lan_mode");
    v4 = strcmp(v3, "1");
    v59 = "a";
    v6 = sprintf(v2 + 29, "\"dual_lan\":\"%d\"", v4 == 0) + 29;
    v5 = (const char *)nvram_get("lan_ifname");
    if ( !v5 )
      v5 = "";
    v7 = v6 + sprintf(&v2[v6], ",\"lan_ifname\":\"%s\"", v5);
    strcpy(&v2[v7], ",\"routes_static\":");
    qmemcpy(&v2[v7], ",\"routes_static\"", 16);
    v8 = v7 + 17;
    v9 = 0x200000 - (v7 + 17);
    v10 = &v2[v7 + 17];
    v11 = nvram_get("routes_static");
    v12 = snprintf(&v2[v8], 0x200000 - v8, (char *)&word_642A04);
    if ( v12 >= 0x200000 - v8 )
      v12 = 0x1FFFFF - v8;
    if ( v11 )
    {
      v13 = (const char **)malloc(0x20u);
      v60 = (char *)malloc(0x4008u);
      v15 = v60;
      v14 = malloc(0x200000u);
      ptr = v14;
      if ( v14 )
      {
        if ( v13 )
        {
          v16 = v11;
          if ( v60 )
          {
            v17 = v14;
            strlcpy(v14, v16, 0x200000);
            v18 = split_string(v17, 62, v60, 4096);
            if ( v18 > 0 )
            {
              for ( i = 0; i != v18; ++i )
              {
                v20 = split_string(*(_DWORD *)v15, 60, v13, 6);
                format_routers_static(v13, v20, &v10[v12], v9 - v12);
                v12 += v21;
                v15 += 4;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v13 )
        free(v13);
      if ( v60 )
        free(v60);
    }
    v22 = &v10[v12];
    if ( v12 > 0 && *(v22 - 1) == 44 )
      v22 = &v10[--v12];
    v23 = v9 - v12;
    *v22 = 0;
    v24 = snprintf(v22, v23, &byte_6445A0);
    if ( v24 >= v23 )
      v24 = v23 - 1;
    v25 = v12 + v24 + v8;
    strcpy(&v2[v25], ",\"activeroutes\":");
    qmemcpy(&v2[v25], ",\"activeroutes\":", 16);
    v26 = v25 + 16 + asp_activeroutes(&v2[v25 + 16], 0x200000 - (v25 + 16));
    v27 = &v2[v26];
    strcpy(&v2[v26], ",\"wans\":");
    *(_DWORD *)v27 = 1635197484;
    *((_DWORD *)v27 + 1) = 975336302;
    v28 = v26 + 8 + get_wans_data(&v2[v26 + 8], 0x200000 - (v26 + 8));
    v29 = &v2[v28];
    strcpy(&v2[v28], ",\"vpns\":");
    *(_DWORD *)v29 = 1886790188;
    *((_DWORD *)v29 + 1) = 975336302;
    v30 = v28 + 8 + get_vpns_iface(&v2[v28 + 8]);
    v31 = &v2[v30];
    strcpy(&v2[v30], ",\"lans\":[");
    *(_DWORD *)v31 = 1634476588;
    *((_DWORD *)v31 + 1) = 975336302;
    v32 = (const char *)jhl_nv_get_def(v57 + 13964);
    v33 = v30 + 9;
    if ( !strcmp(v32, v58 + 9340) )
    {
      v41 = nvram_get("lan_ifnames");
      if ( v41 )
        v42 = (const char *)v41;
      else
        v42 = "";
      v63 = strdup(v42);
      v43 = 1;
      if ( v63 )
      {
        v56[0] = (char *)v63;
        v60 = "a";
        ptr = "lan_ipaddr";
        v62 = "a";
        while ( 1 )
        {
          v44 = strsep(v56, " ");
          v45 = v44;
          if ( !v44 )
            break;
          v46 = *v44;
          if ( v46 == 32 )
          {
            v47 = (char *)(v45 + 1);
            do
              v46 = *v47++;
            while ( v46 == 32 );
            v45 = v47 - 1;
          }
          if ( !v46 )
            break;
          if ( !strncmp(v45, "bind_", 5u) || !strncmp(v45, "bond_", 5u) )
          {
            ++v43;
          }
          else
          {
            v48 = jhl_langet(v60 + 14348, v43 - 1);
            v57 = (char *)nvram_get(v48);
            if ( !v57 )
              break;
            v49 = jhl_langet(ptr, v43 - 1);
            v50 = (const char *)nvram_get(v49);
            if ( !v50 )
              v50 = "";
            v59 = &v2[v33];
            v58 = (char *)v50;
            v51 = jhl_langet(v62 + 15044, v43 - 1);
            v52 = (const char *)nvram_get(v51);
            if ( !v52 )
              v52 = "";
            v33 += sprintf(
                     v59,
                     "{\"iface\":%d,\"ifname\":\"%s\",\"show_ifname\":\"%s\",\"ipaddr\":\"%s\",\"netmask\":\"%s\"},",
                     v43++ - 1,
                     v45,
                     v57,
                     v58,
                     v52);
          }
        }
        v37 = &v2[v33];
        if ( v33 > 0 && *(v37 - 1) == 44 )
          v37 = &v2[--v33];
        v53 = v63;
        *v37 = 0;
        free(v53);
      }
      else
      {
        v37 = &v2[v33];
      }
    }
    else
    {
      v34 = (const char *)nvram_get(v59 + 13980);
      if ( !v34 )
        v34 = "";
      v35 = (const char *)nvram_get("lan_ipaddr");
      if ( !v35 )
        v35 = "";
      v36 = (const char *)nvram_get("lan_netmask");
      if ( !v36 )
        v36 = "";
      v33 += sprintf(
               &v2[v33],
               "{\"iface\":0,\"ifname\":\"%s\",\"show_ifname\":\"LAN\",\"ipaddr\":\"%s\",\"netmask\":\"%s\"}",
               v34,
               v35,
               v36);
      v37 = &v2[v33];
    }
    v38 = v33 + 1;
    *(_WORD *)v37 = 93;
    v39 = snprintf(&v2[v38], 0x200000 - v38, "}}");
    if ( v39 >= 0x200000 - v38 )
      v39 = 0x1FFFFF - v38;
    result = httpd_cgi_ret(a1, v2, v39 + v38, 8);
  }
  else
  {
    v54 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v55 = snprintf((char *)v56, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v54);
    if ( v55 >= 0x100 )
      v55 = 255;
    result = httpd_cgi_ret(a1, (char *)v56, v55, 4);
  }
  return result;
}
// 4963BC: variable 'v1' is possibly undefined
// 496654: variable 'v21' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 64331C: using guessed type int dword_64331C;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 64BD3C: using guessed type int dword_64BD3C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8994: using guessed type int __fastcall jhl_langet(_DWORD, _DWORD);

