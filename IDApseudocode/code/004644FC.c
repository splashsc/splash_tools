_DWORD *__fastcall _get_timer_man_tid(int a1, const char *a2, const char *a3)
{
  int v6; // $s2
  size_t v7; // $s7
  _DWORD *v8; // $s0
  const char *v9; // $s1
  int v10; // $v0
  char v12[64]; // [sp+18h] [-40h] BYREF

  memset(v12, 0, sizeof(v12));
  v6 = 0;
  v7 = strlen(a2);
  snprintf(v12, 64, "\"%s\"", a3);
  v8 = *(_DWORD **)(a1 + 8);
  if ( v8 )
  {
    do
    {
      v9 = (const char *)GetJSONItemValueAsString(v8, &off_646D58);
      if ( !memcmp(v9, a2, v7) )
      {
        if ( strstr(v9, v12) )
        {
          v10 = GetJSONItemValueAsIntDef(v8, &off_646D54, 0);
          if ( v10 )
            dword_67D500[v6++] = v10;
        }
      }
      v8 = (_DWORD *)*v8;
    }
    while ( v8 && v6 < 4095 );
  }
  dword_67D500[v6] = 0;
  return dword_67D500;
}
// 646D54: using guessed type void *off_646D54;
// 646D58: using guessed type void *off_646D58;
// 6A84CC: using guessed type int __fastcall GetJSONItemValueAsIntDef(_DWORD, _DWORD, _DWORD);
// 6A887C: using guessed type int __fastcall GetJSONItemValueAsString(_DWORD, _DWORD);

