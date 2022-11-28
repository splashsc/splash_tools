bool __fastcall ip_allow_to_access(_DWORD *a1)
{
  int v1; // $s0
  int v3; // $s2
  uint32_t v4; // $s0
  uint32_t v6; // $v0
  __int64 v7; // $s0

  v1 = a1[4];
  v3 = a1[2] | a1[3];
  if ( v1 ^ htonl(0xFFFFu) | v3 )
  {
    LODWORD(v7) = a1[5];
    HIDWORD(v7) = a1[2] | a1[3] | a1[4];
    if ( v7 != htonl(1u) )
      return 1;
    v4 = htonl(0x7F000001u);
    if ( !v4 )
      return 1;
  }
  else
  {
    v4 = a1[5];
    if ( !v4 )
      return 1;
  }
  if ( v4 == htonl(0x7F000001u) )
    return 1;
  v6 = ntohl(v4);
  return ip_allow_to_access_jhttpd(v6) != 0;
}

