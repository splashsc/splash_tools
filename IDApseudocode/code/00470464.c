int __fastcall sub_470464(int a1)
{
  char *v1; // $v0
  int v3; // $a0
  char *v4; // $v1
  const char *v5; // $v0
  int v6; // $t1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  char v11[1024]; // [sp+18h] [-400h] BYREF

  v1 = httpd_get_parm(a1, "lx");
  if ( !v1 )
    v1 = " ";
  jhl_parm_set("rzglLx", v1);
  jhl_parm_commit(v3);
  v4 = v11;
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v6 = *(_DWORD *)v5;
    v7 = *((_DWORD *)v5 + 1);
    v8 = *((_DWORD *)v5 + 2);
    v9 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v4 = v6;
    *((_DWORD *)v4 + 1) = v7;
    *((_DWORD *)v4 + 2) = v8;
    *((_DWORD *)v4 + 3) = v9;
    v4 += 16;
  }
  while ( v5 != "}" );
  *(_WORD *)v4 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v11, 33, 4);
}
// 4704C4: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);

