int __fastcall ctxz_rule_check_used_group(int a1, int a2, void *a3, size_t a4, int a5)
{
  int v8; // $s2
  _DWORD *v9; // $s0
  int v10; // $s3
  int v11; // $fp
  int v12; // $s1
  int v13; // $v0
  _DWORD v15[4096]; // [sp+18h] [-4028h] BYREF
  int v16[8]; // [sp+4018h] [-28h] BYREF
  int (__fastcall *v17)(int, _DWORD); // [sp+4038h] [-8h]

  if ( a2 )
  {
    v8 = 5;
    v17 = (int (__fastcall *)(int, _DWORD))check_time_group_contain;
  }
  else
  {
    v8 = 2;
    v17 = (int (__fastcall *)(int, _DWORD))check_ips_group_contain;
  }
  memset(a3, 0, a4);
  jhl_parm_get("hixz_ct", a3, a4);
  v9 = v15;
  v10 = split_string(a3, 60, v15, 4096);
  if ( v10 <= 0 )
    return 0;
  v11 = 0;
  v12 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      ++v12;
      if ( v8 < split_string(*v9, 124, v16, 6) )
      {
        if ( v17(a1, v15[v8 + 4096]) )
          break;
      }
      ++v9;
      if ( v10 == v12 )
        return v11;
    }
    if ( !a5 )
      break;
    v11 = 126;
    v13 = cJSON_CreateString(v16[0]);
    cJSON_AddItemToArray(a5, v13);
    ++v9;
    if ( v10 == v12 )
      return v11;
  }
  return 126;
}
// 6A83FC: using guessed type int __fastcall cJSON_CreateString(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);

