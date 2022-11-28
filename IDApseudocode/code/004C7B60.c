int __fastcall sub_4C7B60(int a1)
{
  int v2; // $v0
  int v3; // $v0
  const char *v4; // $v0
  int v5; // $v0
  int v6; // $v0
  char v8[102400]; // [sp+20h] [-19028h] BYREF
  _DWORD v9[5]; // [sp+19020h] [-28h] BYREF
  char *v10; // [sp+19034h] [-14h] BYREF
  int v11; // [sp+19038h] [-10h]
  int v12; // [sp+1903Ch] [-Ch]
  int v13; // [sp+19040h] [-8h]
  int v14; // [sp+19044h] [-4h]

  memset(v8, 0, sizeof(v8));
  v11 = 102400;
  v10 = v8;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  nvram_set("ipv6_router", "");
  v9[0] = "wys";
  v9[1] = "ipv6";
  v9[2] = "router";
  v9[3] = "info";
  v9[4] = 0;
  eval(v9, 0, 0, 0);
  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v12 = 29;
  mcl_bytearray_printf(&v10, (const char *)&dword_6459A8);
  v12 += get_ipv6_router_data(&v10[v12], v11 - v12);
  mcl_bytearray_printf(&v10, ",\"static\":");
  v12 += get_ipv6_router_static_data(&v10[v12], v11 - v12);
  mcl_bytearray_printf(&v10, (const char *)&dword_64BD3C);
  v12 += asp_activeroutes(&v10[v12], v11 - v12);
  mcl_bytearray_printf(&v10, ",\"lan\":[");
  lan_iface_foreach(&v10, sub_4C5A3C);
  v2 = v12;
  if ( v12 > 0 && v10[v12 - 1] == 44 )
    v2 = --v12;
  v10[v2] = 0;
  mcl_bytearray_printf(&v10, &byte_6445A0);
  mcl_bytearray_printf(&v10, ",\"wan\":[");
  wan_iface_foreach(&v10, sub_4C4F78);
  v3 = v12;
  if ( v12 > 0 && v10[v12 - 1] == 44 )
    v3 = --v12;
  v10[v3] = 0;
  mcl_bytearray_printf(&v10, &byte_6445A0);
  v4 = (const char *)nvram_get("pppoesrv");
  if ( !v4 )
    v4 = "";
  mcl_bytearray_printf(&v10, ",\"tun\":[{\"iface\":\"%u\",\"ifname\":\"%s\",\"showname\":\"%s\"}],", 99, v4, "PPPOE");
  v5 = v12;
  if ( v12 > 0 && v10[v12 - 1] == 44 )
    v5 = --v12;
  v10[v5] = 0;
  v6 = snprintf(&v10[v12], v11 - v12, "}}");
  if ( v6 >= v11 - v12 )
    v6 = v11 - v12 - 1;
  return httpd_cgi_ret(a1, v10, v6 + v12, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6459A8: using guessed type int dword_6459A8;
// 64BD3C: using guessed type int dword_64BD3C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83F0: using guessed type int __fastcall wan_iface_foreach(_DWORD, _DWORD);
// 6A8414: using guessed type int mcl_bytearray_printf(_DWORD, const char *, ...);
// 6A84EC: using guessed type int __fastcall lan_iface_foreach(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

