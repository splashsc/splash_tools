void __fastcall _mem_free(void *a1)
{
  if ( a1 )
  {
    mem_list_del((int)a1);
    --all_mem_malloc_num;
    free(a1);
  }
}
// 67D0A8: using guessed type int all_mem_malloc_num;

