int __fastcall eval_nowait_tty(int a1, int a2, int a3, int a4, socklen_t *a5)
{
  int v5; // $a0
  int v6; // $a1
  int v7; // $a2
  void *v8; // $a3

  MEMORY[0]();
  return getsockopt(v5, v6, v7, v8, a5);
}
// 4CE5A9: variable 'v5' is possibly undefined
// 4CE5A9: variable 'v6' is possibly undefined
// 4CE5A9: variable 'v7' is possibly undefined
// 4CE5A9: variable 'v8' is possibly undefined

