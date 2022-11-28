int __fastcall sub_43AD7C(int a1)
{
  char *v1; // $v0
  const char *v2; // $s0
  _DWORD *v3; // $v0
  char *v4; // $v0
  char *v5; // $s2
  _DWORD *v6; // $s3
  int v7; // $a2
  unsigned int v8; // $v0
  int v9; // $a1
  bool v10; // dc
  unsigned int v11; // $v0
  char *v12; // $a2
  uint32_t v13; // $v0
  const char *v14; // $v0
  int v15; // $s0
  _DWORD *v17; // $s0
  int v18; // $s7
  int v19; // $s1
  uint32_t v20; // $a0
  uint32_t v21; // $v0
  uint32_t v22; // $a0
  uint32_t v23; // $s5
  int v24; // $v0
  int v25; // $fp
  uint16_t v26; // $a0
  int v27; // $v0
  uint16_t v28; // $a0
  int v29; // $v0
  uint16_t v30; // $a0
  int v31; // $v0
  uint32_t v32; // $v0
  int v33; // $s1
  int v34; // $t6
  int v35; // $t1
  int v36; // $t2
  int v37; // $t3
  int v38; // $t5
  int v39; // $t7
  int v40; // $s5
  int v41; // $v0
  int v42; // $a0
  int v43; // $v0
  char *v44; // $a0
  int v45; // $v0
  int v46; // $s1
  const char *v47; // $v0
  unsigned int v48; // $v0
  const char *v49; // $v0
  char v50[128]; // [sp+48h] [-E0h] BYREF
  char v51[48]; // [sp+C8h] [-60h] BYREF
  int v52; // [sp+F8h] [-30h]
  int v53; // [sp+FCh] [-2Ch]
  int v54; // [sp+100h] [-28h]
  int v55; // [sp+104h] [-24h]
  int v56; // [sp+108h] [-20h]
  int v57; // [sp+10Ch] [-1Ch]
  int v58; // [sp+110h] [-18h]
  int v59; // [sp+114h] [-14h]
  char *v60; // [sp+118h] [-10h]
  char *format; // [sp+11Ch] [-Ch]
  const char *v62; // [sp+120h] [-8h]
  char *v63; // [sp+124h] [-4h]

  v1 = httpd_get_parm(a1, "hi");
  if ( v1 )
  {
    v2 = v1;
    _mem_malloc(0x200000, "hictlistxx2_data", 1847);
    v5 = v4;
    _mem_malloc(0x100000, "hictlistxx2_data", 1848);
    v6 = v3;
    if ( v5 && v3 )
    {
      *v3 = 13;
      v3[3] = 28;
      v3[1] = 0x100000;
      if ( strchr(v2, 46) || strchr(v2, 58) )
      {
        StrToIpaddr(v2, v6 + 9);
      }
      else
      {
        v13 = J_atoi(v2);
        v6[10] = htonl(v13);
      }
      if ( jianhl_order_opt_fun(v6, v6[1], v7) )
      {
        v9 = *(unsigned __int8 *)(a1 + 210102);
        v12 = "";
        goto LABEL_15;
      }
      v8 = v6[2];
      if ( v8 )
      {
        if ( v8 == 3 )
        {
          v49 = (const char *)_GET_LANG_TEXT(16, *(unsigned __int8 *)(a1 + 210102), "");
          v15 = snprintf(v50, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v49);
          if ( (unsigned int)v15 >= 0x80 )
            v15 = 127;
          goto LABEL_17;
        }
        v9 = *(unsigned __int8 *)(a1 + 210102);
        v10 = v8 >= 0x33;
        v11 = v8;
        if ( v10 || (v12 = (char *)jhlret_err_str[v11]) == 0 )
          v12 = "not find err!";
LABEL_15:
        v14 = (const char *)_GET_LANG_TEXT(3, v9, v12);
        v15 = snprintf(v5, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
        if ( v15 >= 0x200000 )
          v15 = 0x1FFFFF;
LABEL_17:
        _mem_free(v6);
        return httpd_cgi_ret(a1, v5, v15, 8);
      }
      strcpy(v5, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy(v5, "{\"code\":0,\"error", 16);
      v17 = v6 + 6;
      if ( (int)v6[5] <= 0 )
      {
        v43 = 28;
        v42 = 29;
        v19 = 29;
      }
      else
      {
        v60 = v50;
        format = "{\"mid\":%d,\"nip\":%u,\"fip\":%u,\"nip6\":\"%s\",\"fip6\":\"%s\",\"iport\":%u,\"nport\":%u,\"fport\":%"
                 "u,\"prot\":%d,\"dir\":%d,\"tm\":%u,\"act\":%d,\"ptr\":%lu,";
        v18 = 0;
        v62 = "mr_ct_rule_name";
        v19 = 29;
        v63 = "\"id\":\"%08X\",\"z0\":%u,\"z1\":%u,\"pri0\":%d,\"pri1\":%d,\"n\":\"%s\",\"prif\":%d,\"clt\":%d,\"flag\":%"
              "lu,\"dns\":\"%s\",\"mr_rule\":\"%s\",\"sb_re\":\"%d\",\"show_mr\":\"%d\"},";
        do
        {
          v20 = v17[4];
          v56 = *((unsigned __int16 *)v17 + 29);
          v21 = ntohl(v20);
          v22 = v17[9];
          v55 = v21;
          v23 = ntohl(v22);
          v25 = IpaddrToStr(v51, v17 + 3);
          v24 = IpaddrToStr(v60, v17 + 8);
          v26 = *((_WORD *)v17 + 28);
          v54 = v24;
          v27 = ntohs(v26);
          v28 = *((_WORD *)v17 + 26);
          v53 = v27;
          v29 = ntohs(v28);
          v30 = *((_WORD *)v17 + 27);
          v52 = v29;
          v31 = ntohs(v30);
          v33 = sprintf(
                  &v5[v19],
                  format,
                  v56,
                  v55,
                  v23,
                  v25,
                  v54,
                  v53,
                  v52,
                  v31,
                  *((unsigned __int8 *)v17 + 60),
                  *((unsigned __int8 *)v17 + 61),
                  v17[2],
                  *((unsigned __int8 *)v17 + 64),
                  *v17)
              + v19;
          v32 = ntohl(v17[17]);
          v34 = v17[66];
          v35 = *((unsigned __int8 *)v17 + 62);
          v36 = *((unsigned __int8 *)v17 + 63);
          v37 = *((unsigned __int8 *)v17 + 65);
          v38 = *((unsigned __int8 *)v17 + 66);
          v39 = *((unsigned __int8 *)v17 + 67);
          v59 = v17[26];
          v58 = v34;
          v57 = v35;
          v56 = v36;
          v55 = v37;
          v54 = v38;
          v53 = v39;
          v52 = v32;
          v40 = v17[27];
          v41 = nvram_get_int(v62);
          ++v18;
          v19 = v33
              + sprintf(&v5[v33], v63, v52, v59, v40, v57, v56, v17 + 18, v55, v54, v58, v17 + 34, v17 + 50, v53, v41);
          v17 += 67;
        }
        while ( v18 < v6[5] && 0x200000 - v19 >= 500 );
        v42 = v19;
        if ( v19 <= 0 )
        {
LABEL_28:
          v44 = &v5[v42];
          *v44 = 0;
          v45 = snprintf(v44, 0x200000 - v19, "]}");
          if ( v45 >= 0x200000 - v19 )
            v45 = 0x1FFFFF - v19;
          v46 = v19 + v45;
          _mem_free(v6);
          return jhl_data_giz(a1, v5, v46, 0x200000);
        }
        v43 = v19 - 1;
      }
      if ( v5[v43] == 44 )
        v42 = --v19;
      goto LABEL_28;
    }
    _mem_free(v5);
    _mem_free(v6);
    v47 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  }
  else
  {
    v47 = (const char *)_GET_LANG_TEXT(16, *(unsigned __int8 *)(a1 + 210102), 1847);
  }
  v60 = v50;
  v48 = snprintf(v50, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v47);
  if ( v48 >= 0x80 )
    v48 = 127;
  return httpd_cgi_ret(a1, v60, v48, 4);
}
// 43AE08: variable 'v4' is possibly undefined
// 43AE14: variable 'v3' is possibly undefined
// 43AE70: variable 'v7' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

