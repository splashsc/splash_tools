void __fastcall usb_httpd_conn_check_user(int a1)
{
  char *v2; // $v0
  int v3; // $s1
  char *v4; // $v0
  int v5; // $v1
  const char *v6; // $a2
  _BYTE *v7; // $v0
  int v8; // $v0

  if ( !*(_BYTE *)(a1 + 43) )
  {
    if ( (*(_DWORD *)(a1 + 32) & 0x800) != 0 )
    {
      v2 = strstr(*(const char **)(a1 + 205524), "usb_userid=");
      v3 = (int)(v2 + 11);
      if ( v2 )
      {
        v4 = strstr(v2 + 11, "usb_passwd=");
        if ( v4 )
        {
          v5 = *v4;
          *(v4 - 1) = 0;
          v6 = v4 + 11;
          if ( v5 )
          {
            v7 = v4 + 1;
            if ( v5 == 59 )
            {
              --v7;
LABEL_15:
              *v7 = 0;
              v8 = usb_httpd_user_check_cookie(a1, v3, v6);
              if ( v8 <= 0 )
                goto LABEL_14;
              goto LABEL_12;
            }
            while ( *v7 )
            {
              if ( *v7 == 59 )
                goto LABEL_15;
              ++v7;
            }
          }
          v8 = usb_httpd_user_check_cookie(a1, v3, v6);
          if ( v8 > 0 )
          {
LABEL_12:
            *(_DWORD *)(a1 + 205588) = v8;
            *(_BYTE *)(a1 + 43) = 1;
            return;
          }
        }
      }
    }
LABEL_14:
    *(_BYTE *)(a1 + 43) = 3;
  }
}

