int __fastcall sub_4552E0(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  char *v4; // $s0
  int v5; // $s0
  uint32_t v6; // $s3
  char *v7; // $v0
  char *v8; // $v0
  char *v9; // $s1
  char *v10; // $s2
  uint32_t v11; // $v0
  int v12; // $a1
  int v13; // $a2
  unsigned int v14; // $v0
  int v15; // $a1
  bool v16; // dc
  unsigned int v17; // $v0
  char *v18; // $a2
  const char *v19; // $v0
  unsigned int v20; // $v0
  const char *v22; // $v0
  int v23; // $s0
  char *v24; // $s7
  const char *v25; // $s0
  int v26; // $fp
  int v27; // $s3
  uint32_t v28; // $v0
  int v29; // $a0
  int v30; // $v0
  char *v31; // $a0
  int v32; // $v0
  int v33; // $s3
  char v34[128]; // [sp+38h] [-80h] BYREF

  v3 = httpd_get_parm(a1, "id");
  v2 = httpd_get_parm(a1, "iface");
  if ( v2 && (v4 = v2, strcmp(v2, "all")) )
  {
    v5 = J_atoi(v4);
    if ( v5 < 101 )
      ++v5;
  }
  else
  {
    v5 = 0;
  }
  v6 = J_atohx16(v3);
  _mem_malloc(0x200000, "shibie_id_data", 76);
  v9 = v8;
  _mem_malloc(0x100000, "shibie_id_data", 77);
  v10 = v7;
  if ( v9 && v7 )
  {
    *(_DWORD *)v7 = 34;
    *((_DWORD *)v7 + 3) = 13;
    *((_DWORD *)v7 + 1) = 0x100000;
    v11 = htonl(v6);
    v12 = *((_DWORD *)v10 + 1);
    *((_DWORD *)v10 + 4) = v11;
    *((_DWORD *)v10 + 5) = v5;
    if ( jianhl_order_opt_fun(v10, v12, v13) )
    {
      v15 = *(unsigned __int8 *)(a1 + 210102);
      v18 = "";
LABEL_18:
      v22 = (const char *)_GET_LANG_TEXT(3, v15, v18);
      v23 = snprintf(v9, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
      if ( v23 >= 0x200000 )
        v23 = 0x1FFFFF;
      _mem_free(v10);
      return httpd_cgi_ret(a1, v9, v23, 8);
    }
    v14 = *((_DWORD *)v10 + 2);
    if ( v14 )
    {
      v15 = *(unsigned __int8 *)(a1 + 210102);
      v16 = v14 >= 0x33;
      v17 = v14;
      if ( v16 || (v18 = (char *)jhlret_err_str[v17]) == 0 )
        v18 = "not find err!";
      goto LABEL_18;
    }
    strcpy(v9, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v9, "{\"code\":0,\"error", 16);
    v24 = v9 + 29;
    if ( *((int *)v10 + 6) <= 0 )
    {
      v30 = 28;
      v29 = 29;
      v27 = 29;
    }
    else
    {
      v25 = v10 + 40;
      v26 = 0;
      v27 = 29;
      do
      {
        ++v26;
        v28 = ntohl(*((_DWORD *)v25 - 2));
        v27 += sprintf(
                 v24,
                 "{\"id\":\"%08X\",\"n\":\"%s\",\"cn\":%d,\"su\":%u,\"sd\":%u,\"cu\":%llu,\"cd\":%llu},",
                 v28,
                 v25,
                 *((_DWORD *)v25 - 1),
                 *((_DWORD *)v25 + 8),
                 *((_DWORD *)v25 + 9),
                 *((_QWORD *)v25 + 5),
                 *((_QWORD *)v25 + 6));
        v29 = v27;
        v24 = &v9[v27];
        if ( v26 >= *((_DWORD *)v10 + 6) )
          break;
        v25 += 64;
      }
      while ( 0x200000 - v27 >= 500 );
      v30 = v27 - 1;
      if ( v27 <= 0 )
      {
        v31 = &v9[v27];
LABEL_29:
        *v31 = 0;
        v32 = snprintf(v31, 0x200000 - v27, "]}");
        if ( v32 >= 0x200000 - v27 )
          v32 = 0x1FFFFF - v27;
        v33 = v27 + v32;
        _mem_free(v10);
        return jhl_data_giz(a1, v9, v33, 0x200000);
      }
    }
    if ( v9[v30] == 44 )
      v31 = &v9[--v27];
    else
      v31 = &v9[v29];
    goto LABEL_29;
  }
  _mem_free(v9);
  _mem_free(v10);
  v19 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v20 = snprintf(v34, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
  if ( v20 >= 0x80 )
    v20 = 127;
  return httpd_cgi_ret(a1, v34, v20, 4);
}
// 4553C0: variable 'v8' is possibly undefined
// 4553CC: variable 'v7' is possibly undefined
// 45540C: variable 'v13' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8244: using guessed type int __fastcall J_atohx16(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

