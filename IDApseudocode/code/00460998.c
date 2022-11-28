int __fastcall arp_st_getfile(void *a1, signed int a2)
{
  char *v4; // $v0
  int v5; // $a2
  char *v6; // $s2
  int v7; // $s0
  const char *v9; // $s1
  int v10; // $s5
  int v11; // $v0
  int v12; // $v0
  int v13; // $v0
  int v14; // $s3
  int v15; // $s0
  int v16; // $v0
  int v17; // $v0
  char v18[32]; // [sp+20h] [-60h] BYREF
  char v19[32]; // [sp+40h] [-40h] BYREF
  int v20; // [sp+60h] [-20h]
  int v21; // [sp+64h] [-1Ch]
  char *v22; // [sp+68h] [-18h]
  char *v23; // [sp+6Ch] [-14h]
  char *v24; // [sp+70h] [-10h]
  char *v25; // [sp+74h] [-Ch]
  char *v26; // [sp+78h] [-8h]
  char *format; // [sp+7Ch] [-4h]

  v24 = "a";
  _mem_malloc(0x200000, "arp_st_getfile", 645);
  v6 = v4;
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = 3;
  *((_DWORD *)v4 + 3) = 7;
  *((_DWORD *)v4 + 1) = 0x200000;
  v7 = 0;
  if ( !jianhl_order_opt_fun(v4, 0x200000, v5) )
  {
    memset(a1, 0, a2);
    v7 = snprintf((char *)a1, a2, aIIpaddrMMacadd);
    if ( v7 >= a2 )
      v7 = a2 - 1;
    v9 = v6 + 76;
    if ( *((int *)v6 + 5) > 0 )
    {
      v22 = "a";
      v10 = 0;
      v23 = "a";
      v26 = "a";
      v21 = a2 - 149;
      format = ",t:only";
      v25 = "undefine";
      do
      {
        v20 = IpToStr(v19, *((_DWORD *)v9 - 13));
        v12 = MacToStr(v18, v9 - 40);
        v13 = snprintf((char *)a1 + v7, a2 - v7, v22 + 26548, v20, v12, v9 - 24);
        if ( v13 >= a2 - v7 )
          v13 = a2 - v7 - 1;
        v14 = v13 + v7;
        if ( *((_DWORD *)v9 - 7) == 4 )
        {
          v17 = snprintf((char *)a1 + v14, a2 - v14, format);
          if ( v17 >= a2 - v14 )
            v17 = a2 - v14 - 1;
          v14 += v17;
        }
        if ( *v9 )
        {
          v15 = a2 - v14;
          if ( strcmp(v9, v25) )
          {
            v16 = snprintf((char *)a1 + v14, a2 - v14, v26 + 26572, v9);
            if ( v16 >= v15 )
              v16 = v15 - 1;
            v14 += v16;
          }
        }
        v11 = snprintf((char *)a1 + v14, a2 - v14, v23 + 26580);
        if ( v11 >= a2 - v14 )
          v11 = a2 - v14 - 1;
        v7 = v14 + v11;
        ++v10;
        if ( v14 + v11 >= v21 )
          break;
        v9 += 96;
      }
      while ( v10 < *((_DWORD *)v6 + 5) );
    }
  }
  _mem_free(v6);
  return v7;
}
// 460A00: variable 'v4' is possibly undefined
// 460A24: variable 'v5' is possibly undefined
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

