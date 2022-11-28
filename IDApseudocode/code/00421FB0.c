int __fastcall usb_acc_check(int *a1)
{
  int v2; // $a1
  int v3; // $a0
  int v4; // $v0
  int v5; // $a2
  int v6; // $v1
  int result; // $v0
  int v8[257]; // [sp+18h] [-404h] BYREF

  memset(v8, 0, 0x400u);
  v2 = a1[2];
  v3 = a1[3];
  v4 = *a1;
  v5 = a1[1];
  v6 = a1[4];
  v8[0] = 11;
  v8[3] = 29;
  v8[6] = v2;
  v8[7] = v3;
  v8[1] = 1024;
  v8[4] = v4;
  v8[5] = v5;
  v8[8] = v6;
  result = jianhl_order_opt_fun(v8, 1024, v5);
  if ( result )
    return 0;
  if ( !v8[2] )
  {
    if ( v8[9] )
      result = v8[10];
    else
      result = nvram_match_def("usb_acc_wan", "1") == 0;
  }
  return result;
}
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

