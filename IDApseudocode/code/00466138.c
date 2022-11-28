int __fastcall time_group_get_id(int a1)
{
  char *v1; // $s0
  int v2; // $s2
  unsigned int v3; // $s4
  int v4; // $s1
  unsigned int v5; // $v0
  char v7[16384]; // [sp+18h] [-4018h] BYREF
  int v8[6]; // [sp+4018h] [-18h] BYREF

  v1 = v7;
  v2 = split_string(a1, 60, v7, 4096);
  if ( v2 <= 0 )
    return 1;
  v3 = 0;
  v4 = 0;
  do
  {
    while ( 1 )
    {
      ++v4;
      if ( split_string(*(_DWORD *)v1, 124, v8, 3) >= 3 )
      {
        v5 = J_atoi(v8[0]);
        if ( v3 < v5 )
          break;
      }
      v1 += 4;
      if ( v2 == v4 )
        return v3 + 1;
    }
    v3 = v5;
    v1 += 4;
  }
  while ( v2 != v4 );
  return v3 + 1;
}
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

