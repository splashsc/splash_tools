int __fastcall usb_httpd_user_auth_cookie(int a1)
{
  char *v2; // $a1
  char *v3; // $v0
  int v4; // $v1
  bool v5; // dc
  _BYTE *v6; // $v1
  int v7; // $v0
  int result; // $v0
  char v9[1028]; // [sp+18h] [-404h] BYREF

  if ( (*(_DWORD *)(a1 + 32) & 0x800) == 0 )
    goto LABEL_13;
  memset(v9, 0, 0x400u);
  v2 = strstr(*(const char **)(a1 + 205524), "usb_userid=");
  if ( !v2 )
    goto LABEL_13;
  strlcpy(v9, v2, 1024);
  v3 = strstr(&v9[11], "usb_passwd=");
  if ( !v3 )
    goto LABEL_13;
  v4 = v3[11];
  *(v3 - 1) = 0;
  if ( v4 )
  {
    v5 = v4 == 59;
    v6 = v3 + 11;
    if ( v5 )
    {
LABEL_12:
      *v6 = 0;
    }
    else
    {
      while ( *++v6 )
      {
        if ( *v6 == 59 )
          goto LABEL_12;
      }
    }
  }
  v7 = usb_httpd_user_check_cookie(a1, (int)&v9[11], v3 + 11);
  if ( v7 > 0 )
  {
    *(_DWORD *)(a1 + 205588) = v7;
    result = 0;
    *(_BYTE *)(a1 + 43) = 1;
  }
  else
  {
LABEL_13:
    *(_BYTE *)(a1 + 43) = 3;
    usb_httpd_send_login_html(a1);
    result = -1;
  }
  return result;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);

