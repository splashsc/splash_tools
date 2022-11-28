int __fastcall sub_4480DC(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  int v5; // $s1
  char *v6; // $v0
  int v7; // $s1
  int v8; // $s1
  int v9; // $s1
  int v10; // $v0
  char *v11; // $v0
  int v12; // $s1
  char *v13; // $v1
  int v14; // $s1
  int v15; // $s1
  char *v16; // $a0
  int v17; // $a2
  int result; // $v0
  const char *v19; // $v0
  unsigned int v20; // $v0
  char v21[256]; // [sp+20h] [-140h] BYREF
  int v22[8]; // [sp+120h] [-40h] BYREF
  int v23[8]; // [sp+140h] [-20h] BYREF

  v23[0] = 0;
  v23[1] = 0;
  v23[2] = 0;
  v23[3] = 0;
  v23[4] = 0;
  v23[5] = 0;
  v23[6] = 0;
  v23[7] = 0;
  v22[0] = 0;
  v22[1] = 0;
  v22[2] = 0;
  v22[3] = 0;
  v22[4] = 0;
  v22[5] = 0;
  v22[6] = 0;
  v22[7] = 0;
  _mem_malloc(0x200000, "wans_data", 1199);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = get_vlan_name_data((char *)(v2 + 29));
    v5 = v4 + 30;
    v6 = &v3[v4 + 29];
    *v6 = 44;
    v6[1] = 0;
    v7 = v5 + get_wan_nvarms((const char **)wan_parms, &v3[v5], 0x200000 - v5);
    v8 = v7 + sprintf(&v3[v7], "\"x86\":%d,", 0);
    v9 = v8 + sprintf(&v3[v8], "\"ipc\":%d,", 1);
    get_client_info((int)v23, (int)v22, a1 + 205460);
    if ( v10 )
    {
      v12 = v9 + sprintf(&v3[v9], "\"compmac\":\"%s\",", (const char *)v23);
    }
    else
    {
      v11 = &v3[v9];
      strcpy(&v3[v9], "\"compmac\":\"\",");
      *(_DWORD *)v11 = 1836016418;
      *((_DWORD *)v11 + 1) = 1667329392;
      v12 = v9 + 13;
    }
    strcpy(&v3[v12], "\"show_ifname_mem\":\"0\",");
    qmemcpy(&v3[v12], "\"show_ifname_mem\":\"0", 20);
    v13 = &v3[v12 + 22];
    strcpy(v13, "\"ap_flag\":\"0\",");
    *(_DWORD *)v13 = 1601200418;
    *((_DWORD *)v13 + 1) = 1734437990;
    v14 = v12 + 36 + sprintf(&v3[v12 + 36], "\"hide_ipoe\":%d,", 0);
    v15 = v14 + sprintf(&v3[v14], "\"hide_igmp\":%d,", 0);
    v16 = &v3[v15];
    if ( v15 > 0 && *(v16 - 1) == 44 )
      v16 = &v3[--v15];
    *v16 = 0;
    v17 = snprintf(v16, 0x200000 - v15, "}}");
    if ( v17 >= 0x200000 - v15 )
      v17 = 0x1FFFFF - v15;
    result = httpd_cgi_ret(a1, v3, v15 + v17, 8);
  }
  else
  {
    v19 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v20 = snprintf(v21, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( v20 >= 0x100 )
      v20 = 255;
    result = httpd_cgi_ret(a1, v21, v20, 4);
  }
  return result;
}
// 44816C: variable 'v2' is possibly undefined
// 448290: variable 'v10' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 643D4C: using guessed type char byte_643D4C;
// 66E224: using guessed type char *wan_parms[4];
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

