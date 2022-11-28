int __fastcall sub_4CABA8(int a1)
{
  const char *v1; // $v0
  char *v2; // $v1
  int v4; // $t1
  int v5; // $t0
  int v6; // $a3
  int v7; // $a1
  int v8; // $t0
  int v9; // $a3
  __int16 v10; // $v0
  int v11; // $v0
  char v13[2048]; // [sp+18h] [-1004h] BYREF
  char v14[2052]; // [sp+818h] [-804h] BYREF

  v1 = (const char *)&unk_65139C;
  v2 = v14;
  do
  {
    v4 = *(_DWORD *)v1;
    v5 = *((_DWORD *)v1 + 1);
    v6 = *((_DWORD *)v1 + 2);
    v7 = *((_DWORD *)v1 + 3);
    v1 += 16;
    *(_DWORD *)v2 = v4;
    *((_DWORD *)v2 + 1) = v5;
    *((_DWORD *)v2 + 2) = v6;
    *((_DWORD *)v2 + 3) = v7;
    v2 += 16;
  }
  while ( v1 != "\"CAST\"}]}" );
  v8 = *(_DWORD *)v1;
  v9 = *((_DWORD *)v1 + 1);
  v10 = *((_WORD *)v1 + 4);
  *(_DWORD *)v2 = v8;
  *((_DWORD *)v2 + 1) = v9;
  *((_WORD *)v2 + 4) = v10;
  v11 = gbk_to_utf8(v14, v13, 2047);
  *(_DWORD *)(a1 + 36) |= 0x8000u;
  return httpd_cgi_ret(a1, v13, v11, 4);
}
// 6A85C8: using guessed type int __fastcall gbk_to_utf8(_DWORD, _DWORD, _DWORD);

