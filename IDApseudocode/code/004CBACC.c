const char *__fastcall sub_4CBACC(const char *a1)
{
  int v2; // $a0
  const char *v3; // $a1
  int v4; // $v1
  int v5; // $v0
  const char *v6; // $s0

  iptv_token_init_and_check_timeout();
  v2 = *a1;
  if ( *a1 )
  {
    v3 = a1;
    v4 = 0;
    do
    {
      ++v3;
      v5 = 65600 * v4 + v2;
      v2 = *v3;
      v4 = v5 - v4;
    }
    while ( *v3 );
    v4 = (unsigned __int8)v4;
  }
  else
  {
    v4 = 0;
  }
  v6 = (const char *)iptv_token_hlist_head[v4];
  if ( !v6 )
    return 0;
  while ( strcmp(v6 - 48, a1) )
  {
    v6 = *(const char **)v6;
    if ( !v6 )
      return 0;
  }
  get_uptime2(v6 - 52);
  return v6 - 52;
}
// 6A8804: using guessed type int __fastcall get_uptime2(_DWORD);

