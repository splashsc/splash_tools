int __fastcall jhl_get_hi_redirect_ipmac(_DWORD *a1, char *a2)
{
  int v4; // $a1
  int v5; // $v0
  int v6; // $a3
  int v7; // $a2
  int v8; // $v1
  int v10[512]; // [sp+18h] [-800h] BYREF

  memset(v10, 0, sizeof(v10));
  v4 = a1[51368];
  v5 = a1[51365];
  v6 = a1[51366];
  v7 = a1[51367];
  v8 = a1[51369];
  v10[0] = 13;
  v10[3] = 49;
  v10[1] = 2048;
  v10[7] = v4;
  v10[4] = v5;
  v10[5] = v6;
  v10[6] = v7;
  v10[8] = v8;
  if ( jianhl_order_opt_fun(v10, 2048, v7) || v10[2] )
    return -1;
  strcpy(a2, (char *)&v10[9]);
  return 0;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

