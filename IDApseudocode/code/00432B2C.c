int __fastcall httpd_user_auth_cookie(int a1)
{
  char *v2; // $a1
  const char **v3; // $fp
  int v4; // $v0
  const char *v5; // $s6
  const char **v6; // $s1
  const char *v7; // $s4
  const char *v8; // $s7
  const char *i; // $v0
  int v10; // $v0
  int result; // $v0
  char v12[1024]; // [sp+18h] [-420h] BYREF
  _DWORD v13[8]; // [sp+418h] [-20h] BYREF

  if ( (*(_DWORD *)(a1 + 32) & 0x800) == 0 )
    goto LABEL_22;
  memset(v12, 0, sizeof(v12));
  v2 = strstr(*(const char **)(a1 + 205524), "vue_userid=");
  if ( !v2 )
    goto LABEL_22;
  strlcpy(v12, v2, 1024);
  v3 = (const char **)v13;
  v4 = split_string(v12, 44, v13, 6);
  v5 = 0;
  if ( v4 <= 0 )
    goto LABEL_22;
  v6 = (const char **)&v13[v4];
  v7 = 0;
  do
  {
    v8 = *v3;
    if ( **v3 )
    {
      i = *v3;
      if ( **v3 == 59 )
      {
LABEL_21:
        *i = 0;
        v8 = *v3;
      }
      else
      {
        for ( i = *v3 + 1; ; ++i )
        {
          v8 = *v3;
          if ( !*i )
            break;
          if ( *i == 59 )
            goto LABEL_21;
        }
      }
    }
    if ( !strncmp(v8, "vue_userid=", 0xBu) )
    {
      v7 = v8 + 11;
    }
    else if ( !strncmp(v8, "vue_passwd=", 0xBu) )
    {
      v5 = v8 + 11;
    }
    ++v3;
  }
  while ( v3 != v6 );
  if ( v7 && v5 && (v10 = httpd_user_check_cookie(a1, v7, v5), v10 > 0) )
  {
    *(_DWORD *)(a1 + 205588) = v10;
    result = 0;
    *(_BYTE *)(a1 + 43) = 1;
  }
  else
  {
LABEL_22:
    *(_BYTE *)(a1 + 43) = 3;
    httpd_send_login_html(a1);
    result = -1;
  }
  return result;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

