signed int __fastcall dns_acc_get(char *a1, size_t a2)
{
  char *v4; // $v0
  int v5; // $a2
  char *v6; // $s6
  signed int v7; // $s0
  const char *v9; // $s5
  int v10; // $fp
  int v11; // $v0

  _mem_malloc(0x200000, "dns_acc_get", 2471);
  v6 = v4;
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = 4;
  *((_DWORD *)v4 + 3) = 10;
  *((_DWORD *)v4 + 1) = 0x200000;
  if ( jianhl_order_opt_fun(v4, 0x200000, v5) || (memset(a1, 0, a2), v9 = v6 + 16, *((int *)v6 + 2) <= 0) )
  {
    v7 = 0;
  }
  else
  {
    v7 = 0;
    v10 = 0;
    do
    {
      v11 = snprintf(&a1[v7], a2 - v7, "%s<", v9);
      if ( v11 >= (int)(a2 - v7) )
        v11 = a2 - v7 - 1;
      v7 += v11;
      ++v10;
      if ( v7 >= (int)(a2 - 49) )
        break;
      v9 += 128;
    }
    while ( v10 < *((_DWORD *)v6 + 2) );
  }
  _mem_free(v6);
  return v7;
}
// 46AA94: variable 'v4' is possibly undefined
// 46AAB8: variable 'v5' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

