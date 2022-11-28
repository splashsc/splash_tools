int __fastcall sub_4CA910(int a1)
{
  const char *v1; // $v0
  char *v2; // $v1
  int v3; // $t2
  int v4; // $t1
  int v5; // $t0
  int v6; // $a3
  int v7; // $t1
  __int16 v8; // $t0
  char v9; // $a3
  int v10; // $v0
  char v12[2052]; // [sp+18h] [-804h] BYREF

  v1 = "{\"ret\":\"0\",\"msg\":\"not info\",\"data\":{}}";
  v2 = v12;
  do
  {
    v3 = *(_DWORD *)v1;
    v4 = *((_DWORD *)v1 + 1);
    v5 = *((_DWORD *)v1 + 2);
    v6 = *((_DWORD *)v1 + 3);
    v1 += 16;
    *(_DWORD *)v2 = v3;
    *((_DWORD *)v2 + 1) = v4;
    *((_DWORD *)v2 + 2) = v5;
    *((_DWORD *)v2 + 3) = v6;
    v2 += 16;
  }
  while ( v1 != "a\":{}}" );
  v7 = *(_DWORD *)v1;
  v8 = *((_WORD *)v1 + 2);
  v9 = v1[6];
  v10 = *(_DWORD *)(a1 + 36) | 0x8000;
  v2[6] = v9;
  *(_DWORD *)v2 = v7;
  *((_WORD *)v2 + 2) = v8;
  *(_DWORD *)(a1 + 36) = v10;
  return httpd_cgi_ret(a1, v12, 38, 4);
}

