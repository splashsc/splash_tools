bool __fastcall hs_addr_loopback(int a1)
{
  int v1; // $a0
  int v2; // $s0
  int v3; // $s1
  uint32_t v4; // $v0
  int v6; // $s0

  v1 = a1 + 196608;
  if ( *(_BYTE *)(v1 + 8852) )
  {
    v2 = *(_DWORD *)(v1 + 8868);
    v3 = *(_DWORD *)(v1 + 8856) | *(_DWORD *)(v1 + 8860) | *(_DWORD *)(v1 + 8864);
    v4 = v2 ^ htonl(1u) | v3;
  }
  else
  {
    v6 = *(_DWORD *)(v1 + 8856);
    v4 = v6 ^ htonl(0x7F000001u);
  }
  return v4 == 0;
}

