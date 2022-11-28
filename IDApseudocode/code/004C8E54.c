int __fastcall is_in_time(int a1, int a2, int a3)
{
  const char **v5; // $s0
  int v6; // $s3
  int v7; // $s1
  char *v8; // $v0
  char *v9; // $s2
  bool v10; // dc
  int result; // $v0
  char v12[1024]; // [sp+18h] [-604h] BYREF
  char v13[516]; // [sp+418h] [-204h] BYREF

  strlcpy(v12, a1, 1024);
  v5 = (const char **)v13;
  v6 = split_string(v12, 44, v13, 120);
  if ( v6 <= 0 )
    return 0;
  v7 = 0;
  while ( 1 )
  {
    v8 = strchr(*v5, 58);
    v9 = v8;
    ++v7;
    if ( v8 )
    {
      *v8 = 0;
      if ( atoi(*v5) == a2 )
      {
        v10 = atoi(v9 + 1) != a3;
        result = 1;
        if ( !v10 )
          break;
      }
    }
    ++v5;
    if ( v6 == v7 )
      return 0;
  }
  return result;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

