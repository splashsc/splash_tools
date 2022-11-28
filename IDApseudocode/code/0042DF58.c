int cpu_rate_set()
{
  bool v0; // dc
  int result; // $v0
  int v2; // $v0
  int v3; // $s0
  __int64 v4; // $v0
  int v5[8]; // [sp+20h] [-30h] BYREF
  int v6; // [sp+40h] [-10h] BYREF
  int v7; // [sp+44h] [-Ch]
  int v8; // [sp+48h] [-8h]

  v5[0] = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v5[6] = 0;
  v5[7] = 0;
  v0 = _get_cpu_uptime(&v6) != 0;
  result = -1;
  if ( !v0 )
  {
    v2 = v6;
    if ( v6 != dword_67D0C8 )
    {
      v3 = 20 * (v7 - dword_67D0CC);
      if ( _ltsf2(v3, 1065353216) < 0 )
      {
        v4 = 0x3FF0000000000000LL;
      }
      else
      {
        LODWORD(v4) = _gtsf2(v3, 1120272384);
        if ( (int)v4 > 0 )
          v4 = 0x4058C00000000000LL;
      }
      snprintf((char *)v5, 32, "%.1f", *(double *)&v4);
      nvram_set("device_cpu_rate", v5);
      v2 = v6;
    }
    dword_67D0C8 = v2;
    dword_67D0CC = v7;
    result = 0;
    dword_67D0D0 = v8;
  }
  return result;
}
// 42E09C: variable 'v4' is possibly undefined
// 67D0C8: using guessed type int dword_67D0C8;
// 67D0CC: using guessed type int dword_67D0CC;
// 67D0D0: using guessed type int dword_67D0D0;
// 6A8400: using guessed type int __fastcall _get_cpu_uptime(_DWORD);
// 6A8638: using guessed type int __fastcall _ltsf2(_DWORD, _DWORD);
// 6A8798: using guessed type int __fastcall _gtsf2(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

