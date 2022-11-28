int __fastcall exec_service(const char *a1)
{
  int v2; // $s0
  _BYTE *v3; // $v0
  int v4; // $s0
  int result; // $v0
  bool v6; // dc

  if ( debug_level > 0 )
    printf("%s:%d exec_service: %s\n", "exec_service", 6260, a1);
  v2 = 10;
  while ( 1 )
  {
    v3 = (_BYTE *)nvram_get("action_service");
    --v2;
    if ( v3 )
    {
      if ( !*v3 )
        break;
    }
    if ( v2 == -1 )
      break;
    if ( debug_level > 0 )
      printf("%s:%d %s: waiting before %d\n", "exec_service", 6264, "exec_service", v2);
    sleep(1u);
  }
  nvram_set("action_service", a1);
  kill(1, 16);
  v4 = 3;
  while ( 1 )
  {
    result = nvram_get("action_service");
    if ( !result )
      break;
    if ( !a1 )
      break;
    v6 = strcmp((const char *)result, a1) == 0;
    result = -1;
    if ( !v6 )
      break;
    if ( --v4 == -1 )
      break;
    if ( debug_level > 0 )
      printf("%s:%d %s: waiting after %d\n", "exec_service", 6273, "exec_service", v4);
    sleep(1u);
  }
  return result;
}
// 67D0BC: using guessed type int debug_level;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

