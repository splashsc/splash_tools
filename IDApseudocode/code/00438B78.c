void __fastcall sdwan_check_in_ac(int *a1, unsigned __int8 *a2)
{
  int v2; // $s3
  int v4; // $s2
  int *v5; // $s0
  int v6; // $s1
  unsigned __int8 *v7; // $s5

  if ( a1 )
  {
    v2 = *a1;
    if ( *a1 )
    {
      v4 = *a2;
      v5 = a1 + 2;
      v6 = 0;
      v7 = a2 + 4;
      while ( 1 )
      {
        ++v6;
        if ( *((unsigned __int8 *)v5 - 4) != v4 )
          goto LABEL_4;
        if ( v4 )
        {
          if ( !memcmp(v5, v7, 0x10u) )
            return;
          v5 += 5;
          if ( v2 == v6 )
            return;
        }
        else
        {
          if ( *v5 == *((_DWORD *)a2 + 1) )
            return;
LABEL_4:
          v5 += 5;
          if ( v2 == v6 )
            return;
        }
      }
    }
  }
}

