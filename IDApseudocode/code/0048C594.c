int __fastcall sub_48C594(int a1)
{
  char *v1; // $v0
  int v2; // $s3
  char *v3; // $s0
  const char *v4; // $v0
  int v5; // $v0
  char *v6; // $v1
  int v7; // $fp
  char *v8; // $s6
  int v9; // $s2
  char *v10; // $s5
  int v11; // $s1
  const char **v12; // $s4
  void *v13; // $v0
  void *v14; // $s7
  char *v15; // $s6
  const char *i; // $s7
  int v17; // $v0
  int v18; // $v0
  char *v19; // $a0
  int v20; // $s2
  int v21; // $v0
  int v22; // $s1
  int v23; // $s1
  int v24; // $s2
  int v25; // $v0
  char *v26; // $s4
  int v27; // $v0
  const char *v28; // $v0
  int v29; // $v0
  const char *v30; // $s7
  int v31; // $s1
  int v32; // $s1
  char *v33; // $v0
  char *v34; // $v0
  int v35; // $s1
  int v36; // $v0
  int v37; // $a2
  int result; // $v0
  const char *v39; // $v0
  const char *v40; // $v0
  unsigned int v41; // $a2
  char v42[256]; // [sp+20h] [-110h] BYREF
  const char *v43; // [sp+120h] [-10h]
  char *format; // [sp+124h] [-Ch]
  void *ptr; // [sp+128h] [-8h]
  char *v46; // [sp+12Ch] [-4h]

  v2 = sq_file_get_max_wan();
  _mem_malloc(77824, "ipsec_net_data", 561);
  v3 = v1;
  if ( v1 )
  {
    strcpy(v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v1, "{\"code\":0,\"error", 16);
    v4 = (const char *)nvram_get("ipsec_net_enable");
    if ( !v4 )
      v4 = "0";
    v5 = sprintf(v3 + 29, "\"enable\":%s", v4);
    v6 = &v3[v5 + 29];
    strcpy(v6, ",\"all\":");
    *(_DWORD *)v6 = *(_DWORD *)",\"all\":";
    v7 = v5 + 36;
    v8 = (char *)nvram_get("ipsec_net_users");
    if ( !v8 )
      v8 = " ";
    v9 = 77824 - v7;
    v10 = &v3[v7];
    v11 = snprintf(&v3[v7], 77824 - v7, (char *)&word_642A04);
    if ( v11 >= 77824 - v7 )
      v11 = 77823 - v7;
    v12 = (const char **)malloc(0x80u);
    format = (char *)malloc(0x4008u);
    v13 = malloc(0x200000u);
    ptr = v13;
    if ( v13 )
    {
      if ( v12 )
      {
        if ( format )
        {
          v14 = v13;
          strlcpy(v13, v8, 0x200000);
          v15 = format;
          v43 = (const char *)split_string(v14, 60, format, 4096);
          if ( (int)v43 > 0 )
          {
            for ( i = 0; i != v43; ++i )
            {
              v17 = split_string(*(_DWORD *)v15, 124, v12, 30);
              format_ipsec_net_data(v12, v17, &v10[v11], v9 - v11);
              v11 += v18;
              v15 += 4;
            }
          }
        }
      }
      free(ptr);
    }
    if ( v12 )
      free(v12);
    if ( format )
      free(format);
    v19 = &v10[v11];
    if ( v11 > 0 && *(v19 - 1) == 44 )
      v19 = &v10[--v11];
    v20 = v9 - v11;
    *v19 = 0;
    v21 = snprintf(v19, v20, &byte_6445A0);
    if ( v21 >= v20 )
      v21 = v20 - 1;
    v22 = v11 + v21 + v7;
    strcpy(&v3[v22], ",\"wans\":[ ");
    *(_DWORD *)&v3[v22] = 1635197484;
    v23 = v22 + 10;
    if ( v2 > 0 )
    {
      ptr = "1\"";
      v43 = "wan_proto";
      v24 = 0;
      format = "{\"iface\":%d,\"wan_ifname\":\"%s\"";
      do
      {
        while ( 1 )
        {
          v25 = jhl_nvget("wan_ifname", v24);
          v26 = (char *)nvram_get(v25);
          if ( !v26 )
            v26 = "";
          if ( !*v26 )
            goto LABEL_39;
          v27 = jhl_nvget("wan_down", v24);
          v28 = (const char *)nvram_get(v27);
          if ( (!v28 || strcmp(v28, "1")) && !jhl_iface_link_up_check(v26, v24) )
            break;
          ++v24;
LABEL_27:
          if ( v2 == v24 )
            goto LABEL_39;
        }
        v29 = jhl_nvget(v43, v24);
        v30 = (const char *)nvram_get(v29);
        if ( v30 )
        {
          v46 = "a";
          if ( !strcmp("3G", v30) )
          {
            v39 = (const char *)nvram_get("wan_3g_enable");
            if ( v39 )
            {
              if ( !strcmp(v39, "disable") )
              {
                ++v24;
                goto LABEL_27;
              }
            }
          }
          if ( !strncmp(v30, v46 + 12644, 2u) )
            v30 = "4G";
        }
        else
        {
          v30 = "";
        }
        v31 = sprintf(&v3[v23], format, v24, v26) + v23;
        v32 = v31 + sprintf(&v3[v31], (char *)ptr - 20260, v30);
        v33 = &v3[v32];
        ++v24;
        *v33 = 125;
        *(_WORD *)(v33 + 1) = 44;
        v23 = v32 + 2;
      }
      while ( v2 != v24 );
    }
LABEL_39:
    v34 = &v3[v23];
    if ( v23 > 0 && *(v34 - 1) == 44 )
      v34 = &v3[--v23];
    v35 = v23 + 1;
    *(_WORD *)v34 = 93;
    v36 = snprintf(&v3[v35], 77824 - v35, "}}");
    if ( v36 >= 77824 - v35 )
      v37 = 77823 - v35;
    else
      v37 = v36;
    result = httpd_cgi_ret(a1, v3, v37 + v35, 8);
  }
  else
  {
    v40 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 77824);
    v41 = snprintf(v42, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v40);
    if ( v41 >= 0x100 )
      v41 = 255;
    result = httpd_cgi_ret(a1, v42, v41, 4);
  }
  return result;
}
// 48C60C: variable 'v1' is possibly undefined
// 48C814: variable 'v18' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

