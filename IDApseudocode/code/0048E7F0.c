int __fastcall sub_48E7F0(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s2
  int v5; // $a1
  const char *v6; // $a2
  const char *v7; // $v0
  const char **v8; // $v1
  const char *v9; // $v0
  const char *v10; // $t0
  const char *v11; // $a3
  const char *v12; // $a2
  const char *v13; // $a1
  unsigned int v14; // $a2
  const char *v16; // $v0
  const char *v17; // [sp+20h] [-404h] BYREF
  const char *v18; // [sp+24h] [-400h]
  const char *v19; // [sp+28h] [-3FCh]
  const char *v20; // [sp+2Ch] [-3F8h]
  int v21; // [sp+30h] [-3F4h]
  int v22; // [sp+34h] [-3F0h]

  v3 = httpd_get_parm(a1, "opt");
  v2 = httpd_get_parm(a1, "ip");
  if ( v3 )
  {
    v4 = (int)v2;
    if ( !strcmp(v3, "disconn") )
    {
      if ( v4 )
      {
        v17 = "racoonctl";
        v18 = "-s";
        v19 = "/var/run/racoon.sock";
        v7 = "vpn-disconnect";
LABEL_11:
        v20 = v7;
        v21 = v4;
        v22 = 0;
        eval_nowait(&v17, 0, 0, 0);
LABEL_12:
        v8 = &v17;
        v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v10 = *(const char **)v9;
          v11 = (const char *)*((_DWORD *)v9 + 1);
          v12 = (const char *)*((_DWORD *)v9 + 2);
          v13 = (const char *)*((_DWORD *)v9 + 3);
          v9 += 16;
          *v8 = v10;
          v8[1] = v11;
          v8[2] = v12;
          v8[3] = v13;
          v8 += 4;
        }
        while ( v9 != "}" );
        v14 = 33;
        *(_WORD *)v8 = *(_WORD *)v9;
        return httpd_cgi_ret(a1, (char *)&v17, v14, 4);
      }
LABEL_9:
      v5 = *(unsigned __int8 *)(a1 + 210102);
      v6 = "NOT IP";
      goto LABEL_20;
    }
    if ( !strcmp(v3, "conn") )
    {
      if ( v4 )
      {
        v17 = "racoonctl";
        v18 = "-s";
        v19 = "/var/run/racoon.sock";
LABEL_18:
        v7 = "vpn-connect";
        goto LABEL_11;
      }
      goto LABEL_9;
    }
    if ( !strcmp(v3, "reboot") )
    {
      if ( v4 )
      {
        if ( strcmp(v3, "reboot") )
          goto LABEL_12;
        v17 = "racoonctl";
        v18 = "-s";
        v19 = "/var/run/racoon.sock";
        v20 = "vpn-disconnect";
        v21 = v4;
        v22 = 0;
        eval_nowait(&v17, 0, 0, 0);
        v17 = "racoonctl";
        v18 = "-s";
        v19 = "/var/run/racoon.sock";
        goto LABEL_18;
      }
      goto LABEL_9;
    }
  }
  v5 = *(unsigned __int8 *)(a1 + 210102);
  v6 = "NOT OPT";
LABEL_20:
  v16 = (const char *)_GET_LANG_TEXT(12, v5, v6);
  v14 = snprintf((char *)&v17, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
  if ( v14 >= 0x400 )
    v14 = 1023;
  return httpd_cgi_ret(a1, (char *)&v17, v14, 4);
}
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);

