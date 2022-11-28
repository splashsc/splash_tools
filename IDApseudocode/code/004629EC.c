int __fastcall ddos_fy_black_list(char *a1, int a2)
{
  _DWORD *v4; // $v0
  int v5; // $a2
  _DWORD *v6; // $s2
  char *v7; // $s3
  int v8; // $s1
  _DWORD *v10; // $s0
  int v11; // $s4
  int v12; // $s1
  int v13; // $s7
  int v14; // $v0
  int v15; // $v1

  *(_WORD *)a1 = 91;
  _mem_malloc(102400, "ddos_fy_black_list", 1482);
  v6 = v4;
  if ( !v4 )
  {
    *(_WORD *)(a1 + 1) = 93;
    return 2;
  }
  *v4 = 12;
  v4[3] = 2;
  v4[1] = 102400;
  if ( !jianhl_order_opt_fun(v4, 102400, v5) && !v6[2] )
  {
    v10 = v6 + 6;
    if ( (int)v6[5] <= 0 )
    {
      v15 = 0;
      v14 = 1;
      v12 = 1;
    }
    else
    {
      v11 = a2 - 49;
      v12 = 1;
      v13 = 0;
      do
      {
        ++v13;
        v12 += sprintf(
                 &a1[v12],
                 "{\"m\":\"%02X:%02X:%02X:%02X:%02X:%02X\",\"type\":%d,\"time\":%d},",
                 *((unsigned __int8 *)v10 + 24),
                 *((unsigned __int8 *)v10 + 25),
                 *((unsigned __int8 *)v10 + 26),
                 *((unsigned __int8 *)v10 + 27),
                 *((unsigned __int8 *)v10 + 28),
                 *((unsigned __int8 *)v10 + 29),
                 v10[1],
                 v10[5]);
        if ( v12 >= v11 )
          break;
        v10 += 8;
      }
      while ( v13 < v6[5] );
      v14 = v12;
      if ( v12 <= 0 )
        goto LABEL_15;
      v15 = v12 - 1;
    }
    if ( a1[v15] == 44 )
      v14 = --v12;
LABEL_15:
    v7 = &a1[v14];
    *v7 = 0;
    v8 = v12 + 1;
    goto LABEL_4;
  }
  v7 = a1 + 1;
  v8 = 2;
LABEL_4:
  *(_WORD *)v7 = 93;
  _mem_free(v6);
  return v8;
}
// 462A5C: variable 'v4' is possibly undefined
// 462A7C: variable 'v5' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

