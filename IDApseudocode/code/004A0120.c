void __fastcall speed_test_mr_list(int a1)
{
  int v1; // $s0
  int v3; // $s1
  unsigned int v4; // $v0
  int (__fastcall **v5)(_DWORD, _DWORD); // $t9
  const char *v6; // $a0
  unsigned int v7; // $a1
  int v8; // $v0
  char *v9; // $v0
  int v10[5]; // [sp+8h] [-38h] BYREF

  if ( *(int *)(a1 + 4) > 0 )
  {
    v1 = a1 + 8;
    v3 = 0;
    do
    {
      v4 = *(unsigned __int16 *)(v1 + 8);
      v5 = &jhl_vpnget;
      v6 = (const char *)&unk_645880;
      v7 = v4 - 101;
      if ( v4 < 0x65 )
      {
        v6 = "wan_name";
        v7 = v4 - 1;
        v5 = &jhl_nvget;
      }
      v8 = ((int (__fastcall *)(const char *, unsigned int, int (__fastcall **)(_DWORD, _DWORD)))v5)(v6, v7, &jhl_nvget);
      v9 = (char *)nvram_get(v8);
      if ( !v9 )
        v9 = "";
      v10[0] = (int)"speedTest";
      v10[1] = (int)v9;
      v10[2] = 0;
      eval_nowait(v10, 0, 0, 0);
      ++v3;
      v1 += 340;
    }
    while ( v3 < *(_DWORD *)(a1 + 4) );
  }
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

