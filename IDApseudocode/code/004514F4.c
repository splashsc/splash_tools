int get_speed_test_iface()
{
  int v0; // $s2
  int v1; // $s0
  int result; // $v0
  int v3; // $v0
  char *v4; // $s7
  int v5; // $v0
  int v6; // $fp
  int v7; // $v0
  const char *v8; // $v0
  int v9; // $a1
  int v10; // $v0
  int v11; // $v0
  const char *v12; // $v0
  int v13; // $v0

  v0 = sq_file_get_max_wan();
  if ( v0 > 0 )
  {
    v1 = 0;
    while ( 1 )
    {
      v3 = jhl_nvget("wan_ifname", v1);
      v4 = (char *)nvram_get(v3);
      if ( !v4 )
        v4 = "";
      v5 = jhl_get_wan_proto(v1);
      v6 = v5;
      if ( !*v4 )
        break;
      if ( (unsigned int)(v5 - 10) < 3
        || (v7 = jhl_nvget("wan_down", v1), (v8 = (const char *)nvram_get(v7)) != 0) && !strcmp(v8, "1")
        || jhl_iface_link_up_check(v4, v1) )
      {
        ++v1;
      }
      else
      {
        if ( v6 != 4
          || (v11 = jhl_nvget("ppp_demand_run", v1), (v12 = (const char *)nvram_get(v11)) == 0)
          || (v13 = strcmp(v12, "1"), v9 = 0, v13) )
        {
          v9 = jhl_check_wanup(v1);
        }
        v10 = jhl_link_uptime_s(v1++, v9);
        if ( v10 >= 2 )
          return v1 - 1;
      }
      result = -1;
      if ( v0 == v1 )
        return result;
    }
  }
  return -1;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

