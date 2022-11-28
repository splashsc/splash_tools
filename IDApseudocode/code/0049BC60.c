int __fastcall sub_49BC60(int a1)
{
  int v1; // $v0
  int v2; // $s7
  int v3; // $s6
  int v4; // $s5
  const char *v5; // $v0
  int v6; // $s6
  int v7; // $s5
  const char *v8; // $v0
  int v9; // $s6
  char *v10; // $s1
  int v11; // $s5
  int v12; // $v0
  const char *v13; // $s1
  const char *v14; // $v0
  int v15; // $v0
  int v16; // $s0
  int v17; // $s1
  int v18; // $v0
  int v19; // $s0
  int v20; // $v0
  int v21; // $s0
  int v22; // $v0
  int v23; // $a2
  int result; // $v0
  const char *v25; // $v0
  unsigned int v26; // $v0
  const char *v27; // $v0
  int v28; // $v0
  const char *v29; // $v0
  char v30[10240]; // [sp+30h] [-7890h] BYREF
  char v31[10240]; // [sp+2830h] [-5090h] BYREF
  char v32[10240]; // [sp+5030h] [-2890h] BYREF
  int v33; // [sp+7830h] [-90h] BYREF
  char v34[12]; // [sp+7834h] [-8Ch] BYREF
  char *format; // [sp+78B0h] [-10h]
  int v36; // [sp+78B4h] [-Ch]
  int v37; // [sp+78B8h] [-8h]

  memset(v32, 0, sizeof(v32));
  memset(v31, 0, sizeof(v31));
  memset(v30, 0, sizeof(v30));
  _mem_malloc(0x200000, "pppoe_br_data", 1275);
  v2 = v1;
  if ( v1 )
  {
    v36 = (int)"a";
    v3 = 2;
    format = "pppoe_br_wan%d";
    v4 = 0;
    v37 = 1869639792;
    while ( v3 == 2 )
    {
      v33 = v37;
      strcpy(v34, "e_br_wan");
      v27 = (const char *)jhl_nv_get_def(&v33);
      v4 += sprintf(&v32[v4], "%s|", v27);
      v3 = 3;
    }
    sprintf((char *)&v33, format, 2);
    v5 = (const char *)jhl_nv_get_def(&v33);
    sprintf(&v32[v4], "%s|", v5);
    format = "pppoe_br_vlan%d";
    v6 = 2;
    v7 = 0;
    v37 = 1869639792;
    while ( v6 == 2 )
    {
      v33 = v37;
      strcpy(v34, "e_br_vlan");
      v29 = (const char *)jhl_nv_get_def(&v33);
      v7 += sprintf(&v31[v7], "%s|", v29);
      v6 = 3;
    }
    sprintf((char *)&v33, format, 2);
    v8 = (const char *)jhl_nv_get_def(&v33);
    sprintf(&v31[v7], "%s|", v8);
    format = "pppoe_br_info%d";
    v9 = 2;
    v10 = (char *)(v36 + 11516);
    v11 = 0;
    v36 = 1869639792;
    while ( v9 == 2 )
    {
      v33 = v36;
      strcpy(v34, "e_br_info");
      v28 = jhl_nv_get_def(&v33);
      v11 += sprintf(&v30[v11], v10, v28);
      v9 = 3;
    }
    sprintf((char *)&v33, format, 2);
    v12 = jhl_nv_get_def(&v33);
    sprintf(&v30[v11], v10, v12);
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v13 = (const char *)jhl_nv_get_def("pppoe_br_enable");
    v14 = (const char *)jhl_nv_get_def("pppoe_br_time");
    v15 = snprintf(
            (char *)(v2 + 29),
            2097123,
            "\"enable\":%s,\"wan_br_iface\":\"%s\",\"wan_br_vlan\":\"%s\",\"wan_br_info\":\"%s\",\"wan_br_time\":\"%s\",\""
            "wan_max\":\"%d\"",
            v13,
            v32,
            v31,
            v30,
            v14,
            2);
    if ( v15 >= 2097123 )
      v15 = 2097122;
    v16 = v15 + 29;
    v17 = 0x200000 - (v15 + 29);
    v18 = snprintf((char *)(v2 + v15 + 29), v17, ",\"state\":[");
    if ( v18 >= v17 )
      v18 = 0x1FFFFF - v16;
    v19 = v18 + v16 + pppoe_br_get_state((char *)(v2 + v18 + v16), 0x200000 - (v18 + v16));
    v20 = snprintf((char *)(v2 + v19), 0x200000 - v19, &byte_6445A0);
    if ( v20 >= 0x200000 - v19 )
      v20 = 0x1FFFFF - v19;
    v21 = v20 + v19;
    v22 = snprintf((char *)(v2 + v21), 0x200000 - v21, "}}");
    if ( v22 >= 0x200000 - v21 )
      v23 = 0x1FFFFF - v21;
    else
      v23 = v22;
    result = httpd_cgi_ret(a1, (char *)v2, v23 + v21, 8);
  }
  else
  {
    v25 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v26 = snprintf((char *)&v33, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
    if ( v26 >= 0x80 )
      v26 = 127;
    result = httpd_cgi_ret(a1, (char *)&v33, v26, 4);
  }
  return result;
}
// 49BDA4: conditional instruction was optimized away because of '$s6.4==3'
// 49BE24: conditional instruction was optimized away because of '$s6.4==3'
// 49BEAC: conditional instruction was optimized away because of '$s6.4==3'
// 49BDA8: ignored the value written to the shadow area of the succeeding call
// 49BE28: ignored the value written to the shadow area of the succeeding call
// 49BD14: variable 'v1' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

