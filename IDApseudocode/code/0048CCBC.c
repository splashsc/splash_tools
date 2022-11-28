int __fastcall sub_48CCBC(int a1)
{
  char *v2; // $s2
  char *v3; // $s4
  char *v4; // $s7
  char *v5; // $s5
  int v6; // $s3
  _BYTE *v7; // $v0
  _BYTE *v8; // $s1
  _DWORD *v9; // $s5
  int v10; // $v0
  int v11; // $a0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  int v18; // $s6
  int v20; // $a1
  const char *v21; // $a2
  const char *v22; // $v0
  bool v23; // dc
  char *v24; // $v0
  int v25; // $v0
  const char *v26; // $a2
  int v27; // $v0
  char *v28; // $v0
  const char *v29; // $v0
  const char *v30; // $v0
  const char *v31; // $v0
  unsigned int v32; // $v0
  char s[1024]; // [sp+28h] [-618h] BYREF
  int v34[64]; // [sp+428h] [-218h] BYREF
  int v35[25]; // [sp+528h] [-118h] BYREF
  char *v36; // [sp+58Ch] [-B4h]
  char *v37; // [sp+590h] [-B0h]
  char *v38; // [sp+594h] [-ACh]
  char *v39; // [sp+598h] [-A8h]
  char *v40; // [sp+59Ch] [-A4h]
  int v41[9]; // [sp+5A8h] [-98h] BYREF
  char *v42; // [sp+5CCh] [-74h]
  char *v43; // [sp+5D0h] [-70h]
  char *v44; // [sp+5D4h] [-6Ch]
  char *v45; // [sp+5D8h] [-68h]
  char *v46; // [sp+5DCh] [-64h]
  char *v47; // [sp+5E0h] [-60h]
  char *v48; // [sp+5E4h] [-5Ch]
  char *v49; // [sp+5E8h] [-58h]
  char *v50; // [sp+5ECh] [-54h]
  char *v51; // [sp+5F0h] [-50h]
  char *v52; // [sp+5F4h] [-4Ch]
  char *v53; // [sp+5F8h] [-48h]
  char *v54; // [sp+5FCh] [-44h]
  char *v55; // [sp+600h] [-40h]
  char *v56; // [sp+604h] [-3Ch]
  char *v57; // [sp+608h] [-38h]
  char *v58; // [sp+60Ch] [-34h]
  char *v59; // [sp+610h] [-30h]
  char *v60; // [sp+614h] [-2Ch]
  char *v61; // [sp+618h] [-28h]
  char *v62; // [sp+61Ch] [-24h]
  char *v63; // [sp+620h] [-20h]
  char *v64; // [sp+624h] [-1Ch]
  char *v65; // [sp+628h] [-18h]
  char *v66; // [sp+62Ch] [-14h]
  char *v67; // [sp+630h] [-10h]
  char *v68; // [sp+634h] [-Ch]
  char *v69; // [sp+638h] [-8h]
  const char *v70; // [sp+63Ch] [-4h]

  v2 = httpd_get_parm(a1, "opt");
  v3 = httpd_get_parm(a1, "name");
  v47 = httpd_get_parm(a1, "old_name");
  v53 = httpd_get_parm(a1, "auto");
  v54 = httpd_get_parm(a1, "wans");
  v42 = httpd_get_parm(a1, "host_ip");
  v43 = httpd_get_parm(a1, "host_mask");
  v4 = httpd_get_parm(a1, "ipsec_ip");
  v44 = httpd_get_parm(a1, "remot_ip");
  v45 = httpd_get_parm(a1, "remot_mask");
  v55 = httpd_get_parm(a1, "ike_type");
  v56 = httpd_get_parm(a1, "psk_key");
  v5 = httpd_get_parm(a1, "enable");
  v57 = httpd_get_parm(a1, "ike_dh_group");
  v58 = httpd_get_parm(a1, "ike_encrypt");
  v59 = httpd_get_parm(a1, "ike_auth");
  v60 = httpd_get_parm(a1, "ike_lifetime");
  v61 = httpd_get_parm(a1, "ike_pfs_group");
  v62 = httpd_get_parm(a1, "ipsec_encrypt");
  v63 = httpd_get_parm(a1, "ipsec_auth");
  v64 = httpd_get_parm(a1, "ipsec_lifetime");
  v65 = httpd_get_parm(a1, "ip_compress");
  v66 = httpd_get_parm(a1, "ike_pfs");
  v67 = httpd_get_parm(a1, "dpd_time");
  v68 = httpd_get_parm(a1, "dpd_latertime");
  v69 = httpd_get_parm(a1, "exchange_mode");
  v6 = httpd_get_json_parm(a1, (int)"del_list");
  v48 = httpd_get_parm(a1, "remot_ident");
  v49 = httpd_get_parm(a1, "remot_ident_type");
  v50 = httpd_get_parm(a1, "local_ident");
  v51 = httpd_get_parm(a1, "local_ident_type");
  if ( !v48 || !v50 )
  {
    v51 = "";
    v49 = "";
    v50 = "0";
    v48 = "0";
  }
  v41[8] = (int)"1\"";
  v52 = httpd_get_parm(a1, "ping_en");
  _mem_malloc(76800, "ipsec_net_asp", 689);
  v8 = v7;
  if ( v7 )
  {
    if ( v2 )
    {
      v46 = "a";
      if ( !strcmp(v2, (const char *)&off_646D8C) || !strcmp(v2, (const char *)&off_648DDC) || !strcmp(v2, "del") )
      {
        if ( !v4 || *v4 )
        {
          if ( strcmp(v2, "enable") )
          {
LABEL_13:
            if ( !strcmp(v2, "del") )
            {
              if ( v6 )
              {
                v9 = *(_DWORD **)(v6 + 8);
                if ( v9 )
                {
                  if ( v9[4] )
                  {
                    v70 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
                    do
                    {
                      *(_WORD *)v8 = 32;
                      v10 = nvram_get("ipsec_net_users");
                      if ( !v10 )
                        v10 = (int)(v70 - 1556);
                      if ( strdb_del(v10) == 1 )
                        nvram_set("ipsec_net_users", v8);
                      v3 = (char *)v9[4];
                      v9 = (_DWORD *)*v9;
                    }
                    while ( v9 && v9[4] );
                  }
                }
              }
            }
            if ( strcmp(v2, (const char *)&off_648DDC) && strcmp(v2, v46 + 28044) )
              goto LABEL_30;
            *v8 = 32;
            v23 = v47 == 0;
            v8[1] = 0;
            if ( !v23 )
            {
              v24 = (char *)nvram_get("ipsec_net_users");
              if ( !v24 )
                v24 = "";
              goto LABEL_42;
            }
            if ( v3 )
            {
              v24 = (char *)nvram_get("ipsec_net_users");
              if ( !v24 )
                v24 = "";
LABEL_42:
              if ( strdb_del(v24) == 1 )
                nvram_set("ipsec_net_users", v8);
              if ( !strcmp(v2, v46 + 28044) )
              {
                v18 = check_rule_num_limit(a1, 20, (int)"ipsec_net_users", 60, s, 0x400u);
                if ( v18 > 0 )
                {
LABEL_35:
                  _mem_free(v8);
                  return httpd_cgi_ret(a1, s, v18, 4);
                }
              }
              else if ( strcmp(v2, (const char *)&off_648DDC) )
              {
LABEL_30:
                jhl_parm_commit(v11);
                if ( !strcmp(v2, "enable") )
                {
                  schedule_ipsec(1, 0);
                }
                else
                {
                  v29 = (const char *)nvram_get("ipsec_mode");
                  if ( v29 && !strcmp(v29, "net") )
                  {
                    snprintf((char *)v34, 256, "%s|%s<", v2, v3);
                    schedule_ipsec(0, v34);
                  }
                }
                goto LABEL_32;
              }
              v35[0] = (int)v3;
              v35[1] = (int)v53;
              v35[5] = (int)v4;
              v35[2] = (int)v54;
              v35[3] = (int)v42;
              v35[4] = (int)v43;
              v35[6] = (int)v44;
              v35[7] = (int)v45;
              v35[8] = (int)v55;
              v35[9] = (int)v56;
              v35[12] = (int)v57;
              v35[13] = (int)v58;
              v35[14] = (int)v59;
              v35[15] = (int)v60;
              v35[16] = (int)v61;
              v35[17] = (int)v62;
              v35[18] = (int)v63;
              v35[19] = (int)v64;
              v35[20] = (int)v65;
              v35[21] = (int)v66;
              v35[22] = (int)v67;
              v35[23] = (int)v68;
              v35[24] = (int)v69;
              v39 = v48;
              v40 = v49;
              v37 = v50;
              v38 = v51;
              if ( v52 )
                v36 = v52;
              else
                v36 = "0";
              v25 = mask_addr_to_inet(v43);
              v26 = v42;
              v42 = (char *)v41;
              v41[0] = 0;
              v41[1] = 0;
              v41[2] = 0;
              v41[3] = 0;
              v41[4] = 0;
              v41[5] = 0;
              v41[6] = 0;
              v41[7] = 0;
              v34[0] = 0;
              v34[1] = 0;
              v34[2] = 0;
              v34[3] = 0;
              v34[4] = 0;
              v34[5] = 0;
              v34[6] = 0;
              v34[7] = 0;
              sprintf((char *)v41, "%s/%d", v26, v25);
              v27 = mask_addr_to_inet(v45);
              sprintf((char *)v34, "%s/%d", v44, v27);
              v35[10] = (int)v42;
              v35[11] = (int)v34;
              v28 = (char *)nvram_get("ipsec_net_users");
              if ( !v28 )
                v28 = "";
              if ( strdb_add(v28, v8, v35, 30, 60, 124) > 0 )
                nvram_set("ipsec_net_users", v8);
              goto LABEL_30;
            }
            v20 = *(unsigned __int8 *)(a1 + 210102);
            v21 = (const char *)&unk_6442E4;
LABEL_37:
            v22 = (const char *)_GET_LANG_TEXT(12, v20, v21);
            v18 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
            if ( (unsigned int)v18 >= 0x400 )
              v18 = 1023;
            goto LABEL_35;
          }
LABEL_11:
          nvram_set("ipsec_net_enable", v5);
          if ( !strcmp(v5, "1") )
          {
            nvram_set("ipsec_mode", "net");
            nvram_set("ipsec_road_enable", "0");
            nvram_set("ipsec_l2tp_enable", "0");
            nvram_set("ipsec_l2tp_cli_enable", "0");
          }
          else
          {
            v30 = (const char *)nvram_get("ipsec_mode");
            if ( !v30 || strcmp(v30, "net") )
            {
LABEL_32:
              v12 = s;
              v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
              do
              {
                v14 = *(_DWORD *)v13;
                v15 = *((_DWORD *)v13 + 1);
                v16 = *((_DWORD *)v13 + 2);
                v17 = *((_DWORD *)v13 + 3);
                v13 += 16;
                *(_DWORD *)v12 = v14;
                *((_DWORD *)v12 + 1) = v15;
                *((_DWORD *)v12 + 2) = v16;
                *((_DWORD *)v12 + 3) = v17;
                v12 += 16;
              }
              while ( v13 != "}" );
              v18 = 33;
              *(_WORD *)v12 = *(_WORD *)v13;
              goto LABEL_35;
            }
            nvram_set("ipsec_mode", "none");
          }
          goto LABEL_13;
        }
LABEL_36:
        v20 = *(unsigned __int8 *)(a1 + 210102);
        v21 = (const char *)&unk_64B158;
        goto LABEL_37;
      }
      if ( !strcmp(v2, "enable") )
      {
        if ( !v4 || *v4 )
          goto LABEL_11;
        goto LABEL_36;
      }
    }
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = "not opt";
    goto LABEL_37;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 76800);
  v32 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( v32 >= 0x400 )
    v32 = 1023;
  return httpd_cgi_ret(a1, s, v32, 4);
}
// 48D0BC: variable 'v7' is possibly undefined
// 48D384: variable 'v11' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81D0: using guessed type int __fastcall strdb_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8404: using guessed type int __fastcall strdb_del(_DWORD);
// 6A8724: using guessed type int __fastcall schedule_ipsec(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

