int __fastcall dns_more_dnstype_search(_WORD *a1, size_t a2, int a3)
{
  int v6; // $a1
  int v7; // $a2
  bool v8; // dc
  int result; // $v0
  int v10; // $v1
  int v11[256]; // [sp+20h] [-400h] BYREF

  memset(v11, 0, sizeof(v11));
  v11[0] = 58;
  v11[3] = 22;
  v11[1] = 1024;
  strlcpy(&v11[4], a3, 128);
  v6 = v11[1];
  *a1 = 91;
  v8 = jianhl_order_opt_fun(v11, v6, v7) == 0;
  result = 2;
  if ( v8 )
  {
    memset(a1, 0, a2);
    if ( BYTE2(v11[36]) )
    {
      v10 = sprintf(
              (char *)a1,
              "{\"dns\":\"%s\",\"name\":\"%s\",\"sys\":%d}",
              (const char *)&v11[4],
              (const char *)&v11[36] + 2,
              BYTE1(v11[36]));
      result = v10 + 1;
    }
    else
    {
      result = 1;
      v10 = 0;
    }
  }
  else
  {
    v10 = 1;
  }
  *(_WORD *)((char *)a1 + v10) = 93;
  return result;
}
// 492E08: variable 'v7' is possibly undefined
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

