int __fastcall sub_4AE504(int a1)
{
  int *v2; // $v1
  const char *v3; // $v0
  int v4; // $t0
  int v5; // $a3
  int v6; // $a2
  int v7; // $a1
  int v9[1251]; // [sp+18h] [-138Ch] BYREF

  v9[0] = (int)"wys";
  v9[1] = (int)"errinfo";
  v9[2] = (int)"erase";
  v9[3] = 0;
  eval(v9, 0, 0, 0);
  v2 = v9;
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v4 = *(_DWORD *)v3;
    v5 = *((_DWORD *)v3 + 1);
    v6 = *((_DWORD *)v3 + 2);
    v7 = *((_DWORD *)v3 + 3);
    v3 += 16;
    *v2 = v4;
    v2[1] = v5;
    v2[2] = v6;
    v2[3] = v7;
    v2 += 4;
  }
  while ( v3 != "}" );
  *(_WORD *)v2 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, (char *)v9, 33, 4);
}
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);

