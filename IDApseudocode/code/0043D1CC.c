int __fastcall sub_43D1CC(int a1)
{
  char *v2; // $v1
  const char *v3; // $v0
  int v4; // $t0
  int v5; // $a3
  int v6; // $a2
  int v7; // $a1
  char v9[128]; // [sp+18h] [-94h] BYREF
  int v10[5]; // [sp+98h] [-14h] BYREF

  memset(v9, 0, sizeof(v9));
  v10[0] = (int)"wys";
  v10[1] = (int)"dns";
  v10[2] = (int)"dnsc_clear";
  v10[3] = 0;
  eval(v10, 0, 0, 0);
  v2 = v9;
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v4 = *(_DWORD *)v3;
    v5 = *((_DWORD *)v3 + 1);
    v6 = *((_DWORD *)v3 + 2);
    v7 = *((_DWORD *)v3 + 3);
    v3 += 16;
    *(_DWORD *)v2 = v4;
    *((_DWORD *)v2 + 1) = v5;
    *((_DWORD *)v2 + 2) = v6;
    *((_DWORD *)v2 + 3) = v7;
    v2 += 16;
  }
  while ( v3 != "}" );
  *(_WORD *)v2 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, v9, 33, 4);
}
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);

