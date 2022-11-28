int __fastcall sub_472D44(int a1)
{
  const char *v2; // $v0
  const char *v3; // $s0
  int v4; // $v0
  char v6[200]; // [sp+18h] [-11Ch] BYREF
  int v7[12]; // [sp+E0h] [-54h] BYREF
  int v8[5]; // [sp+110h] [-24h] BYREF
  int v9; // [sp+124h] [-10h] BYREF
  __int16 v10; // [sp+128h] [-Ch]

  v9 = 0;
  v10 = 0;
  v7[0] = 0;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[8] = 0;
  v7[9] = 0;
  v7[10] = 0;
  v7[11] = 0;
  v8[0] = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v8[4] = 0;
  find_hs_mac((_DWORD *)a1, (int)&v9, 0);
  v3 = (const char *)IpaddrToStr(v7, a1 + 205460);
  v2 = (const char *)MacToStr(v8, &v9);
  v4 = sprintf(v6, "{\"ip\":\"%s\",\"mac\":\"%s\"}", v3, v2);
  return httpd_cgi_ret(a1, v6, v4, 4);
}
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);

