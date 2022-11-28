int __fastcall sub_4746CC(int a1)
{
  char *v2; // $v0
  const char *v3; // $v0
  const char *v4; // $s1
  int v5; // $a0
  char *v6; // $v1
  const char *v7; // $v0
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v11; // $a1
  char v13[260]; // [sp+18h] [-104h] BYREF

  memset(v13, 0, 0x100u);
  v2 = httpd_get_parm(a1, "en");
  if ( v2 )
  {
    v4 = v2;
    v3 = (const char *)nvram_get("user_list_enable");
    if ( !v3 || strcmp(v3, v4) )
    {
      nvram_set("user_list_enable", v4);
      jhl_parm_commit(v5);
    }
  }
  v6 = v13;
  v7 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v8 = *(_DWORD *)v7;
    v9 = *((_DWORD *)v7 + 1);
    v10 = *((_DWORD *)v7 + 2);
    v11 = *((_DWORD *)v7 + 3);
    v7 += 16;
    *(_DWORD *)v6 = v8;
    *((_DWORD *)v6 + 1) = v9;
    *((_DWORD *)v6 + 2) = v10;
    *((_DWORD *)v6 + 3) = v11;
    v6 += 16;
  }
  while ( v7 != "}" );
  *(_WORD *)v6 = *(_WORD *)v7;
  return httpd_cgi_ret(a1, v13, 33, 4);
}
// 474794: variable 'v5' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

