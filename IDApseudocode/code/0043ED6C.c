int __fastcall sub_43ED6C(int a1)
{
  char *v2; // $s1
  const char *v3; // $v0
  int v4; // $a0
  char *v5; // $v1
  const char *v6; // $v0
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  int v10; // $a1
  char v12[1028]; // [sp+18h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "en");
  memset(v12, 0, 0x400u);
  if ( v2 )
  {
    v3 = (const char *)nvram_get("sfe_enable");
    if ( !v3 || strcmp(v3, v2) )
    {
      nvram_set("sfe_enable", v2);
      restart_sfe();
      jhl_parm_commit(v4);
    }
  }
  v5 = v12;
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
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, v12, 33, 4);
}
// 43EE48: variable 'v4' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A893C: using guessed type int restart_sfe(void);

