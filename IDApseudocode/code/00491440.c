int __fastcall dns_more_rule_check_used_group(int a1, int a2)
{
  void *v3; // $v0
  int v4; // $s1
  void *v5; // $s0
  int v6; // $v0
  int v7; // $s1

  v4 = 4 - (a2 != 0);
  _mem_malloc(0x200000, "dns_more_rule_check_used_group", 56);
  if ( !v3 )
    return 0;
  v5 = v3;
  jhl_parm_get("dns_more_dnswan_rule", v3, 0x200000);
  v6 = nvparm_find_str(v5, 60, 4096, a1, 124, v4);
  v7 = 0;
  if ( v6 )
    v7 = 116;
  _mem_free(v5);
  return v7;
}
// 491494: variable 'v3' is possibly undefined
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

