int __fastcall set_vlan_name_data(int a1)
{
  int v2; // $a0

  if ( !a1 || nvram_match_def("vlan_name", a1) )
    return -1;
  nvram_set("vlan_name_old", a1);
  jhl_parm_commit(v2);
  return 0;
}
// 44867C: variable 'v2' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

