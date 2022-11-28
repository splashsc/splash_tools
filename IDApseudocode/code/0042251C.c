int __fastcall jhl_get_hi_redirect_url(_DWORD *a1, char *a2, int a3)
{
  int v6; // $a1
  int v7; // $v0
  int v8; // $a3
  int v9; // $a2
  int v10; // $v1
  int v11; // $s0
  int v13[513]; // [sp+18h] [-804h] BYREF

  memset(v13, 0, 0x800u);
  v6 = a1[51368];
  v7 = a1[51365];
  v8 = a1[51366];
  v9 = a1[51367];
  v10 = a1[51369];
  v13[0] = 13;
  v13[3] = 47;
  v13[1] = 2048;
  v13[7] = v6;
  v13[4] = v7;
  v13[5] = v8;
  v13[6] = v9;
  v13[8] = v10;
  if ( jianhl_order_opt_fun(v13, 2048, v9) )
    return -1;
  v11 = v13[2];
  if ( v13[2] )
    return -1;
  snprintf(a2, a3, "http://%s", (const char *)&v13[11]);
  if ( (v13[10] & 0xFFFF0000) != 16842752 )
    v11 = HIBYTE(v13[10]);
  return v11;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

