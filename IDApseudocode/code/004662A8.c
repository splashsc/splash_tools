int __fastcall get_time_group_data(char *a1, int a2)
{
  int v4; // $s2
  int v5; // $s0
  const char **v6; // $s4
  void *v7; // $v0
  _DWORD *v8; // $s7
  void *v9; // $fp
  int v10; // $s6
  _DWORD *v11; // $s3
  int i; // $s2
  int v13; // $v0
  int v14; // $v0
  char *v15; // $a0
  int v16; // $s1
  int v17; // $v0

  v4 = nvram_get("time_group");
  v5 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v5 >= a2 )
    v5 = a2 - 1;
  if ( v4 )
  {
    v6 = (const char **)malloc(0x14u);
    v8 = malloc(0x4008u);
    v7 = malloc(0x200000u);
    v9 = v7;
    if ( v7 )
    {
      if ( v6 )
      {
        if ( v8 )
        {
          strlcpy(v7, v4, 0x200000);
          v10 = split_string(v9, 60, v8, 4096);
          if ( v10 > 0 )
          {
            v11 = v8;
            for ( i = 0; i != v10; ++i )
            {
              v13 = split_string(*v11, 124, v6, 3);
              format_time_group_data(v6, v13, &a1[v5], a2 - v5);
              v5 += v14;
              ++v11;
            }
          }
        }
      }
      free(v9);
    }
    if ( v6 )
      free(v6);
    if ( v8 )
      free(v8);
  }
  v15 = &a1[v5];
  if ( v5 > 0 && *(v15 - 1) == 44 )
    v15 = &a1[--v5];
  v16 = a2 - v5;
  *v15 = 0;
  v17 = snprintf(v15, v16, &byte_6445A0);
  if ( v17 >= v16 )
    v17 = v16 - 1;
  return v5 + v17;
}
// 466414: variable 'v14' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

