int __fastcall find_hs_mac(_DWORD *a1, int a2, _BYTE *a3)
{
  int v6; // $a1
  int v7; // $v0
  int v8; // $a3
  int v9; // $a2
  int v10; // $v1
  bool v11; // dc
  int result; // $v0
  char v13; // $a1
  char v14; // $v1
  int v15[129]; // [sp+18h] [-204h] BYREF

  memset(v15, 0, 0x200u);
  v6 = a1[51368];
  v7 = a1[51365];
  v8 = a1[51366];
  v9 = a1[51367];
  v10 = a1[51369];
  v15[0] = 13;
  v15[3] = 30;
  v15[1] = 512;
  v15[7] = v6;
  v15[4] = v7;
  v15[5] = v8;
  v15[6] = v9;
  v15[8] = v10;
  v11 = jianhl_order_opt_fun(v15, 512, v9) != 0;
  result = -1;
  if ( !v11 )
  {
    result = v15[2];
    if ( v15[2] )
    {
      result = -1;
    }
    else
    {
      if ( a2 )
      {
        v13 = v15[10];
        v14 = BYTE1(v15[10]);
        *(_DWORD *)a2 = v15[9];
        *(_BYTE *)(a2 + 4) = v13;
        *(_BYTE *)(a2 + 5) = v14;
      }
      if ( a3 )
        *a3 = v15[12];
    }
  }
  return result;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

