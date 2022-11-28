int __fastcall url_member_get_file(char *a1, size_t a2)
{
  unsigned __int8 *v4; // $v0
  int v5; // $a2
  unsigned __int8 *v6; // $s6
  signed int v7; // $s1
  const char *v9; // $v0
  int v10; // $v0
  char *v11; // $v1
  _DWORD *v12; // $a0
  int v13; // $a1
  int v14; // $a2
  int v15; // $a1
  char v16; // $a2
  char v17; // $a1
  char v18; // $a0
  char *v19; // $a0
  const char *v20; // $s0
  signed int v21; // $s3
  int v22; // $s7

  _mem_malloc(0x200000, "url_member_get_file", 403);
  v6 = v4;
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = 24;
  *((_DWORD *)v4 + 3) = 5;
  *((_DWORD *)v4 + 1) = 0x200000;
  v7 = 0;
  if ( !jianhl_order_opt_fun(v4, 0x200000, v5) )
  {
    memset(a1, 0, a2);
    v9 = (const char *)jhl_nv_get_def(&unk_64A61C);
    v10 = sprintf(a1, "gids:%s\r\n", v9);
    v11 = &a1[v10];
    v12 = &unk_64A6D8;
    do
    {
      v13 = v12[1];
      *(_DWORD *)v11 = *v12;
      *((_DWORD *)v11 + 1) = v13;
      v14 = v12[2];
      *((_DWORD *)v11 + 1) = v13;
      *((_DWORD *)v11 + 2) = v14;
      v15 = v12[3];
      *((_DWORD *)v11 + 2) = v14;
      *((_DWORD *)v11 + 3) = v15;
      v12 += 4;
      *((_DWORD *)v11 + 3) = v15;
      v11 += 16;
    }
    while ( v12 != (_DWORD *)&unk_64A708 );
    v16 = *(_BYTE *)v12;
    v17 = *((_BYTE *)v12 + 1);
    v18 = *((_BYTE *)v12 + 2);
    *v11 = v16;
    v11[2] = v18;
    v11[1] = v17;
    v7 = v10 + 50;
    v19 = &a1[v10 + 50];
    v20 = (const char *)(v6 + 24);
    if ( *((int *)v6 + 5) > 0 )
    {
      v21 = a2 - 49;
      v22 = 0;
      do
      {
        v7 += sprintf(
                v19,
                "{n:%s,u:%s,g:%u}\r\n",
                &v20[*((unsigned __int8 *)v20 + 2) + 9],
                v20 + 8,
                *(unsigned __int8 *)v20);
        ++v22;
        v19 = &a1[v7];
        if ( v7 >= v21 )
          break;
        v20 += *((unsigned __int8 *)v20 + 3) + 8;
      }
      while ( v22 < *((_DWORD *)v6 + 5) );
    }
  }
  _mem_free(v6);
  return v7;
}
// 487D4C: variable 'v4' is possibly undefined
// 487D70: variable 'v5' is possibly undefined
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

