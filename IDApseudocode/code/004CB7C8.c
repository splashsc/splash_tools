void **iptv_token_init_and_check_timeout()
{
  _DWORD *v0; // $v0
  void **result; // $v0
  void **v2; // $a0
  void **v3; // $s0
  int v4[3]; // [sp+18h] [-Ch] BYREF

  if ( !dword_681510 )
  {
    v0 = &iptv_token_hlist_head;
    do
      *v0++ = 0;
    while ( v0 != (_DWORD *)&end );
    dword_681510 = 1;
  }
  result = (void **)get_uptime2(v4);
  v2 = (void **)iptv_token_list_head;
  v3 = *(void ***)iptv_token_list_head;
  if ( iptv_token_list_head != &iptv_token_list_head )
  {
    while ( 1 )
    {
      if ( (unsigned int)(v4[0] - (_DWORD)*(v2 - 11)) < 0x3D )
      {
        result = (void **)*v3;
        v2 = v3;
        if ( v3 == &iptv_token_list_head )
          return result;
      }
      else
      {
        iptv_token_del(v2 - 11);
        result = (void **)*v3;
        v2 = v3;
        if ( v3 == &iptv_token_list_head )
          return result;
      }
      v3 = result;
    }
  }
  return result;
}
// 67BEBC: using guessed type void *iptv_token_list_head;
// 681510: using guessed type int dword_681510;
// 6A8804: using guessed type int __fastcall get_uptime2(_DWORD);

