int __fastcall qq_rule_check_used_group(const char *a1, void *a2, size_t a3, int a4)
{
  char *v8; // $s0
  int v9; // $s2
  int v10; // $s6
  int v11; // $s1
  int v12; // $v0
  int v13; // $v0
  char v15[16384]; // [sp+18h] [-4018h] BYREF
  int v16[6]; // [sp+4018h] [-18h] BYREF

  memset(a2, 0, a3);
  jhl_parm_get("hbmd_all_commqq", a2, a3);
  v8 = v15;
  v9 = split_string(a2, 60, v15, 4096);
  if ( v9 <= 0 )
    return 0;
  v10 = 0;
  v11 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      ++v11;
      if ( split_string(*(_DWORD *)v8, 124, v16, 3) >= 3 )
      {
        check_time_group_contain(a1, (const char *)v16[2]);
        if ( v12 )
          break;
      }
      v8 += 4;
      if ( v9 == v11 )
        return v10;
    }
    if ( !a4 )
      break;
    v10 = 122;
    v13 = cJSON_CreateString(v16[0]);
    cJSON_AddItemToArray(a4, v13);
    v8 += 4;
    if ( v9 == v11 )
      return v10;
  }
  return 122;
}
// 463D7C: variable 'v12' is possibly undefined
// 6A83FC: using guessed type int __fastcall cJSON_CreateString(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);

