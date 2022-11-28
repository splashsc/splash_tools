int __fastcall httpd_do_wwwparm(_DWORD *a1, const char *a2)
{
  char *v3; // $v0
  char *v4; // $s1
  char *v5; // $v0
  char *v6; // $v0
  char *v7; // $s0
  int v8; // $v1
  char *v9; // $fp
  char *v10; // $v0
  unsigned int v11; // $v0
  int v13; // $v1
  int v14; // $v0
  int v15; // $v1
  char *v16; // $v0
  int v17; // $v0
  char *v18; // $v0
  const char *v19; // $a0
  size_t v20; // $v0
  int v21; // $v1

  v3 = strchr(a2, 10);
  v4 = v3 + 1;
  if ( v3 && v3 != (char *)-1 && v3[1] )
  {
    do
    {
      v5 = strchr(v4, 10);
      if ( v5 )
      {
        *v5 = 0;
        v7 = v5 + 1;
        v6 = strchr(v4, 58);
        if ( !v6 )
          goto LABEL_22;
      }
      else
      {
        v6 = strchr(v4, 58);
        v7 = 0;
        if ( !v6 )
          break;
      }
      v8 = v6[1];
      v9 = v6 + 1;
      *v6 = 0;
      if ( v8 )
      {
        do
        {
          if ( v8 != 32 && v8 != 9 )
            break;
          v8 = *++v9;
        }
        while ( *v9 );
      }
      v10 = strchr(v9, 13);
      if ( !v10 )
        goto LABEL_22;
      *v10 = 0;
      strlower(v4);
      if ( !strcmp(v4, "content-length") )
      {
        v14 = J_atoi(v9);
        v15 = a1[8] | 0x80;
        a1[51374] = v14;
        v4 = v7;
        a1[8] = v15;
      }
      else
      {
        if ( !strcmp(v4, "content-type") )
        {
          if ( strstr(v9, "x-www-form-urlencoded") )
          {
            a1[8] |= 0x80000u;
          }
          else
          {
            v18 = strstr(v9, "boundary=");
            v19 = v18 + 9;
            if ( v18 )
            {
              a1[51378] = v19;
              v20 = strlen(v19);
              v21 = a1[8] | 0x100;
              a1[51379] = v20;
              a1[8] = v21;
            }
          }
          if ( strstr(v9, "application/json") )
          {
            a1[8] |= 0x8000000u;
            v4 = v7;
            continue;
          }
LABEL_22:
          v4 = v7;
          continue;
        }
        if ( !strcmp(v4, "connection") )
        {
          strlower(v9);
          v4 = v7;
          if ( !strcmp(v9, "keep-alive") )
          {
            a1[8] |= 2u;
          }
          else
          {
            if ( strcmp(v9, "upgrade") )
              goto LABEL_22;
            a1[8] |= 0x100000u;
            v4 = v7;
          }
        }
        else if ( !strcmp(v4, "cookie") )
        {
          v13 = a1[8] | 0x800;
          a1[51372] = v9;
          v4 = v7;
          a1[8] = v13;
          a1[51381] = v9;
        }
        else
        {
          if ( !strcmp(v4, "if-modified-since") )
          {
            v16 = strchr(v9, 59);
            if ( v16 )
              *v16 = 0;
            v17 = a1[8] | 4;
            a1[51373] = v9;
            v4 = v7;
            a1[8] = v17;
            continue;
          }
          if ( !strcmp(v4, "x-jhlss") )
          {
            a1[8] |= 0x10u;
            v4 = v7;
            a1[51375] = v9;
          }
          else if ( !strcmp(v4, "host") )
          {
            a1[8] |= 0x20u;
            v4 = v7;
            a1[51376] = v9;
          }
          else if ( !strcmp(v4, "x-jhljson") )
          {
            v4 = v7;
            a1[8] |= 0x40u;
          }
          else if ( !strcmp(v4, "authorization") )
          {
            a1[8] |= 0x200u;
            v4 = v7;
            a1[51377] = v9;
          }
          else if ( !strcmp(v4, "referer") )
          {
            a1[8] |= 0x400u;
            v4 = v7;
            a1[51380] = v9;
          }
          else if ( !strcmp(v4, "user-agent") )
          {
            a1[8] |= 0x10000u;
            v4 = v7;
            a1[51382] = v9;
          }
          else if ( !strcmp(v4, "range") )
          {
            a1[8] |= 0x20000u;
            v4 = v7;
            a1[51383] = v9;
          }
          else if ( !strcmp(v4, "upgrade") )
          {
            strlower(v9);
            if ( strcmp(v9, "websocket") )
              goto LABEL_22;
            a1[8] |= 0x200000u;
            v4 = v7;
            a1[52498] = v9;
          }
          else if ( !strcmp(v4, "sec-websocket-version") )
          {
            if ( strcmp(v9, "13") )
              goto LABEL_22;
            a1[8] |= 0x400000u;
            v4 = v7;
            a1[52499] = v9;
          }
          else if ( !strcmp(v4, "sec-websocket-key") )
          {
            a1[8] |= 0x800000u;
            v4 = v7;
            a1[52500] = v9;
          }
          else if ( !strcmp(v4, "sec-websocket-extensions") )
          {
            a1[8] |= 0x1000000u;
            v4 = v7;
            a1[52501] = v9;
          }
          else if ( !strcmp(v4, "sec-websocket-protocol") )
          {
            a1[8] |= 0x2000000u;
            v4 = v7;
            a1[52502] = v9;
          }
          else if ( !strcmp(v4, "origin") )
          {
            a1[8] |= 0x4000000u;
            v4 = v7;
            a1[52503] = v9;
          }
          else
          {
            if ( strcmp(v4, "accept-language") )
              goto LABEL_22;
            a1[8] |= 0x10000000u;
            v4 = v7;
            a1[51384] = v9;
          }
        }
      }
    }
    while ( v7 && *v7 );
  }
  v11 = a1[9] & 0xFFFFFFFE;
  a1[8] &= 0xFFFFFFFD;
  a1[9] = v11;
  httpd_set_cookie_language((int)a1);
  return 0;
}
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

