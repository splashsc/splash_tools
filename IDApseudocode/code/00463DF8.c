int __fastcall qos_rule_check_used_group(int a1, int a2, int a3, int a4, size_t n, int a6)
{
  int v8; // $s2
  _DWORD *v9; // $s0
  int v10; // $s3
  int v11; // $fp
  int v12; // $s1
  int v13; // $v0
  _DWORD v15[4096]; // [sp+18h] [-4098h] BYREF
  int v16[19]; // [sp+4018h] [-98h] BYREF
  char v17[68]; // [sp+4064h] [-4Ch] BYREF
  int (__fastcall *v18)(int, _DWORD); // [sp+40A8h] [-8h]

  if ( a3 )
  {
    v8 = 15;
    v18 = (int (__fastcall *)(int, _DWORD))check_time_group_contain;
  }
  else
  {
    v8 = 10;
    v18 = (int (__fastcall *)(int, _DWORD))check_ips_group_contain;
  }
  snprintf(v17, 64, "sqos_%s", (const char *)a1);
  memset((void *)a4, 0, n);
  jhl_parm_get(v17, a4, n);
  v9 = v15;
  v10 = split_string(a4, 60, v15, 4096);
  if ( v10 <= 0 )
    return 0;
  v11 = 0;
  v12 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      ++v12;
      if ( v8 < split_string(*v9, 124, v16, 17) )
      {
        if ( v18(a2, v15[v8 + 4096]) )
          break;
      }
      ++v9;
      if ( v10 == v12 )
        return v11;
    }
    if ( !a6 )
      break;
    v11 = 123;
    v13 = cJSON_CreateString(v16[0]);
    cJSON_AddItemToArray(a6, v13);
    ++v9;
    if ( v10 == v12 )
      return v11;
  }
  return 123;
}
// 6A83FC: using guessed type int __fastcall cJSON_CreateString(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8858: using guessed type int __fastcall cJSON_AddItemToArray(_DWORD, _DWORD);

