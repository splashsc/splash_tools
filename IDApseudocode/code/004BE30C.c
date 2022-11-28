int __fastcall get_rule_num(int a1, int a2)
{
  const char *v2; // $v0
  int v3; // $s1
  const char *v4; // $a0
  int v5; // $s1
  int v6; // $s0
  char *v7; // $v0

  v3 = a2 << 24;
  v2 = (const char *)jhl_nv_get_def(a1);
  if ( !v2 )
    return 0;
  v4 = v2;
  v5 = v3 >> 24;
  if ( !*v2 )
    return 0;
  v6 = 0;
  do
  {
    v7 = strchr(v4, v5);
    v4 = v7 + 1;
    ++v6;
  }
  while ( v7 && v7 != (char *)-1 && v7[1] );
  return v6;
}
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

