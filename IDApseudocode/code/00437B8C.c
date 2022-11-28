int __fastcall sub_437B8C(int a1)
{
  _DWORD *v1; // $v0
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $s1
  _DWORD *v5; // $s5
  const char *v6; // $v0
  int v7; // $v0
  int v8; // $a0
  int v9; // $s0
  _DWORD *v10; // $fp
  int v11; // $s2
  int v12; // $s3
  _BOOL4 v13; // $v0
  uint32_t v14; // $a0
  int v15; // $v0
  int v16; // $v0
  int v17; // $v0
  int v18; // $s0
  _BYTE *v19; // $v0
  char *v20; // $a0
  const char *v21; // $t0
  int v22; // $t2
  char *v23; // $a0
  int v24; // $s2
  int v25; // $v0
  int v26; // $t1
  int v27; // $v0
  int v28; // $s0
  int v29; // $v0
  int v30; // $s0
  int v31; // $v0
  int v32; // $s0
  int v33; // $v0
  int v34; // $s4
  int v35; // $s2
  int v36; // $v0
  bool v37; // dc
  int v38; // $s2
  int v39; // $v0
  int v40; // $s0
  int v41; // $v0
  int v42; // $s4
  int v43; // $v0
  int v44; // $s0
  int v45; // $s4
  int v46; // $v0
  int v47; // $s4
  int v48; // $v0
  int v49; // $s2
  int v50; // $v0
  int v51; // $s2
  int v52; // $v0
  int v53; // $s2
  char *v54; // $a0
  int v55; // $v0
  int v56; // $s0
  int v57; // $v0
  unsigned int v59; // $v0
  int v60; // $a1
  const char *v61; // $a3
  const char *v62; // $v0
  unsigned int v63; // $a2
  const char *v64; // $v0
  int v65; // $s0
  int v66; // $a2
  char v67[1024]; // [sp+60h] [-8D0h] BYREF
  char v68[1024]; // [sp+460h] [-4D0h] BYREF
  char v69[128]; // [sp+860h] [-D0h] BYREF
  char v70[20]; // [sp+8E0h] [-50h] BYREF
  const char *v71; // [sp+8F4h] [-3Ch] BYREF
  int v72; // [sp+8F8h] [-38h]
  int v73; // [sp+8FCh] [-34h]
  int v74; // [sp+900h] [-30h] BYREF
  __int16 v75; // [sp+904h] [-2Ch]
  uint32_t v76; // [sp+908h] [-28h]
  char *v77; // [sp+90Ch] [-24h]
  int v78; // [sp+910h] [-20h]
  char *v79; // [sp+914h] [-1Ch]
  char *format; // [sp+918h] [-18h]
  char *v81; // [sp+91Ch] [-14h]
  char *v82; // [sp+920h] [-10h]
  const char *v83; // [sp+924h] [-Ch]
  char *v84; // [sp+928h] [-8h]

  v74 = 0;
  v75 = 0;
  memset(v68, 0, sizeof(v68));
  memset(v67, 0, sizeof(v67));
  v84 = "a";
  v78 = ai_hi_mem_json_get();
  _mem_malloc(0x200000, "hilist_data", 839);
  v4 = v3;
  _mem_malloc(0x100000, "hilist_data", 840);
  v5 = v1;
  if ( !v4 || !v1 )
  {
    _mem_free(v4);
    _mem_free(v5);
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      strcpy(v69, "{\"err\":\"mem_malloc err\"}");
      v63 = 24;
    }
    else
    {
      v62 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
      v63 = snprintf(v69, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v62);
      if ( v63 >= 0x80 )
        return httpd_cgi_ret(a1, v69, 127, 4);
    }
    return httpd_cgi_ret(a1, v69, v63, 4);
  }
  *v1 = 13;
  v1[3] = 72;
  v1[1] = 0x100000;
  if ( !jianhl_order_opt_fun(v1, 0x100000, v2) )
  {
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      *(_WORD *)v4 = 91;
      v8 = v5[5];
      v10 = v5 + 6;
      if ( v8 > 0 )
      {
        v11 = 0x1FFFFF;
        v9 = 1;
LABEL_9:
        v12 = 1;
        v81 = "a";
        v83 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
        format = "{\"no\":%d,\"ip\":%u,\"ip6\":\"%s\",\"mac\":\"%s\",\"ctm\":%lu,\"ct\":%lu,\"ctt\":%lu,\"ctu\":%lu,\"cti"
                 "\":%lu,\"cto\":%lu,\"zup\":%llu,\"zdw\":%llu,\"up\":%lu,\"qup\":%lu,\"auth_tm\":%lu,";
        v79 = "%s";
        v82 = "\"dw\":%lu,\"qdw\":%lu,\"n_user\":\"%s\",\"n_user2\":\"%s\",\"n_name\":\"%s\",\"n_phone\":\"%s\",\"thd\":%"
              "d,\"block\":%d,\"thd_enable\":%d,\"t_init\":%d,\"rzgl\":%d,\"tas\":%d,\"mrid\":%d";
        while ( 1 )
        {
          v13 = v12 < v8;
          if ( !*((_BYTE *)v10 + 1031) )
            break;
LABEL_47:
          v10 += 268;
          if ( v13 )
          {
            v11 = 0x200000 - v9;
            ++v12;
            if ( 0x200000 - v9 >= 200 )
              continue;
          }
          goto LABEL_49;
        }
        v76 = (uint32_t)v10 + 78;
        if ( !memcmp((char *)v10 + 78, &v74, 6u) )
          MacToStr(v70, v10 + 18);
        else
          MacToStr(v70, v76);
        v14 = v10[8];
        v77 = &v4[v9];
        v76 = ntohl(v14);
        v15 = IpaddrToStr(v69, v10 + 7);
        v16 = snprintf(v77, v11, format, v12, v76, v15, v70, v10[1], v10[25], v10[30], v10[35], v10[40], v10[45]);
        if ( v16 >= v11 )
          v16 = 0x1FFFFF - v9;
        v18 = v16 + v9;
        v17 = get_json_data(v10 + 68);
        snprintf(v68, 1024, v79, v17);
        memset(v67, 0, sizeof(v67));
        split_string2(v68, v81 + 9684, &v71, 3);
        if ( !v71 )
          v71 = v83 - 1556;
        v19 = (_BYTE *)GetJSONItemValueAsString(v78, v70);
        v20 = v67;
        if ( *v19 )
        {
          v59 = snprintf(v67, 1024, v79, v19);
          if ( v59 >= 0x400 )
            v59 = 1023;
          v21 = v71;
          v20 = &v67[v59];
          if ( !*v71 )
            goto LABEL_19;
          v60 = 1024 - v59;
          if ( v59 )
          {
            v61 = " ";
            goto LABEL_67;
          }
        }
        else
        {
          v21 = v71;
          if ( !*v71 )
          {
LABEL_19:
            v22 = v10[6];
            v23 = &v4[v18];
            v24 = 0x200000 - v18;
            goto LABEL_20;
          }
          v60 = 1024;
        }
        v61 = v83 - 1556;
LABEL_67:
        snprintf(v20, v60, "%s%s", v61, v21);
        v21 = v71;
        v23 = &v4[v18];
        v22 = v10[6];
        v24 = 0x200000 - v18;
        if ( !v71 )
        {
          v21 = v83 - 1556;
          v25 = v72;
          if ( v72 )
          {
LABEL_21:
            v26 = v73;
            if ( v73 )
              goto LABEL_22;
LABEL_70:
            v26 = (int)(v83 - 1556);
LABEL_22:
            v27 = snprintf(
                    v23,
                    v24,
                    v82,
                    v22,
                    v22,
                    v67,
                    v21,
                    v25,
                    v26,
                    *((unsigned __int8 *)v10 + 85),
                    *((unsigned __int8 *)v10 + 84),
                    0,
                    *((unsigned __int8 *)v10 + 400),
                    *((unsigned __int8 *)v10 + 401),
                    *((unsigned __int8 *)v10 + 402),
                    *((unsigned __int16 *)v10 + 48));
            if ( v27 >= v24 )
              v27 = 0x1FFFFF - v18;
            v28 = v27 + v18;
            v29 = snprintf(&v4[v28], 0x200000 - v28, ",\"dnsmore\":\"%s\"", (const char *)v10 + 836);
            if ( v29 >= 0x200000 - v28 )
              v29 = 0x1FFFFF - v28;
            v30 = v29 + v28;
            v31 = snprintf(&v4[v30], 0x200000 - v30, ",\"device_type\":\"%d\"", *((unsigned __int8 *)v10 + 868));
            if ( v31 >= 0x200000 - v30 )
              v31 = 0x1FFFFF - v30;
            v32 = v31 + v30;
            v33 = snprintf(&v4[v32], 0x200000 - v32, ",\"dtype\":\"%d\"", *((unsigned __int8 *)v10 + 904));
            if ( v33 >= 0x200000 - v32 )
              v33 = 0x1FFFFF - v32;
            v34 = v33 + v32;
            v35 = 0x200000 - (v33 + v32);
            v36 = snprintf(&v4[v33 + v32], v35, ",\"os\":\"%d\"", v10[225]);
            v37 = v36 < v35;
            v38 = v36 + v34;
            if ( !v37 )
              v38 = 0x1FFFFF;
            v39 = snprintf(&v4[v38], 0x200000 - v38, ",\"tmp_spd\":\"%d|%d\"", v10[16], v10[17]);
            if ( v39 >= 0x200000 - v38 )
              v39 = 0x1FFFFF - v38;
            v40 = v39 + v38;
            v41 = snprintf(
                    &v4[v39 + v38],
                    0x200000 - (v39 + v38),
                    ",\"wififlag\":%d,\"flag_5g\":%d",
                    *((unsigned __int8 *)v10 + 91),
                    *((unsigned __int8 *)v10 + 92));
            if ( v41 >= 0x200000 - v40 )
              v41 = 0x1FFFFF - v40;
            v42 = v41 + v40;
            v43 = snprintf(
                    &v4[v41 + v40],
                    0x200000 - (v41 + v40),
                    ",\"shenji_account\":\"%s\"",
                    (const char *)v10 + 908);
            if ( v43 >= 0x200000 - v42 )
              v43 = 0x1FFFFF - v42;
            v44 = v43 + v42;
            v45 = 0x200000 - (v43 + v42);
            v46 = snprintf(&v4[v44], v45, ",\"auth_type\":\"%d\"", *((unsigned __int8 *)v10 + 905));
            v37 = v46 < v45;
            v47 = v46 + v44;
            if ( !v37 )
              v47 = 0x1FFFFF;
            v48 = snprintf(&v4[v47], 0x200000 - v47, ",\"host_wan_id\":%u", *((unsigned __int16 *)v10 + 453));
            if ( v48 >= 0x200000 - v47 )
              v48 = 0x1FFFFF - v47;
            v49 = v48 + v47;
            if ( *((_WORD *)v10 + 509) )
            {
              v50 = snprintf(
                      &v4[v49],
                      0x200000 - v49,
                      ",\"vlanid\":\"%d.%d\"",
                      *((unsigned __int16 *)v10 + 49),
                      *((unsigned __int16 *)v10 + 509));
              if ( v50 < 0x200000 - v49 )
              {
LABEL_44:
                v51 = v50 + v49;
                v52 = snprintf(&v4[v51], 0x200000 - v51, &byte_65078C);
                if ( v52 >= 0x200000 - v51 )
                  v52 = 0x1FFFFF - v51;
                v8 = v5[5];
                v9 = v51 + v52;
                v13 = v12 < v8;
                goto LABEL_47;
              }
            }
            else
            {
              v50 = snprintf(&v4[v49], 0x200000 - v49, ",\"vlanid\":\"%d\"", *((unsigned __int16 *)v10 + 49));
              if ( v50 < 0x200000 - v49 )
                goto LABEL_44;
            }
            v50 = 0x1FFFFF - v49;
            goto LABEL_44;
          }
LABEL_69:
          v26 = v73;
          v25 = (int)(v83 - 1556);
          if ( v73 )
            goto LABEL_22;
          goto LABEL_70;
        }
LABEL_20:
        v25 = v72;
        if ( v72 )
          goto LABEL_21;
        goto LABEL_69;
      }
      _mem_free(v5);
      v53 = 1;
      v9 = 1;
    }
    else
    {
      strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
      qmemcpy(v4, "{\"code\":0,\"error\":\"\"", 20);
      *((_DWORD *)v4 + 6) = 975331700;
      v6 = (const char *)IpaddrToStr(v69, a1 + 205460);
      v7 = snprintf(v4 + 29, 2097123, "\"selfip\":\"%s\",\"list\":[", v6);
      if ( v7 >= 2097123 )
        v7 = 2097122;
      v8 = v5[5];
      v9 = v7 + 29;
      v10 = v5 + 6;
      if ( v8 > 0 )
      {
        v11 = 0x200000 - v9;
        if ( 0x200000 - v9 >= 200 )
          goto LABEL_9;
      }
LABEL_49:
      _mem_free(v5);
      v53 = v9;
      if ( v9 <= 0 )
        goto LABEL_77;
    }
    v54 = &v4[v53];
    if ( v4[v53 - 1] != 44 )
    {
LABEL_51:
      *v54 = 0;
      v55 = snprintf(v54, 0x200000 - v9, &byte_6445A0);
      if ( v55 >= 0x200000 - v9 )
        v55 = 0x1FFFFF - v9;
      v56 = v9 + v55;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
      {
        v57 = snprintf(&v4[v56], 0x200000 - v56, "}}");
        if ( v57 >= 0x200000 - v56 )
          v57 = 0x1FFFFF - v56;
        v56 += v57;
      }
      cJSON_Delete(v78);
      return jhl_data_giz(a1, v4, v56, 0x200000);
    }
    --v9;
LABEL_77:
    v54 = &v4[v9];
    goto LABEL_51;
  }
  v64 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
  v65 = snprintf(v4, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v64);
  _mem_free(v5);
  cJSON_Delete(v78);
  v66 = v65;
  if ( v65 >= 0x200000 )
    v66 = 0x1FFFFF;
  return httpd_cgi_ret(a1, v4, v66, 8);
}
// 437C58: variable 'v3' is possibly undefined
// 437C64: variable 'v1' is possibly undefined
// 437C8C: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 65078C: using guessed type char byte_65078C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A8834: using guessed type int __fastcall split_string2(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A887C: using guessed type int __fastcall GetJSONItemValueAsString(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A8938: using guessed type int ai_hi_mem_json_get(void);

