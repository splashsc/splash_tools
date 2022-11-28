void __fastcall is_in_wday(_BYTE *a1, int a2)
{
  int v2; // $v1
  int v3; // $v0
  const char *v5; // $s0
  int v6; // $s1

  v2 = (char)*a1;
  if ( *a1 )
  {
    v3 = -1;
    v5 = a1 + 1;
    v6 = -1;
    do
    {
      if ( v6 >= 0 || v2 < 48 )
      {
        if ( v2 == 45 )
        {
          v3 = atoi(v5);
        }
        else if ( v2 == 44 )
        {
          if ( a2 >= v6 && v3 >= a2 )
            return;
          v3 = -1;
          v6 = -1;
        }
      }
      else if ( v2 < 58 )
      {
        v3 = atoi(v5 - 1);
        v6 = v3;
      }
      v2 = *v5++;
    }
    while ( v2 );
  }
}

