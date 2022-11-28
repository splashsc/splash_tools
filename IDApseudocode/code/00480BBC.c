int __fastcall webauth_data_timeout(_DWORD *a1)
{
  int v2; // $a1
  int v3; // $a0
  int v4; // $a3
  int v5; // $a2
  int v6; // $v1
  _DWORD *v7; // $s1
  int v8; // $v0
  int v9; // $s3
  int v11[257]; // [sp+18h] [-404h] BYREF

  memset(v11, 0, 0x400u);
  v2 = a1[51367];
  v3 = a1[51368];
  v4 = a1[51365];
  v5 = a1[51366];
  v6 = a1[51369];
  v11[0] = 16;
  v11[3] = 41;
  v11[6] = v2;
  v11[7] = v3;
  v11[1] = 1024;
  v11[4] = v4;
  v11[5] = v5;
  v11[8] = v6;
  if ( jianhl_order_opt_fun(v11, 1024, v5) )
  {
    v7 = a1 + 49152;
    v8 = a1[51393];
    v11[9] = 0;
    if ( v8 >= 5 )
    {
      v9 = 0;
LABEL_4:
      a1[51388] = httpd_keep_alive_timeout;
      a1[51387] = jiffies_get() + 5000;
      add_timer(a1 + 51385);
      return webauth_data_send((int)a1, v9);
    }
  }
  else
  {
    v9 = v11[9];
    if ( v11[9] )
      goto LABEL_4;
    v7 = a1 + 49152;
    v8 = a1[51393];
    v9 = 0;
    if ( v8 >= 5 )
      goto LABEL_4;
  }
  v7[2241] = v8 + 1;
  v7[2235] = jiffies_get() + 1000;
  v7[2237] = a1;
  v7[2236] = &webauth_data_timeout;
  return add_timer(a1 + 51385);
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

