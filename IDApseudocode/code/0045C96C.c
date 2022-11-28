int __fastcall sub_45C96C(int a1)
{
  unsigned int v2; // $s4
  char *v3; // $v0
  char *v4; // $s2
  char *v5; // $s3
  int v6; // $a0
  char *v7; // $v1
  const char *v8; // $v0
  int v9; // $t0
  int v10; // $a3
  int v11; // $a2
  int v12; // $a1
  char v14[512]; // [sp+18h] [-200h] BYREF

  memset(v14, 0, sizeof(v14));
  v2 = time(0);
  v4 = httpd_get_parm(a1, "http_username");
  v3 = httpd_get_parm(a1, "http_passwd");
  v5 = v3;
  if ( !v4 )
  {
    if ( !v3 )
      goto LABEL_7;
    goto LABEL_3;
  }
  nvram_set("http_hadmin", v4);
  if ( v5 )
LABEL_3:
    nvram_set("http_hadminpwd", v5);
  if ( v2 >= 0x5FEDF581 )
    nvram_set_int("http_hadmin_time", v2);
  jhl_parm_commit(v6);
  jhl_httpd_reset_user();
LABEL_7:
  v7 = v14;
  v8 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v9 = *(_DWORD *)v8;
    v10 = *((_DWORD *)v8 + 1);
    v11 = *((_DWORD *)v8 + 2);
    v12 = *((_DWORD *)v8 + 3);
    v8 += 16;
    *(_DWORD *)v7 = v9;
    *((_DWORD *)v7 + 1) = v10;
    *((_DWORD *)v7 + 2) = v11;
    *((_DWORD *)v7 + 3) = v12;
    v7 += 16;
  }
  while ( v8 != "}" );
  *(_WORD *)v7 = *(_WORD *)v8;
  return httpd_cgi_ret(a1, v14, 33, 4);
}
// 45CA64: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

