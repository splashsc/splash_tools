int __fastcall sub_4228B4(int a1)
{
  int v2; // $t0
  int v3; // $a3
  int v4; // $a2
  int v5; // $v1
  int v6; // $a0
  char v7; // $t2
  int v8; // $a1
  char v9; // $t1
  int result; // $v0
  int v11; // $t2
  int v12; // $t3
  int v13; // $t1
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  char v18; // $a0
  int v19[257]; // [sp+18h] [-404h] BYREF

  memset(v19, 0, 0x400u);
  v2 = *(_DWORD *)(a1 + 12);
  v3 = *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a1 + 20);
  v5 = *(_DWORD *)(a1 + 24);
  v6 = *(_DWORD *)(a1 + 8);
  v7 = *(_BYTE *)(a1 + 4);
  v8 = *(_DWORD *)a1;
  v9 = *(_BYTE *)(a1 + 5);
  v19[0] = 13;
  v19[3] = 52;
  v19[1] = 1024;
  v19[4] = v8;
  LOBYTE(v19[5]) = v7;
  BYTE1(v19[5]) = v9;
  v19[6] = v6;
  v19[7] = v2;
  v19[8] = v3;
  v19[9] = v4;
  v19[10] = v5;
  if ( jianhl_order_opt_fun(v19, 1024, v4) )
    return -1;
  result = v19[2];
  if ( v19[2] )
    return -1;
  v11 = *(int *)((char *)&v19[29] + 1);
  v12 = *(int *)((char *)&v19[28] + 1);
  *(_BYTE *)(a1 + 96) = v19[28];
  v13 = *(int *)((char *)&v19[30] + 1);
  v14 = *(int *)((char *)&v19[31] + 1);
  v15 = *(int *)((char *)&v19[32] + 1);
  v16 = *(int *)((char *)&v19[33] + 1);
  v17 = *(int *)((char *)&v19[34] + 1);
  *(_DWORD *)(a1 + 97) = v12;
  *(_DWORD *)(a1 + 101) = v11;
  *(_DWORD *)(a1 + 105) = v13;
  *(_DWORD *)(a1 + 109) = v14;
  *(_DWORD *)(a1 + 113) = v15;
  *(_DWORD *)(a1 + 117) = v16;
  *(_DWORD *)(a1 + 121) = v17;
  LOBYTE(v17) = BYTE2(v19[35]);
  v18 = HIBYTE(v19[35]);
  *(_BYTE *)(a1 + 125) = BYTE1(v19[35]);
  *(_BYTE *)(a1 + 126) = v17;
  *(_BYTE *)(a1 + 127) = v18;
  return result;
}
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

