int __fastcall mask_addr_to_inet(const char *a1)
{
  uint32_t v1; // $v0
  int v2; // $a0
  int v3; // $v1
  uint32_t hostlong[3]; // [sp+18h] [-Ch] BYREF

  inet_aton(a1, (struct in_addr *)hostlong);
  v1 = htonl(hostlong[0]);
  v2 = 0;
  if ( (v1 & 1) != 0 )
    return 32;
  v3 = 1;
  do
  {
    v3 *= 2;
    ++v2;
  }
  while ( (v3 & v1) == 0 );
  return 32 - v2;
}

