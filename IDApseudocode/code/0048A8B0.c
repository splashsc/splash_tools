void __fastcall read_file_buf(const char *a1, int *a2)
{
  int v4; // $s1
  int v5; // $v0
  int v6; // $s2
  struct stat v7; // [sp+8h] [-B8h] BYREF

  if ( a1 && stat(a1, &v7) >= 0 )
  {
    v4 = v7.st_atim.tv_sec + 1024;
    _mem_malloc(v7.st_atim.tv_sec + 1024, "read_file_buf", 53);
    v6 = v5;
    if ( v5 )
    {
      do_file(a1, v5, v4);
      *a2 = v6;
    }
  }
}
// 48A924: variable 'v5' is possibly undefined

