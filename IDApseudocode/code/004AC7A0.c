int __fastcall sub_4AC7A0(int a1)
{
  char *v2; // $s1
  char *v3; // $s4
  char *v4; // $s7
  char *v5; // $s5
  char *v6; // $s6
  char *v7; // $s3
  char *v8; // $v1
  const char *v9; // $v0
  int v10; // $t0
  int v11; // $a3
  int v12; // $a2
  int v13; // $a1
  char v15[1028]; // [sp+28h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "fx");
  v4 = httpd_get_parm(a1, "ip");
  v5 = httpd_get_parm(a1, "type");
  v6 = httpd_get_parm(a1, "outdev");
  v7 = httpd_get_parm(a1, "indev");
  if ( !v2 || strcmp(v2, "1") )
    v2 = "0";
  if ( v3 )
  {
    if ( v5 )
      goto LABEL_6;
  }
  else
  {
    v3 = "all";
    if ( v5 )
    {
LABEL_6:
      if ( v6 )
        goto LABEL_7;
      goto LABEL_12;
    }
  }
  v5 = "0";
  if ( !v6 )
LABEL_12:
    v6 = "WAN1";
LABEL_7:
  if ( !v7 )
    v7 = "0";
  sprintf(v15, "%s<%s<%s<%s<%s<%s", v2, v3, v4, v5, v6, v7);
  jhl_parm_set("jingx2", v15);
  jingx_do(-1, 0);
  v8 = v15;
  v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v10 = *(_DWORD *)v9;
    v11 = *((_DWORD *)v9 + 1);
    v12 = *((_DWORD *)v9 + 2);
    v13 = *((_DWORD *)v9 + 3);
    v9 += 16;
    *(_DWORD *)v8 = v10;
    *((_DWORD *)v8 + 1) = v11;
    *((_DWORD *)v8 + 2) = v12;
    *((_DWORD *)v8 + 3) = v13;
    v8 += 16;
  }
  while ( v9 != "}" );
  *(_WORD *)v8 = *(_WORD *)v9;
  jhl_parm_commit("}");
  return httpd_cgi_ret(a1, v15, 33, 4);
}
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82E8: using guessed type int __fastcall jingx_do(_DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);

