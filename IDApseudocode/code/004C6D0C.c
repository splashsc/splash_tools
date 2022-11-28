int __fastcall get_ipv6_wans_data(char *a1, int a2)
{
  int v3; // $s5
  int v4; // $s2
  int v5; // $s0
  int v6; // $v0
  char *v7; // $s1
  int v8; // $v0
  int v9; // $v0
  const char *v10; // $v0
  int v11; // $v0
  const char *v12; // $v0
  int v13; // $v0
  int v14; // $v0
  int v15; // $s2
  const char *v16; // $v0
  int v17; // $v0
  int v18; // $v0
  int v19; // $s1
  int v20; // $s2
  int v21; // $v0
  int v22; // $v0
  int v23; // $v0
  int v24; // $v0
  int v25; // $v0
  char *v26; // $v1
  int v27; // $v0
  const char *v28; // $v0
  int v29; // $v0
  int v30; // $s1
  int v31; // $v0
  char *v32; // $a0
  int v33; // $s4
  int v34; // $v0
  char *v36; // [sp+30h] [-30h]
  char *v37; // [sp+30h] [-30h]
  const char *v38; // [sp+38h] [-28h]
  const char *v39; // [sp+3Ch] [-24h]
  const char *v40; // [sp+40h] [-20h]
  const char *v41; // [sp+44h] [-1Ch]
  const char *v42; // [sp+58h] [-8h]

  v3 = sq_file_get_max_wan();
  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  if ( v3 > 0 && v4 < a2 - 99 )
  {
    v5 = 0;
    do
    {
      v6 = jhl_nvget("wan_ifname", v5);
      v7 = (char *)nvram_get(v6);
      if ( !v7 )
        v7 = "";
      v8 = jhl_nvget("wan_orgifname", v5);
      nvram_get(v8);
      if ( !*v7 )
        break;
      v9 = jhl_nvget("wan_down", v5);
      v10 = (const char *)nvram_get(v9);
      if ( v10 && !strcmp(v10, "1") || jhl_iface_link_up_check(v7, v5) )
      {
        if ( v3 == ++v5 )
          break;
      }
      else
      {
        v11 = jhl_nvget("wan_proto", v5);
        v12 = (const char *)nvram_get(v11);
        v36 = (char *)v12;
        if ( v12 )
        {
          if ( !strncmp(v12, "3G", 2u) )
          {
            v36 = "4G";
          }
          else if ( !strncmp(v36, "4G", 2u) )
          {
            v36 = "4G";
          }
        }
        else
        {
          v36 = "disabled";
        }
        v13 = snprintf(&a1[v4], a2 - v4, (char *)&word_642164);
        if ( v13 >= a2 - v4 )
          v13 = a2 - v4 - 1;
        v15 = v13 + v4;
        v14 = jhl_nvget("wan_name", v5);
        v16 = (const char *)nvram_get(v14);
        if ( !v16 )
          v16 = "";
        v17 = snprintf(
                &a1[v15],
                a2 - v15,
                "\"iface\":\"%d\",\"wan_ifname\":\"%s\",\"wan_type\":\"%s\",\"wan_name\":\"%s\",",
                v5,
                v7,
                v36,
                v16);
        if ( v17 >= a2 - v15 )
          v17 = a2 - v15 - 1;
        v19 = v17 + v15;
        v18 = jhl_nvget("ipv6.wan_proto", v5);
        v20 = a2 - v19;
        v37 = (char *)nvram_get(v18);
        if ( !v37 )
          v37 = "OFF";
        v21 = jhl_nvget("ipv6.wan_mode", v5);
        v38 = (const char *)nvram_get(v21);
        if ( !v38 )
          v38 = "router";
        v22 = jhl_nvget("ipv6.wan_local_ip", v5);
        v39 = (const char *)jhl_nv_get_def(v22);
        if ( !v39 )
          v39 = "";
        v23 = jhl_nvget("ipv6.wan_peer_ip", v5);
        v40 = (const char *)jhl_nv_get_def(v23);
        if ( !v40 )
          v40 = "";
        v24 = jhl_nvget("ipv6.wan_local_ip6", v5);
        v41 = (const char *)jhl_nv_get_def(v24);
        if ( !v41 )
          v41 = "";
        v25 = jhl_nvget("ipv6.wan_static_ip6", v5);
        v26 = (char *)jhl_nv_get_def(v25);
        if ( !v26 )
          v26 = "";
        v42 = v26;
        v27 = jhl_nvget("ipv6.wan_static_gw6", v5);
        v28 = (const char *)jhl_nv_get_def(v27);
        if ( !v28 )
          v28 = "";
        v29 = snprintf(
                &a1[v19],
                a2 - v19,
                "\"proto\":\"%s\",\"mode\":\"%s\",\"local_ip\":\"%s\",\"peer_ip\":\"%s\",\"local_ip6\":\"%s\",\"static_ip"
                "6\":\"%s\",\"static_gw6\":\"%s\"",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v28);
        if ( v29 >= v20 )
          v29 = v20 - 1;
        v30 = v29 + v19;
        v31 = snprintf(&a1[v30], a2 - v30, &byte_65078C);
        if ( v31 >= a2 - v30 )
          v31 = a2 - v30 - 1;
        ++v5;
        v4 = v31 + v30;
        if ( v3 == v5 )
          break;
      }
    }
    while ( v4 < a2 - 99 );
  }
  v32 = &a1[v4];
  if ( v4 > 0 && *(v32 - 1) == 44 )
    v32 = &a1[--v4];
  v33 = a2 - v4;
  *v32 = 0;
  v34 = snprintf(v32, v33, &byte_6445A0);
  if ( v34 >= v33 )
    v34 = v33 - 1;
  return v4 + v34;
}
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 65078C: using guessed type char byte_65078C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

