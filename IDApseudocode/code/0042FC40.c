int __fastcall get_name_hash(unsigned __int8 *a1)
{
  int v1; // $v0
  int v2; // $v1
  int v3; // $a1
  unsigned int v4; // $v1
  int v5; // $a1
  int v6; // $a2

  v1 = 0;
  while ( 1 )
  {
    v2 = *a1;
    v3 = 16 * v1;
    ++a1;
    if ( !v2 )
      break;
    while ( 1 )
    {
      v1 = v2 + v3;
      v4 = (v2 + v3) & 0xF0000000;
      v5 = HIBYTE(v4) ^ v1;
      v6 = ~v4;
      if ( !v4 )
        break;
      v2 = *a1;
      LOWORD(v1) = v6 & v5;
      v3 = 16 * (v6 & v5);
      ++a1;
      if ( !v2 )
        return v1 & 0xFFF;
    }
  }
  return v1 & 0xFFF;
}

