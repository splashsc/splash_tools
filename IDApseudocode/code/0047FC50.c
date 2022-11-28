unsigned __int8 *__fastcall ShiBie_find(unsigned __int8 *a1, int a2, unsigned __int8 *a3, int a4)
{
  int v4; // $t3
  unsigned __int8 *i; // $t4
  int v7; // $t0
  int v8; // $v1

  if ( !a1 || a2 < a4 )
    return 0;
  while ( 1 )
  {
    v4 = a4;
    if ( !a4 )
      break;
    for ( i = a1; ; ++i )
    {
      v7 = *a3;
      --v4;
      if ( (unsigned int)(v7 - 65) < 0x1A )
        v7 = (unsigned __int8)(v7 + 32);
      v8 = *i;
      ++a3;
      if ( (unsigned int)(v8 - 65) < 0x1A )
        v8 = (unsigned __int8)(v8 + 32);
      if ( v7 != v8 )
        break;
      if ( !v4 )
        return a1;
    }
    ++a1;
    --a2;
    if ( !a1 || a2 < a4 )
      return 0;
  }
  return a1;
}

