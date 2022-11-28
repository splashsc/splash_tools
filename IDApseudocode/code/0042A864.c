int __fastcall httpd_dowith_get(int a1)
{
  int v1; // $v0
  _BYTE *v2; // $s0
  int v4; // $v0
  const char *v5; // $s0
  const char *v6; // $s0
  int v7; // $a1
  int v8; // $s0
  char *v10; // $a0
  _BYTE *v11; // $a1
  int v12; // $v0
  _BYTE *v13; // $s0
  _BYTE *v14; // $s0
  char v16[32]; // [sp+18h] [-4Ch] BYREF
  int v17[7]; // [sp+38h] [-2Ch] BYREF
  int v18[4]; // [sp+54h] [-10h] BYREF

  v1 = *(char *)(a1 + 568);
  v2 = (_BYTE *)(a1 + 568);
  v18[0] = 0;
  *(_DWORD *)(a1 + 44) = a1 + 568;
  if ( v1 == 32 )
  {
LABEL_8:
    *v2 = 0;
    v5 = v2 + 1;
    unescape(*(char **)(a1 + 44));
    *(_DWORD *)(a1 + 52) = 0;
    goto LABEL_9;
  }
  if ( v1 != 63 )
  {
    if ( v1 )
    {
      do
      {
        v4 = (char)*++v2;
        if ( v4 == 32 )
          break;
        if ( v4 == 63 )
          goto LABEL_18;
      }
      while ( *v2 );
    }
    goto LABEL_8;
  }
LABEL_18:
  *v2 = 0;
  v10 = *(char **)(a1 + 44);
  v18[1] = (int)(v2 + 1);
  unescape(v10);
  v11 = v2 + 1;
  *(_DWORD *)(a1 + 52) = 0;
  if ( v2 == (_BYTE *)-1 )
  {
    v5 = 0;
  }
  else
  {
    v12 = v2[1] & 0xDF;
    v13 = v2 + 1;
    if ( v12 )
    {
      v14 = v11 + 1;
      while ( *v14++ & 0xDF )
        ;
      v13 = v14 - 1;
    }
    *v13 = 0;
    httpd_formdata_parse((_DWORD *)a1, v11, 0);
    v5 = v13 + 1;
  }
LABEL_9:
  httpd_do_wwwparm((_DWORD *)a1, v5);
  if ( !httpd_proxy_check(a1, v18) )
  {
    v6 = *(const char **)(a1 + 44);
    goto LABEL_11;
  }
  v8 = httpd_proxy_is_self(a1);
  if ( v8 )
  {
    v6 = *(const char **)(a1 + 44);
    if ( !strncmp(v6, "/ap/", 4u) )
    {
      v6 += 3;
      *(_DWORD *)(a1 + 44) = v6;
    }
    if ( !strncmp(v6, "/rt/", 4u) )
    {
      v6 += 3;
      *(_DWORD *)(a1 + 44) = v6;
    }
LABEL_11:
    if ( !strncmp(v6, "/usb/", 5u) || !strncmp(v6, "/auth_html/", 0xBu) )
    {
      v7 = 1;
    }
    else
    {
      if ( !strcmp(v6, "/welcome/ioswificheck.php") )
      {
        IpaddrToStr(v16, a1 + 205460);
        v17[0] = (int)"wys";
        v17[1] = (int)"hi";
        v17[2] = (int)"redirct_flag";
        v17[3] = (int)"set";
        v17[4] = (int)v16;
        v17[5] = (int)"1";
        v17[6] = 0;
        eval(v17, 0, 0, 0);
        strcpy(v16, "{ok}");
        return httpd_cgi_ret(a1, v16, 4, 4);
      }
      v7 = 0;
    }
    *(_BYTE *)(a1 + 41) = 2;
    v8 = 0;
    httpd_send_file(a1, v7);
    return v8;
  }
  if ( v18[0] && httdp_proxy_check_user(a1) )
    return v8;
  return httpd_proxy_cgi(a1);
}
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);

