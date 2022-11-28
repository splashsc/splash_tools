int __fastcall sub_44B60C(_BYTE **a1, int a2, int a3)
{
  _BYTE **v3; // $s0
  _BYTE *v4; // $a0
  int v7; // $s1
  int v8; // $s6
  char *v9; // $v0
  const char *v10; // $v0
  char v12[256]; // [sp+18h] [-108h] BYREF
  char *format; // [sp+118h] [-8h]

  v3 = a1;
  v4 = *a1;
  if ( !v4 || !*v4 )
    return 0;
  v7 = 0;
  format = " \"%s\":\"\",";
  do
  {
    v8 = jhl_nv_get_def(v4);
    strlcpy(v12, *v3, 256);
    v9 = strstr(v12, "_5g");
    if ( v9 )
      *v9 = 0;
    if ( v8 )
    {
      v10 = (const char *)get_json_data(v8);
      v7 += sprintf((char *)(a2 + v7), " \"%s\":\"%s\",", v12, v10);
    }
    else
    {
      v7 += sprintf((char *)(a2 + v7), format, v12);
    }
    ++v3;
    if ( v7 + 199 >= a3 )
      break;
    v4 = *v3;
    if ( !*v3 )
      break;
  }
  while ( *v4 );
  return v7;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);

