int __fastcall sub_4CA7E0(int a1)
{
  const char *v1; // $v0
  char *v2; // $v1
  int v3; // $t2
  int v4; // $t1
  int v5; // $t0
  int v6; // $a3
  char v7; // $a3
  int v8; // $v0
  char v10[2052]; // [sp+18h] [-804h] BYREF

  v1 = "{\"ret\":\"0\",\"msg\":\"ok\",\"data\":{}}";
  v2 = v10;
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
  while ( v1 != "" );
  v7 = *v1;
  v8 = *(_DWORD *)(a1 + 36) | 0x8000;
  *v2 = v7;
  *(_DWORD *)(a1 + 36) = v8;
  return httpd_cgi_ret(a1, v10, 32, 4);
}

