int __fastcall pppoe_br_get_state(char *a1, size_t a2)
{
  char *v4; // $v0
  int v5; // $a2
  char *v6; // $fp
  int v7; // $v0
  int v8; // $s7
  char *v10; // $s5
  int v11; // $s3
  int v12; // $v0
  int v13; // $v0
  char v14[32]; // [sp+28h] [-38h] BYREF
  int v15; // [sp+48h] [-18h]
  char *v16; // [sp+4Ch] [-14h]
  char *format; // [sp+50h] [-10h]
  char *v18; // [sp+54h] [-Ch]
  char *v19; // [sp+58h] [-8h]
  char *v20; // [sp+5Ch] [-4h]

  _mem_malloc(a2, "pppoe_br_get_state", 1202);
  v6 = v4;
  if ( v4 )
  {
    *(_DWORD *)v4 = 41;
    *((_DWORD *)v4 + 3) = 2;
    *((_DWORD *)v4 + 1) = a2;
    if ( !jianhl_order_opt_fun(v4, a2, v5) )
    {
      memset(a1, 0, a2);
      v10 = v6 + 2116;
      v16 = "1\"";
      v15 = a2 - 49;
      format = "%u-%u";
      v8 = 0;
      v19 = "%u";
      v11 = 1;
      v18 = ".%u-%u";
      v20 = ".%u";
      do
      {
        if ( *((unsigned __int16 *)v10 + 8) == *((unsigned __int16 *)v10 + 9) )
          v12 = sprintf(v14, v19);
        else
          v12 = sprintf(v14, format);
        if ( *((_WORD *)v10 + 10) )
        {
          if ( *((unsigned __int16 *)v10 + 10) == *((unsigned __int16 *)v10 + 11) )
            sprintf(&v14[v12], v20);
          else
            sprintf(&v14[v12], v18);
        }
        v13 = snprintf(&a1[v8], a2 - v8, v16 - 15576, v11, v10, *((_DWORD *)v10 + 6), *((_DWORD *)v10 + 7), v14);
        if ( v13 >= (int)(a2 - v8) )
          v13 = a2 - v8 - 1;
        v8 += v13;
        if ( v8 >= v15 )
          break;
        ++v11;
        v10 += 32;
      }
      while ( v11 != 3 );
      if ( v8 > 0 )
      {
        v7 = v8;
        if ( a1[v8 - 1] != 44 )
          goto LABEL_4;
        --v8;
      }
      v7 = v8;
      goto LABEL_4;
    }
  }
  v7 = 0;
  v8 = 0;
LABEL_4:
  a1[v7] = 0;
  _mem_free(v6);
  return v8;
}
// 49BA50: variable 'v4' is possibly undefined
// 49BA70: variable 'v5' is possibly undefined
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

