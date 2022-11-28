int __fastcall sub_443FA8(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  const char *v4; // $v0
  int v5; // $v0
  int v6; // $v0
  int i; // $s7
  int v8; // $a0
  char *v9; // $a0
  int v10; // $a2
  int v12; // $v0
  const char *v13; // $a0
  char *v14; // $v0
  char *v15; // $s6
  char *v16; // $v0
  int v17; // $v1
  int v18; // $v0
  int v19; // $v0
  const char *v20; // $v0
  unsigned int v21; // $v0
  char *v22[65]; // [sp+20h] [-104h] BYREF

  _mem_malloc(0x200000, "dhcp_list_data", 3002);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = (const char *)jhl_nv_get_def("dual_lan_mode");
    if ( !strcmp(v4, "1") )
    {
      v12 = nvram_get("lan_ifnames");
      if ( v12 )
        v13 = (const char *)v12;
      else
        v13 = "";
      v14 = strdup(v13);
      v15 = v14;
      if ( v14 )
      {
        v22[0] = v14;
        v16 = strsep(v22, " ");
        for ( i = 29; v16; v16 = strsep(v22, " ") )
        {
          do
            v17 = *v16++;
          while ( v17 == 32 );
          v18 = (int)(v16 - 1);
          if ( !v17 )
            break;
          dhcp_list_buf((int)&v3[i], 0x200000 - i, v18);
          i += v19;
        }
        free(v15);
LABEL_5:
        v8 = i;
        if ( i <= 0 || v3[i - 1] != 44 )
        {
LABEL_7:
          v9 = &v3[v8];
          *v9 = 0;
          v10 = snprintf(v9, 0x200000 - i, "]}");
          if ( v10 >= 0x200000 - i )
            v10 = 0x1FFFFF - i;
          return httpd_cgi_ret(a1, v3, i + v10, 8);
        }
LABEL_20:
        v8 = --i;
        goto LABEL_7;
      }
    }
    else
    {
      v5 = jhl_nv_get_def("lan_ifname");
      dhcp_list_buf((int)(v3 + 29), 2097123, v5);
      if ( v6 )
      {
        i = v6 + 29;
        goto LABEL_5;
      }
    }
    v8 = 29;
    i = 29;
    if ( v3[28] != 44 )
      goto LABEL_7;
    goto LABEL_20;
  }
  v20 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v21 = snprintf((char *)v22, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
  if ( v21 >= 0x100 )
    v21 = 255;
  return httpd_cgi_ret(a1, (char *)v22, v21, 4);
}
// 444004: variable 'v2' is possibly undefined
// 4440E0: variable 'v6' is possibly undefined
// 444240: variable 'v19' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

