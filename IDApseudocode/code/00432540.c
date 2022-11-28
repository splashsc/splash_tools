void __fastcall sub_432540(int a1)
{
  int v1; // $v0
  const char *v3; // $s0
  size_t v4; // $v0
  char *v5; // $v0
  int v6; // $v0
  char *v7; // $a1
  const char **v8; // $fp
  int v9; // $v0
  bool v10; // dc
  int v11; // $v0
  char *v12; // $s2
  const char *v13; // $s6
  const char *v14; // $s4
  const char *v15; // $s7
  const char *i; // $v0
  char v17[1024]; // [sp+8h] [-448h] BYREF
  char v18[32]; // [sp+408h] [-48h] BYREF

  if ( !*(_BYTE *)(a1 + 43) )
  {
    v1 = *(_DWORD *)(a1 + 32);
    if ( (v1 & 0x200) != 0 )
    {
      v3 = (const char *)(*(_DWORD *)(a1 + 205508) + 6);
      if ( !strstr(*(const char **)(a1 + 205508), "Basic") )
        goto LABEL_7;
      v4 = strlen(v3);
      v17[base64_decode(v3, v17, v4)] = 0;
      v5 = strchr(v17, 58);
      if ( v5 )
        *v5++ = 0;
      v6 = httpd_user_check(a1, v17, v5);
      if ( v6 <= 0 )
      {
LABEL_7:
        *(_BYTE *)(a1 + 43) = 3;
        return;
      }
    }
    else
    {
      if ( (v1 & 0x800) == 0 )
        goto LABEL_7;
      memset(v17, 0, sizeof(v17));
      v7 = strstr(*(const char **)(a1 + 205524), "vue_userid=");
      if ( !v7 )
        goto LABEL_7;
      strlcpy(v17, v7, 1024);
      v8 = (const char **)v18;
      v9 = split_string(v17, 44, v18, 6);
      v10 = v9 <= 0;
      v11 = 4 * v9;
      if ( v10 )
        goto LABEL_7;
      v12 = &v18[v11];
      v13 = 0;
      v14 = 0;
      do
      {
        v15 = *v8;
        if ( **v8 )
        {
          i = *v8;
          if ( **v8 == 59 )
          {
LABEL_28:
            *i = 0;
            v15 = *v8;
          }
          else
          {
            for ( i = *v8 + 1; ; ++i )
            {
              v15 = *v8;
              if ( !*i )
                break;
              if ( *i == 59 )
                goto LABEL_28;
            }
          }
        }
        if ( !strncmp(v15, "vue_userid=", 0xBu) )
        {
          v14 = v15 + 11;
        }
        else if ( !strncmp(v15, "vue_passwd=", 0xBu) )
        {
          v13 = v15 + 11;
        }
        ++v8;
      }
      while ( v8 != (const char **)v12 );
      if ( !v14 )
        goto LABEL_7;
      if ( !v13 )
        goto LABEL_7;
      v6 = httpd_user_check_cookie(a1, v14, v13);
      if ( v6 <= 0 )
        goto LABEL_7;
    }
    *(_DWORD *)(a1 + 205588) = v6;
    *(_BYTE *)(a1 + 43) = 1;
  }
}
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

