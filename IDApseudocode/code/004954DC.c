int __fastcall sub_4954DC(int a1)
{
  char *v1; // $v0
  int v3; // $s1
  int v4; // $v0
  char *v5; // $s0
  int v6; // $v0
  int v7; // $s1
  char *v8; // $a0
  int v9; // $a2
  int v11; // $a1
  int v12; // $a2
  int v13; // $a0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[256]; // [sp+20h] [-100h] BYREF

  v1 = httpd_get_parm(a1, (char *)&off_64918C);
  if ( v1 )
  {
    v3 = J_atoi(v1);
    if ( (unsigned int)(v3 - 1) >= 0xFF )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (int)"not i_gid";
      v13 = 12;
    }
    else
    {
      _mem_malloc(0x200000, "dns_more_dnstype_item_data", 1264);
      v5 = (char *)v4;
      if ( v4 )
      {
        strcpy((char *)v4, "{\"code\":0,\"error\":\"\",\"data\":[");
        qmemcpy((void *)v4, "{\"code\":0,\"error", 16);
        *(_DWORD *)(v4 + 24) = 975331700;
        v6 = dns_more_dns_gid_member_get(v4 + 29, 2097123, v3);
        v7 = v6 + 29;
        v8 = &v5[v6 + 29];
        if ( v6 + 29 > 0 && *(v8 - 1) == 44 )
        {
          v7 = v6 + 28;
          v8 = &v5[v6 + 28];
        }
        *v8 = 0;
        v9 = snprintf(v8, 0x200000 - v7, "]}");
        if ( v9 >= 0x200000 - v7 )
          v9 = 0x1FFFFF - v7;
        return jhl_data_giz(a1, v5, v7 + v9, 0x200000);
      }
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = 0x200000;
      v13 = 4;
    }
  }
  else
  {
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = (int)&unk_649188;
    v13 = 12;
  }
  v14 = (const char *)_GET_LANG_TEXT(v13, v11, v12);
  v15 = snprintf(v16, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
  if ( v15 >= 0x100 )
    v15 = 255;
  return httpd_cgi_ret(a1, v16, v15, 4);
}
// 49556C: variable 'v4' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 64918C: using guessed type void *off_64918C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A860C: using guessed type int __fastcall dns_more_dns_gid_member_get(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

