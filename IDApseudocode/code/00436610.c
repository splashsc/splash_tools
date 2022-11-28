int __fastcall mr_list_index_get(int a1, int a2, int a3)
{
  int v3; // $s1
  int v6; // $s0
  int v7; // $s2
  int v8; // $s5
  int v9; // $v0

  if ( *(int *)(a1 + 4) <= 0 )
    return 0;
  v3 = a3;
  if ( a3 < 100 )
    return 0;
  v6 = a1 + 8;
  v7 = 0;
  v8 = 0;
  do
  {
    v9 = snprintf(
           (char *)(a2 + v7),
           v3,
           "{\"iface\":%d,\"status\":%d,\"status_v6\":%d,\"jh_en\":%d,\"jh_val\":%lu,\"zc_en\":%d,\"host\":%d,\"ct_num\":%d},",
           *(unsigned __int16 *)(v6 + 8) - 1,
           *(unsigned __int8 *)(v6 + 2),
           *(unsigned __int8 *)(v6 + 7),
           *(unsigned __int8 *)(v6 + 1),
           *(_DWORD *)(v6 + 20),
           *(unsigned __int8 *)(v6 + 120),
           *(_DWORD *)(v6 + 12),
           *(_DWORD *)(v6 + 16));
    if ( v9 >= v3 )
      v9 = v3 - 1;
    ++v8;
    v3 -= v9;
    v7 += v9;
    v6 += 340;
  }
  while ( v8 < *(_DWORD *)(a1 + 4) && v3 >= 100 );
  return v7;
}

