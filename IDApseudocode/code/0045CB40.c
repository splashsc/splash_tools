int __fastcall sub_45CB40(int a1)
{
  _DWORD *v1; // $v0
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $s0
  _DWORD *v5; // $s2
  int v6; // $a1
  int v7; // $a2
  int v8; // $a0
  const char *v9; // $v0
  unsigned int v10; // $s1
  const char *v12; // $v0
  int v13; // $fp
  unsigned __int8 *v14; // $s6
  int v15; // $s1
  int v16; // $v0
  int v17; // $v0
  unsigned __int8 *v18; // $s4
  int v19; // $v0
  int v20; // $v0
  int v21; // $s4
  int v22; // $v0
  char *v23; // $v0
  int v24; // $s1
  int v25; // $s1
  int v26; // $v0
  int v27; // $s1
  const char *v28; // $v0
  int v29; // [sp+10h] [-260h]
  int v30; // [sp+14h] [-25Ch]
  __int16 v31[256]; // [sp+38h] [-238h] BYREF
  char v32[32]; // [sp+238h] [-38h] BYREF
  uint32_t v33; // [sp+258h] [-18h]
  int v34; // [sp+25Ch] [-14h]
  char *v35; // [sp+260h] [-10h]
  int v36; // [sp+264h] [-Ch]
  char *format; // [sp+268h] [-8h]
  char *v38; // [sp+26Ch] [-4h]

  v38 = "a";
  _mem_malloc(0x200000, "arp_list_data", 63);
  v4 = v3;
  _mem_malloc(0x100000, "arp_list_data", 64);
  v5 = v1;
  if ( !v4 )
  {
    v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v10 = snprintf((char *)v31, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
    if ( v10 >= 0x100 )
      v10 = 255;
    goto LABEL_8;
  }
  if ( !v1 )
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 0x200000;
    v8 = 4;
    goto LABEL_5;
  }
  *v1 = 3;
  v1[3] = 9;
  v1[1] = 0x100000;
  if ( jianhl_order_opt_fun(v1, 0x100000, v2) )
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = (int)"";
    v8 = 3;
LABEL_5:
    v9 = (const char *)_GET_LANG_TEXT(v8, v6, v7);
    v10 = snprintf((char *)v31, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    _mem_free(v4);
LABEL_8:
    if ( v5 )
      _mem_free(v5);
    return httpd_cgi_ret(a1, (char *)v31, v10, 4);
  }
  v12 = (const char *)nvram_get("lan_ifname");
  if ( !v12 || !*v12 )
    v12 = "br0";
  strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy(v4, "{\"code\":0,\"error", 16);
  v13 = sprintf(v4 + 29, "\"lan_ifname\":\"%s\",\"data\":[", v12) + 29;
  if ( (int)v5[5] > 0 )
  {
    v14 = (unsigned __int8 *)v5 + 42;
    if ( 0x200000 - v13 >= 100 )
    {
      v35 = "a";
      v36 = a1 + 196608;
      v15 = 0;
      format = "%s";
      while ( 1 )
      {
        v20 = *(_DWORD *)(v14 + 30);
        if ( (v20 & 1) != 0 )
          break;
        if ( (v20 & 2) != 0 )
        {
          v30 = v14[3];
          v29 = v14[2];
          v16 = _GET_LANG_TEXT(15, *(unsigned __int8 *)(v36 + 13494), *v14);
          goto LABEL_18;
        }
        v31[0] = 32;
        v17 = *(_DWORD *)(v14 + 6);
        v18 = v14 + 10;
        if ( v17 != 2 )
        {
LABEL_19:
          if ( v17 == 4 )
          {
            v34 = 2;
          }
          else if ( v17 == 3 )
          {
            v34 = 3;
          }
          else
          {
            v34 = 0;
          }
          goto LABEL_22;
        }
LABEL_27:
        v34 = 1;
LABEL_22:
        v33 = ntohl(*(_DWORD *)(v14 - 18));
        v19 = MacToStr(v32, v14 - 6);
        v13 += sprintf(&v4[v13], v35 + 25472, ++v15, v33, v19, v34, v18, v31, *(_DWORD *)(v14 + 26), v14 + 34, 0);
        if ( v15 < v5[5] )
        {
          v14 += 96;
          if ( 0x200000 - v13 >= 100 )
            continue;
        }
        --v13;
        goto LABEL_32;
      }
      v21 = *(unsigned __int8 *)(v36 + 13494);
      v22 = MacToStr(v32, v14);
      v16 = _GET_LANG_TEXT(14, v21, v22);
LABEL_18:
      snprintf((char *)v31, 512, format, v16, v29, v30);
      v17 = *(_DWORD *)(v14 + 6);
      v18 = v14 + 10;
      if ( v17 != 2 )
        goto LABEL_19;
      goto LABEL_27;
    }
  }
LABEL_32:
  v23 = &v4[v13];
  strcpy(&v4[v13], "],\"wans\":");
  *(_DWORD *)v23 = 1998728285;
  *((_DWORD *)v23 + 1) = 577990241;
  v24 = v13 + 9 + get_wans_data(&v4[v13 + 9], 0x200000 - (v13 + 9));
  strcpy(&v4[v24], ",\"noauth\":\"0\"");
  qmemcpy(&v4[v24], ",\"noauth\":\"0", 12);
  v25 = v24 + 13;
  v26 = snprintf(&v4[v25], 0x200000 - v25, "}}");
  if ( v26 >= 0x200000 - v25 )
    v26 = 0x1FFFFF - v25;
  v27 = v26 + v25;
  _mem_free(v5);
  return httpd_cgi_ret(a1, v4, v27, 8);
}
// 45CBB8: variable 'v3' is possibly undefined
// 45CBC4: variable 'v1' is possibly undefined
// 45CBEC: variable 'v2' is possibly undefined
// 45CE3C: variable 'v29' is possibly undefined
// 45CE3C: variable 'v30' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6463E0: using guessed type int dword_6463E0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

