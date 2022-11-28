int __fastcall jhl_nat_onebyone_add_iface(int a1, int a2)
{
  int v4; // $v0
  int v5; // $v0
  char *v6; // $s3
  int v7; // $v0
  char *v8; // $s1
  int v9; // $s2
  int v11; // $v0
  const char *v12; // $v0
  int v13; // $v0
  int v14; // $v0
  char v15[256]; // [sp+18h] [-124h] BYREF
  int v16[9]; // [sp+118h] [-24h] BYREF

  memset(v15, 0, sizeof(v15));
  v4 = jhl_nvget("wan_ifname", a1);
  v5 = nvram_get(v4);
  if ( v5 )
    v6 = (char *)v5;
  else
    v6 = "";
  v7 = jhl_nvget("wan_name", a1);
  v8 = (char *)nvram_get(v7);
  if ( !v8 )
    v8 = "";
  v9 = get_duolan_ip(0, 0, a2, 0);
  if ( v9 )
    return -1;
  if ( *v8 )
  {
    if ( *v6 )
    {
      v11 = jhl_nvget("wan_down", a1);
      v12 = (const char *)nvram_get(v11);
      if ( (!v12 || strcmp(v12, "1"))
        && !jhl_iface_link_up_check(v6, a1)
        && (jhl_get_wan_proto(a1) & 0xFFFFFFF7) != 0
        && jhl_check_wanup(a1) )
      {
        v13 = jhl_nvget("wan_netmask", a1);
        v9 = 0;
        v14 = jhl_nv_get_def(v13);
        ip_get_duolan(a2, v14, v15);
        v16[0] = (int)"ip";
        v16[1] = (int)"addr";
        v16[2] = (int)&off_646D8C;
        v16[3] = (int)v15;
        v16[4] = (int)"dev";
        v16[5] = (int)v8;
        v16[6] = 0;
        eval(v16, 0, 0, 0);
      }
    }
  }
  return v9;
}
// 646D8C: using guessed type char *off_646D8C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A8558: using guessed type int __fastcall get_duolan_ip(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A881C: using guessed type int __fastcall ip_get_duolan(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

