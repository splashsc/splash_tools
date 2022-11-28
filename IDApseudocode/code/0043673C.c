bool __fastcall sub_43673C(int a1)
{
  _BYTE *v2; // $v0
  _BOOL4 v3; // $s2
  _BYTE *v4; // $v0
  int v5; // $s1
  int v7[6]; // [sp+18h] [-18h] BYREF

  v2 = (_BYTE *)jhl_nv_get_def("router_domain");
  if ( v2 && *v2 )
    dns_url_del(v2);
  v3 = jhl_web_save_parms(a1, base_ident_nvarms, 1) != 0;
  if ( nvram_get_int("billing_en") == 1 && nvram_get_int("mqtt_cbg_settlement_mode") == 1 )
  {
    nvram_reset_def("router_domain");
    puts("billing enabled and settlement_mode is 1, can not modify router domain");
  }
  v4 = (_BYTE *)jhl_nv_get_def("router_domain");
  v5 = (int)v4;
  if ( v4 && *v4 )
    dns_url_add(v4, 0, 1);
  v7[0] = (int)"wys";
  v7[1] = (int)"router_domain";
  v7[3] = v5;
  v7[2] = (int)"set";
  v7[4] = 0;
  eval(v7, 0, 0, 0);
  return v3;
}
// 66D240: using guessed type char *base_ident_nvarms[5];
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E0: using guessed type int __fastcall nvram_reset_def(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8548: using guessed type int __fastcall dns_url_add(_DWORD, _DWORD, _DWORD);
// 6A8884: using guessed type int __fastcall dns_url_del(_DWORD);

