void mem_list_show()
{
  int v0; // $s0
  int v1; // $v0
  int v2; // $s1

  v0 = ll_mem_debug_list;
  if ( (int *)ll_mem_debug_list != &ll_mem_debug_list )
  {
    v1 = 1;
    do
    {
      v2 = v1 + 1;
      syslog(7, "%d %s[%d] len:%d", v1, (const char *)(v0 + 20), *(_DWORD *)(v0 + 84), *(_DWORD *)(v0 + 88));
      v0 = *(_DWORD *)v0;
      v1 = v2;
    }
    while ( (int *)v0 != &ll_mem_debug_list );
  }
}
// 67D060: using guessed type int ll_mem_debug_list;

