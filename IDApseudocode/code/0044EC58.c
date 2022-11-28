int __fastcall get_duolanlist_data(char *a1, int a2)
{
  int v4; // $s0
  char *v5; // $s1
  int v6; // $s7
  int i; // $s2
  int v8; // $s3
  int v9; // $v0
  char *v10; // $a0
  int v11; // $s4
  int v12; // $v0
  char v14[8192]; // [sp+20h] [-2098h] BYREF
  char v15[136]; // [sp+2020h] [-98h] BYREF
  const char *v16[4]; // [sp+20A8h] [-10h] BYREF

  memset(v14, 0, sizeof(v14));
  jhl_parm_get("duolanlist", v14, 0x2000);
  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  v5 = v15;
  v6 = split_string(v14, 60, v15, 32);
  if ( v6 > 0 )
  {
    for ( i = 0; i != v6; ++i )
    {
      v8 = a2 - v4;
      if ( split_string(*(_DWORD *)v5, 124, v16, 2) >= 2 )
      {
        v9 = snprintf(&a1[v4], a2 - v4, "{\"ip\":\"%s\",\"mask\":\"%s\"},", v16[0], v16[1]);
        if ( v9 >= v8 )
          v9 = v8 - 1;
        v4 += v9;
      }
      v5 += 4;
    }
  }
  v10 = &a1[v4];
  if ( v4 > 0 && *(v10 - 1) == 44 )
    v10 = &a1[--v4];
  v11 = a2 - v4;
  *v10 = 0;
  v12 = snprintf(v10, v11, &byte_6445A0);
  if ( v12 >= v11 )
    v12 = v11 - 1;
  return v4 + v12;
}
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

