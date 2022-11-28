void __fastcall _mem_malloc(int a1, const char *a2, int a3)
{
  _BYTE *v6; // $v0
  _BYTE *v7; // $v1

  if ( a1 > 0 && !httpd_check_sys_freemem2() )
  {
    v6 = malloc(a1);
    if ( v6 )
    {
      v7 = v6;
      ++all_mem_malloc_num;
      do
        *v7++ = 0;
      while ( v7 != &v6[a1] );
      mem_list_add((int)v6, a2, a3, a1);
    }
  }
}
// 67D0A8: using guessed type int all_mem_malloc_num;
// 6A88E8: using guessed type int httpd_check_sys_freemem2(void);

