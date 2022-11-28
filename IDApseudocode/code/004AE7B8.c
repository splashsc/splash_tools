int sq_file_del_fun()
{
  int v0; // $a2
  bool v1; // dc
  int result; // $v0
  int v3[256]; // [sp+18h] [-400h] BYREF

  memset(v3, 0, sizeof(v3));
  v3[0] = 6;
  v3[3] = 2;
  v3[1] = 1024;
  v1 = jianhl_order_opt_fun(v3, 1024, v0) != 0;
  result = -1;
  if ( !v1 )
    result = v3[2];
  return result;
}
// 4AE810: variable 'v0' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

