int __fastcall do_file(const char *a1, int a2, int a3)
{
  FILE *v5; // $s3
  int v6; // $s0
  int v7; // $v0
  void *v8; // $a0
  char v10[1028]; // [sp+18h] [-404h] BYREF

  v5 = fopen(a1, "r");
  if ( !v5 )
    return 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = fread(v10, 1u, 0x400u, v5);
    v8 = (void *)(a2 + v6);
    if ( v7 <= 0 || a3 < v6 + v7 )
      break;
    v6 += v7;
    memcpy(v8, v10, v7);
  }
  fclose(v5);
  return v6;
}

