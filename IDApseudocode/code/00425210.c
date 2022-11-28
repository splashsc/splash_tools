char *__fastcall find_file_end(int a1, char *a2, signed int a3)
{
  int v3; // $a0
  const void *v4; // $s3
  signed int v6; // $s2
  signed int v7; // $s0

  v3 = a1 + 196608;
  v4 = *(const void **)(v3 + 8904);
  if ( !v4 )
    return (char *)v4;
  v6 = *(_DWORD *)(v3 + 8908);
  v7 = a3;
  if ( a3 >= v6 )
  {
    while ( 1 )
    {
      --v7;
      if ( !memcmp(a2, v4, v6) )
        break;
      ++a2;
      if ( v7 < v6 )
        return 0;
    }
    return a2 - 4;
  }
  return 0;
}

