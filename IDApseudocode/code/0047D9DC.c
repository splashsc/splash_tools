int __fastcall tg_url_get(char *a1, int a2, int *a3, int a4)
{
  int v8; // $a1
  int v9; // $a0
  int v10; // $v0
  int v11; // $a2
  int v12; // $v1
  bool v13; // dc
  int result; // $v0
  int v15[128]; // [sp+18h] [-200h] BYREF

  memset(v15, 0, sizeof(v15));
  v8 = a3[2];
  v9 = a3[3];
  v10 = *a3;
  v11 = a3[1];
  v12 = a3[4];
  v15[0] = 27;
  v15[3] = 3;
  v15[6] = v8;
  v15[7] = v9;
  v15[1] = 232;
  v15[4] = v10;
  v15[5] = v11;
  v15[8] = v12;
  v15[9] = a4;
  v13 = jianhl_order_opt_fun(v15, 232, v11) != 0;
  result = 0;
  if ( !v13 )
  {
    result = 0;
    if ( !v15[2] )
    {
      result = snprintf(a1, a2, "%s", (const char *)&v15[10]);
      if ( result >= a2 )
        result = a2 - 1;
    }
  }
  return result;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

