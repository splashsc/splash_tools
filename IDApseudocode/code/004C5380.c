int __fastcall sub_4C5380(int a1)
{
  char *v2; // $s1
  char *v3; // $s2
  char *v4; // $s4
  char *v5; // $s6
  char *v6; // $v0
  char *v7; // $fp
  char *nptr; // $s7
  int v9; // $s3
  int v10; // $a0
  char *v11; // $a1
  int v12; // $a2
  char v13; // $v0
  char *v14; // $v1
  int v15; // $v0
  int v16; // $v0
  int v17; // $a1
  int v18; // $a0
  const char *v19; // $v0
  unsigned int v20; // $a2
  char *v22; // $v1
  int v23; // $v0
  int v24; // $v0
  char *v25; // $v1
  const char *v26; // $v0
  int v27; // $t0
  int v28; // $a3
  int v29; // $a2
  int v30; // $a1
  char *v31; // $v0
  char *v32; // $fp
  int v33; // $a3
  char *v34; // $fp
  char v35[256]; // [sp+28h] [-150h] BYREF
  char v36[64]; // [sp+128h] [-50h] BYREF
  int v37[2]; // [sp+168h] [-10h] BYREF
  char *s; // [sp+170h] [-8h]

  v2 = httpd_get_parm(a1, "opt");
  v3 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "remote_ipv4");
  v5 = httpd_get_parm(a1, "local_ipv4");
  v7 = httpd_get_parm(a1, "local_ipv6");
  v6 = httpd_get_parm(a1, "tunnel_enable");
  v37[0] = 0;
  v37[1] = 0;
  if ( !v2
    || (nptr = v6, (v9 = strcmp(v2, (const char *)&off_648DDC)) != 0)
    && strcmp(v2, (const char *)&off_646D8C)
    && strcmp(v2, "del") )
  {
    v19 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_23;
  }
  if ( !v3 || (v10 = *v3, v11 = v3 + 1, !*v3) )
  {
    v19 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
    goto LABEL_23;
  }
  v12 = 95;
  v13 = v10 | 0x20;
  do
  {
    ++v11;
    if ( (unsigned __int8)(v13 - 97) >= 0x1Au && (unsigned __int8)(v10 - 48) >= 0xAu && v10 != 95 && v10 != 46 )
    {
      v19 = (const char *)_GET_LANG_TEXT(159, *(unsigned __int8 *)(a1 + 210102), 95);
LABEL_23:
      v20 = snprintf(v35, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
      if ( v20 >= 0x100 )
        v20 = 255;
      return httpd_cgi_ret(a1, v35, v20, 4);
    }
    v10 = *(v11 - 1);
    v13 = v10 | 0x20;
  }
  while ( *(v11 - 1) );
  if ( !v9 || (s = "a", !strcmp(v2, (const char *)&off_646D8C)) )
  {
    if ( v4 )
    {
      v14 = "1\"";
      if ( *v4 )
      {
        s = "1\"";
        v15 = strcmp(v4, "any");
        v14 = "1\"";
        if ( v15 )
        {
          v16 = uv_inet_pton4(v4, v35);
          v14 = s;
          if ( v16 )
          {
            v17 = *(unsigned __int8 *)(a1 + 210102);
            v18 = 160;
            goto LABEL_21;
          }
        }
      }
      else
      {
        v4 = "any";
      }
    }
    else
    {
      v14 = "1\"";
      v4 = "any";
    }
    if ( v5 && *v5 && (s = v14, !uv_inet_pton4(v5, v35)) )
    {
      if ( !v7 || !*v7 )
      {
        uv_inet_pton4(v5, v37);
        v23 = strcmp(v4, s - 4312);
        s = v36;
        if ( v23 )
          snprintf(
            v36,
            64,
            "2002:%02x%02x:%02x%02x::1/48",
            LOBYTE(v37[0]),
            BYTE1(v37[0]),
            BYTE2(v37[0]),
            HIBYTE(v37[0]));
        else
          snprintf(
            v36,
            64,
            "2002:%02x%02x:%02x%02x::1/16",
            LOBYTE(v37[0]),
            BYTE1(v37[0]),
            BYTE2(v37[0]),
            HIBYTE(v37[0]));
        goto LABEL_36;
      }
      s = v36;
      snprintf(v36, 64, "%s", v7);
      v31 = strchr(s, 47);
      v32 = v31;
      if ( v31 )
        *v31 = 0;
      if ( v36[0] && !uv_inet_pton6(s, v35) )
      {
        if ( v32 )
        {
          v33 = atoi(v32 + 1);
          if ( (unsigned int)(v33 - 8) >= 0x79 )
            v33 = 64;
        }
        else
        {
          v34 = s;
          v32 = &v34[strlen(s)];
          v33 = 64;
        }
        snprintf(v32, (char *)v37 - v32, (char *)&off_650A30, v33);
LABEL_36:
        v24 = strcmp(v2, "del");
        v7 = s;
        if ( !v24 )
          goto LABEL_46;
        goto LABEL_37;
      }
      v17 = *(unsigned __int8 *)(a1 + 210102);
      v18 = 162;
    }
    else
    {
      v17 = *(unsigned __int8 *)(a1 + 210102);
      v18 = 161;
    }
LABEL_21:
    v19 = (const char *)_GET_LANG_TEXT(v18, v17, v12);
    goto LABEL_23;
  }
  if ( strcmp(v2, "del") )
  {
    v22 = s;
    goto LABEL_39;
  }
LABEL_46:
  sub_4C50A8((int)v3);
LABEL_37:
  if ( !strcmp(v2, (const char *)&off_648DDC) )
    goto LABEL_40;
  v22 = "a";
LABEL_39:
  if ( !strcmp(v2, v22 + 28044) )
  {
LABEL_40:
    if ( !nptr )
      nptr = "0";
    sub_4C51B0((int)v3, (int)v4, (int)v5, (int)v7, nptr);
  }
  v25 = v35;
  v26 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v27 = *(_DWORD *)v26;
    v28 = *((_DWORD *)v26 + 1);
    v29 = *((_DWORD *)v26 + 2);
    v30 = *((_DWORD *)v26 + 3);
    v26 += 16;
    *(_DWORD *)v25 = v27;
    *((_DWORD *)v25 + 1) = v28;
    *((_DWORD *)v25 + 2) = v29;
    *((_DWORD *)v25 + 3) = v30;
    v25 += 16;
  }
  while ( v26 != "}" );
  v20 = 33;
  *(_WORD *)v25 = *(_WORD *)v26;
  return httpd_cgi_ret(a1, v35, v20, 4);
}
// 4C55CC: variable 'v12' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 650A30: using guessed type void *off_650A30;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A870C: using guessed type int __fastcall uv_inet_pton6(_DWORD, _DWORD);
// 6A8714: using guessed type int __fastcall uv_inet_pton4(_DWORD, _DWORD);

