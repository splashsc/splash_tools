int __fastcall sub_454B30(int a1)
{
  char *v1; // $v0
  const char *v3; // $a0
  const char *v4; // $s2
  void **v5; // $s0
  int v6; // $s1
  char *v7; // $a0
  const char *v8; // $v0
  char *v9; // $v1
  int v10; // $t0
  int v11; // $a3
  int v12; // $a2
  int v13; // $a1
  int v15; // $a1
  const char *v16; // $a2
  const char *v17; // $v0
  unsigned int v18; // $v0
  char v19[256]; // [sp+20h] [-100h] BYREF

  v1 = httpd_get_parm(a1, "id");
  if ( v1 )
  {
    v3 = ll_log_str;
    v4 = v1;
    if ( ll_log_str )
    {
      v5 = &off_66F118;
      v6 = 0;
      while ( 1 )
      {
        v5 += 2;
        if ( !strcmp(v3, v4) )
          break;
        v3 = (const char *)*(v5 - 2);
        ++v6;
        if ( !v3 )
          goto LABEL_16;
      }
      v7 = (&ll_log_str)[2 * v6 + 1];
      if ( v7 )
      {
        if ( v7 == (char *)-1 )
        {
          log_del_file_all("/var/log/messages");
          log_del_file_all("/var/log/messages.0");
          log_del_file_all("/var/log/messages2");
        }
        else if ( v7 == (char *)-2 )
        {
          log_del_file_all("/var/log/openvpn.log");
          log_del_file_all("/var/log/openvpn2.log");
        }
        else if ( v7 == (char *)1 )
        {
          del_log_data(1);
          del_log_data(27);
        }
        else if ( v7 == (char *)28 )
        {
          log_del_file_all("/etc/racoon/ipsec.log");
        }
        else if ( v7 == (char *)39 )
        {
          del_vpnmessage_file();
        }
        else
        {
          del_log_data(v7);
        }
        v8 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        v9 = v19;
        do
        {
          v10 = *(_DWORD *)v8;
          v11 = *((_DWORD *)v8 + 1);
          v12 = *((_DWORD *)v8 + 2);
          v13 = *((_DWORD *)v8 + 3);
          v8 += 16;
          *(_DWORD *)v9 = v10;
          *((_DWORD *)v9 + 1) = v11;
          *((_DWORD *)v9 + 2) = v12;
          *((_DWORD *)v9 + 3) = v13;
          v9 += 16;
        }
        while ( v8 != "}" );
        *(_WORD *)v9 = *(_WORD *)v8;
        return httpd_cgi_ret(a1, v19, 33, 4);
      }
    }
LABEL_16:
    v15 = *(unsigned __int8 *)(a1 + 210102);
    v16 = "not logid";
  }
  else
  {
    v15 = *(unsigned __int8 *)(a1 + 210102);
    v16 = "not id";
  }
  v17 = (const char *)_GET_LANG_TEXT(12, v15, v16);
  v18 = snprintf(v19, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
  if ( v18 >= 0x100 )
    v18 = 255;
  return httpd_cgi_ret(a1, v19, v18, 4);
}
// 66F110: using guessed type char *ll_log_str;
// 66F118: using guessed type void *off_66F118;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8498: using guessed type int __fastcall del_log_data(_DWORD);
// 6A85C4: using guessed type int __fastcall log_del_file_all(_DWORD);

