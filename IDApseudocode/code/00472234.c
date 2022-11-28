int __fastcall sub_472234(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  const char *v4; // $s0
  char *v5; // $v1
  const char *v6; // $v0
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  int v10; // $a1
  unsigned int v11; // $a2
  char *v13; // $s0
  const char *v14; // $v0
  const char *v15; // $s1
  char *v16; // $v0
  char *v17; // $v0
  const char *v18; // $s4
  __int64 v19; // $v0
  int v20; // $v0
  int v21; // $v0
  uint32_t v22; // $v0
  int v23[2560]; // [sp+20h] [-291Ch] BYREF
  char v24[256]; // [sp+2820h] [-11Ch] BYREF
  int v25; // [sp+2920h] [-1Ch] BYREF
  int v26; // [sp+2924h] [-18h]
  int v27; // [sp+2928h] [-14h]
  int v28; // [sp+292Ch] [-10h]
  int v29; // [sp+2930h] [-Ch]

  memset(v24, 0, sizeof(v24));
  v3 = httpd_get_parm(a1, "id");
  v2 = httpd_get_parm(a1, "opt");
  if ( v3 )
  {
    v4 = v2;
    if ( v2 )
    {
      if ( strcmp(v2, "all") )
      {
        if ( !strcmp(v4, "select") )
        {
          v15 = (const char *)v23;
          memset(v23, 0, sizeof(v23));
          v16 = httpd_get_parm(a1, "ips");
          if ( v16 )
          {
            strlcpy(v23, v16, 10240);
            while ( 1 )
            {
              if ( !*v15 )
                goto LABEL_5;
              v17 = strchr(v15, 124);
              v18 = 0;
              if ( v17 )
              {
                v18 = v17 + 1;
                *v17 = 0;
              }
              v25 = 0;
              v26 = 0;
              v27 = 0;
              v28 = 0;
              v29 = 0;
              if ( strchr(v15, 46) || strchr(v15, 58) )
              {
                StrToIpaddr(v15, &v25);
                LODWORD(v19) = v26;
              }
              else
              {
                v22 = J_atoi(v15);
                LODWORD(v19) = htonl(v22);
                v26 = v19;
              }
              if ( (_BYTE)v25 )
                break;
              if ( (_DWORD)v19 )
                goto LABEL_27;
LABEL_25:
              if ( !v18 )
                goto LABEL_5;
              v15 = v18;
            }
            HIDWORD(v19) = v27 | v28 | v29;
            if ( !v19 )
              goto LABEL_25;
LABEL_27:
            v20 = jhl_nv_get_def("macuser_down_del");
            v21 = J_atoi(v20);
            user_ipdown_set(&v25, v21);
            goto LABEL_25;
          }
        }
        goto LABEL_5;
      }
      if ( !strcmp(v3, "pppoe") )
      {
        v13 = "pppoe";
      }
      else
      {
        if ( strcmp(v3, "web") )
          goto LABEL_5;
        v13 = "web";
      }
      v23[0] = (int)"wys";
      v23[1] = (int)"user";
      v23[2] = (int)"down_all";
      v23[3] = (int)v13;
      v23[4] = 0;
      eval(v23, 0, 0, 0);
LABEL_5:
      v5 = v24;
      v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v7 = *(_DWORD *)v6;
        v8 = *((_DWORD *)v6 + 1);
        v9 = *((_DWORD *)v6 + 2);
        v10 = *((_DWORD *)v6 + 3);
        v6 += 16;
        *(_DWORD *)v5 = v7;
        *((_DWORD *)v5 + 1) = v8;
        *((_DWORD *)v5 + 2) = v9;
        *((_DWORD *)v5 + 3) = v10;
        v5 += 16;
      }
      while ( v6 != "}" );
      v11 = 33;
      *(_WORD *)v5 = *(_WORD *)v6;
      return httpd_cgi_ret(a1, v24, v11, 4);
    }
  }
  v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not id or opt");
  v11 = snprintf(v24, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
  if ( v11 >= 0x100 )
    v11 = 255;
  return httpd_cgi_ret(a1, v24, v11, 4);
}
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A82C4: using guessed type int __fastcall user_ipdown_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

