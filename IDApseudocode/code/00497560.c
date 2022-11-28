int __fastcall sub_497560(int a1)
{
  char *v2; // $v0
  const char *v3; // $s3
  char *v4; // $s0
  int v5; // $s4
  char *v6; // $v0
  int v7; // $s1
  int v8; // $s1
  char *v9; // $v1
  int v10; // $v0
  const char *v11; // $v0
  int v12; // $s1
  int v13; // $s1
  int v14; // $a2
  const char *v16; // $s4
  const char *v17; // $v0
  const char *v18; // $v0
  unsigned int v19; // $v0
  char v20[5120]; // [sp+50h] [-1C48h] BYREF
  char v21[2048]; // [sp+1450h] [-848h] BYREF
  int v22[18]; // [sp+1C50h] [-48h] BYREF

  memset(v20, 0, sizeof(v20));
  memset(v22, 0, sizeof(v22));
  v3 = (const char *)jhl_nv_get_def("dual_lan_mode");
  _mem_malloc(5120, "pppoe_base_data", 43);
  if ( v2 )
  {
    v4 = v2;
    jhl_parm_get("pppoeBase", v20, 5120);
    split_string(v20, 60, v22, 16);
    if ( v22[0] )
    {
      if ( v22[1] )
        goto LABEL_4;
    }
    else
    {
      v22[0] = (int)&off_63F984;
      if ( v22[1] )
      {
LABEL_4:
        if ( v22[2] )
          goto LABEL_5;
        goto LABEL_28;
      }
    }
    v22[1] = (int)"Router_PPPoE";
    if ( v22[2] )
    {
LABEL_5:
      if ( v22[3] )
        goto LABEL_6;
      goto LABEL_29;
    }
LABEL_28:
    v22[2] = (int)"10.0.0.1";
    if ( v22[3] )
    {
LABEL_6:
      if ( v22[4] )
        goto LABEL_7;
      goto LABEL_30;
    }
LABEL_29:
    v22[3] = (int)"255.255.255.0";
    if ( v22[4] )
    {
LABEL_7:
      if ( v22[5] )
        goto LABEL_8;
      goto LABEL_31;
    }
LABEL_30:
    v22[4] = (int)"6";
    if ( v22[5] )
    {
LABEL_8:
      if ( v22[6] )
        goto LABEL_9;
      goto LABEL_32;
    }
LABEL_31:
    v22[5] = (int)"3";
    if ( v22[6] )
    {
LABEL_9:
      if ( v22[7] )
        goto LABEL_10;
      goto LABEL_33;
    }
LABEL_32:
    v22[6] = (int)&off_63F984;
    if ( v22[7] )
    {
LABEL_10:
      if ( v22[8] )
        goto LABEL_11;
      goto LABEL_34;
    }
LABEL_33:
    v22[7] = (int)"1";
    if ( v22[8] )
    {
LABEL_11:
      if ( v22[9] )
        goto LABEL_12;
      goto LABEL_35;
    }
LABEL_34:
    v22[8] = (int)"0";
    if ( v22[9] )
    {
LABEL_12:
      if ( v22[10] )
        goto LABEL_13;
      goto LABEL_36;
    }
LABEL_35:
    v22[9] = (int)"0";
    if ( v22[10] )
    {
LABEL_13:
      if ( v22[11] )
        goto LABEL_14;
      goto LABEL_37;
    }
LABEL_36:
    v22[10] = (int)"0";
    if ( v22[11] )
    {
LABEL_14:
      if ( v22[12] )
        goto LABEL_15;
      goto LABEL_38;
    }
LABEL_37:
    v22[11] = (int)"1";
    if ( v22[12] )
    {
LABEL_15:
      if ( v22[13] )
        goto LABEL_16;
      goto LABEL_39;
    }
LABEL_38:
    v22[12] = (int)"0.0.0.0";
    if ( v22[13] )
    {
LABEL_16:
      if ( v22[14] )
        goto LABEL_17;
      goto LABEL_40;
    }
LABEL_39:
    v22[13] = (int)"0.0.0.0";
    if ( v22[14] )
    {
LABEL_17:
      if ( v22[15] )
      {
LABEL_18:
        strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
        qmemcpy(v4, "{\"code\":0,\"error\":\"\"", 20);
        v5 = sprintf(
               v4 + 29,
               "\"en\":\"%s\",\"acn\":\"%s\",\"stip\":\"%s\",\"endip\":\"%s\",\"chktm\":%s,\"chkmax\":%s,\"only_pppoe\":\""
               "%s\",\"pap_en\":\"%s\",\"chap_en\":\"%s\",\"mschap_en\":\"%s\",\"mschap2_en\":\"%s\",\"any_acname\":\"%s\""
               ",\"dns0\":\"%s\",\"dns1\":\"%s\",\"any_user\":\"%s\",\"any_user_dq\":\"%s\"",
               (const char *)v22[0],
               (const char *)v22[1],
               (const char *)v22[2],
               (const char *)v22[3],
               (const char *)v22[4],
               (const char *)v22[5],
               (const char *)v22[6],
               (const char *)v22[7],
               (const char *)v22[8],
               (const char *)v22[9],
               (const char *)v22[10],
               (const char *)v22[11],
               (const char *)v22[12],
               (const char *)v22[13],
               (const char *)v22[14],
               (const char *)v22[15]);
        v6 = &v4[v5 + 29];
        strcpy(v6, ",\"pppoe_group_flag\":\"1\"");
        strcpy(v6, ",\"pppoe_group_flag\":\"1\"");
        v7 = v5 + 52;
        if ( !strcmp(v3, "1") )
        {
          memset(v21, 0, sizeof(v21));
          dual_lan_get_lan_showname(v21, 2048);
          v16 = (const char *)jhl_nv_get_def("pppoesrv_iface_en");
          v17 = (const char *)jhl_nv_get_def("pppoesrv_iface_list");
          v8 = v7
             + sprintf(
                 &v4[v7],
                 ",\"iface_show\":\"1\",\"lan_list\":\"%s\",\"iface_en\":\"%s\",\"iface_list\":\"%s\"",
                 v21,
                 v16,
                 v17);
        }
        else
        {
          strcpy(&v4[v7], ",\"iface_show\":\"0\"");
          qmemcpy(&v4[v7], ",\"iface_show", 12);
          v8 = v5 + 69;
        }
        strcpy(&v4[v8], ",\"chap2_show\":\"1\"");
        qmemcpy(&v4[v8], ",\"chap2_show\":\"1", 16);
        v9 = &v4[v8 + 17];
        strcpy(v9, ",\"ipv6_show\":\"1\"");
        *((_DWORD *)v9 + 3) = *(_DWORD *)":\"1\"";
        v10 = lan_name_get2("ipv6.lan", 0, "pppsrv", 0);
        v12 = v8 + 33;
        v11 = (const char *)nvram_get(v10);
        if ( !v11 )
          v11 = "";
        v13 = v12 + sprintf(&v4[v12], ",\"stipv6\":\"%s\"", v11);
        v14 = snprintf(&v4[v13], 5120 - v13, "}}");
        if ( v14 >= 5120 - v13 )
          v14 = 5119 - v13;
        return httpd_cgi_ret(a1, v4, v14 + v13, 8);
      }
LABEL_41:
      v22[15] = (int)"0";
      goto LABEL_18;
    }
LABEL_40:
    v22[14] = (int)&off_63F984;
    if ( v22[15] )
      goto LABEL_18;
    goto LABEL_41;
  }
  v18 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 5120);
  v19 = snprintf(v21, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v18);
  if ( v19 >= 0x100 )
    v19 = 255;
  return httpd_cgi_ret(a1, v21, v19, 4);
}
// 497604: variable 'v2' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8434: using guessed type int __fastcall dual_lan_get_lan_showname(_DWORD, _DWORD);
// 6A84C4: using guessed type int __fastcall lan_name_get2(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

