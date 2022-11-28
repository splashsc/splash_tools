int __fastcall ai_ping_test(int a1, int a2)
{
  char *v2; // $v0
  int v4[10]; // [sp+18h] [-2Ch] BYREF
  char v5; // [sp+40h] [-4h] BYREF

  v2 = (char *)v4;
  do
  {
    *(_DWORD *)v2 = 0;
    v2 += 4;
  }
  while ( v2 != &v5 );
  v4[0] = (int)"ping";
  v4[1] = (int)"-c";
  v4[2] = (int)"4";
  v4[5] = a1;
  v4[3] = (int)"-s";
  v4[4] = (int)"32";
  eval_nowait_file(v4, ">>/tmp/ai_wx_wan_ping/ping", 0, a2);
  return 0;
}
// 6A8640: using guessed type int __fastcall eval_nowait_file(_DWORD, _DWORD, _DWORD, _DWORD);

