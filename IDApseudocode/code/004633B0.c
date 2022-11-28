int __fastcall sub_4633B0(const char *a1, int a2)
{
  const char **v2; // $s0
  int v4; // $s2
  int v5; // $s1
  char v7[2052]; // [sp+18h] [-804h] BYREF

  v2 = (const char **)v7;
  v4 = split_string(a2, 44, v7, 510);
  if ( v4 <= 0 )
    return 0;
  v5 = 0;
  while ( 1 )
  {
    ++v5;
    if ( !strcmp(a1, *v2) )
      break;
    ++v2;
    if ( v4 == v5 )
      return 0;
  }
  return 1;
}
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

