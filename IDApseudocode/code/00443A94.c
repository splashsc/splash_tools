int __fastcall get_dual_lan_list_data(char *a1, int a2)
{
  int v4; // $s3
  char *v5; // $s1
  int v6; // $s5
  int v7; // $s2
  char *v8; // $v0
  const char *v9; // $s0
  signed int v10; // $v0
  bool v11; // dc
  int v12; // $v0
  const char *v13; // $v0
  int v14; // $v0
  int v15; // $s4
  int v16; // $v0
  char *v17; // $a0
  int v18; // $s6
  int v19; // $v0
  char v21[8192]; // [sp+50h] [-20E8h] BYREF
  char v22[136]; // [sp+2050h] [-E8h] BYREF
  int v23[3]; // [sp+20D8h] [-60h] BYREF
  char *v24; // [sp+20E4h] [-54h]
  int v25; // [sp+20E8h] [-50h]
  int v26; // [sp+20ECh] [-4Ch]
  int v27; // [sp+20F0h] [-48h]
  int v28; // [sp+20F4h] [-44h]
  int v29; // [sp+20F8h] [-40h]
  int v30; // [sp+20FCh] [-3Ch]
  int v31; // [sp+2100h] [-38h]
  int v32; // [sp+2104h] [-34h]
  const char *v33; // [sp+2108h] [-30h]
  char *haystack; // [sp+210Ch] [-2Ch]
  int v35; // [sp+2110h] [-28h]
  char *v36; // [sp+2120h] [-18h]
  char *v37; // [sp+2124h] [-14h]
  char *format; // [sp+2128h] [-10h]
  char *v39; // [sp+212Ch] [-Ch]
  const char *v40; // [sp+2130h] [-8h]

  memset(v21, 0, sizeof(v21));
  jhl_parm_get("dual_lan_list", v21, 0x2000);
  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  v5 = v22;
  v6 = split_string(v21, 60, v22, 32);
  if ( v6 > 0 )
  {
    v7 = 0;
    v37 = "a";
    v40 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    v36 = (char *)&off_63F984;
    format = "{\"vlanid\":\"%s\",\"lan_ipaddr\":\"%s\",\"lan_netmask\":\"%s\",\"dhcp_type\":\"%s\",\"dhcp_lease\":%s,\"dh"
             "cp_start\":\"%s\",\"dhcp_end\":\"%s\",\"dhcp_gw\":\"%s\",\"dhcp_dns0\":\"%s\",\"dhcp_dns1\":\"%s\",\"dhcp_m"
             "ask\":\"%s\",\"mac_lan\":\"%s\",\"port\":\"%s\",\"mem\":\"%s\",\"dhcp_option43\":\"%s\"},";
    v39 = "admin";
    do
    {
      if ( split_string(*(_DWORD *)v5, 124, v23, 15) >= 13 )
      {
        if ( strcmp(v24, v36) )
          v24 = v39;
        v8 = strstr(haystack, v37 + 9684);
        if ( v8 )
          *v8 = 0;
        v9 = v33;
        v10 = strlen(v33);
        v11 = v10 <= 0;
        v12 = v10 - 1;
        if ( !v11 )
        {
          v13 = &v9[v12];
          if ( *v13 == 44 )
          {
            *v13 = 0;
            v9 = v33;
          }
        }
        v14 = v35;
        v15 = a2 - v4;
        if ( !v35 )
          v14 = (int)(v40 - 1556);
        v16 = snprintf(
                &a1[v4],
                a2 - v4,
                format,
                v23[0],
                v23[1],
                v23[2],
                v24,
                v25,
                v26,
                v27,
                v28,
                v30,
                v31,
                v29,
                v32,
                v9,
                haystack,
                v14);
        if ( v16 >= v15 )
          v16 = v15 - 1;
        v4 += v16;
      }
      ++v7;
      v5 += 4;
    }
    while ( v6 != v7 );
  }
  v17 = &a1[v4];
  if ( v4 > 0 && *(v17 - 1) == 44 )
    v17 = &a1[--v4];
  v18 = a2 - v4;
  *v17 = 0;
  v19 = snprintf(v17, v18, &byte_6445A0);
  if ( v19 >= v18 )
    v19 = v18 - 1;
  return v4 + v19;
}
// 63F984: using guessed type void *off_63F984;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

