int __fastcall pppoe_opt(__int16 a1, __int16 a2)
{
  int v4; // $a2
  bool v5; // dc
  int result; // $v0
  int v7[256]; // [sp+18h] [-400h] BYREF

  memset(v7, 0, sizeof(v7));
  v7[0] = 9;
  v7[3] = 7;
  v7[1] = 1024;
  LOWORD(v7[4]) = a1;
  HIWORD(v7[4]) = a2;
  v5 = jianhl_order_opt_fun(v7, 1024, v4) != 0;
  result = -1;
  if ( !v5 )
    result = v7[2];
  return result;
}
// 498D24: variable 'v4' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

