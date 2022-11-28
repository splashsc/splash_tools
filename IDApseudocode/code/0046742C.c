int __fastcall get_hbmd_data(const char *a1, char *a2, int a3)
{
  int v5; // $s2
  int v6; // $s0
  const char **v7; // $s4
  void *v8; // $v0
  _DWORD *v9; // $s7
  void *v10; // $fp
  int v11; // $s6
  _DWORD *v12; // $s3
  int i; // $s2
  int v14; // $v0
  int v15; // $v0
  char *v16; // $a0
  int v17; // $s1
  int v18; // $v0
  char v20[64]; // [sp+18h] [-40h] BYREF

  snprintf(v20, 64, "hbmd_all_%s", a1);
  v5 = nvram_get(v20);
  v6 = snprintf(a2, a3, (char *)&word_642A04);
  if ( v6 >= a3 )
    v6 = a3 - 1;
  if ( v5 )
  {
    v7 = (const char **)malloc(0x14u);
    v9 = malloc(0x1008u);
    v8 = malloc(0x200000u);
    v10 = v8;
    if ( v8 )
    {
      if ( v7 )
      {
        if ( v9 )
        {
          strlcpy(v8, v5, 0x200000);
          v11 = split_string(v10, 60, v9, 1024);
          if ( v11 > 0 )
          {
            v12 = v9;
            for ( i = 0; i != v11; ++i )
            {
              v14 = split_string(*v12, 124, v7, 3);
              format_hbmd_data(v7, v14, &a2[v6], a3 - v6);
              v6 += v15;
              ++v12;
            }
          }
        }
      }
      free(v10);
    }
    if ( v7 )
      free(v7);
    if ( v9 )
      free(v9);
  }
  v16 = &a2[v6];
  if ( v6 > 0 && *(v16 - 1) == 44 )
    v16 = &a2[--v6];
  v17 = a3 - v6;
  *v16 = 0;
  v18 = snprintf(v16, v17, &byte_6445A0);
  if ( v18 >= v17 )
    v18 = v17 - 1;
  return v6 + v18;
}
// 4675C0: variable 'v15' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

