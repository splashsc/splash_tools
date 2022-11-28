void __fastcall strlower(char *a1)
{
  int v2; // $a0
  _BYTE *v3; // $s0
  unsigned int v4; // $v1

  if ( a1 )
  {
    v2 = *a1;
    v3 = a1;
    if ( v2 )
    {
      v4 = v2 - 65;
      do
      {
        if ( v4 < 0x1A )
          *v3 = tolower(v2);
        v2 = (char)*++v3;
        v4 = v2 - 65;
      }
      while ( *v3 );
    }
    *v3 = 0;
  }
}

