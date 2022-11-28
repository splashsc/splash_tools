int __fastcall user_name_pwd_get(int *a1, char *a2, char *a3)
{
  int v6; // $a1
  int v7; // $a0
  int v8; // $v0
  int v9; // $a2
  int v10; // $v1
  bool v11; // dc
  int result; // $v0
  int v13[513]; // [sp+18h] [-804h] BYREF

  memset(v13, 0, 0x800u);
  v6 = a1[2];
  v7 = a1[3];
  v8 = *a1;
  v9 = a1[1];
  v10 = a1[4];
  v13[0] = 16;
  v13[3] = 50;
  v13[6] = v6;
  v13[7] = v7;
  v13[1] = 2048;
  v13[4] = v8;
  v13[5] = v9;
  v13[8] = v10;
  v11 = jianhl_order_opt_fun(v13, 2048, v9) != 0;
  result = -1;
  if ( !v11 )
  {
    strcpy(a2, (char *)&v13[9]);
    strcpy(a3, (char *)&v13[25]);
    result = v13[2];
  }
  return result;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

