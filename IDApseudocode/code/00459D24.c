int defaults_asp_timer_fun()
{
  int v1[5]; // [sp+18h] [-14h] BYREF

  killall_tk("wan_flow_mr");
  prepare_upgrade();
  killall("pppoecd", 15);
  sleep(1u);
  v1[0] = (int)"nvram";
  v1[1] = (int)"defaults";
  v1[2] = (int)"--yes";
  v1[3] = 0;
  return eval(v1, 0, 0, 0);
}
// 6A8178: using guessed type int __fastcall killall(_DWORD, _DWORD);
// 6A81C0: using guessed type int prepare_upgrade(void);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);

