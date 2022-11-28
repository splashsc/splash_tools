int __fastcall jhl_nat_more_add_wanip(int a1, int a2)
{
  int v4; // $v0
  int v5; // $v0
  char *v6; // $s2
  int v7; // $v0
  char *v8; // $s7
  int result; // $v0
  int v10; // $v0
  const char *v11; // $v0
  uint32_t v12; // $s2
  uint32_t v13; // $s6
  uint32_t v14; // $a0
  uint32_t v15; // $v0
  int v16; // $v0
  int v17; // $v0
  uint32_t netlong[64]; // [sp+18h] [-248h] BYREF
  char v19[256]; // [sp+118h] [-148h] BYREF
  char v20[32]; // [sp+218h] [-48h] BYREF
  int v21[8]; // [sp+238h] [-28h] BYREF
  char *v22; // [sp+258h] [-8h]
  char *v23; // [sp+25Ch] [-4h]

  memset(v19, 0, sizeof(v19));
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
              memset(netlong, 0, sizeof(netlong));
              result = get_iplist_str(netlong, a2);
              if ( result )
              {
                v12 = ntohl(netlong[0]);
                v13 = ntohl(netlong[1]);
                result = v13 < v12;
                if ( v13 >= v12 )
                {
                  v22 = "a";
                  v23 = "a";
                  do
                  {
                    memset(v19, 0, sizeof(v19));
                    v14 = v12++;
                    v15 = htonl(v14);
                    IpToStr(v20, v15);
                    if ( !get_duolan_ip(0, 0, v20, 0) )
                    {
                      v16 = jhl_nvget(v22 + 6792, a1);
                      v17 = jhl_nv_get_def(v16);
                      ip_get_duolan(v20, v17, v19);
                      v21[0] = (int)"ip";
                      v21[1] = (int)"addr";
                      v21[2] = (int)&off_646D8C;
                      v21[3] = (int)v19;
                      v21[4] = (int)(v23 + 6704);
                      v21[5] = (int)v8;
                      v21[6] = 0;
                      eval(v21, 0, 0, 0);
                    }
                    result = v13 < v12;
                  }
                  while ( v13 >= v12 );
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 646D8C: using guessed type char *off_646D8C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A8558: using guessed type int __fastcall get_duolan_ip(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A881C: using guessed type int __fastcall ip_get_duolan(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8924: using guessed type int __fastcall get_iplist_str(_DWORD, _DWORD);

