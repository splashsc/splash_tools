int __fastcall sub_45461C(int a1)
{
  char *v2; // $v0
  char *v3; // $s2
  _BOOL4 v4; // $s4
  const char *v5; // $a0
  void **v6; // $s0
  int v7; // $s1
  char *v8; // $s1
  int v9; // $v0
  char *v10; // $s0
  int v11; // $s2
  char *v12; // $v0
  int v13; // $s5
  int v14; // $s4
  char *v15; // $a0
  int v16; // $a1
  int v17; // $v0
  int v18; // $a2
  int v20; // $a1
  const char *v21; // $a2
  int v22; // $a0
  const char *v23; // $v0
  unsigned int v24; // $v0
  int v25; // $a2
  int v26; // $a1
  int v27; // $s4
  int v28; // $s4
  int v29; // $a2
  int v30; // $a1
  int v31; // $s4
  char *v32; // $s4
  char v33[260]; // [sp+20h] [-104h] BYREF

  v3 = httpd_get_parm(a1, "id");
  v2 = httpd_get_parm(a1, "mode");
  v4 = 0;
  if ( v2 )
    v4 = J_atoi(v2) != 0;
  if ( v3 )
  {
    v5 = ll_log_str;
    v6 = &off_66F118;
    if ( !ll_log_str )
      goto LABEL_25;
    v7 = 0;
    while ( 1 )
    {
      v6 += 2;
      if ( !strcmp(v5, v3) )
        break;
      v5 = (const char *)*(v6 - 2);
      ++v7;
      if ( !v5 )
        goto LABEL_25;
    }
    v8 = (&ll_log_str)[2 * v7 + 1];
    if ( v8 )
    {
      _mem_malloc(0x200000, "sys_log_data", 387);
      v10 = (char *)v9;
      if ( v9 )
      {
        qmemcpy((void *)v9, "{\"code\":0,\"error\":\"\",\"data\":", 28);
        qmemcpy((void *)v9, "{\"code\":0,\"error", 16);
        v11 = v9 + 29;
        *(_BYTE *)(v9 + 28) = 91;
        *(_BYTE *)(v9 + 29) = 0;
        if ( v8 == (char *)-1 )
        {
          if ( nvram_match_def("usblogd_en", "1") )
          {
            v27 = read_sysmessage_file("/var/log/messages2", v10 + 29, 2097123);
            v26 = v27;
            v25 = 2097123 - v27;
          }
          else
          {
            v25 = 2097123;
            v26 = 0;
            v27 = 0;
          }
          v28 = v27 + read_sysmessage_file("/var/log/messages.0", v11 + v26, v25);
          v12 = (char *)(v28 + read_sysmessage_file("/var/log/messages", v11 + v28, 2097123 - v28));
        }
        else if ( v8 == (char *)-2 )
        {
          if ( nvram_match_def("usblogd_en", "1") )
          {
            v31 = read_ovpn_file("/var/log/openvpn2.log", v10 + 29, 2097123);
            v30 = v31;
            v29 = 2097123 - v31;
          }
          else
          {
            v29 = 2097123;
            v30 = 0;
            v31 = 0;
          }
          v12 = (char *)(v31 + read_ovpn_file("/var/log/openvpn.log", v11 + v30, v29));
        }
        else
        {
          if ( v8 == (char *)-3 )
          {
            *(_BYTE *)(v9 + 29) = 93;
            v18 = 31;
            *(_WORD *)(v9 + 30) = 125;
            return httpd_cgi_ret(a1, v10, v18, 8);
          }
          if ( v8 == (char *)2 )
          {
            v32 = read_vpnmessage_file((char *)(v9 + 29), 2097123);
            v12 = &read_ipsec_file(&v32[v11], 2097123)[(_DWORD)v32];
          }
          else if ( v8 == (char *)39 )
          {
            v12 = (char *)((int (__fastcall *)(int, int, int))read_vpnmessage_file)(v9 + 29, 2097123, -1);
          }
          else if ( v8 == (char *)26 )
          {
            v12 = (char *)((int (__fastcall *)(int, int, int))read_error_by_ipsec_file)(v9 + 29, 2097123, -1);
          }
          else if ( v8 == (char *)28 )
          {
            v12 = (char *)((int (__fastcall *)(int, int, int))read_ipsec_file)(v9 + 29, 2097123, 2031616);
          }
          else
          {
            v12 = (char *)read_log_data(v8, v9 + 29, 2097123, v4);
          }
        }
        if ( v12 )
        {
          v13 = (int)(v12 + 28);
          v14 = 0x200000 - (_DWORD)(v12 + 28);
          v12[v11 - 1] = 0;
          v15 = &v12[(_DWORD)v10 + 28];
          v16 = v14;
        }
        else
        {
          v16 = 2097123;
          v15 = v10 + 29;
          v14 = 2097123;
          v13 = 29;
        }
        v17 = snprintf(v15, v16, "]}");
        if ( v17 >= v14 )
          v17 = 0x1FFFFF - v13;
        v18 = v17 + v13;
        if ( v8 == (char *)34 )
          *(_DWORD *)(a1 + 36) |= 0x8000u;
        return httpd_cgi_ret(a1, v10, v18, 8);
      }
      v20 = *(unsigned __int8 *)(a1 + 210102);
      v21 = (const char *)0x200000;
      v22 = 4;
    }
    else
    {
LABEL_25:
      v20 = *(unsigned __int8 *)(a1 + 210102);
      v21 = "not logid";
      v22 = 12;
    }
  }
  else
  {
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = "not id";
    v22 = 12;
  }
  v23 = (const char *)_GET_LANG_TEXT(v22, v20, v21);
  v24 = snprintf(v33, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v23);
  if ( v24 >= 0x100 )
    v24 = 255;
  return httpd_cgi_ret(a1, v33, v24, 4);
}
// 454728: variable 'v9' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 66F110: using guessed type char *ll_log_str;
// 66F118: using guessed type void *off_66F118;
// 6A8294: using guessed type int __fastcall read_ovpn_file(_DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A868C: using guessed type int __fastcall read_sysmessage_file(_DWORD, _DWORD, _DWORD);
// 6A88BC: using guessed type int __fastcall read_log_data(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

