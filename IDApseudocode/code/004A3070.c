int __fastcall sub_4A3070(int a1)
{
  int v1; // $v0
  int v3; // $v0
  const char *v4; // $v0
  char *v5; // $s0
  const char *v6; // $a1
  int v7; // $a0
  const char *v8; // $v0
  char *v9; // $v1
  int v10; // $t1
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  char v15[512]; // [sp+18h] [-200h] BYREF

  v1 = httpd_get_json_parm(a1, (int)"menus");
  v3 = cJSON_PrintUnformatted(v1);
  if ( v3 )
  {
    v5 = (char *)v3;
    v4 = (const char *)nvram_get("vue_customeze_menus");
    if ( !v4 || strcmp(v4, v5) )
    {
      v6 = v5;
      if ( !*v5 )
        v6 = "[]";
      nvram_set("vue_customeze_menus", v6);
      jhl_parm_commit(v7);
    }
    free(v5);
  }
  v8 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v9 = v15;
  do
  {
    v10 = *(_DWORD *)v8;
    v11 = *((_DWORD *)v8 + 1);
    v12 = *((_DWORD *)v8 + 2);
    v13 = *((_DWORD *)v8 + 3);
    v8 += 16;
    *(_DWORD *)v9 = v10;
    *((_DWORD *)v9 + 1) = v11;
    *((_DWORD *)v9 + 2) = v12;
    *((_DWORD *)v9 + 3) = v13;
    v9 += 16;
  }
  while ( v8 != "}" );
  *(_WORD *)v9 = *(_WORD *)v8;
  return httpd_cgi_ret(a1, v15, 33, 4);
}
// 4A3144: variable 'v7' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A85D0: using guessed type int __fastcall cJSON_PrintUnformatted(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

