int __fastcall jhl_nat_onebyone_del_iface(int a1, const char *a2)
{
  int v4; // $v0
  int v5; // $v0
  char *v6; // $s4
  int v7; // $v0
  char *v8; // $s0
  int result; // $v0
  int v10; // $v0
  const char *v11; // $v0
  int v12; // $v0
  int v13; // $v0
  const char *v14; // $a1
  int v15; // $v0
  int v16; // $v0
  char v17[256]; // [sp+18h] [-120h] BYREF
  int v18[8]; // [sp+118h] [-20h] BYREF

  memset(v17, 0, sizeof(v17));
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
  result = *v8;
  if ( *v8 )
  {
    result = *v6;
    if ( *v6 )
    {
      v10 = jhl_nvget("wan_down", a1);
      v11 = (const char *)nvram_get(v10);
      if ( !v11 || (result = strcmp(v11, "1")) != 0 )
      {
        result = jhl_iface_link_up_check(v6, a1);
        if ( !result )
        {
          result = jhl_get_wan_proto(a1) & 0xFFFFFFF7;
          if ( result )
          {
            result = jhl_check_wanup(a1);
            if ( result )
            {
              v12 = jhl_nvget("wan_ipaddr", a1);
              v13 = nvram_get(v12);
              if ( v13 )
                v14 = (const char *)v13;
              else
                v14 = "";
              result = strcmp(a2, v14);
              if ( result )
              {
                v15 = jhl_nvget("wan_netmask", a1);
                v16 = jhl_nv_get_def(v15);
                ip_get_duolan(a2, v16, v17);
                v18[0] = (int)"ip";
                v18[1] = (int)"addr";
                v18[2] = (int)"del";
                v18[3] = (int)v17;
                v18[4] = (int)"dev";
                v18[5] = (int)v8;
                v18[6] = 0;
                eval(v18, 0, 0, 0);
                result = start_qos_iface(a1, v6);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A881C: using guessed type int __fastcall ip_get_duolan(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A89B8: using guessed type int __fastcall start_qos_iface(_DWORD, _DWORD);

