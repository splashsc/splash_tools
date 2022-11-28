void __fastcall search_str(char *a1, int a2, const void *a3, size_t a4)
{
  char *v5; // $s0
  char *v7; // $s1
  int v8; // $v0

  if ( a4 && (int)(a2 - a4) > 0 )
  {
    v5 = a1;
    v7 = &a1[a2 - a4];
    do
      v8 = memcmp(v5++, a3, a4);
    while ( v8 && v5 != v7 );
  }
}

