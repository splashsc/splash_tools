_DWORD *__fastcall iptv_token_create(const char *a1)
{
  int v2; // $v0
  _DWORD *v3; // $s1
  void **v4; // $s2
  _DWORD *v5; // $a2
  void **v6; // $v1
  int v7; // $a0
  int v8; // $v1
  int v9; // $v0
  int v10; // $v1
  int v11; // $a0
  _DWORD *v12; // $v1

  _mem_malloc(60, "iptv_token_create", 26);
  v3 = (_DWORD *)v2;
  if ( v2 )
  {
    v4 = (void **)(v2 + 44);
    *(_DWORD *)(v2 + 44) = v2 + 44;
    *(_DWORD *)(v2 + 48) = v2 + 44;
    *(_DWORD *)(v2 + 52) = 0;
    *(_DWORD *)(v2 + 56) = 0;
    snprintf((char *)(v2 + 4), 40, "%s", a1);
    get_uptime2(v3);
    v5 = v3 + 13;
    v6 = off_67BEC0;
    v3[11] = &iptv_token_list_head;
    v3[12] = v6;
    off_67BEC0 = v4;
    *v6 = v4;
    v7 = *a1;
    v8 = 0;
    if ( *a1 )
    {
      do
      {
        ++a1;
        v9 = 65600 * v8 + v7;
        v7 = *a1;
        v8 = v9 - v8;
      }
      while ( *a1 );
      v8 = (unsigned __int8)v8;
    }
    v10 = 4 * v8;
    v11 = *(_DWORD *)((char *)&iptv_token_hlist_head + v10);
    v3[13] = v11;
    if ( v11 )
      *(_DWORD *)(v11 + 4) = v5;
    v12 = (_DWORD *)((char *)&iptv_token_hlist_head + v10);
    *v12 = v5;
    v3[14] = v12;
  }
  return v3;
}
// 4CB66C: variable 'v2' is possibly undefined
// 67BEBC: using guessed type void *iptv_token_list_head;
// 67BEC0: using guessed type void **off_67BEC0;
// 6A8804: using guessed type int __fastcall get_uptime2(_DWORD);

