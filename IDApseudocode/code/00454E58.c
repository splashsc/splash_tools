int __fastcall sub_454E58(int a1)
{
  char *v2; // $v0
  char *v3; // $s2
  _BOOL4 v4; // $s5
  const char *v5; // $a0
  void **v6; // $s0
  int v7; // $s1
  char *v8; // $s0
  _BYTE *v9; // $v0
  int v10; // $a2
  _BYTE *v11; // $s1
  char *v12; // $s3
  char *v13; // $v0
  int v14; // $a3
  char *v15; // $v1
  int v16; // $a1
  const char *v17; // $a2
  int v18; // $a0
  const char *v19; // $v0
  unsigned int v20; // $v0
  int v22; // $a2
  int v23; // $a1
  int v24; // $s2
  int v25; // $s2
  int v26; // $a2
  int v27; // $a1
  int v28; // $s2
  char *v29; // $s2
  char v30[260]; // [sp+20h] [-104h] BYREF

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
      goto LABEL_22;
    v7 = 0;
    while ( 1 )
    {
      v6 += 2;
      if ( !strcmp(v5, v3) )
        break;
      v5 = (const char *)*(v6 - 2);
      ++v7;
      if ( !v5 )
        goto LABEL_22;
    }
    v8 = (&ll_log_str)[2 * v7 + 1];
    if ( v8 )
    {
      _mem_malloc(0x200000, "sys_log_cfg", 581);
      v11 = v9;
      if ( v9 )
      {
        *(_WORD *)v9 = 91;
        v12 = v9 + 1;
        if ( v8 == (char *)-1 )
        {
          if ( nvram_match_def("usblogd_en", "1") )
          {
            v24 = read_sysmessage_file("/var/log/messages2", v11 + 1, 0x1FFFFF);
            v23 = v24;
            v22 = 0x1FFFFF - v24;
          }
          else
          {
            v22 = 0x1FFFFF;
            v23 = 0;
            v24 = 0;
          }
          v25 = v24 + read_sysmessage_file("/var/log/messages.0", &v12[v23], v22);
          v13 = (char *)(v25 + read_sysmessage_file("/var/log/messages", &v12[v25], 0x1FFFFF - v25));
          v15 = &v13[(_DWORD)v12];
          if ( v13 )
            goto LABEL_19;
        }
        else if ( v8 == (char *)-2 )
        {
          if ( nvram_match_def("usblogd_en", "1") )
          {
            v28 = read_ovpn_file("/var/log/openvpn2.log", v11 + 1, 0x1FFFFF);
            v27 = v28;
            v26 = 0x1FFFFF - v28;
          }
          else
          {
            v26 = 0x1FFFFF;
            v27 = 0;
            v28 = 0;
          }
          v13 = (char *)(v28 + read_ovpn_file("/var/log/openvpn.log", &v12[v27], v26));
          v15 = &v13[(_DWORD)v12];
          if ( v13 )
            goto LABEL_19;
        }
        else if ( v8 != (char *)-3 )
        {
          if ( v8 == (char *)2 )
          {
            v29 = read_vpnmessage_file(v9 + 1, 0x1FFFFF);
            v13 = &read_ipsec_file(&v29[(_DWORD)v12], 0x1FFFFF)[(_DWORD)v29];
            v15 = &v13[(_DWORD)v12];
            if ( v13 )
              goto LABEL_19;
          }
          else
          {
            if ( v8 == (char *)39 )
            {
              v13 = (char *)((int (__fastcall *)(_BYTE *, int, int))read_vpnmessage_file)(v9 + 1, 0x1FFFFF, v10);
            }
            else if ( v8 == (char *)26 )
            {
              v13 = (char *)((int (__fastcall *)(_BYTE *, int, int))read_error_by_ipsec_file)(v9 + 1, 0x1FFFFF, v10);
            }
            else
            {
              if ( v8 != (char *)28 )
              {
                v13 = (char *)read_log_data(v8, v9 + 1, 0x1FFFFF, v4);
                v14 = 2;
                if ( !v13 )
                  goto LABEL_20;
                v15 = &v13[(_DWORD)v12];
LABEL_19:
                v12 = v15 - 1;
                *(v15 - 1) = 0;
                v14 = (int)(v13 + 1);
LABEL_20:
                *v12 = 93;
                v12[1] = 0;
                if ( v8 == (char *)34 )
                  *(_DWORD *)(a1 + 36) |= 0x8000u;
                return httpd_send_mime_file(a1, "application/binary-file", v11, v14);
              }
              v13 = (char *)((int (__fastcall *)(_BYTE *, int, int))read_ipsec_file)(v9 + 1, 0x1FFFFF, 2031616);
            }
            v15 = &v13[(_DWORD)v12];
            if ( v13 )
              goto LABEL_19;
          }
        }
        v11[1] = 93;
        v14 = 2;
        v11[2] = 0;
        return httpd_send_mime_file(a1, "application/binary-file", v11, v14);
      }
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = (const char *)0x200000;
      v18 = 4;
    }
    else
    {
LABEL_22:
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = "not logid";
      v18 = 12;
    }
  }
  else
  {
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = "not id";
    v18 = 12;
  }
  v19 = (const char *)_GET_LANG_TEXT(v18, v16, v17);
  v20 = snprintf(v30, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
  if ( v20 >= 0x100 )
    v20 = 255;
  return httpd_cgi_ret(a1, v30, v20, 4);
}
// 454F64: variable 'v9' is possibly undefined
// 455208: variable 'v10' is possibly undefined
// 66F110: using guessed type char *ll_log_str;
// 66F118: using guessed type void *off_66F118;
// 6A8294: using guessed type int __fastcall read_ovpn_file(_DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A868C: using guessed type int __fastcall read_sysmessage_file(_DWORD, _DWORD, _DWORD);
// 6A88BC: using guessed type int __fastcall read_log_data(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

