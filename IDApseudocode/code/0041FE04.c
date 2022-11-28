int sub_41FE04()
{
  _DWORD *v0; // $ra
  int v1; // $a0
  void *v3; // [sp+8h] [-20h]
  int v4; // [sp+28h] [+0h] BYREF

  ((void (__fastcall *)(int *, char *))((char *)v0 + v0[1] - *v0))(&v4, (char *)v0 + v0[2] - *v0);
  _libc_start_main(main, *(_DWORD *)v1, (char **)(v1 + 4), init_proc, (void (*)(void))term_proc, 0, v3);
  return sub_41FE70();
}
// 41FE18: variable 'v0' is possibly undefined
// 41FE3C: variable 'v1' is possibly undefined
// 41FE5C: variable 'v3' is possibly undefined

